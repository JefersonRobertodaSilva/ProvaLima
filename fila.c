#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// Cria fila vazia
void criarFila(Fila **fila) {
    *fila = (Fila *) malloc(sizeof(Fila));
    (*fila)->inicio = NULL;
    (*fila)->fim = NULL;
    (*fila)->tamanho = 0;
    printf("Fila criada!\n");
}

// Insere elemento no final da fila	
void inserirElementoFila(Fila *fila, int valor) {
    NoFila *novo = (NoFila *) malloc(sizeof(NoFila));
    novo->infor = valor;
    novo->prox = NULL;

    if (fila->inicio == NULL) { 
        // fila vazia
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->prox = novo;
        fila->fim = novo;
    }
    fila->tamanho++;
}

// Exclui elemento da fila 
void excluirElementoFila(Fila *fila) {
    if (fila->inicio == NULL) {
        printf("Fila vazia! Nada para remover.\n");
        return;
    }

    NoFila *temp = fila->inicio;
    fila->inicio = temp->prox;

    // se a fila ficou vazia, zera também o fim
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    printf("Valor %d removido da fila.\n", temp->infor);
    free(temp);
    fila->tamanho--;
}
// Imprime todos os elementos da fila
void imprimirFila(Fila *fila) {
    NoFila *aux = fila->inicio;
    printf("Fila: ");
    while (aux != NULL) {
        printf("%d ", aux->infor);
        aux = aux->prox;
    }
    printf("\n");
}

// Procura elemento na fila
void procurarElementoFila(Fila *fila, int valor) {
    NoFila *aux = fila->inicio;
    int pos = 0;
    while (aux != NULL) {
        if (aux->infor == valor) {
            printf("Valor %d encontrado na posicao %d da fila.\n", valor, pos);
            return;
        }
        aux = aux->prox;
        pos++;
    }
    printf("Valor %d nao encontrado na fila.\n", valor);
}


