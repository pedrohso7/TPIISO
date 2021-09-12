#include <sys/types.h>
#include "ProcessList.h"


#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H

typedef int Time; 

//Estrutura de dados da CPU
typedef struct{
    int *processProgram; //Ponteiro para a memória
    int *PC; //Ponteiro para o PC do processo simulado
    int PCValue;//Valor lido e utilizado na CCPU
    int timeCPU;//Fatia de tempo ????
} CPU;

//A TABELA DE PROCESSOS ARMAZENA OS DADOS DOS PROCESSOS
//ENQUANTO A CPU EXECUTA, UTILIZANDO OS DADOS INICIAIS DA TABELA
//DE PROCESSOS DO RESPECTIVO PROCESSO (EM EXECUÇÃO) E, APÓS A 
//TROCA DE CONTEXTO, REGISTRA A ALTERAÇÕES QUE O PROCESSADOR FEZ PARA
//A TABELA E PARA O OS "REGISTRADORES" DO PROCESSO

// typedef struct{
//     int *pid;
//     int *PC;
//     int *EstructData;
//     int priority;
//     //State state;
//     int timeCPU;
// } Process;

void clearArray(char* instructionReceived, int N);
void getManagerInitialState(List* processTable, List* blockedList, List* readyList, int* time, CPU *i3);
void getControllerData(int* pipe, char *instructionReceived);
void runInstructionFromController(char* instructionReceived, CPU* i3);
void createFirstProcess(pid_t* pid, int* pipe);
void processManager(int *pipe);//"main"




#endif