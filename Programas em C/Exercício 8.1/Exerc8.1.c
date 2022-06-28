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
    numero num; int i;
    printf("Digite a base do numero (2 a 9): ");
    scanf("%d", &num.base);
    printf("\nDigite o numero na base %d: ", num.base);
    scanf(" %s", num.valnabase);

/* Verificacao da correcao da base e inicializacoes */

    for(i = 0, num.valido = True; i < strlen(num.valnabase); i++)
        if(num.valnabase[i] < '0' || num.valnabase[i] >= '0' + num.base)
            num.valido = False;

/* Calculo do valor em decimal de um numero correto */

    if(num.valido == True)
    {
        for(i = 0, num.valdecimal = 0; i < strlen(num.valnabase); i++)
            num.valdecimal = num.base*num.valdecimal + (num.valnabase[i] - '0');
        printf("\n\t(%s)%d = (%d)10", num.valnabase, num.base, num.valdecimal);
    }

/* Aviso de numero incorreto */

    else
        printf("\n\t%s nao representa um numero na base %d", num.valnabase, num.base);

/* Encerramento do programa */

    printf("\n\n"); system("pause"); return 0;
}
