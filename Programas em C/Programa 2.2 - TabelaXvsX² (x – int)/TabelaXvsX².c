#include <stdio.h>   //nesse rograma, só estamos usando essa biblioteca!
#include <stdlib.h>  //vale lembrar que não estamos utilizando essa biblioteca...

int main ()
{
    int x, n;
    printf("Digite o limite superior da tabela: ");
    scanf("%d", &n);                                //O limite superior é "n", digitado
    printf("\n\t\t******************************");
    printf("\n\t\t*    x |        x^2          *");
    printf("\n\t\t*----------------------------*");
    x=1;
    while(x<=n)
    {
        printf("\n\t\t* %4d | %10d          *", x, x*x);
        x=x+1;
    }
    printf("\n\t\t******************************");
    printf("\n\n"); system("pause"); return 0;
}
