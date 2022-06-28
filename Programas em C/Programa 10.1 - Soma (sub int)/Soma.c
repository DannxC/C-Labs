#include <stdio.h>
#include <stdlib.h>

int soma (int x, int y)
{
    return x+y;
}

int main()
{
    int a, b, c;
    printf("Digite a e b: ");
    scanf("%d%d", &a, &b);
    c = soma(a, b);
    printf("\nc = a + b = %d + %d = %d", a, b, c);
    printf("\n\n"); system("pause"); return 0;
}
