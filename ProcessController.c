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

#define TAM 256


void createPipeAndManagerProcess(int* fd, pid_t* pid){
    //Controlador começa primeiro
    //*hasData = 0;

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
    printf("| I: Imprimer o estado atual do sistema.                            |\n");
    printf("| M: Imprime o tempo medio do ciclo e finaliza o sistema.           |\n");
    printf("|-------------------------------------------------------------------|\n");
    printf("Opcao: ");
    
    scanf("%s", instructionReceived);
    
    //printf("\n%d\n", hasData);
    
    //se foi inserido alguma coisa
    if(strlen(instructionReceived) > 0){
        //Escreve os dados no pipe
        //printf("\n%s\n", instructionReceived);
        write(pipe[1], instructionReceived, sizeof(instructionReceived) + 1);
            //break;
    }
}


void interactionByKeyboard() {
    int pipe[2]; // Usado para o pipe com o gerenciador de processos
    pid_t pid; // Variável para armazenar o pid dos processos
    int mutex = 1, hasData = 0;
    

    //O nome já diz...
    createPipeAndManagerProcess(pipe, &pid);
    
    //while(true){

        // Código do processo pai (Controller)
        if(pid > 0){
            char instructionReceived[TAM]; // Opções de comando

            //Como esse processo apenas escreverá, vamos fechar o primeiro fd do vetor
            close(pipe[0]);

             while(true){
                 if(mutex == 1){
                    mutex--;
                    getDataFromKeyboardAndWrite(pipe, instructionReceived);          
                 }
             }
        }

        // Código do processo filho (Manager)
        else if( pid == 0) { 
            //printf("FILHO hasData: %d", hasData);
            //Como esse processo apenas lerá, vamos fechar o segundo fd do vetor
            close(pipe[1]);
            
             while(true){    //hasData = 0;
                if(mutex == 0){
                    mutex++;

                    processManager(&pid, pipe, hasData);
                }
            }
            
        } 

        // Código executado por ambos 
    //}
    
}


int main(int *argc, char* argv){
//    char mem[MAXTAM];

    interactionByKeyboard();

    //Testes do processo simulado
    //processMain(mem);

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