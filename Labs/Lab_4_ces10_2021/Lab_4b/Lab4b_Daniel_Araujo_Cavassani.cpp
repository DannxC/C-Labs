#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, a, b, ma, mb, mmc;
    printf("MMC ENTRE VARIOS PARES DE NUMEROS\n\n");
    printf("Digite quantos pares de numeros: ");
    scanf("%d", &n);
    i = 1;
    while(i <= n)
    {
        printf("\n\nDigite o par %d: ", i);
        scanf("%d%d", &a, &b);
        printf("\tMMC (%d, %d) = ", a, b);
        if(a == 0 || b == 0)
            mmc = 0;
        else
        {
            a = abs(a);
            b = abs(b);
            ma = a;
            mb = b;
            while(ma != mb)
            {
                if(ma < mb)
                    ma = ma+a;
                else
                    mb = mb+b;
            }
            mmc = ma;
        }
        printf("%d", mmc);
        i = i+1;
    }
    printf("\n\n\n"); system("pause"); return 0;
}
