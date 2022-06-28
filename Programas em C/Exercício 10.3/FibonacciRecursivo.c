#include <stdio.h>
#include <stdlib.h>

int v;

int Fib(int x)
{
    int f;
    v++;
    if(x < 0)
        f = -1;
    else if(x == 0)
        f = 0;
    else if(x == 1)
        f = 1;
    else
        f = Fib(x - 2) + Fib(x - 1);
    return f;
}

int main()
{
    int i, n;
    printf("TABELA DE FIBONACCI");
    printf("\n\nDigite o numero de termos de fibonacci: ");
    scanf("%d", &n);
    printf("\n\t         n  |         Fib(n)  | Chamadas recursivas");
    printf("\n\t--------------------------------------------------------");
    for(i = 0; i <= n; i++)
    {
        v = 0;
        printf("\n\t%10d | %15d |     ", i, Fib(i));
        printf("%15d", v); //testei o limite e é 42... a partir daí sao mtas retomadas de função, e a variavel int n consegue atender os valores.
    }
    printf("\n\n"); system("pause"); return 0;
}
