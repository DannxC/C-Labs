#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char logic;
const logic True = 1, False = 0;
typedef char cadeia[30];
typedef struct binario binario;

struct binario
{
    cadeia valbinario;
    int valdecimal;
    logic valido;
};

int main()
{
    binario bin; int i, n;
    printf("Digite um numero binario: ");
    scanf("%s", bin.valbinario);
    bin.valido = True; n = strlen(bin.valbinario);
    for(i = 0; i < n && bin.valido == True; i++)
        if(bin.valbinario[i] != '0' && bin.valbinario[i] != '1')
            bin.valido = False;
    if(bin.valido == True)
    {
        for(i = 0, bin.valdecimal = 0; i < n; i++)
            bin.valdecimal = 2*bin.valdecimal + (bin.valbinario[i] - '0');
        printf("\n\t(%s)2 = (%d)10", bin.valbinario, bin.valdecimal);
    }
    else
        printf("\n\t%s nao representa um binario", bin.valbinario);
    printf("\n\n"); system("pause"); return 0;
}
