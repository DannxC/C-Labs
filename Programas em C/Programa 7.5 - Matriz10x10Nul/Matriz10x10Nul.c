#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[10][10] = {0}, i, j;          //Variavel indexada bidimensional 10x10 (ou matriz 10x10)
    printf("Matriz 10x10 nula:\n\n");
    system("pause");
    printf("\n\n");
    for(i = 0; i <= 9; i++)
    {
        for(j = 0; j <= 9; j++)
            printf("%4d", A[i][j]);
        printf("\n");
    }
    printf("\n\n");
    system("pause"); return 0;
}
