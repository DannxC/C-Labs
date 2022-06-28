#include <stdio.h>
#include <stdlib.h>

void soma(int *z, int x, int y)
{
    *z = x + y;
}

int main()
{
    int a, b, c;
    printf("Digite a e b: ");
    scanf("%d%d", &a, &b);
    soma(&c, a, b);
    printf("\nc = a + b = %d + %d = %d", a, b, c);
    printf("\n\n"); system("pause"); return 0;
}
