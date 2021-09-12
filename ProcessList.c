#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ProcessList.h"

//Criando a lista
void inicialize(List *sequence)
{
    sequence->begin = NULL;
    sequence->end = NULL;
    sequence->length = 0;
}

//Insere adiciona um elemento na lista
int insertElement(List *sequence, Element *actual, ProcessData *data)
{
    Element *new_element;
    if ((new_element = (Element *)malloc(sizeof(Element))) == NULL)
        return -1;

    if ((new_element->data = (ProcessData *)malloc(sizeof(ProcessData))) == NULL)
        return -1;

    new_element->data = data;
    if (actual == NULL)
    {
        if (sequence->length == 0)
            sequence->end = new_element;
        new_element->next = sequence->begin;
        sequence->begin = new_element;
    }
    else
    {
        if (actual->next == NULL)
            sequence->end = new_element;
        new_element->next = actual->next;
        actual->next = new_element;
    }
    sequence->length++;
    return 0;
}

//Remove um Elemento da lista 
int removeElement(List *sequence)
{
    Element *remove_element;
    if (sequence->length == 0)
        return -1;
    remove_element = sequence->begin;
    sequence->begin = sequence->begin->next;
    free(remove_element->data);
    free(remove_element);
    sequence->length--;
    return 0;
}

//Imprime a lista 
void show(List *sequence)
{
    Element *actual;
    int i;
    char state[15];

    
    printf("\n %d\n", sequence->length);
    // actual = sequence->begin;
    // if(sequence->length == 0){
    //     printf("Lista Vazia!\n");
    // } else {
    //     printf("step 1");
    //     for (i = 0; i < sequence->length; ++i){
    //         printf("step 2");
    //         //Torna a variável estado mais visual
    //         switch(*(actual->data->state)){
    //             case 0:
    //                 strcpy(state, "bloqueado");
    //                 break;
    //             case 1:
    //                 strcpy(state, "pronto");
    //                 break;
    //             case 2:
    //                 strcpy(state, "em execucao");
    //                 break;
    //         }
    //         printf("step 3");
    //         printf("%d -> PID: %d | PC: %d | ESTADO: %s | PRIORIDADE: \n", i, *(actual->data->pid), *(actual->data->PC), state);
    //         actual = actual->next;
    //     }
    // }
}