#include <sys/types.h>

#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H

//Tipos de de estados de um processo
// enum Estado { Pronto, Bloqueado, Execução};

// //Tipos de prioridade
// enum Prioridade { Alta, Media, Baixa};

//Estrutura de dados da CPU
// typedef struct{
//     int *ArrayProgam;
//     int contProgram;
//     int *memoryEstructdados;
//     int timeProcessSimulado;
// } CPU;

// //Estrutura de dados de um processo
// typedef struct{
//     int pid;
//     int *programCounter;
//     int EstructData;
//     enum Prioridade prioridade;
//     enum Estado estado;
//     int timeI;
//     int timeCPU;
// } Process;

// //Estrutura de dados da tabela de processos
// typedef struct{
//     int pid;
//     int ppid;
//     int *ContProgram;
//     int EstructData;
//     int prioridada;
//     int estado;
//     int timeI;
//     int timeCPU;
// } ProcessTable;

// //Estrutura de dados do processo gerenciador de processos
// typedef struct{
//     CPU cpu;
//     ProcessTable* processTable;
//     int stateExec;
// } GerenciadordeProcesso;


void ProcessManager(pid_t pid, int *fd); // Processo gerenciador de processos




#endif