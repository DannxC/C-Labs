#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[10][10], m, n, i, j;
    printf("Leitura e escrita de matriz\n\n");
    do
    {
        printf("\ndimensoes m e n (<=10): ");
        scanf("%d%d", &m, &n);
    } while(m < 1 || m > 10 || n < 1 || n > 10);
    printf("\n\n");
    for(i = 0; i <= m-1; i++)
    {
        printf("%d elementos da linha %d: ", n, i);
        for(j = 0; j <= n-1; j++)
            scanf("%d", &A[i][j]);
    }
    printf("\n\nMatriz A:\n\n");
    for(i = 0; i <= m-1; i++)
    {
        for(j = 0; j <= n-1; j++)
            printf("%6d", A[i][j]);
        printf("\n\n");
    }
    printf("\n\n"); system("pause"); return 0;
}
