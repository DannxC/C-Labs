#include <stdio.h>
#include <stdlib.h>

int fat(int n)
{
    int f, i; static int v = 0;
    v++;
    printf("\n");
    for(i = 1; i <= v; i++)
        printf("   ");
    printf("Entrada em fat versao %d; n = %d; ", v, n);
    system("pause");
    if(n < 0)
        f = -1;
    else if(n <= 1)
        f = 1;
    else
        f = n*fat(n-1);
    printf("\n");
    for(i = 1; i <= v; i++)
        printf("   ");
    printf("Saida de fat versao %d; n = %d, fat = %d; ", v, n, f);
    system("pause");
    v--;
    if(v == 0)
        printf("\n");
    return f;
}

int main()
{
    int n;
    printf("Calculo de fatorial de n");
    printf("\n\n\tDigite n: ");
    scanf("%d", &n);
    printf("\n\tFat(%d) = %d", n, fat(n));
    printf("\n\n"); system("pause"); return 0;
}
