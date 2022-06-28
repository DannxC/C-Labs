#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[10][10], i, j, n;
    printf("Triangulo de Pascal com n linhas:\n");
    do
    {
        printf("\nDigite n (<= 10): "); scanf("%d", &n);
    } while(n < 1 || n > 10);
    for(i = 0; i <= n-1; i++)
        for(j = 0; j <= i; j++)
        {
            if(j == 0 || j == i)
                A[i][j] = 1;
            else
                A[i][j] = A[i-1][j-1] + A[i-1][j];
        }
    printf("\n\n");
    for(i = 0; i <= n-1; i++)
    {
        for(j = 0; j <= i; j++)
            printf("%5d", A[i][j]);
        printf("\n\n");
    }
    printf("\n\n"); system("pause"); return 0;
}
