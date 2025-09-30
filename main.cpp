#include <stdio.h>
#include <stdlib.h>
#include "bloco.h"
#include "pilha.h"
#include "fila.h"
#include "listaDupla.h"


//-----------------------------------------------------------------------------------------------------
// A_recursiva

// iten 1

int f1(int n) // fatorial
{
    if (n == 0)
        return (1);
    else
        return (n * f1(n - 1));
}

int f2(int n) // expressao
{
    if (n == 0)
        return (1);
    if (n == 1)
        return (1);
    else
        return (f2(n - 1) + 2 * f2(n - 2));
}

int f3(int n) // N ate 'zero'.   repete 2 vezes o numero atual e diminui em 1,se chegar em zero, imprime
// 'zero' ao inves do numero '0' e encerra a funcao.
{
    if (n == 0)
    {
        
        printf("Zero\n");
        
    }

    else
    {
         printf("%d", n);
         printf("%d", n);
         f3(n - 1);
    }
   return 0;
}

//***************************

// A recursiva item 2
int somaPares(int n) {
    if (n == 0)
    {
        return 0; // condicao para parar
    }
    if (n % 2 == 0)
    { // se for par, a funcao da print e chama ela mesma para o antecessor do n
        printf("%d ", n);
        return n + somaPares(n - 1);
    }
    else
    { // se for impar, chama ela mesmo para o antecessor
        return somaPares(n - 1);
    }
}

//***************************

// A recursiva item 3
int calculaProduto(int a, int b) {
    if (b == 1)
    { // retorna o a ja que A*1=A
        return a;
    }
    else if (b > 1)
    { 			// retorna a multiplicacao normal, essa expressao resulta no mesmo do 
				//que fazer a propria multiplicacao.3, 3 3 * 2 + 3 = 9 return a * (b - 1) + a;
	return a* (b-1) + a;
	
    }
    // as ordens do enunciado nao implementa para caso um b menor que 1, implementei para que fique completo, mas se tivesse inserido um numero
// b<1, o programa retornava um resultado incorreto.

/*else{    //caso o numero do b for b<1
    return a*b;
}*/
}
//*****************************

// A recursiva item 4


// Insere um elemento no final da lista recursivamente

void InserirRecursivoLista(Bloco **cabeca, int valor) {
    if (*cabeca == NULL) {
        // lista vazia ou chegou no final, cria novo nó
        Bloco *novo = (Bloco*) malloc(sizeof(Bloco));
        novo->valor = valor;
        novo->prox = NULL;
        *cabeca = novo;
        printf("Elemento %d inserido!\n", valor);
        return;
    }
    // recursao para o proximo no							imagine essa lista: 10 20 
    InserirRecursivoLista(&((*cabeca)->prox), valor);  //necessario *cabeca estar entre () pois: (*cabeca) == 10,  (*cabeca)->prox== 20,
	// &((*cabeca)->prox) é o endereco disso. assim quando antigir NULL, esta no fim da lista e insere o elemnto, fazendo assim recusrivamente.
}

void ImprimirListaRecursivo(Bloco* cabeca){
	Bloco* aux= cabeca;
	
	if(aux==NULL){
		printf("\n");
		return;
	}
	printf("%d ", aux->valor);
	
	ImprimirListaRecursivo(aux->prox);  //caso mais simples pois aux e um ponteiro simples  (nao e ponteiro para ponteiro)
}

void BuscaRecursivo(Bloco* cabeca, int valor){
	Bloco* aux=cabeca;
	
	if(aux==NULL){   // isso so acontece se passar do fim ou nao tem lista
		printf("elemento nao encontrado/lista nao existe\n");
		return;	
	}
	else if(aux->valor==valor){
		printf("elemento %d encontrado!\n", valor);
		return;
	}
	else{
		 BuscaRecursivo(aux->prox, valor);
	}
	
}

void ExcluirRecursivo(Bloco **cabeca, int valor) {
    if (*cabeca == NULL) return;  // lista vazia

    Bloco *atual = *cabeca;

    if (atual->valor == valor) {
        // removendo o primeiro nó
        *cabeca = atual->prox;
        free(atual);
        printf("Elemento %d excluido!\n", valor);
        return;
    }

    // recursão para os próximos nós
    if (atual->prox != NULL) {
        if (atual->prox->valor == valor) {
            Bloco *temp = atual->prox;
            atual->prox = temp->prox; // ajusta o ponteiro do nó anterior
            free(temp);
            printf("Elemento %d excluido!\n", valor);
        } else {
            ExcluirRecursivo(&(atual->prox), valor);
        }
    }
}

