#include <stdio.h>
#include <stdlib.h>

typedef struct listaDupla {
    int valor;
    struct listaDupla *prox;
    struct listaDupla *ant;
} listaDupla;

void criarListaDupla(listaDupla **ld);
 
void inserirElementoListaDupla(listaDupla **ld, int valor, int pos);

void excluirElementoListaDupla(listaDupla **ld, int valor);

void imprimirRecursivoListaDupla(listaDupla *ld);

void buscarElementoListaDupla(listaDupla *ld, int valor);

//questao 2 da lista dupla
void inserirInicioLD(listaDupla **ld, int valor);


//questao 3 da lista dupla ( circular )

    void inserirElementoCircular(listaDupla **lp, int valor);
                
    void excluirElementoCircular(listaDupla **lp, int valor);
                
    void imprimirCircular(listaDupla *lp);
                




