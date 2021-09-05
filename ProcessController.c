#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>

#include "ProcessManager.c"
#include "ProcessSimulation.c"


void interactionByKeyboard() {
    int option; // Opções de comando

    while (1){
        printf("\n");
        printf("|-------------------------------------------------------------------|\n");
        printf("| 1. U: Fim de uma unidade de tempo.                                |\n");
        printf("| 2. L: Desbloqueia o primeiro processo simulado na fila bloqueada  |\n");
        printf("| 3. I: Imprimer o estado atual do sistema.                         |\n");
        printf("| 4. M: Imprime o tempo medio do ciclo e finaliza o sistema.        |\n");
        printf("|-------------------------------------------------------------------|\n");
        printf("Opcao: ");
        scanf("%d", &option);
        
        switch(option){
            case 1:
                //code
                printf("Processo desbloqueado!.\n");
                getchar();
                getchar();
                break;
            case 2:
                //code;
                printf("Processo desbloqueado!.\n");
                getchar();
                getchar();
                break;
            case 3:
                //code;
                printf("Estado atual do sistema:\n");
                getchar();
                getchar();
                break;
            case 4:
                //code;
                printf("Tempo médio do ciclo: \n");
                printf("PROGRAMA ENCERRADO!!\n");
                getchar();
                exit(EXIT_SUCCESS);
                break;
            default: 
                printf("Opcao Invalida...Digite novamente.\n");
                break;
                
        }
           
    }
}


int main(int *argc, char* argv){
    int fd[2]; // Usado para o pipe com o gerenciador de processos
    pid_t pid; // Variável para armazenar o pid
    int option; // Opção selecionada para o processo controller
    char mem[MAXTAM];

    //Cria o pipe
    // pipe(fd);
    // pid = fork();
    // if(fd < 0){//Verifica se o pipe foi instanciado corretamente (retorna -1 se deu erro)
    //     printf("ERRO AO CRIAR O PIPE!!");
    //     exit(EXIT_SUCCESS);
    // }
    // if(pid < 0){//Verifica se o processo foi instanciado corretamente (retorna -1 se deu erro)
    //     printf("ERRO AO CRIAR O PROCESSO!!");
    //     exit(EXIT_SUCCESS);
    // }
    // if(pid > 0){// Código do processo pai
    //     char str[256] = "TESTE!";

    //     //Como esse processo apenas escreverá, vamos fechar o primeiro fd do vetor
    //     close(fd[0]);

    //     printf("String enviada pelo pai no Pipe: '%s'\n\n", str);

    //     //Escreve os dados no pipe
    //     write(fd[1], str, sizeof(str) + 1);
    //     //processMain();

        
    // } else if (pid == 0){ // Código do processo pai
    //     ProcessManager(pid, fd);
    // }
    

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
    processMain(mem);
    return 0; // Retorno padrão do main (status 0 = OK)
}
