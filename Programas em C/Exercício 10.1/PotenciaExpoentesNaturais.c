#include <stdio.h>
#include <stdlib.h>

float exponencial(float x, int y)
{
    float z;
    if(y == 0)
        z = 1;
    else
        z = x * exponencial(x, y - 1);
    return z;
}

int main()
{
    float A; int n;
    printf("Calculo de A^n");
    do
    {
        printf("\n\n\tDigite A e n: ");
        scanf("%f%d", &A, &n);
        if(n < 0)
            printf("\n\tDigite n inteiro e não negativo: ");
    } while(n < 0);
    printf("\n\t(%g)^%d = %g", A, n, exponencial(A, n));
    printf("\n\n"); system("pause"); return 0;
}
