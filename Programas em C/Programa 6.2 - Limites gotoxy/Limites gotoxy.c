#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>

int main()
{
    int i, n;
    printf("TESTE DO LIMITE DE LINHAS DO GOTOXY");
    printf("\n\nDigite o numero de linhas: ");
    scanf("%d", &n);
    printf("Maximize a tela e digite algo!");
    getche(); clrscr();
    for(i = 1; i <= n; i++)
    {
        gotoxy((i - 1) % 120 + 1, i);
        printf("%d", i % 10);
    }
    printf("\nDigite algo para encerrar: ");
    getch();
    return 0;
}
