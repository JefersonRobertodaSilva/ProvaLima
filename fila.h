#include <stdio.h>
#include <stdlib.h>

//prefirimos criar outra struct semelhante, para facilitar a implementecao
typedef struct RegFila {
    int infor;
    struct RegFila *prox;
} NoFila;

typedef struct TipoFila {
    NoFila *inicio;
    NoFila *fim;
    int tamanho;
} Fila;

void criarFila(Fila **fila);

void inserirElementoFila(Fila *inicio, int valor);
void excluirElementoFila(Fila *inicio);
void imprimirFila(Fila *inicio);
void procurarElementoFila(Fila *inicio, int valor);
