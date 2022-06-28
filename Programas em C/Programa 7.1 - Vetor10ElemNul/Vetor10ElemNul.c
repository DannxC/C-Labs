#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, V[10] = {0};             //V[1] define uma variavel indexado unidimensional (veotr) de 10 elementos... " = {0} " torna todos eles elementos nulos!
    printf("Vetor de 10 elementos nulos:\n\n");
    system("pause");
    printf("\n\n");
    for(i = 0; i <= 9; i++)
        printf("%4d", V[i]);        //os indices de uma variavel indexada podem ser expressoes inteiras!
    printf("\n\n");
    system("pause");
    return 0;
}
