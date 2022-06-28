#include <stdio.h>
#include <stdlib.h>

int fat(int n)
{
    int f;
    if(n < 0)
        f = -1;
    else if(n <= 1)
        f = 1;
    else
        f = n*fat(n-1);
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
