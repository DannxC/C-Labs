#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, V[10];
    printf("Leitura e escrita de vetor\n\n");
    do
    {
        printf("\nDigite o n.o de elementos (<= 10): ");
        scanf("%d", &n);
    } while(n < 1 || n > 10);
    for(i = 0; i <= n-1; i++)
    {
        printf("Elemento %d: ", i);
        scanf("%d", &V[i]);
    }
    printf("\n\nVetor V:\n\n");
    for(i = 0; i <= n-1; i++)
        printf("%6d", V[i]);
    printf("\n\n"); system("pause"); return 0;
}
