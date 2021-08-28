#include "ProcessSimulation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTAM 1000

void instructionsList(){
    
    printf("|-------------------------------------------------------------------|\n");
    printf(" N: Numero de variaveis que serao declaradas nesse pS.\n");
    printf(" D: Declara variavel inteira x.\n");
    printf(" V: Define o valor da variavel x.\n");
    printf(" A: Adiciona n ao valor da variavel x.\n");
    printf(" S: Subtrai n ao valor da variavel x.\n");
    printf(" B: Bloqueia esse processo simulado.\n");
    printf(" T: Termina esse processo simulado.\n");
    printf(" F: Cria um novo processo simulado.\n");
    printf(" R: Trocar o processo atual por um de outro arquivo.\n");
    printf("|------------------------------------------------------------------|\n");

}

void clearMemoryGarbage(char *array, int N){
    int i;

    for(i = 0;i < N; i++){
        array[i] = 0;
    }
}

void formatInstruction(char *instruction, char *instructionLetter, char *firstArgument, char *secondArgument){
    char *formatedInstruction;
    int iteraction = 0;

    //printf( " ORIGINAL: %s\n", instruction);
    clearMemoryGarbage(instructionLetter, MAXTAM);
    clearMemoryGarbage(firstArgument, MAXTAM);
    clearMemoryGarbage(secondArgument, MAXTAM);

    //Divide string por espaços
    formatedInstruction = strtok(instruction, " ");

    //Percorre substrings geradas pelo strtok
    while(formatedInstruction != NULL){
        int i;

        for(i=0;i<strlen(formatedInstruction);i++){
            if(iteraction == 0) instructionLetter[i] = formatedInstruction[i];
            if(iteraction == 1) firstArgument[i] = formatedInstruction[i];
            if(iteraction == 2) secondArgument[i] = formatedInstruction[i];    
        }
        formatedInstruction = strtok(NULL, " ");
        iteraction++;
    }   
    
}

void processMain(){
    char instructionLetter[MAXTAM];
    char firstArgument[MAXTAM];
    char secondArgument[MAXTAM];
    int n; //Número de variáveis
    int *d; //Sequência de memória a ser referenciad

    /* forces getline to allocate with malloc */
    char *instruction = NULL;//Vetor de leitura das instruções

    char *formatedInstruction;
    int i;

    /*
        Esse algoritmo de leitura da linha inteira do teclado é relatado em:
        https://stackoverflow.com/questions/7709452/how-to-read-string-from-keyboard-using-c/24177745
    */
    size_t len = 0;/* Ignorado quando a linha é NULL */
    ssize_t read;
    
    
    while(1){
        printf("Digite I para exibir as possiveis instrucoes...\n\n");
        printf("Digite F para finalizar a insercao dos dados do processo...\n\n");
        printf("Instrucao:");
        while ((read = getline(&instruction, &len, stdin)) != -1) {

            if (read > 0) {
                //printf ("\n  PEGUEI : %s\n" , instruction);
                break;
            }else{
                printf ("\n Nao foi encontrada nenhuma instrucao\n");
            }
        }
        formatInstruction(instruction, instructionLetter, firstArgument, secondArgument);

        switch (instructionLetter[0]){//Trata a instrução recebida
            case 'N':
                /* N n: Número de variáveis que serão declaradas neste processo simulado */
                break;
            case 'D':
                /* D x: Simulação a posição na memória de uma das variáveis "prometidas" */
                break;
            case 'V':
                /* V x n: Define o valor da variável inteira x para n, onde n é um inteiro */
                break;
            case 'A':
                /* A x n: Adiciona n ao valor da variável inteira x, onde n é um inteiro */
                break;
            case 'S':
                /* S x n: Subtrai n do valor da variável inteira x, onde n é um inteiro */
                break;
            case 'F':
                /* F n: Cria um novo processo simulad */
                break;
            case 'R':
                /*R nome_do_arquivo: Substitui o programa do processo simulado pelo programa no arquivo nome_do_arquivo 
                e define o contador de programa para a primeira instrução desse novo programa*/
                break;
            case 'B':
                /* Bloqueia o processo simulado */
                break;
            case 'T':
                /* Termina o processo simulado */
                break;
            
            case 'I':
                /* Imprime as opções de instrução */
                instructionsList();
                break;
            default:
                printf("\nESSE COMANDO NÃO EXISTE!!!!!!\n");
                break;
        }
    }
}
