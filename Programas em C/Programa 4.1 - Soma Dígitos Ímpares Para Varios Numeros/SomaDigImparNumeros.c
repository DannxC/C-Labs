#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, dig, quoc, somaimp;
    printf("Digite um numero inteiro: ");
    scanf("%d", &num);
    while(num >= 0)
    {
        somaimp = 0;
        quoc = num;
        while(quoc > 0)
        {
            dig = quoc%10;      //resto de quoc por 10 = ultimo digito de quoc
            if(dig%2 != 0)      //se o ultimo digito for par, descarta, se for impar, conta. OBS: " != " É o sinal "diferente"!!
                somaimp = somaimp + dig;
            quoc = quoc/10;     //preparando a leitura do segundo/terceiro/... digitos.
            printf("%d ", quoc);
        }
        printf("\n\tA soma dos digitos impares do numero %d eh dada por: %d", num, somaimp);
        printf("\n\n\nDigite o proximo numero inteiro: ");
        scanf("%d", &num);
    }
    printf("\n\n"); system("pause"); return 0;
}
