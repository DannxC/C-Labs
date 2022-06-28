#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, achou; char c;
    printf("DIVISORES DE VARIOS NUMEROS MAIORES QUE 1");
    do
    {
        printf("\n\n\nDivisores de um numero? (s/n): ");
        do
        {
            scanf(" %c", &c);
        }
        while(c != 's' && c != 'S' && c != 'n' && c != 'N');
        if(c == 's' || c == 'S')
        {
            printf("Digite um numero maior que um: ");
            scanf("%d", &n);
            while(n < 2)
            {
                printf("Numero improprio, digite novamente: ");
                scanf("%d", &n);
            }
            printf("Divisores de %d:", n);
            i = 2;
            achou = 0;
            while(i <= n/2)
            {
                if(n%i == 0)
                {
                    printf(" %d;", i);
                    achou = achou+1;
                }
                i = i+1;
            }
            if(achou == 0)
                printf(" %d eh primo", n);
        }
    }
    while(c == 's' || c == 'S');
    printf("\n\n"); system("pause"); return 0;
}
