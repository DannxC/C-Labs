#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[10][10], m, n, i, j;
    FILE *FileIn;
    FileIn = fopen("Matriz.txt", "r");
    printf("Informacoes sobre matriz:");
    printf("\n\n\tMatriz de entrada no arquivo Matriz");
    fscanf(FileIn, "%d%d", &m, &n);
    for(i = 0; i <= m-1; i++)
        for(j = 0; j <= n-1; j++)
            fscanf(FileIn, "%d", &A[i][j]);
    printf("\n\nMatriz A:\n\n");
    for(i = 0; i <= m-1; i++)
    {
        for(j = 0 ; j <= n-1; j++)
            printf("%4d", A[i][j]);
        printf("\n\n");
    }
    printf("\n\n"); system("pause"); return 0;
}
