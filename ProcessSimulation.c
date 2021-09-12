#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#include "ProcessSimulation.h"

#define MAXTAM 1000


// void instructionsList(){ 
//     printf("|-------------------------------------------------------------------|\n");
//     printf(" N: Numero de variaveis que serao declaradas nesse pS.\n");
//     printf(" D: Declara variavel inteira x.\n");
//     printf(" V: Define o valor da variavel x.\n");
//     printf(" A: Adiciona n ao valor da variavel x.\n");
//     printf(" S: Subtrai n ao valor da variavel x.\n");
//     printf(" B: Bloqueia esse processo simulado.\n");
//     printf(" T: Termina esse processo simulado.\n");
//     printf(" F: Cria um novo processo simulado.\n");
//     printf(" R: Trocar o processo atual por um de outro arquivo.\n");
//     printf("|------------------------------------------------------------------|\n");
// }

// void clearMemoryGarbage(char *array, int N){
//     int i;

//     for(i = 0;i < N; i++) array[i] = 0;
// }

void impressProcessMemory(char **instructions, int N){
    int i, j;

    //printf("%ld", strlen(instructions));
    //printf("%ld", strlen(instructions[0]));
    for(i=0; i<N; i++)
        printf(" %s\n", instructions[i]);
    

}

char** getInstructionsFromFile(int *instructionNum, char* fileName){
    /* forces getline to allocate with malloc */
    char **instructions = NULL;

    FILE* fp;//File Pointer para ler instruções do processo a partir do arquivo
    char c;//Auxilia na leitura do arquivo
    char buffer[MAXTAM];
    char length = 0;//Tamanho da linha de instrução

    int index = 0;//índice da linha da matriz de instrução
    int i;//usado em loop
    int offset;


    size_t len = 0;/* Ignorado quando a linha é NULL */
    ssize_t read;

    fp = fopen(fileName, "r");
    if (fp == NULL){
        perror("ERRO AO ABRIR ARQUIVO.\n");
        exit(EXIT_FAILURE);
    }

    //Conta número de instruções
    while((c = fgetc(fp)) != EOF) 
        if(c == '\n') 
            index++;

    //printf("%d", index);

    //Aloca linhas
    instructions = (char **)malloc( index * sizeof(char*) );
    if(instructions == NULL) {
        printf("Memoria insuficiente!\n");
        free(instructions[(*instructionNum)]);
        exit(EXIT_FAILURE);
    }
    
    rewind(fp);

    index = 0;
    while((c = fgetc(fp)) != EOF){
        
        if(c == '\n') {
            //Aloca coluna
            instructions[*instructionNum] = NULL;
            instructions[*instructionNum] = (char *)malloc( length * sizeof(char) );
            if(instructions[*instructionNum] == NULL) {
                printf("Memoria insuficiente!\n");
                free(instructions[(*instructionNum)]);
                exit(EXIT_FAILURE);
            }

            //Passa a instrução do buffer para o vetor de programa
            for(i = 0;i < length; i++) 
                instructions[*instructionNum][i] = buffer[i];
            //printf("%s\n", instructions[*instructionNum]);
            (*instructionNum)++;
            length = 0;
        }
        else {
            buffer[length] = c;
            length++;
        }
    }

    return instructions;

   fclose(fp);
}

void getInstructionsFromKeyboard(char **instructions, int *instructionNum){
    /* forces getline to allocate with malloc */
    char *instruction = NULL;//Vetor de leitura das instruções
    
    int index = 0;

    size_t len = 0;/* Ignorado quando a linha é NULL */
    ssize_t read;


    while(1){
        printf("Digite I para exibir as possiveis instrucoes...\n\n");
        printf("Digite F para finalizar a insercao dos dados do processo...\n\n");
        printf("Instrucao: ");
        /*
            Esse algoritmo de leitura da linha inteira do teclado é relatado em:
            https://stackoverflow.com/questions/7709452/how-to-read-string-from-keyboard-using-c/24177745
        */
        while ((read = getline(&instruction, &len, stdin)) != -1) {
            if (read > 0) {
                instructions[index] = (char*)malloc( strlen(instruction) * sizeof(char*) );
                instructions[index] = instruction;
                index++;
                *instructionNum++;
                break;
            }else{
                printf ("\n Nao foi encontrada nenhuma instrucao\n");
            }
        }
    }
}

void formatInstruction(char *instruction, char *instructionLetter, char *firstArgument, char *secondArgument){
    char *formatedInstruction;
    int iteraction = 0;

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

void runInstructionPS(char *instruction, int *n, int *d, char *mem){
    char instructionLetter[MAXTAM];
    char firstArgument[MAXTAM];
    char secondArgument[MAXTAM]; //se tiver

    pid_t pid;

    int i;

    formatInstruction(instruction, instructionLetter, firstArgument, secondArgument);

    switch (instructionLetter[0]){//Trata a instrução recebida
        case 'N': //Número de va
            /*N n: número de variáveis que serão declaradas neste processo simulado*/
            *n = atoi(firstArgument);
            break;
        case 'D':
            /*D x: Índices das variáveis*/
            d = (int*)malloc( *n * sizeof(int*) );
            for(i = 0; i < *n ; i++) d[i] = i; // preenche índices
            break;
        case 'V':
            /* V x n: Define o valor da variável inteira x para n, onde n é um inteiro */
            mem[atoi(firstArgument)] = atoi(secondArgument);
            break;
        case 'A':
            /* A x n: Adiciona n ao valor da variável inteira x, onde n é um inteiro */
            mem[atoi(firstArgument)] = mem[atoi(firstArgument)] + atoi(secondArgument);
            break;
        case 'S':
            /* S x n: Subtrai n do valor da variável inteira x, onde n é um inteiro */
            mem[atoi(firstArgument)] = mem[atoi(secondArgument)] - atoi(firstArgument);
            break;
        case 'F':
            /* F n: Cria um novo processo simulad */
            pid = fork();
            if(pid < 0){//Verifica se o processo foi instanciado corretamente (retorna -1 se deu erro)
                printf("ERRO AO CRIAR O PROCESSO!!");
                exit(EXIT_SUCCESS);
            }
            if(pid > 0){// Código do processo pai
                
            } else if (pid == 0){ // Código do processo filho
                
            }
            break;
        case 'R':
            /*R nome_do_arquivo: Substitui o programa do processo simulado pelo programa no arquivo nome_do_arquivo 
            e define o contador de programa para a primeira instrução desse novo programa*/
            // char *argsExecv[]={firstArgument, NULL};
            // execv(argsExecv[0], argsExecv);
            break;
        case 'B':
            /* Bloqueia o processo simulado */
            //??
            break;
        case 'T':
            /* Termina o processo simulado */
            return;//pthread_exit(void *pid);
            break;
        
        case 'I':
            /* Imprime as opções de instrução */
            //instructionsList();
            break;
        default:
            printf("\nESSE COMANDO NÃO EXISTE!!!!!!\n");
            break;
    }
}



void processMain(char *fileName, List *processTable){
    
    int n; //Número de variáveis
    int *d; //Sequência de memória a ser referenciad
    char **instructions = NULL;
    
    int PC = 0;
    int timeSlice;

    int instructionNum = 0;
    
    instructions = getInstructionsFromFile(&instructionNum, fileName);
    int isFirstTime = 1;
    while(1){
        if(isFirstTime == 1){
            impressProcessMemory(instructions, instructionNum);   
            isFirstTime = 0;
        }
    }
    
}
