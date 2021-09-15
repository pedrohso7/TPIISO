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
#include <fcntl.h>
#include <errno.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>

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

    // int PID = 2134;
    // int *d;
    // int PC = 0;
    // int state = 0;
    // int timeCPU = 0;
    // int priority = 0;

    Element *newElement;

    /* Open physical memory */
    //ShmID = shmget(ShmKEY, sizeof(struct Memory), IPC_CREAT | 0666);
    key_t PTKEY, BLKEY, RLKEY, I3KEY, TIMEKEY;

    int PTID = shmget(PTKEY, sizeof(List), IPC_CREAT | 0666);
    int BLID = shmget(BLKEY, sizeof(List), IPC_CREAT | 0666);
    int RLID = shmget(RLKEY, sizeof(List), IPC_CREAT | 0666);
    int I3ID = shmget(I3ID, sizeof(List), IPC_CREAT | 0666);
    int TIMEID = shmget(TIMEKEY, sizeof(List), IPC_CREAT | 0666);

    if (PTID < 0 && BLID < 0 && RLID < 0 && I3ID < 0 && TIMEID < 0) {
        printf("*** shmat error (server) ***\n");
        exit(1);
    }

    processTable = (List *) shmat(PTID, NULL, 0);
    blockedList = (List *) shmat(BLID, NULL, 0);
    readyList = (List *) shmat(RLID, NULL, 0);
    i3 = (CPU *) shmat(I3ID, NULL, 0);
    time = (Time *) shmat(TIMEID, NULL, 0);

    if((int ) time == -1 || (int )processTable == -1 || (int )blockedList == -1 || (int )readyList == -1 || (int )i3 == -1 ){
        printf("Memoria insuficiente!\n");
        free(i3);
        free(readyList);
        free(blockedList);
        free(processTable);
        
        exit(EXIT_FAILURE);
    }
    
    //Inicializa dados de controle das listas
    // processTable = (List *)mmap(NULL, sizeof(List), PROT_READ | PROT_WRITE, 
    //                 MAP_SHARED , fdPT, 0);

    // blockedList = (List *)mmap(NULL, sizeof(List), PROT_READ | PROT_WRITE, 
    //                 MAP_SHARED , fdBL, 0);

    // readyList = (List *)mmap(NULL, sizeof(List), PROT_READ | PROT_WRITE, 
    //                 MAP_SHARED, fdRL, 0);
    
    // i3 = (CPU *)mmap(NULL, sizeof(CPU), PROT_READ | PROT_WRITE, 
    //                 MAP_SHARED, fdI3, 0);
    
    // time = (Time *)mmap(NULL, sizeof(Time), PROT_READ | PROT_WRITE, 
    //                 MAP_SHARED, fdTime, 0);

    inicialize(processTable);
    // printf("\n man:%d\n", processTable->length);
    inicialize(blockedList);
    inicialize(readyList);

    // if ((newElement = (Element *)malloc(sizeof(Element))) == NULL){
    //     printf("FALHA AO ALOCAR MEMÓRIA!!");
    //     free(newElement);
    //     exit(EXIT_FAILURE);
    // }

    // if ((newElement->data = (ProcessData *)malloc(sizeof(ProcessData))) == NULL){
    //     printf("FALHA AO ALOCAR MEMÓRIA!!");
    //     free(newElement->data);
    //     exit(EXIT_FAILURE);
    // }
    // newElement->data->pid = &PID;
    // newElement->data->data = d;
    // newElement->data->pc = &PC;
    // newElement->data->state = &state;
    // newElement->data->timeCPU = &timeCPU;
    // newElement->data->priority = &priority;

    // printf("newEINIT: %p\n", newElement);
    
    // printf("\n\nPID: %d | PC: %d | ESTADO: %d | PRIORIDADE: %d\n", *(newElement->data->pid), *(newElement->data->pc), *(newElement->data->state), *(newElement->data->priority));
    // insertElement(processTable, processTable->end, newElement);

    

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
            //printf("%d", processTable->begin->data->pid);
            // printf("PID: %d | PC: %d | ESTADO: %d | PRIORIDADE: %d\n", *(processTable->begin->data->pid), *(processTable->begin->data->pc), *(processTable->begin->data->state), *(processTable->begin->data->priority));
            
            //Exibe tabela de processos
            //fflush(stdin);
            // printf("\n PT:%d\n", processTable->length);
            // printf("\n BL:%d\n", blockedList->length);
            // printf("\n RL:%d\n", readyList->length);
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
            printf("Tempo medio do ciclo: \n");
            printf("PROGRAMA ENCERRADO!!\n");
            exit(EXIT_SUCCESS);
            break;
        default: 
            printf("Opcao Invalida...Digite novamente.\n");
            break;
    }
}

void createManagerAndFirstProcess(int* pipe, pid_t *pid){
    getManagerInitialState(/*processTable, blockedList, readyList, time, i3*/);

    *pid = fork();

    //Verifica se o processo foi instanciado corretamente (retorna -1 se deu erro)
    if(*(pid) < 0){
        printf("ERRO AO CRIAR O PROCESSO!!\n");
        printf("PROGRAMA ENCERRADO!!\n");
        exit(EXIT_FAILURE);
    }
    
    // Código do processo pai (Manager)
    if(*(pid) > 0){
        int *PC;
        int PCValue;
        char instructionReceived[TAM];//usada para pegar os dados no pipe

        printf("pai");

        while(1){
            // Lê os dados do pipe
            getControllerData(pipe, instructionReceived);

            //Avalia se foi recebido algo
            if(strlen(instructionReceived) > 0){
                fflush(stdout);
                //Executa instrução exigida pelo controller
                runInstructionFromController(instructionReceived/*, processTable, blockedList, readyList, &time, i3*/);
                //clearArray(instructionReceived, strlen(instructionReceived));
            }
        }
        
    } 

    // Código do processo filho (Primeiro/Unico processo filho)
    else if (*(pid) == 0){
        fflush(stdin);
        printf("CODIGO FILHO====");
        //while(1){}
        processMain("testProcess.txt", processTable);
    }
    //printf("pai: %d, filho: %d", pidParent, pidChildren);
}

void processManager(int *pipe){
    pid_t pid;
    createManagerAndFirstProcess(pipe, &pid);
    
}