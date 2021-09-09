typedef struct
{
    int state;
    
}

typedef struct ListElement
{
    char *data;
    struct ListElement *next;
} Element;

typedef struct ListaDetectada
{
    Element *begin;
    Element *end;
    int length;
} Queue;

//Recuperação do dado no inicio da fila (FIFO)
#define fila_dado(sequence) sequence->begin->data


//Inicializando a Fila
void inicialize(Queue *sequence);
//Inserindo na Fila
int insert(Queue *sequence, Element *actual, char *data);
//Removendo na Fila
int remove(Fila *sequence);
//Imprime a fila
void show(Fila *sequence);