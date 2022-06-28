#include <stdio.h>
#include <stdlib.h>

/* Cabeçalho, declarações e digitação do número de cadeias */

int main()
{           //Início da função main
    char carac, lixo; int estado, i, n;
    printf("R E C O N H E C I M E N T O   D E   C A D E I A S   B I N A R I A S   C O M   0'S   E   1'S   A L T E R N A D O S");
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
                case 1:                 //Teste do caractere no estado 1
                    switch(carac)
                    {
                        case '0': estado = 2; break;
                        case '1': estado = 3; break;
                        default: estado = 4;
                    }
                    break;
                case 2:                 //Teste do caractere no estado 2
                    switch(carac)
                    {
                        case '1': estado = 3; break;
                        default: estado = 4;
                    }
                    break;
                case 3:                 //Teste do caractere no estado 3
                    switch(carac)
                    {
                        case '0': estado = 2; break;
                        default: estado = 4;
                    }
                    break;
                case 4:                 //Teste do caractere no estado 4
                    estado = 4;         //Ação para o estado 4 (dispensável)
                    break;
            }
/*Escrita do resultdo do teste*/
        if(estado == 2 || estado == 3)
            printf("\n\tCadeia aprovada!");
        else
            printf("\n\tCadeia reprovada!");
    }
/*Fechamento da tela*/
    printf("\n\n"); system("pause"); return 0;
}           //Fim da função main e do programa