//-------------------------------------------------------------------------------------------------

void menuLista(Bloco **inicio) {
    int opcao, valor;
    do {
    	system("cls");
        printf("\n=== MENU LISTA ===\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Excluir elemento\n");
        printf("3 - Imprimir lista\n");
        printf("4 - Procurar elemento\n");
        printf("5 - Numero de elementos\n");
        printf("0 - Retornar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        if (opcao == 0) break;   //somente para caso decidir sair do menu, evintando pausar o programa com isso

        switch (opcao) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                inserirElemento(inicio, valor);
                break;
            case 2:
                printf("Digite o valor para excluir: ");
                scanf("%d", &valor);
                excluirElemento(inicio, valor);
                break;
            case 3:
                imprimirLista(*inicio);
                break;
            case 4:
                printf("Digite o valor para procurar: ");
                scanf("%d", &valor);
                procurarElemento(inicio, valor);
                break;
            case 5:
                numeroDeElementos(*inicio);
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                
        }
		system("pause");
    } while (opcao != 0);
    
}

void menuPilha(Pilha *p) {
    int opcao, valor;
    do {
    	system("cls");
        printf("\n=== MENU PILHA ===\n");
        printf("1 - Empilhar (push)\n");
        printf("2 - Desempilhar (pop)\n");
        printf("3 - Imprimir pilha\n");
        printf("4 - Procurar elemento\n");
        printf("0 - Retornar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        if (opcao == 0) break;			  //evita ter um pause quando seleciona voltar

        switch (opcao) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                inserirElementoPilha(p, valor);
                break;
            case 2:
                excluirElementoPilha(p);
                break;
            case 3:
                imprimirPilha(p);
                break;
            case 4:
                printf("Digite o valor para procurar: ");
                scanf("%d", &valor);
                procurarElementoPilha(p, valor);
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
        system("pause");
    } while (opcao != 0);
}

void menuFila(Fila *f) {
    int opcao, valor;
    do {
    	system("cls");
        printf("\n=== MENU FILA ===\n");
        printf("1 - Enfileirar\n");
        printf("2 - Desenfileirar\n");
        printf("3 - Imprimir fila\n");
        printf("4 - Procurar elemento\n");
        printf("0 - Retornar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        if (opcao == 0) break; 		//evita ter um pause quando seleciona voltar

        switch (opcao) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                inserirElementoFila(f, valor);
                break;
            case 2:
                excluirElementoFila(f);
                break;
            case 3:
                imprimirFila(f);
                break;
            case 4:
                printf("Digite o valor para procurar: ");
                scanf("%d", &valor);
                procurarElementoFila(f, valor);
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                
        } 
		system("pause");
    } while (opcao != 0);
}

void menuListaRecursiva() {
    Bloco *cabeca = NULL; // Lista da recursiva
    int opcao, valor;

    do {
        system("cls");
        printf("\n=== MENU LISTA RECURSIVA ===\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Excluir elemento\n");
        printf("3 - Imprimir lista\n");
        printf("4 - Procurar elemento\n");
        printf("0 - Retornar ao menu recursivo\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        if (opcao == 0) break;   //evita ter um pause quando seleciona voltar

        switch(opcao) {
            case 1:
                printf("Digite o valor para inserir: ");
                scanf("%d", &valor);
                InserirRecursivoLista(&cabeca, valor);
                break;
            case 2:
                printf("Digite o valor para excluir: ");
                scanf("%d", &valor);
                ExcluirRecursivo(&cabeca, valor);
                break;
            case 3:
                printf("Lista: ");
                ImprimirListaRecursivo(cabeca);
                break;
            case 4:
                printf("Digite o valor para procurar: ");
                scanf("%d", &valor);
                BuscaRecursivo(cabeca, valor);
                break;
            case 0:
                printf("Voltando ao menu recursivo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
        system("pause");
    } while(opcao != 0);
}

void menuRecursiva() {
    int opcao, valor, a, b;

    do {
        system("cls");
        printf("\n=== MENU RECURSIVO ===\n");
        printf("1 - Lista recursiva\n");
        printf("2 - Fatorial (f1)\n");
        printf("3 - Expressao (f2)\n");
        printf("4 - N ate 'zero' (f3)\n");
        printf("5 - Soma pares ate n (somaPares)\n");
        printf("6 - Produto recursivo (calculaProduto)\n");
        printf("0 - Retornar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        if (opcao == 0) break;  	//evita ter um pause quando seleciona voltar

        switch(opcao) {
            case 1:
                menuListaRecursiva();
                break;
            case 2:
                printf("f1(0) = %d\n", f1(0));
                printf("f1(1) = %d\n", f1(1));
                printf("f1(5) = %d\n", f1(5));
                break;
            case 3:
                printf("f2(0) = %d\n", f2(0));
                printf("f2(1) = %d\n", f2(1));
                printf("f2(5) = %d\n", f2(5));
                break;
            case 4:
                printf("f3(0): "); f3(0);
                printf("f3(1): "); f3(1);
                printf("f3(5): "); f3(5);
                break;
            case 5:
                printf("Digite n para somaPares: ");
                scanf("%d", &valor);
                printf("Soma dos pares: %d\n", somaPares(valor));
                break;
            case 6:
                printf("Digite a e b para calculaProduto(a,b): ");
                scanf("%d %d", &a, &b);
                printf("Produto: %d\n", calculaProduto(a,b));
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

        system("pause");

    } while(opcao != 0);
}

void menuListaCircular(listaDupla **lp) {
    int opcao, valor, pos;
    *lp=NULL;

    do {
        system("cls"); // limpa tela no Windows
        printf("\n=== MENU LISTA CIRCULAR ===\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Excluir elemento\n");
        printf("3 - Imprimir lista\n");
        printf("0 - Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        if (opcao == 0) break;

        switch (opcao) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                inserirElementoCircular(lp, valor);
                break;
            case 2:
                printf("Digite o valor para excluir: ");
                scanf("%d", &valor);
                excluirElementoCircular(lp, valor);
                break;
            case 3:
                imprimirCircular(*lp);
                printf("\n");
                break;
            case 0:
                printf("Voltando...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
        system("pause");
    } while (opcao != 0);
}

void menuListaDupla(listaDupla **lp) {
    int opcao, valor, pos;

    do {
        system("cls"); // limpa tela no Windows
        printf("\n=== MENU LISTA DUPLA ===\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Excluir elemento\n");
        printf("3 - Imprimir lista\n");
        printf("4 - Procurar elemento\n");
        printf("5 - Inserir sem duplicatas\n");
        printf("6 - Lista Circular\n");
        printf("0 - Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                printf("Digite a posicao: ");
                scanf("%d", &pos);
                inserirElementoListaDupla(lp, valor, pos);
                break;
            case 2:
                printf("Digite o valor para excluir: ");
                scanf("%d", &valor);
                excluirElementoListaDupla(lp, valor);
                break;
            case 3:
                imprimirRecursivoListaDupla(*lp);
                printf("\n");
                break;
            case 4:
                printf("Digite o valor para procurar: ");
                scanf("%d", &valor);
                buscarElementoListaDupla(*lp, valor);
                break;
            case 5:
                printf("Digite o valor para inserir: ");
                scanf("%d", &valor);
                inserirInicioLD(lp, valor);
                break;
            case 6:
                menuListaCircular(lp);
                *lp=NULL;
                break;
            case 0:
                printf("Voltando...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
        system("pause");
    } while (opcao != 0);
}




int main() {
	//criando as listas
    Bloco *inicio;
    Pilha *p;
    Fila *f;
    listaDupla *ld;
    
	//iniciando
    criarLista(&inicio);
    criarPilha(&p);
    criarFila(&f);
    criarListaDupla(&ld);

    int opcao;
    do {
    system("cls");
    printf("\n=== MENU PRINCIPAL ===\n");
    printf("1 - Operacoes com Lista\n");
    printf("2 - Operacoes com Pilha\n");
    printf("3 - Operacoes com Fila\n");
    printf("4 - Operacoes Recursivas\n");
    printf("5 - Operacoes com lista dupla\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            menuLista(&inicio);
            break;
        case 2:
            menuPilha(p);
            break;
        case 3:
            menuFila(f);
            break;
        case 4:
            menuRecursiva();
            break;
        case 5:
        	menuListaDupla(&ld);
        	break;
        case 0:
            printf("Encerrando programa...\n");
            break;
        default:
            printf("Opcao invalida!\n");
    }

} while(opcao != 0);

    return 0;
}


