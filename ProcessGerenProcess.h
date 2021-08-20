#ifndef PROCESSGERENPROCESS
#define PROCESSGERENPROCESS
//#include <unistd.h>
//Essas struct foram implementadas por outra pessoa.
typedef struct CPU{
    int *ArrayProgam;
    int contProgram;
    int *memoryEstructdados;
    int timeProcessSimulado;
};

typedef struct Tabeladeprocessos{
    int pid;
    int ppid;
    int *ContProgram = 0;
    int EstructData;
    int prioridada;
    int estado;
    int timeI;
    int timeCPU;
};

typedef struct GerenciadordeProcesso{
    CPU cpu;
    Tabeladeprocessos* tabelaProcess;
    int stateExec;
};







#endif