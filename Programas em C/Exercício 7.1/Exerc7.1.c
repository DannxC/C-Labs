#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[10][10], i, j, n;
    printf("Matriz n x n (diagonal, linhas e colunas extremantes = 27):\n");
    do
    {
        printf("\nDigite n (<= 10): "); scanf("%d", &n);
    } while(n < 1 || n > 10);
    for(i = 0; i <= 9; i++)
        for(j = 0; j <= 9; j++)
            A[i][j] = 0;
    for(i = 0; i <= n-1; i++)
    {
        A[i][i] = A[0][i] = A[n-1][i] = A[i][0] = A[i][n-1] = 27;
    }
    printf("\n\n");
    for(i = 0; i <= n-1; i++)
    {
        for(j = 0; j <= n-1; j++)
            printf("%4d", A[i][j]);
        printf("\n\n");
    }
    printf("\n\n"); system("pause"); return 0;
}

