#ifndef PROCESSLIST_H
#define PROCESSLIST_H

//Tipos de prioridade
enum ProcessState { Blocked, InExecution, Ready } State;

//Dados de um elemento
typedef struct
{
    int *pid;
    int *PC;
    int *EstructData;
    int priority;
    int state;
    int timeCPU;
} ProcessData;

//Elemento da lista
typedef struct ListElement
{
    ProcessData *data;
    struct ListElement *next;
} Element;

//Dados de controle da Lista. LISTA!!
typedef struct ListaDetectada
{
    Element *begin;
    Element *end;
    int length;
} List;

//Recuperação do dado no inicio da Lista
#define firstToLeft(sequence) sequence->begin->data


//Inicializando a Lista
void inicialize(List *sequence);
//Inserindo na Lista
int insertElement(List *sequence, Element *actual, ProcessData *data);
//Removendo na Lista
int removeElement(List *sequence);
//Imprime a Lista
void show(List *sequence);

#endif //PROCESSOSIMULADO_H