#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>

int main()
{
    int col, lin; char c;
    printf("Maximize a tela e digite algo: ");
    getche(); clrscr();                             //clrscr() é da conio2.h e limpa toda a tela
    printf("Posicionar cursor? (s/n): ");
    c = getche();
    while(c == 's' || c == 'S')
    {
        printf("\rDigite a coluna e a linha: ");    //o \r reescreve a primeira linha da tela
        scanf("%d%d", &col, &lin);
        gotoxy(col, lin); getche();                 //o gotoxy posiciona o cursor nas coordenadas (col, lin) da tela
        gotoxy(1, 1);
        printf("                                                                                "); //limpar a primeira linha (80 espaços em branco)
        printf("\rPosicionar cursor? (s/n): ");
        c = getche();
    }
    printf("\n\n"); system("pause"); return 0;
}
