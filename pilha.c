#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"


// Cria pilha vazia
void criarPilha(Pilha **p) {
    *p = (Pilha *) malloc(sizeof(Pilha));
    (*p)->topo = NULL;
    (*p)->tamanho = 0;
    printf("Pilha criada!\n");
}

// Insere elemento no topo (push)
void inserirElementoPilha(Pilha *p, int valor) {
    No *novo = (No *) malloc(sizeof(No));
    novo->infor = valor;
    novo->prox = p->topo;  // novo nó aponta para o antigo topo
    p->topo = novo;        // topo da pilha agora é o novo nó
    p->tamanho++;
}

void excluirElementoPilha(Pilha *p) {
    if (p->topo == NULL) {
        printf("Pilha vazia! Nada para remover.\n");
        return;
    }

    No *temp = p->topo;
    p->topo = temp->prox;  // topo passa a ser o próximo
    printf("Valor %d removido da pilha.\n", temp->infor);
    free(temp);
    p->tamanho--;
}

// Imprime todos os elementos
void imprimirPilha(Pilha *p) {
    No *aux = p->topo;
    printf("Pilha: ");
    while (aux != NULL) {
        printf("%d ", aux->infor);
        aux = aux->prox;	
    }
    printf("\n");
}

void procurarElementoPilha(Pilha *p, int valor) {
    No *aux = p->topo;
    int pos = 0;
    while (aux != NULL) {
        if (aux->infor == valor) {
            printf("Valor %d encontrado na posicao %d da pilha.\n", valor, pos);
            return;
        }
        aux = aux->prox;
        pos++;
    }
    printf("Valor %d nao encontrado na pilha.\n", valor);
}


