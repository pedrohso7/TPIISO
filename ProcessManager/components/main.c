#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaProcessosBloqueados.h"

int main()
{
    Fila *sequencia;
    
    if ((sequencia = (Fila *)malloc(sizeof(Fila))) == NULL)
        return -1;
        
    inicialize(sequencia);
    printf("Inserir uma palavra:");
    scanf("%s", nome);
    insert(sequencia, sequencia->fim, nome);
    printf("A F (%de elementos)\n", sequencia->tamanho);
    printf("\nInício de la F [ ");
    show(sequencia);

    /*primeiro elemento inserido será exibido */
    printf(" ] fim de la F\n\n");
    printf("Inserir uma palavra:");
    scanf("%s", nome);
    inserir(sequencia, sequencia->fim, nome);
    printf("A F (%de elementos)\n", sequencia->tamanho);
    printf("\nInício da F [ ");
    exibir(sequencia);

    /*primeiro elemento inserido será exibido */
    printf(" ] fim da F\n\n");
    printf("Inserir uma palavra:");
    scanf("%s", nome);
    inserir(sequencia, sequencia->fim, nome);
    printf("A F (%de elementos)\n", sequencia->tamanho);
    printf("\nInício de la F [ ");
    exibir(sequencia);

    /*primeiro elemento inserido será exibido */
    printf(" ] fim da F\n\n");
    //printf("\nO primeiro elemento inserido (FirstInFirstOut) [ %s ] será removido", fila_dado(sequencia));
    printf("\nO primeiro elemento inserido é removido\n");
    remover(sequencia);

    /*remoção do primeiro elemento inserido*/
    printf("A F (%d elementos): \n", sequencia->tamanho);
    printf("\nInício da F [ ");
    exibir(sequencia);
    printf(" ] fim da F\n\n");
    return 0;
}
