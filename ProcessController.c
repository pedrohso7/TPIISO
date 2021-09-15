/* ESSE PROGRAMA DEVE EXIBIR NO TERMINAL:
1. U: Fim de uma unidade de tempo.
2. L: Desbloqueia o primeiro processo simulado na fila bloqueada.
3. I: Imprime o estado atual do sistema.
4. M: Imprime o tempo médio do ciclo e finaliza o sistema.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>


//#include "ProcessManager.c"
#include "ProcessManager.h"
#include "ProcessSimulation.h"

#define TAM 256


void createPipeAndManagerProcess(int* fd, pid_t* pid){
    //Cria o pipe
    pipe(fd);

    //Cria o processo gerenciador
    *pid = fork();


    //Verifica se o pipe foi instanciado corretamente (retorna -1 se deu erro)
    if(fd < 0){
        printf("ERRO AO CRIAR O PIPE!!\n");
        printf("PROGRAMA ENCERRADO!!\n");
        exit(EXIT_FAILURE);
    }

    //Verifica se o processo foi instanciado corretamente (retorna -1 se deu erro)
    if(*pid < 0){
        printf("ERRO AO CRIAR O PROCESSO GERENCIADOR!!\n");
        printf("PROGRAMA ENCERRADO!!\n");
        exit(EXIT_FAILURE);
    }
}

void getDataFromKeyboardAndWrite(int *pipe, char *instructionReceived){
    printf("\n");
    printf("|-------------------------------------------------------------------|\n");
    printf("| U: Fim de uma unidade de tempo.                                   |\n");
    printf("| L: Desbloqueia o primeiro processo simulado na fila bloqueada     |\n");
    printf("| I: Imprime o estado atual do sistema.                            |\n");
    printf("| M: Imprime o tempo medio do ciclo e finaliza o sistema.           |\n");
    printf("|-------------------------------------------------------------------|\n");
    printf("Opcao: ");
    
    scanf("%s", instructionReceived);
    
    //se foi inserido alguma coisa
    if(strlen(instructionReceived) > 0)
        //Escreve os dados no pipe
        write(pipe[1], instructionReceived, sizeof(instructionReceived) + 1);
    
}


void interactionByKeyboard() {
    int pipe[2]; // Usado para o pipe com o gerenciador de processos
    pid_t pid; // Variável para armazenar o pid dos processos
    //int mutex = true, hasData = 0;
    

    //O nome já diz...
    createPipeAndManagerProcess(pipe, &pid);

    // Código do processo pai (Controller)
    if(pid > 0){
        char instructionReceived[TAM]; // Opções de comando

        //Como esse processo apenas escreverá, vamos fechar o primeiro fd do vetor
        close(pipe[0]);

        while(true){
            //system("clear");
            fflush(stdout);
            getDataFromKeyboardAndWrite(pipe, instructionReceived);
            getchar();
            getchar();
        }
    }

    // Código do processo filho (Manager)
    else if( pid == 0) { 
        //Como esse processo apenas lerá, vamos fechar o segundo fd do vetor
        close(pipe[1]);

        processManager(pipe);
    } 

    // Código executado por ambos
}


int main(int *argc, char* argv){

    //Testes do processo gerenciador
    interactionByKeyboard();

    return 0; // Retorno padrão do main (status 0 = OK)
}


/*A parte abaixo provavelmente será utilizada também*/
    // printf("\n");
    // printf("|-------------------------------------------------------------------|\n");
    // printf("|     - Trabalho Pratico 2 - Sistemas Operacionais                  |\n");
    // printf("|     - Mariana Souza - EF03898                                     |\n");
    // printf("|     - Pedro Oliveira - EF02677                                    |\n");
    // printf("|-------------------------------------------------------------------|\n");

    // while(1){
    //     printf("\n");
    //     printf("|-------------------------------------------------------------------|\n");
    //     printf("| 1. Leitura de dados a partir de um arquivo.                       |\n");
    //     printf("| 2. Leitura de dados a partir do teclado.                          |\n");
    //     printf("| 3. Encerrar programa.                                             |\n");
    //     printf("|-------------------------------------------------------------------|\n");
    //     printf("Opcao: ");
    //     scanf("%d", &option);

    //     switch(option){
    //         case 1:
    //             //interacaoUsuarioArquivo();
    //             break;
    //         case 2:
    //             interactionByKeyboard();
    //             break;
    //         case 3:
    //             exit(EXIT_SUCCESS);
    //         default:
    //             printf("Opcao Invalida...Digite novamente.\n");
    //             break;

    //     }
    // }