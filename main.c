#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>

int main (int *argc, char* argv){
   
    
    bool op1 = true, op2 = true, op3 = true;
    int opcao1, opcao2;

    printf("\n");
    printf("|-------------------------------------------------------------------|\n");
    printf("|     - Trabalho Pratico 2 - Sistemas Operacionais                  |\n");
    printf("|     - Gabriel Miranda - EF03857                                   |\n");
    printf("|     - Felipe Stenner - EF03888                                    |\n");
    printf("|     - Mariana Souza - EF03898                                     |\n");
    printf("|     - Pedro Oliveira - EF02677                                    |\n");
    printf("|-------------------------------------------------------------------|\n");

    while(op1 ==  true){
        printf("\n");
        printf("|-------------------------------------------------------------------|\n");
        printf("| 1. Leitura de dados a partir de um arquivo.                       |\n");
        printf("| 2. Leitura de dados a partir do teclado.                          |\n");
        printf("| 3. Encerrar programa.                                             |\n");
        printf("|-------------------------------------------------------------------|\n");
        printf("Opcao: ");
        scanf("%d", &opcao1);
        if(opcao1 == 1){
            //code
        }
        if(opcao1 == 2){
            while (op2 == true){
                printf("\n");
                printf("|-------------------------------------------------------------------|\n");
                printf("| 1. U: Fim de uma unidade de tempo.                                |\n");
                printf("| 2. L: Desbloqueia o primeiro processo simulado na fila bloqueada  |\n");
                printf("| 3. I: Imprimer o estado atual do sistema.                         |\n");
                printf("| 4. M: Imprime o tempo medio do ciclo e finaliza o sistema.        |\n");
                printf("|-------------------------------------------------------------------|\n");
                printf("Opcao: ");
                scanf("%d", &opcao2);
                while(op3 == true){
                    if(opcao2 == 1) {
                        /* code */
                    }
                    if(opcao2 == 2){
                        //code
                    }
                    if(opcao2 == 3){
                        //code
                    }
                    if(opcao2 == 4){
                        //code
                    }else{
                        printf("Opcao Invalida...Digite novamente.\n");

                    }
                }
                
            }
        }
        if(opcao1 == 3){
            op1 = false;
        }
        else{
            printf("\nOpcao Invalida...Digite novamente.\n");
        }
    }
    return 0;
}

#define TAM 30
void mano(){
    int fd[2]; //Descritores de arquivos para o pipe, posições: 0 leitura - 1 escrita
    pid_t pid; // variável para o fork

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