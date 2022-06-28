#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>

int main()
{
    int i, j, demora = 20000000;
    printf("Maximize a tela e digite algo: ");
    getche(); clrscr();
    for(i = 10; i <= 60; i++)
    {
        gotoxy(i, 5); printf(" *");
        for(j = 1; j <= demora; j++);
    }
    for(i = 6; i <= 40; i++)                        //faz o * permanecer numa posição num certo intervalo de tempo perceptível. o valor 20000000
    {                                               //é experimental, apenas.
        gotoxy(61, i-1); printf(" ");
        for(j = 1; j <= demora; j++);
    }
    printf("\n\nDigite algo para encerrar: ");
    getche(); return 0;
}
