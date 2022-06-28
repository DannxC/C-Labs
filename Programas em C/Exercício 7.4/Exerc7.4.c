#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[10][10], m, n, i, j, cont[10];
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
    fprintf(FileOut, "                                              Elementos\n");
    fprintf(FileOut, "-------------------------------------------------------");
    for(i = 0; i <= m-1; i++)
    {
        fprintf(FileOut, "\nLinh: %d", i);
        for(j = 0; j <= n-1; j++)
            fprintf(FileOut, "%8d", A[i][j]);
    }
    fprintf(FileOut, "\n");
    fprintf(FileOut, "-------------------------------------------------------");
    fprintf(FileOut, "\n> Zero:");
    for(j = 0; j <= n-1; j++)
    {
        for(i = 0, cont[j] = 0; i <= m-1; i++)
        {
            if(A[i][j] > 0)
                cont[j]++;
        }
        fprintf(FileOut, "%8d", cont[j]);
    }
    printf("\n\n"); system("pause"); return 0;
}
