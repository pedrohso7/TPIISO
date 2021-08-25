
#include "ProcessManager.h"

#define TAM 256 //2^8

void ProcessManager(pid_t pid, int *fd){
    char str[TAM];

    //Como esse processo apenas lerá, vamos fechar o segundo fd do vetor
    close(fd[1]);
    
    /* Lê dados no pipe */
    read(fd[0], str, sizeof(str));
    
    printf("String lida pelo filho no Pipe : '%s'\n\n", str);
    getchar();
    getchar();
    exit(0);
};