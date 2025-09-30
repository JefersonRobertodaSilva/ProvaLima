#include <stdio.h>
#include <stdlib.h>

typedef struct Bloco{     //typedef serve para 'resumir' quando voce for criar uma variavel do tipo bloco
    int valor;
   struct Bloco* prox;
} Bloco;

//'cascas' para marcar as funcoes que serao usadas
void criarLista(Bloco** inicio);
void inserirElemento(Bloco** inicio, int valor);
void excluirElemento(Bloco** inicio, int valor);
void imprimirLista(Bloco* inicio);
void procurarElemento(Bloco** inicio, int valor);
void numeroDeElementos(Bloco* inicio);
