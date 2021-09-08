#include <sys/types.h>

#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H

//Tipos de de estados de um processo
// enum Estado { Pronto, Bloqueado, Execução};

// //Tipos de prioridade
enum ProcessState { Blocked, InExecution, Ready } State;

typedef int* Time; 

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

typedef struct{
    int *pid;
    int *PC;
    int *EstructData;
    int priority;
    //State state;
    int timeCPU;
} Process;

// //Estrutura de dados da tabela de processos
typedef struct{
    Process *ProcessTable;
} ProcessTable;

void getControllerData(int* pipe, char *instructionReceived);
void runInstructionPM(char* instructionReceived);
void processManager(pid_t* pid, int *pipe, int hasData);//"main"




#endif