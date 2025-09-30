#include <stdio.h>
#include <stdlib.h>

typedef struct Reg{
	int infor;
	Reg *prox;
}No;

typedef struct TipoPilha{ 
	No *topo;
	int tamanho;	
}Pilha;

void criarPilha(Pilha **p);

void inserirElementoPilha(Pilha *p, int valor);
void excluirElementoPilha(Pilha *p);
void imprimirPilha(Pilha *p);
void procurarElementoPilha(Pilha *p, int valor);

	
