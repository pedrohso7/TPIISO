#include <sys/types.h>

#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H


typedef struct{
    int *ArrayProgam;
    int contProgram;
    int *memoryEstructdados;
    int timeProcessSimulado;
} CPU;

typedef struct{
    int pid;
    int ppid;
    int *ContProgram;
    int EstructData;
    int prioridada;
    int estado;
    int timeI;
    int timeCPU;
} ProcessTable;

typedef struct{
    CPU cpu;
    ProcessTable* processTable;
    int stateExec;
} GerenciadordeProcesso;


void ProcessManager(pid_t pid, int *fd); // Processo gerenciador de processos




#endif