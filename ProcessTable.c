#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "FilaProcessosBloqueados.h"

//Criando a lista
void inicialize(ProcessTable *sequence)
{
    sequence->begin = NULL;
    sequence->end = NULL;
    sequence->length = 0;
}

//Insere adiciona um elemento na lista
int insert(ProcessTable *sequence, Element *actual, ProcessData *data)
{
    Element *new_element;
    if ((new_element = (Element *)malloc(sizeof(Element))) == NULL)
        return -1;

    if ((new_element->data = (ProcessData *)malloc(sizeof(ProcessData))) == NULL)
        return -1;

    strcpy(new_element->data, data);
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
int remove(ProcessTable *sequence)
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
void show(ProcessTable *sequence)
{
    Element *actual;
    int i;
    actual = sequence->begin;
    for (i = 0; i < sequence->length; ++i)
    {
        //printf(" %s ", actual->data);
        actual = actual->next;
    }
}