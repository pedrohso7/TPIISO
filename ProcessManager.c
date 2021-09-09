/*
    Esse componente precisa:
    -> Criar um novo processo (simulado).
    -> Substituir a imagem atual de um processo simulado por uma imagem nova de processo
    -> Gerenciar a transição de estados do processo.
    -> Escalonar processos e trocar contexto (Política de escalonamento).
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>

#include "ProcessManager.h"
//#include "ProcessSimulation.c"

#define TAM 256 //2^8

void getControllerData(int* pipe, char *instructionReceived){
    
    /* Lê dados no pipe */
    read(pipe[0], instructionReceived, sizeof(instructionReceived));
}

void runInstructionPM(char* instructionReceived, int* timeCPU){
    system("clear");

    switch(instructionReceived[0]){
        case 'U': //Fim de uma unidade de tempo
            printf("Fim de uma unidade de tempo!.\n");
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

void processManager(pid_t* pid, int *pipe, int hasData){
    int timeCPU = 0;
    int auxTime;
    int *PC;
    int PCValue;
    char instructionReceived[TAM];//usada para pegar os dados no pipe
    ProcessTable* processTable;
    
    if ((processTable = (Fila *)malloc(sizeof(ProcessTable))) == NULL)
        return -1;
        
    inicialize(processTable);
    
    /* Pedro: Comentei para testar a implementação das listas
    //Lê os dados do pipe
    getControllerData(pipe, instructionReceived);
    
    if(strlen(instructionReceived) > 0){
        auxTime = timeCPU;
        runInstructionPM(instructionReceived, &timeCPU);
        if(auxTime != timeCPU){
            //CODE
        }
    }*/
}