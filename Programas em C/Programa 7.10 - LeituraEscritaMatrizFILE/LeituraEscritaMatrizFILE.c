#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[10][10], m, n, i, j;
    FILE *FileIn, *FileOut;
    FileIn = fopen("Matriz.txt", "r");
    FileOut = fopen("MatrizSaida.txt", "w");
    printf("Informacoes sobre matriz:");
    printf("\n\n\tMatriz de entrada no arquivo Matriz");
    printf("\n\n\tMatriz de saida no arquivo MatrizSaida");
    fscanf(FileIn, "%d%d", &m, &n);
    for(i = 0; i <= m-1; i++)
        for(j = 0; j <= n-1; j++)
            fscanf(FileIn, "%d", &A[i][j]);
    fprintf(FileOut, "Matriz A:\n\n");
    for(i = 0; i <= m-1; i++)
    {
        for(j = 0; j <= n-1; j++)
            fprintf(FileOut, "%4d", A[i][j]);
        fprintf(FileOut, "\n\n");
    }
    printf("\n\n"); system("pause"); return 0;
}
