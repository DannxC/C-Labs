#include <stdio.h>
#include <stdlib.h>

int main()
{
    char Cad1[10], Cad2[] = "abcde"; int i;
    printf("Digite uma cadeia de caracteres:\n\n");
    scanf("%s", Cad1);                                  //note que nao tem operador de atribuicao "&" para cadeias (strings)!
    printf("\nCad1 = %s", Cad1);
    printf("\nCad2 = %s", Cad2);
    printf("\n");
    for(i = 0; i <= 9; i++)
        printf("\n\tCad[%d] = '%c' ou %d", i, Cad1[i], Cad1[i]);
    printf("\n");
    for(i = 0; i <= 5; i++)
        printf("\n\tCad2[%d] = '%c' ou %d", i, Cad2[i], Cad2[i]);
    printf("\n\n"); system("pause"); return 0;
}
