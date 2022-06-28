#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>

int main()
{
    int i, j, t;
    printf("Maximize a tela e digite algo!");
    getche(); clrscr();

/*Pintar o fundo de branco*/

    for(textbackground(15), i = 1; i <= 160; i += 40)
    {
        for(j = 1; j <= 35; j++)
        {
            gotoxy(i, j);
            printf("                                        ");
        }
    }

/*Construir o chao verde*/

    for(textbackground(2), i = 1; i <= 160; i += 40)
        for(j = 36; j <= 45; j++)
    {
        gotoxy(i, j);
        printf("                                        ");
    }

/*HP do pikachu*/

    gotoxy(63, 15); textbackground(0); printf("                                      ");
    gotoxy(63, 16); textbackground(0); printf("  "); textbackground(12); printf("    "); textbackground(15); printf("                              "); textbackground(0); printf("  ");
    gotoxy(63, 17); textbackground(0); printf("                                      ");

/*Desenho do pikachu (linha por linha)*/

//linha 1
    for(textbackground(0), i = 81, j = 42; i <= 86; i += 2)
    {
        gotoxy(i, j);
        printf("  ");
    }
//linha 2
    for(i = 79, j = 41; i <= 88; i += 2)
    {
        gotoxy(i, j);
        switch(i)
        {
            case 79: case 87: textbackground(0); printf("  "); break;
            default: textbackground(14); printf("  "); break;
        }
    }
//linha 3
    for(i = 77, j = 40; i <= 88; i += 2)
    {
        gotoxy(i, j);
        switch(i)
        {
            case 83: textbackground(14); printf("  "); break;
            default: textbackground(0); printf("  "); break;
        }
    }
//linha 4
    for(i = 67, j = 39; i <= 88; i += 2)
    {
        gotoxy(i, j);
        switch(i)
        {
            case 77: textbackground(14); printf("          "); break;
            case 67: textbackground(0); printf("          "); break;
            case 87: textbackground(0); printf("  "); break;
        }
    }
//linha 5
    for(i = 67, j = 38; i <= 90; i += 2)
    {
        gotoxy(i, j);
        switch(i)
        {
            case 67: case 71: case 81: case 89: textbackground(0); printf("  "); break;
            default: textbackground(14); printf("  "); break;
        }
    }
//linha 6
    for(i = 69, j = 37; i <= 90; i += 2)
    {
        gotoxy(i, j);
        switch(i)
        {
            case 69: case 79: case 89: textbackground(0); printf("  "); break;
            default: textbackground(14); printf("  "); break;
        }
    }
//linha 7
    for(i = 67, j = 36; i <= 90; i += 2)
    {
        gotoxy(i, j);
        switch(i)
        {
            case 67: case 69: case 81: case 89: textbackground(0); printf("  "); break;
            case 87: textbackground(6); printf("  "); break;
            default: textbackground(14); printf("  "); break;
        }
    }
//linha 8
    for(i = 65, j = 35; i <= 90; i += 2)
    {
        gotoxy(i, j);
        switch(i)
        {
            case 65: case 89: textbackground(0); printf("  "); break;
            default: textbackground(14); printf("  "); break;
        }
    }
//linha 9
    for(i = 67, j = 34; i <= 90; i += 2)
    {
        gotoxy(i, j);
        switch(i)
        {
            case 67: case 89: textbackground(0); printf("  "); break;
            case 77: textbackground(12); printf("  "); break;
            case 85: case 87: textbackground(6); printf("  "); break;
            default: textbackground(14); printf("  "); break;
        }
    }
//linha 10
    for(i = 67, j = 33; i <= 90; i += 2)
    {
        gotoxy(i, j);
        switch(i)
        {
            case 67: case 89: textbackground(0); printf("  "); break;
            case 77: case 79: textbackground(12); printf("  "); break;
            default: textbackground(14); printf("  "); break;
        }
    }
//linha 11
    for(i = 65, j = 32; i <= 92; i += 2)
    {
        gotoxy(i, j);
        switch(i)
        {
            case 65: case 73: case 75: case 87: case 89: case 91: textbackground(0); printf("  "); break;
            default: textbackground(14); printf("  "); break;
        }
    }
//linha 12
    for(i = 63, j = 31; i <= 94; i += 2)
    {
        gotoxy(i, j);
        switch(i)
        {
            case 63: case 75: case 87: case 89: case 93: textbackground(0); printf("  "); break;
            case 73: textbackground(7); printf("  "); break;
            default: textbackground(14); printf("  "); break;
        }
    }
//linha 13
    for(i = 63, j = 30; i <= 96; i += 2)
    {
        gotoxy(i, j);
        switch(i)
        {
            case 63: case 65: case 85: case 89: case 95: textbackground(0); printf("  "); break;
            case 87: textbackground(15); printf("  "); break;
            default: textbackground(14); printf("  "); break;
        }
    }
//linha 14
    for(i = 63, j = 29; i <= 96; i += 2)
    {
        gotoxy(i, j);
        switch(i)
        {
            case 63: case 85: case 89: case 95: textbackground(0); printf("  "); break;
            case 65: textbackground(7); printf("  "); break;
            case 87: textbackground(15); printf("  "); break;
            default: textbackground(14); printf("  "); break;
        }
    }
//linha 15
    for(i = 65, j = 28; i <= 94; i += 2)
    {
        gotoxy(i, j);
        switch(i)
        {
            case 65: case 85: case 87: case 93: textbackground(0); printf("  "); break;
            default: textbackground(14); printf("  "); break;
        }
    }
//linha 16
    for(i = 67, j = 27; i <= 96; i += 2)
    {
        gotoxy(i, j);
        switch(i)
        {
            case 67: case 77: case 79: case 87: case 95: textbackground(0); printf("  "); break;
            case 85: textbackground(6); printf("  "); break;
            default: textbackground(14); printf("  "); break;
        }
    }
//linha 17 (parte A)
    for(i = 69, j = 26; i <= 76; i += 2)
    {
        gotoxy(i, j);
        switch(i)
        {
            case 69: case 75: textbackground(0); printf("  "); break;
            default: textbackground(14); printf("  "); break;
        }
    }
//linha 17 (parte B)
    for(i = 81, j = 26; i <= 98; i += 2)
    {
        gotoxy(i, j);
        switch(i)
        {
            case 81: case 83: case 89: case 97: textbackground(0); printf("  "); break;
            case 85: case 87: textbackground(6); printf("  "); break;
            default: textbackground(14); printf("  "); break;
        }
    }
//linha 18 (parte A)
    for(i = 69, j = 25; i <= 76; i += 2)
    {
        gotoxy(i, j);
        switch(i)
        {
            case 69: case 75: textbackground(0); printf("  "); break;
            default: textbackground(14); printf("  "); break;
        }
    }
//linha 18 (parte B)
    for(i = 85, j = 25; i <= 100; i += 2)
    {
        gotoxy(i, j);
        switch(i)
        {
            case 85: case 87: case 89: case 99: textbackground(0); printf("  "); break;
            default: textbackground(14); printf("  "); break;
        }
    }
//linha 19 (parte A)
    for(i = 71, j = 24; i <= 76; i += 2)
    {
        gotoxy(i, j);
        switch(i)
        {
            case 71: case 75: textbackground(0); printf("  "); break;
            default: textbackground(14); printf("  "); break;
        }
    }
//linha 19 (parte B)
    for(i = 91, j = 24; i <= 100; i += 2)
    {
        gotoxy(i, j);
        switch(i)
        {
            case 91: case 99: textbackground(0); printf("  "); break;
            default: textbackground(14); printf("  "); break;
        }
    }
//linha 20 (parte A)
    for(i = 71, j = 23; i <= 76; i += 2)
    {
        gotoxy(i, j);
        switch(i)
        {
            case 71: case 75: textbackground(0); printf("  "); break;
            case 73: textbackground(6); printf("  "); break;
            default: textbackground(14); printf("  "); break;
        }
    }
//linha 20 (parte B)
    for(i = 93, j = 23; i <= 98; i += 2)
    {
        gotoxy(i, j);
        switch(i)
        {
            case 93: case 97: textbackground(0); printf("  "); break;
            default: textbackground(14); printf("  "); break;
        }
    }
//linha 21 (parte A)
    for(i = 73, j = 22; i <= 76; i += 2)
    {
        gotoxy(i, j);
        switch(i)
        {
            case 73: case 75: textbackground(0); printf("  "); break;
        }
    }
//linha 21 (parte B)
    for(i = 95, j = 22; i <= 96; i += 2)
    {
        gotoxy(i, j);
        textbackground(0); printf("  ");
    }

/*Desenho da Pokebola, bem como seu movimento para a direita*/

    for(i = 9; i <= 56; i += 2)
    {
        for(j = 28; j <= 34; j++)
        {
            switch(j)
            {
                case 28: gotoxy(i-4, 28); textbackground(15); printf("  "); textbackground(0); printf("      "); break;
                case 29: gotoxy(i-6, 29); textbackground(15); printf("  "); textbackground(0); printf("  "); textbackground(12); printf("      "); textbackground(0); printf("  "); break;
                case 30: gotoxy(i-8, 30); textbackground(15); printf("  "); textbackground(0); printf("  "); textbackground(12); printf("    "); textbackground(0); printf("  "); textbackground(12); printf("    "); textbackground(0); printf("  "); break;
                case 31: gotoxy(i-8, 31); textbackground(15); printf("  "); textbackground(0); printf("      "); textbackground(15); printf("  "); textbackground(0); printf("      "); break;
                case 32: gotoxy(i-8, 32); textbackground(15); printf("  "); textbackground(0); printf("  "); textbackground(15); printf("    "); textbackground(0); printf("  "); textbackground(15); printf("    "); textbackground(0); printf("  "); break;
                case 33: gotoxy(i-6, 33); textbackground(15); printf("  "); textbackground(0); printf("  "); textbackground(15); printf("      "); textbackground(0); printf("  "); break;
                case 34: gotoxy(i-4, 34); textbackground(15); printf("  "); textbackground(0); printf("      "); break;
            }
        }
    for(t = 1; t <= 20000000; t++);
    }

/*Momento de encontro da pokebola e do pikachu (pisca os olhos)*/

    for(t=1; t <= 60000000; t++);       //tempo prolongado para visualização do momento
    textbackground(6);
    gotoxy(65, 29); printf("  ");
    gotoxy(73, 31); printf("    ");
    for(t=1; t <= 60000000; t++);       //tempo entre a primeira e a segunda parte da piscada
    gotoxy(73, 32); printf("    ");
    for(t=1; t <= 60000000; t++);       //tempo para abrir o olho novamente
    textbackground(7);
    gotoxy(65, 29); printf("  ");
    gotoxy(73, 31); printf("  ");
    textbackground(0);
    gotoxy(75, 31); printf("  ");
    gotoxy(73, 32); printf("    ");
    for(t=1; t <= 60000000; t++);       //tempo antes da tentativa de captura de fato

/*Momento da entrada na pokebola (Pikachu some)*/

    for(j = 15; j <= 35; j++)
    {
        gotoxy(63, j); textbackground(15); printf("                                      ");
    }
    for(j = 36; j <= 42; j++)
    {
        gotoxy(63, j); textbackground(2); printf("                            ");
    }

/*Caida da pokebola ao solo*/

    for(i = 55, j = 31; j <= 37; j++)
    {
        gotoxy(i-2, j-4); textbackground(15); printf("      ");
        gotoxy(i-4, j-3); textbackground(15); printf("  "); textbackground(0); printf("      "); textbackground(15); printf("  ");
        gotoxy(i-6, j-2); textbackground(15); printf("  "); textbackground(0); printf("  "); textbackground(12); printf("      "); textbackground(0); printf("  "); textbackground(15); printf("  ");
        gotoxy(i-6, j-1); textbackground(0); printf("  "); textbackground(12); printf("    "); textbackground(0); printf("  "); textbackground(12); printf("    "); textbackground(0); printf("  ");
        gotoxy(i-6, j); textbackground(0); printf("      "); textbackground(15); printf("  "); textbackground(0); printf("      ");
        gotoxy(i-6, j+1); textbackground(0); printf("  "); textbackground(15); printf("    "); textbackground(0); printf("  "); textbackground(15); printf("    "); textbackground(0); printf("  ");
        gotoxy(i-4, j+2); textbackground(0); printf("  "); textbackground(15); printf("      "); textbackground(0); printf("  ");
        gotoxy(i-2, j+3); textbackground(0); printf("      ");
        for(t = 1; t <= 20000000; t++);
    }

/*Indicacao da pokebola de que o Pikachu foi capturado com sucesso*/

    for(t = 1; t <= 80000000; t++);
    gotoxy(53, 33); textbackground(7); printf("      ");
    gotoxy(51, 34); textbackground(7); printf("  "); textbackground(0); printf("      "); textbackground(7); printf("  ");
    gotoxy(49, 35); textbackground(7); printf("  "); textbackground(0); printf("  "); textbackground(4); printf("      "); textbackground(0); printf("  "); textbackground(7); printf("  ");
    gotoxy(49, 36); textbackground(0); printf("  "); textbackground(4); printf("    "); textbackground(0); printf("  "); textbackground(4); printf("    "); textbackground(0); printf("  ");
    gotoxy(49, 37); textbackground(0); printf("      "); textbackground(7); printf("  "); textbackground(0); printf("      ");
    gotoxy(49, 38); textbackground(0); printf("  "); textbackground(7); printf("    "); textbackground(0); printf("  "); textbackground(7); printf("    "); textbackground(0); printf("  ");
    gotoxy(51, 39); textbackground(0); printf("  "); textbackground(7); printf("      "); textbackground(0); printf("  ");
    gotoxy(53, 40); textbackground(0); printf("      ");

/*Encerramento da animacao*/

    gotoxy(1, 49); return 0;
}
