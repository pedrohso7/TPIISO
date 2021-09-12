#ifndef PROCESSLIST_H
#define PROCESSLIST_H

//Tipos de prioridade
enum ProcessState { Blocked, InExecution, Ready } State;

//Dados de um elemento
typedef struct {
    int *pid;
    int *PC;
    int *EstructData;
    int *priority;
    /*
      Valores possíveis para a variável state:
        0: bloqueado,
        1: pronto,
        2: em execução.
    */
    int *state;
    int *timeCPU;
} ProcessData;

//Elemento da lista
typedef struct ListElement{
    ProcessData *data;
    struct ListElement *next;
} Element;

//Dados de controle da Lista. LISTA!!
typedef struct ListaDetectada{
    Element *begin;
    Element *end;
    int length;
} List;

//Recuperação do dado no inicio da Lista
#define firstElement(sequence) sequence->begin->data

//Recuperação do dado no fim da Lista
#define lastElement(sequence) sequence->end->data

//Inicializando a Lista
void inicialize(List *sequence);
//Inserindo na Lista
int insertElement(List *sequence, Element *actual, ProcessData *data);
//Removendo na Lista
int removeElement(List *sequence);
//Imprime a Lista
void show(List *sequence);

#endif //PROCESSOSIMULADO_H