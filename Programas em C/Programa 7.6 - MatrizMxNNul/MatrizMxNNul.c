#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[10][10], i, j, m, n;
    printf("Matriz m x n nula:\n");
    do
    {
        printf("\nDigite m e n (<= 10): ");
        scanf("%d%d", &m, &n);
    } while(m < 1 || m > 10 || n < 1 || n > 10);
    for(i = 0; i <= 9; i++)
        for(j = 0; j <= n-1; j++)
            A[i][j] = 0;
    printf("\n\n");
    for(i = 0; i <= m-1; i++)
    {
        for(j = 0; j <= n-1; j++)
            printf("%4d", A[i][j]);
        printf("\n");
    }
    printf("\n\n"); system("pause"); return 0;
}
