#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, V[10];
    printf("Vetor de n elementos nulos:\n");
    do
    {
        printf("\nDigite n (<= 10): ");
        scanf("%d", &n);
    } while(n < 1 || n > 10);
    for(i = 0; i <= n-1; i++)
        V[i] = 0;
    printf("\n");
    for(i = 0; i <= n-1; i++)
        printf("%4d", V[i]);
    printf("\n\n");
    system("pause");
    return 0;
}
