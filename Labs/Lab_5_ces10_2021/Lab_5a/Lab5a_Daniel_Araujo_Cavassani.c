#include <stdio.h>
#include <stdlib.h>

/* Cabeçalho, declarações e digitação do número de cadeias */

int main()
{               //Início da função main
    char carac, lixo; int estado, i, n;
    printf("I D E N T I F I C A C A O   D E   C O M E N T A R I O S   D A   L I N G U A G E M   C");
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
                        case '/': estado = 2; break;
                        default: estado = 1;
                    }
                    break;
                case 2:         //Teste do caractere no estado 2
                    switch(carac)
                    {
                        case '/': estado = 2; break;
                        case '*': estado = 3; break;
                        default: estado = 1;
                    }
                    break;
                case 3:         //Teste do caractere no estado 3
                    switch(carac)
                    {
                        case '*': estado = 4; break;
                        default: estado = 3;
                    }
                    break;
                case 4:         //Teste do caractere no estado 4
                    switch(carac)
                    {
                        case '*': estado = 4; break;
                        case '/': estado = 5; break;
                        default: estado = 3;
                    }
                    break;
                case 5:
                    estado = 5;         //Ação para o estado 5 (dispensável)
                    break;
            }
/*Escrita do resultdo do teste*/
        if(estado == 5)
            printf("\n\tCadeia aprovada!");
        else
            printf("\n\tCadeia reprovada!");
    }
/*Fechamento da tela*/
    printf("\n\n"); system("pause"); return 0;
}           //Fim da função main e do programa
