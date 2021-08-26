#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "FilaProcessosBloqueados.h"

//Criando a lista
void inicializacao(Fila *sequencia)
{
    sequencia->inicio = NULL;
    sequencia->fim = NULL;
    sequencia->tamanho = 0;
}

//Insere adiciona um elemento na lista
int inserir(Fila *sequencia, Elemento *atual, char *dado)
{
    Elemento *novo_elemento;
    if ((novo_elemento = (Elemento *)malloc(sizeof(Elemento))) == NULL)
        return -1;

    if ((novo_elemento->dado = (char *)malloc(50 * sizeof(char))) == NULL)
        return -1;

    strcpy(novo_elemento->dado, dado);
    if (atual == NULL)
    {
        if (sequencia->tamanho == 0)
            sequencia->fim = novo_elemento;
        novo_elemento->seguinte = sequencia->inicio;
        sequencia->inicio = novo_elemento;
    }
    else
    {
        if (atual->seguinte == NULL)
            sequencia->fim = novo_elemento;
        novo_elemento->seguinte = atual->seguinte;
        atual->seguinte = novo_elemento;
    }
    sequencia->tamanho++;
    return 0;
}

//Remove um elemento da lista 
int remover(Fila *sequencia)
{
    Elemento *remov_Elemento;
    if (sequencia->tamanho == 0)
        return -1;
    remov_Elemento = sequencia->inicio;
    sequencia->inicio = sequencia->inicio->seguinte;
    free(remov_Elemento->dado);
    free(remov_Elemento);
    sequencia->tamanho--;
    return 0;
}

//Imprime a lista 
void exibir(Fila *sequencia)
{
    Elemento *atual;
    int i;
    atual = sequencia->inicio;
    for (i = 0; i < sequencia->tamanho; ++i)
    {
        printf(" %s ", atual->dado);
        atual = atual->seguinte;
    }
}