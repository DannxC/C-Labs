#include <stdio.h>
#include <stdlib.h>

/* Cabeçalho, declarações e digitação do número de cadeias */

int main()
{               //Início da função main
    char carac, lixo; int estado, i, n;
    printf("R E C O N H E C I M E N T O   D E   C O N S T A N T E S   N U M E R I C A S   D A   L I N G U A G E M   C");
    printf("\n\nNumero de cadeias a serem testadas: ");
    scanf("%d%c", &n, &lixo);
    for(i = 1; i <= n; i++)
    {
/*Digitação de cadeias a serem testadas*/
        printf("\n\nDigite a %da cadeia encerrada por <enter>: ", i);
/*Percurso no automato usando os caracteres da cadeia*/
        for(estado = 1, scanf("%c", &carac); carac != '\n'; scanf("%c", &carac))
            switch(estado)
            {
                case 1:         //Teste do caractere no estado 1
                    switch(carac)
                    {
                        case '+': case '-': estado = 2; break;
                        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': estado = 3; break;
                        case '.': estado = 4; break;
                        default: estado = 9;
                    }
                    break;
                case 2:         //Teste do caractere no estado 2
                    switch(carac)
                    {
                        case '.': estado = 4; break;
                        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': estado = 3; break;
                        default: estado = 9;
                    }
                    break;
                case 3:         //Teste do caractere no estado 3
                    switch(carac)
                    {
                        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': estado = 3; break;
                        case '.': estado = 5; break;
                        case 'e': case 'E': estado = 6; break;
                        default: estado = 9;
                    }
                    break;
                case 4:         //Teste do caractere no estado 4
                    switch(carac)
                    {
                        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': estado = 5; break;
                        default: estado = 9;
                    }
                    break;
                case 5:         //Teste do caractere no estado 5
                    switch(carac)
                    {
                        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': estado = 5; break;
                        case 'e': case 'E': estado = 6; break;
                        default: estado = 9;
                    }
                    break;
                case 6:         //Teste do caractere no estado 6
                    switch(carac)
                    {
                        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': estado = 8; break;
                        case '+': case '-': estado = 7; break;
                        default: estado = 9;
                    }
                    break;
                case 7:         //Teste do caractere no estado 7
                    switch(carac)
                    {
                        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': estado = 8; break;
                        default: estado = 9;
                    }
                    break;
                case 8:         //Teste do caractere no estado 8
                    switch(carac)
                    {
                        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': estado = 8; break;
                        default: estado = 9;
                    }
                    break;
                case 9:                 //Estado 9 = estado de erro!
                    estado = 9;         //Ação para o estado 9 (dispensável)
                    break;
            }
/*Escrita do resultdo do teste*/
        if(estado == 3 || estado == 5 || estado == 8)
            printf("\n\tCadeia aprovada!");
        else
            printf("\n\tCadeia reprovada!");
    }
/*Fechamento da tela*/
    printf("\n\n"); system("pause"); return 0;
}           //Fim da função main e do programa
