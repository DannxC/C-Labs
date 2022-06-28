#include <stdio.h>
#include <stdlib.h>

float absreal(float x)
{
    float z;
    if(x < 0)
        z = -x;
    else
        z = x;
    return z;
}

float RaizQuad(float n, float a, float e)
{
    float z;
    if(absreal(a * a - n) < e)
        z = a;
    else
        z = RaizQuad(n, (a * a + n)/(2*a), e);
    return z;
}

int main()
{
    float n, a, e;
    printf("Calculo da raiz quadrada de n");
    do
    {
        printf("\n\n\tDigite n, bem como a primeira aproximacao para sua raiz, e a precisao desejada no calculo: ");
        scanf("%f%f%f", &n, &a, &e);
        if(n < 0 || e < 0)
            printf("\n\tDigite nuerosvalidos: ");
    } while(n < 0 || e < 0);
    printf("\n\tsqrt(%f) = %f", n, RaizQuad(n, a, e));
    printf("\n\n"); system("pause"); return 0;
}
