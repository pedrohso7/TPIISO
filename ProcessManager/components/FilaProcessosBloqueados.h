typedef struct elementoLista
{
    char *dado;
    struct elementoLista *seguinte;
} Elemento;

typedef struct ListaDetectada
{
    Elemento *inicio;
    Elemento *fim;
    int tamanho;
} Fila;

//inicializando a Fila
void inicializacao(Fila *sequencia);
//Inserindo na Fila
int inserir(Fila *sequencia, Elemento *atual, char *dado);
//Removendo na Fila
int remover(Fila *sequencia);
//Recuperação do dado no inicio da fila (FIFO)
#define fila_dado(sequencia) sequencia->início->dado
//imprime a fila
void exibir(Fila *sequencia);