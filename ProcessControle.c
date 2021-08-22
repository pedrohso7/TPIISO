#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>

#define TAM 30


void interacaoUsuarioTeclado() {
    int opcao; // Opções de comando

    while (1){
        printf("\n");
        printf("|-------------------------------------------------------------------|\n");
        printf("| 1. U: Fim de uma unidade de tempo.                                |\n");
        printf("| 2. L: Desbloqueia o primeiro processo simulado na fila bloqueada  |\n");
        printf("| 3. I: Imprimer o estado atual do sistema.                         |\n");
        printf("| 4. M: Imprime o tempo medio do ciclo e finaliza o sistema.        |\n");
        printf("|-------------------------------------------------------------------|\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao){
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


int main (int *argc, char* argv){
    bool tipoLeitura;
    int opcao;

    printf("\n");
    printf("|-------------------------------------------------------------------|\n");
    printf("|     - Trabalho Pratico 2 - Sistemas Operacionais                  |\n");
    printf("|     - Felipe Stenner - EF03888                                    |\n");
    printf("|     - Mariana Souza - EF03898                                     |\n");
    printf("|     - Pedro Oliveira - EF02677                                    |\n");
    printf("|-------------------------------------------------------------------|\n");

    while(1){
        printf("\n");
        printf("|-------------------------------------------------------------------|\n");
        printf("| 1. Leitura de dados a partir de um arquivo.                       |\n");
        printf("| 2. Leitura de dados a partir do teclado.                          |\n");
        printf("| 3. Encerrar programa.                                             |\n");
        printf("|-------------------------------------------------------------------|\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                //interacaoUsuarioArquivo();
                break;
            case 2:
                interacaoUsuarioTeclado();
                break;
            case 3:
                exit(EXIT_SUCCESS);
            default:
                printf("Opcao Invalida...Digite novamente.\n");
                break;

        }
    }   
    
    return 0; // Retorno padrão do main (status 0 = OK)
}


int mano(pid_t pid, int *fd){
    if(pipe(fd) == -1){
        printf("Error pipe\n");
        return 1;
    }
    if((pid = fork() == -1)){
        printf("Error fork\n");
    }
    if(pid > 0){
        char input[TAM] = "testando os testes";
        close(fd[0]);
            
            /*
            pegar dados do teclado do arquivo
            */
        write(fd[1], input, sizeof(input) + 1);
        close(fd[1]);
        //É só isso por parte do pai, a execução encerra aqui ou tem que colocar um sleep()/wait()
        return 1;
    }else{
        char InputComands[TAM];
        close(fd[1]);

        read(fd[0], InputComands, sizeof(InputComands));
        close(fd[0]);
        printf("Resultado: %s\n", InputComands);
        //Parte do gerenciador de processos
    }
}