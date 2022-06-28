#include <stdio.h>
#include <stdlib.h>
#include <math.h>     //contem a função sqrt (raíz quadrada)

int main ()
{
    int x, m, n;
    printf("Digite os limites inferior e superior da tabela: ");
    scanf("%d%d", &m, &n);
    printf("\n\t\t********************************");
    printf("\n\t\t*    x |          sqrt(x)      *");
    printf("\n\t\t*------------------------------*");
    x=m;
    while(x<=n)
    {
        if (x>=0)
            printf("\n\t\t* %4d |  %15.8f      *", x, sqrt(x)); //O %15.8f escreve o sqrt(x) com 15 espaços (ele nao conta o espaço do ponto);
        else                                                    //O .8 indica quantos nºs depois da vírgula esse número REAL (pois é f) terá.
            printf("\n\t\t* %4d |  %15s      *", x, "----------");      //O comando if-else é um condicional. Se x>=0, ele executa o primeiro printf, caso contrário, ele executa o segundo
        x=x+1;                                                  //Nesse caso, usamos o if-else para evitar problemas quando x for negativo, já que o sqrt(x) estaria indefinido (daria problema no programa)
    }                                                           //O %15s é um comando que escreve o que estiver em aspas (no caso "-") em 15 espaços, justaposto à direita! (parecido com o "%4d"
    printf("\n\t\t********************************");
    printf("\n\n"); system("pause"); return 0;
}
