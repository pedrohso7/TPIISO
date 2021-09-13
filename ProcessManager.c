/*
    Esse componente precisa:
    -> Criar um novo processo (simulado). -> V
    -> Substituir a imagem atual de um processo simulado por uma imagem nova de processo
    -> (Em andamento) Gerenciar a transição de estados do processo.
    -> Escalonar processos e trocar contexto (Política de escalonamento).
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>

#include "ProcessManager.h"

//#include "ProcessSimulation.c"

#define TAM 256 //2^8

Time *time;
CPU *i3;//Não tem a mesma quantidade de núcleos mas é representativo, rs
List *processTable;//Armazena todos os processos
List *blockedList;//Fila de processos bloqueados
List *readyList;////Fila de processos "prontos"

void clearArray(char* instructionReceived, int N){
    int i;

    for(i = 0; i < N; i++)
        instructionReceived = 0;
}

void getManagerInitialState(/*List* processTable, List* blockedList, List* readyList, int* time, CPU *i3*/){    
    /*
        O código para alocar os dados dessa maneira,
        de maneira compartilhada, foi tirada de:
        https://stackoverflow.com/questions/13274786/how-to-share-memory-between-processes-created-by-fork
    */
    
    //Inicializa dados de controle das listas
    processTable = mmap(NULL, sizeof *processTable, PROT_READ | PROT_WRITE, 
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    blockedList = mmap(NULL, sizeof *blockedList, PROT_READ | PROT_WRITE, 
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    readyList = mmap(NULL, sizeof *readyList, PROT_READ | PROT_WRITE, 
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    
    i3 = mmap(NULL, sizeof *i3, PROT_READ | PROT_WRITE, 
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    
    time = mmap(NULL, sizeof *time, PROT_READ | PROT_WRITE, 
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    if(time == NULL || processTable == NULL || blockedList == NULL || readyList == NULL || i3 == NULL){
        printf("Memoria insuficiente!\n");
        free(i3);
        free(readyList);
        free(blockedList);
        free(processTable);
        
        exit(EXIT_FAILURE);
    }
    inicialize(processTable);
    printf("\n man:%d\n", processTable->length);
    inicialize(blockedList);
    inicialize(readyList);

    //Inicializa tempo
    *time = 0;
}

void getControllerData(int* pipe, char *instructionReceived){
    
    /* Lê dados no pipe */
    read(pipe[0], instructionReceived, sizeof(instructionReceived));
}

void runInstructionFromController(char *instructionReceived/*, List *processTable, List *blockedList, List *readyList, int *time, CPU *i3*/){
    switch(instructionReceived[0]){
        case 'U': //Fim de uma unidade de tempo
            printf("Executando proxima instrucao do processo simulado!.\n");

            //(*timeCPU)++;
            break;
        case 'L': //Desbloqueia o primeiro processo simulado na fila bloqueada
            //code;
            printf("Desbloqueia o primeiro processo simulado na fila bloqueada!.\n");
            break;
        case 'I': //Imprimer o estado atual do sistema.
            printf("Estado atual do sistema:\n");
            if(processTable->begin->data != NULL){
                printf("qqpega ze");
            }
            //printf("%d", processTable->begin->data->pid);
            // printf("PID: %d | PC: %d | ESTADO: %d | PRIORIDADE: %d\n", *(processTable->begin->data->pid), *(processTable->begin->data->pc), *(processTable->begin->data->state), *(processTable->begin->data->priority));
            //Exibe tabela de processos
            printf("=======TABELA DE PROCESSOS======\n");
            show(processTable);
            printf("================================\n");

            //Exibe lista de processos bloqueados
            printf("=======TABELA DE PROCESSOS BLOQUEADOS======\n");
            show(blockedList);
            printf("===========================================\n");

            //Exibe lista de processos prontos para execução
            printf("=======TABELA DE PROCESSOS PRONTOS======\n");
            show(readyList);
            printf("========================================\n");
            break;
        case 'M': //Imprime o tempo medio do ciclo e finaliza o sistema.
            //code;
            printf("Tempo médio do ciclo: \n");
            printf("PROGRAMA ENCERRADO!!\n");
            exit(EXIT_SUCCESS);
            break;
        default: 
            printf("Opcao Invalida...Digite novamente.\n");
            break;
    }
}

void createManagerAndFirstProcess(int* pipe){
    pid_t pid;//PID do único processo instancido pelo gerenciador
    
    getManagerInitialState(/*processTable, blockedList, readyList, time, i3*/);

    pid = fork();

    //Verifica se o processo foi instanciado corretamente (retorna -1 se deu erro)
    if(pid < 0){
        printf("ERRO AO CRIAR O PROCESSO!!\n");
        printf("PROGRAMA ENCERRADO!!\n");
        exit(EXIT_FAILURE);
    }
    
    // Código do processo pai (Manager)
    if(pid > 0){
        int *PC;
        int PCValue;
        char instructionReceived[TAM];//usada para pegar os dados no pipe

        while(1){
            //Lê os dados do pipe
            getControllerData(pipe, instructionReceived);

            //Avalia se foi recebido algo
            if(strlen(instructionReceived) > 0){
                //Executa instrução exigida pelo controller
                runInstructionFromController(instructionReceived/*, processTable, blockedList, readyList, &time, i3*/);
                //clearArray(instructionReceived, strlen(instructionReceived));
            }
        }
    } 

    // Código do processo filho (Primeiro/Unico processo filho)
    else if( pid == 0) {
        processMain("testProcess.txt", processTable);
    }

    //printf("pai: %d, filho: %d", pidParent, pidChildren);
}

void processManager(int *pipe){

    createManagerAndFirstProcess(pipe);
    
}