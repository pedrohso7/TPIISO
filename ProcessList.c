#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ProcessList.h"

//Criando a lista
void inicialize(List* sequence){
    sequence->begin = NULL;
    sequence->end = NULL;
    sequence->length = 0;
}

//Insere adiciona um elemento na lista
void insertElement(List *sequence, Element *actual, Element *new_element/*, ProcessData *data*/){
    //Element *new_element;
    
    if (actual == NULL){
        if (sequence->length == 0)
            sequence->end = new_element;
        new_element->next = sequence->begin;
        sequence->begin = new_element;
    }else {
        if (actual->next == NULL)
            sequence->end = new_element;
        new_element->next = actual->next;
        actual->next = new_element;
    }
    sequence->length++;
    //return 0;
}

//Remove um Elemento da lista 
int removeElement(List *sequence){
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
void show(List *sequence){
    Element *actual;
    int i;
    char state[15];

    
    // printf("\n %d\n", *(sequence->length));
    actual = sequence->begin;

    if(sequence->length == 0){
        printf("Lista Vazia!\n");
    } else {
        for (i = 0; i < sequence->length; ++i){
            //Torna a variável estado mais visual
            switch(*(actual->data->state)){
                case 0:
                    strcpy(state, "bloqueado");
                    break;
                case 1:
                    strcpy(state, "pronto");
                    break;
                case 2:
                    strcpy(state, "em execucao");
                    break;
            }
            printf("%d -> PID: %d | PC: %d | ESTADO: %d | PRIORIDADE: %d\n", i, *(actual->data->pid), *(actual->data->pc), *(actual->data->state), *(actual->data->priority));
            actual = actual->next;
        }
        printf("FIM!");

    }
}