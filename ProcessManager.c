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
#include <unistd.h>
#include <stdbool.h>

#include "ProcessManager.h"
#include "ProcessSimulation.h"
//#include "ProcessSimulation.c"

#define TAM 256 //2^8

void clearArray(char* instructionReceived, int N){
    int i;

    for(i = 0; i < N; i++)
        instructionReceived = 0;
}

void getControllerData(int* pipe, char *instructionReceived){
    
    /* Lê dados no pipe */
    read(pipe[0], instructionReceived, sizeof(instructionReceived));
}

void runInstructionFromController(char* instructionReceived, CPU* i3){
    //System("clear");

    switch(instructionReceived[0]){
        case 'U': //Fim de uma unidade de tempo
            printf("Executando proxima instrucao do processo simulado!.\n");

            (*timeCPU)++;
            break;
        case 'L': //Desbloqueia o primeiro processo simulado na fila bloqueada
            //code;
            printf("Desbloqueia o primeiro processo simulado na fila bloqueada!.\n");
            break;
        case 'I': //Imprimer o estado atual do sistema.
            //code;
            printf("Estado atual do sistema:\n");
            break;
        case 'M': //Imprime o tempo medio do ciclo e finaliza o sistema.
            //code;
            printf("Tempo médio do ciclo: \nint ");
            printf("PROGRAMA ENCERRADO!!\n");
            exit(EXIT_SUCCESS);
            break;
        default: 
            printf("Opcao Invalida...Digite novamente.\n");
            break;
    }
}

void createFirstProcess(pid_t* pid, int* pipe){
    *pid = fork();

    //Verifica se o processo foi instanciado corretamente (retorna -1 se deu erro)
    if(*pid < 0){
        printf("ERRO AO CRIAR O PROCESSO!!\n");
        printf("PROGRAMA ENCERRADO!!\n");
        exit(EXIT_FAILURE);
    }
    
    // Código do processo pai (Manager)
    if(*pid > 0){
        int *PC;
        int PCValue;
        char instructionReceived[TAM];//usada para pegar os dados no pipe

        Time timeCPU = 0;
        CPU *i3;//Não tem a mesma quantidade de núcleos mas é representativo, rs
        
        i3 = (CPU *)malloc(sizeof(CPU));
        if(i3 == NULL){
            printf("Memoria insuficiente!\n");
            free(i3);
            exit(EXIT_FAILURE);
        }
        
        //ProcessTable *processTable;

        while(1){

            //Lê os dados do pipe
            getControllerData(pipe, instructionReceived);

            //Avalia se foi recebido algo
            if(strlen(instructionReceived) > 0){
                //Executa instrução exigida pelo controller
                runInstructionFromController(instructionReceived, &timeCPU);
                //clearArray(instructionReceived, strlen(instructionReceived));
            }
        }
    } 

    // Código do processo filho (Primeiro/Unico processo filho)
    else if( *pid == 0) {
        processMain("testProcess.txt");
    }
}

void processManager(int *pipe){
    pid_t pid;//PID do único processo instancido pelo gerenciador

    createFirstProcess(&pid, pipe);
    
}