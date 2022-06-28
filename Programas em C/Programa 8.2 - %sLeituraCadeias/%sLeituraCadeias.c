#include <stdio.h>
#include <stdlib.h>

typedef char cadeia[20];

int main()
{
    cadeia Cad1, Cad2;
    printf("Digite uma frase:\n\n");
    scanf("%s%s", Cad1, Cad2);                  //scanf para de ler a cadeia ao encontrar um enter ou um espaço em branco
    printf("\nCad1 = %s", Cad1);
    printf("\nCad2 = %s", Cad2);
    printf("\n\n"); system("pause"); return 0;
}
