typedef struct
{
    int *pid;
    int *PC;
    int *EstructData;
    int priority;
    int state;
    int timeCPU;
} ProcessData;

typedef struct ListElement
{
    ProcessData *data;
    struct ListElement *next;
} Element;

typedef struct ListaDetectada
{
    Element *begin;
    Element *end;
    int length;
} ProcessTable;

//Recuperação do dado no inicio da fila (FIFO)
#define firstElement(sequence) sequence->begin->data


//Inicializando a Fila
void inicialize(Queue *sequence);
//Inserindo na Fila
int insert(Queue *sequence, Element *actual, char *data);
//Removendo na Fila
int remove(Fila *sequence);
//Imprime a fila
void show(Fila *sequence);