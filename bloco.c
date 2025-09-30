#include <stdio.h>
#include <stdlib.h>
#include "bloco.h"

void criarLista(Bloco** inicio) {  // precisa ser 2 '*' pois se nao ele nao consegue mudar o ponteiro 'inicio'0
    if (inicio == NULL) return;  //caso o inicio ja seja null, a lista ja foi criada
    *inicio = NULL;
	printf("lista criada!\n");			//criar lista exclui toda a cadeia(caso exista uma) mas nao desaloca a memoria delas
}

void inserirElemento(Bloco** inicio, int valor) { 
    Bloco* novo = (Bloco*)malloc(sizeof(Bloco)); //aloca uma memoria do tamanho de bloco e retorna como um ponteiro de bloco (Bloco*)
    novo->valor = valor;
    novo->prox = *inicio;  //caso a lista seja vazia, nao tera problemas, pois novo->prox apontara para NULL
    *inicio = novo;   // 'puxa' o inicio para o bloco recem criado
}

void excluirElemento(Bloco** inicio, int valor){
	Bloco* atual = *inicio;
	Bloco* anterior = NULL;
	
	while(atual!=NULL){
		
		if(atual->valor==valor){
			
			if(anterior==NULL){  //anterior sendo NULL quer dizer que estamos excluindo o inicio
				*inicio=atual->prox;
			}
			else{    //esse trata o restante das situacoes(meio)
				anterior->prox=atual->prox;  // 'pula' o bloco atual usando o anterior
			}
			
			free(atual);   //desaloca o bloco atual
			return;  //sai da funcao pois encontramos o elemento que queremos excluir e ja tratamos ele
		}
		
		anterior=atual;    //importante ser nessa ordem para que consiga guardar o anterior corretamente
		atual=atual->prox;
	}
}
	


void imprimirLista(Bloco* inicio) {
    Bloco* atual = inicio;
    
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

void procurarElemento(Bloco** inicio, int valor){
	Bloco* atual= *inicio;
	
	while(atual!=NULL){
		
		if(atual->valor==valor){
			printf("elemento encontrado!\n");
			return;
		}
		atual=atual->prox;
	}
	printf("elemento nao encontrado :(\n");  //sair do laco por ter encontrado atual==NULL, significa que nao tinha o valor desejado
	return;
}


void numeroDeElementos(Bloco* inicio) {
    int contador = 0;
    Bloco* atual = inicio;
    
    while (atual != NULL) {
        contador++;   	//importante nao inverter a ordem aqui, pois se nao seria contado um caso que nao foi testado se era igual a NULL
        atual = atual->prox;
    }
    printf("Numero de elementos: %d\n", contador);
}
