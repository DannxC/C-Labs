#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Declaracoes do tipo logic e do tipo cadeia de caracteres */

typedef char logic;
const logic True = 1, False = 0;
typedef char cadeia[30];

/* Declaracoes da struct numero */

typedef struct numero numero;
struct numero
{
    cadeia valnabase;
    int base, valdecimal;
    logic valido;
};

/* Funcao main, declaracoes  e leitura do numero e da base */

int main()
{
    numero num; int i, j; char bases[20] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    printf("Digite a base do numero (2 a 20): ");
    scanf("%d", &num.base);
    printf("\nDigite o numero na base %d: ", num.base);
    scanf(" %s", num.valnabase);

/* Verificacao da correcao da base e inicializacoes */

    for(i = 0, num.valido = False; i < strlen(num.valnabase); i++)
        for(j = 0; j < num.base; j++)
            if(num.valnabase[i] ==  bases[j])
            {
                num.valido = True;
                break;
            }

/* Calculo do valor em decimal de um numero correto */

    if(num.valido == True)
    {
        for(i = 0, num.valdecimal = 0; i < strlen(num.valnabase); i++)
            for(j = 0; j < num.base; j++)
                if(num.valnabase[i] == bases[j])
                {
                    num.valdecimal = num.base*num.valdecimal + j;
                    continue;
                }
        printf("\n\t(%s)%d = (%d)10", num.valnabase, num.base, num.valdecimal);
    }

/* Aviso de numero incorreto */

    else
        printf("\n\t%s nao representa um numero na base %d", num.valnabase, num.base);

/* Encerramento do programa */

    printf("\n\n"); system("pause"); return 0;
}
