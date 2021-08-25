#include "ProcessSimulation.h"
#include <stdio.h>
#include <stdlib.h>

void MenuPS(){
    int opcao;
    int n;
    int *numberVar;
    printf("|-------------------------------------------------------------------|\n");
    printf("| 1.N: Numero de variaveis que serao declaradas nesse pS                  \n");
    printf("| 2.D: Declara variavel inteira x\n");
    printf("| 3.V: Define o valor da variavel x\n");
    printf("| 4.A: Adiciona n ao valor da variavel x\n");
    printf("| 5.S: Subtrai n ao valor da variavel x\n");
    printf("| 6.B: Bloqueia esse processo simulado\n");
    printf("| 7.T: Termina esse processo simulado.\n");
    printf("| 8.F: Cria um novo processo simulado.\n");
    printf("| 9.R \n");
    printf("|-------------------------------------------------------------------|\n");
    printf("Opcao: ");
    if(opcao == 1){
        scanf("%d", &n);
        numberVar = (int*)malloc(n* sizeof(int));
    }
    if(opcao == 2){
        int x = 0;
    }if(opcao == 3){
        
    }

}
