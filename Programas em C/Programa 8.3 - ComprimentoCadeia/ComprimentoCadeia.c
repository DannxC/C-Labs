#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char cadeia[20];

int main()
{
    cadeia Cad;
    printf("Digite uma cadeia de caracteres:\n\n");
    scanf("%s", Cad);
    printf("\n\tComprimento (%s) = %d", Cad, strlen(Cad));          //strlen(Cad) eh equivaente a String Lenght (Comprimento da cadeia) de Cad, um inteiro.
    printf("\n\n"); system("pause"); return 0;                      //Note que ele nao conta o '\0'
}
