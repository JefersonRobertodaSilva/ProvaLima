#include <stdio.h>
#include <stdlib.h>
#include "listaDupla.h"

void criarListaDupla(listaDupla **ld) {
    *ld = NULL;  
    printf("Lista dupla criada!\n");
}

void inserirElementoListaDupla(listaDupla **inicio, int valor, int pos) {
    listaDupla *novo = (listaDupla*) malloc(sizeof(listaDupla));
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = NULL;

    if (*inicio == NULL || pos <= 1) {
        // inserir no início
        novo->prox = *inicio;
        if (*inicio != NULL)
            (*inicio)->ant = novo;
        *inicio = novo;
        return;
    }

    // percorrer até a posição desejada
    listaDupla *aux = *inicio;
    int i = 1;
     
    while (aux->prox != NULL && i < pos-1) {
        aux = aux->prox;
        i++;
    }
    
    // se a posição e maior que o tamanho da lista + 1
    if (i < pos-1) {
        printf("Posicao %d maior que o tamanho da lista. Inserindo no final.\n", pos);
    }

    // inserir depois de aux
    novo->prox = aux->prox;
    novo->ant = aux;
    if (aux->prox != NULL)
        aux->prox->ant = novo;
    aux->prox = novo;
}

void excluirElementoListaDupla(listaDupla **inicio, int valor) {
    if (*inicio == NULL) return;

    listaDupla *aux = *inicio;

    // se for o primeiro no
    if (aux->valor == valor) {
        *inicio = aux->prox;
        if (*inicio != NULL)
            (*inicio)->ant = NULL;
        free(aux);
        printf("Elemento %d excluido\n", valor);
        return;
    }

    while (aux != NULL && aux->valor != valor) {
        aux = aux->prox;
    }

    if (aux == NULL) {
        printf("Elemento %d nao encontrado\n", valor);
        return;
    }

    // ajustar ponteiros
    if (aux->ant != NULL)
        aux->ant->prox = aux->prox;
    if (aux->prox != NULL)
        aux->prox->ant = aux->ant;

    free(aux);
    printf("Elemento %d excluido\n", valor);
}

void imprimirRecursivoListaDupla(listaDupla *inicio) {
    if (inicio == NULL) {
        return; // caso base: lista acabou
    }
    printf("%d ", inicio->valor); // imprime o valor atual
    imprimirRecursivoListaDupla(inicio->prox);  // chama de novo pro próximo
}

void buscarElementoListaDupla(listaDupla *inicio, int valor) {
    listaDupla *aux = inicio;
    while (aux != NULL) {
        if (aux->valor == valor) {
            printf("Elemento %d encontrado\n", valor);
            return;
        }
        aux = aux->prox;
    }
    printf("Elemento %d nao encontrado\n", valor);
}

//2 questao da lista dupla
// Inserir no início da lista dupla sem duplicados

	void inserirInicioLD(listaDupla **inicio, int valor) {
    // Verifica se o valor já existe
    	listaDupla *aux = *inicio;
    	while (aux != NULL) {
       		if (aux->valor == valor) {
            	printf("Elemento %d ja existe na lista. Nao sera inserido.\n", valor);
            	return; // sai sem inserir
        	}
        	aux = aux->prox;
    	}

	    // Cria o novo nó
	    listaDupla *novo = (listaDupla*) malloc(sizeof(listaDupla));
	    if (!novo) {
	        printf("Erro ao alocar memoria.\n");
	        return;
	    }
	    novo->valor = valor;
	    novo->prox = *inicio;
	    novo->ant = NULL;
	
	    // Ajusta ponteiro do antigo primeiro nó, se existir
	    if (*inicio != NULL) {
	        (*inicio)->ant = novo;
	    }
	
	    // Atualiza o início da lista
	    *inicio = novo;
	
	    printf("Elemento %d inserido no inicio da lista.\n", valor);
	}



	// Inserir elemento no final da lista dupla circular
	void inserirElementoCircular(listaDupla **lp, int valor) {
    	listaDupla *novo = (listaDupla*) malloc(sizeof(listaDupla));
    	if (!novo) {
        	printf("Erro ao alocar memória.\n");
        	return;
    	}
   		novo->valor = valor;

	    if (*lp == NULL) {
	        // Lista vazia: novo nó aponta para si mesmo
	        novo->prox = novo;
	        novo->ant = novo;
	        *lp = novo;
	    } else {
	        // Inserir no final, antes do primeiro
	        listaDupla *ultimo = (*lp)->ant;
	        novo->prox = *lp;
	        novo->ant = ultimo;
	        ultimo->prox = novo;
	        (*lp)->ant = novo;
	    }
	
	    printf("Elemento %d inserido.\n", valor);
	}
	
	// Excluir elemento da lista dupla circular
	void excluirElementoCircular(listaDupla **lp, int valor) {
	    if (*lp == NULL) {
	        printf("Lista vazia.\n");
	        return;
	    }
	
	    listaDupla *aux = *lp;
	    listaDupla *inicio = *lp;
	    int achou = 0;
	
	    do {
	        if (aux->valor == valor) {
	            achou = 1;
	            break;
	        }
	        aux = aux->prox;
	    } while (aux != inicio);
	
	    if (!achou) {
	        printf("Elemento %d nao encontrado.\n", valor);
	        return;
	    }
	
	    if (aux->prox == aux) {
	        // Único elemento
	        *lp = NULL;
	    } else {
	        // Ajusta ponteiros dos vizinhos
	        aux->ant->prox = aux->prox;
	        aux->prox->ant = aux->ant;
	        if (*lp == aux)
	            *lp = aux->prox; // Atualiza início se necessário
	    }
	
	    free(aux);
	    printf("Elemento %d excluido.\n", valor);
	}
	
	// Imprimir elementos da lista circular
	void imprimirCircular(listaDupla *lp) {
	    if (lp == NULL) {
	        printf("Lista vazia.\n");
	        return;
	    }
	
	    listaDupla *aux = lp;
	    do {
	        printf("%d ", aux->valor);
	        aux = aux->prox;
	    } while (aux != lp);
	    printf("\n");
	}


