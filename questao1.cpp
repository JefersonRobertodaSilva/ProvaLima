#include <stdio.h>

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

int f3(int n) // bizarrice
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

// A recursiva item 2
int somaPares(int n)
{
    if (n == 0)
    {
        return 0; // condicao para parar
    }
    if (n % 2 == 0)
    { // se for par, a funcao dá print e chama ela mesma para o antecessor do n
        printf("%d ", n);
        return somaPares(n - 1);
    }
    else
    { // se for impar, chama ela mesmo para o antecessor
        return somaPares(n - 1);
    }
}

// A recursiva item 3
int calculaProduto(int a, int b)
{
    if (b == 1)
    { // retorna o a ja que A*1=A
        return a;
    }
    else if (b > 1)
    { // retorna a multiplicacao normal, essa expressao resulta no mesmo do que fazer a propria multiplicacao.3, 3 3 * 2 + 3 = 9 return a * (b - 1) + a;
    }
}
// as ordens do enunciado nao implementa para caso um b menor que 1, implementei para que fique completo, mas se tivesse inserido um numero
// b<1, o programa retornava um resultado incorreto.

/*else{    //caso o numero do b for b<1
    return a*b;
}
}*/

// A recursiva item 4



int main()
{
    // A- recursiva
    // iten 1

    //  printf("%d\n", f1(0));
     // printf("%d\n", f1(1));
    //  printf("%d\n", f1(5));

    //   printf("%d\n", f2(0));
    //   printf("%d\n", f2(1));
    //   printf("%d\n", f2(5));

    f3(0);
    f3(1);
    f3(5);
       
    // iten 2
    //	printf("%d", somaPares(9));
    //   printf("\n");
    //   //iten 3
   // printf("%d", calculaProduto(9, -1));

    return 0;
}
