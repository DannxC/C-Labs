#include <stdio.h>
#include <stdlib.h>
#include <math.h>     //contem a fun��o sqrt (ra�z quadrada)

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
            printf("\n\t\t* %4d |  %15.8f      *", x, sqrt(x)); //O %15.8f escreve o sqrt(x) com 15 espa�os (ele nao conta o espa�o do ponto);
        else                                                    //O .8 indica quantos n�s depois da v�rgula esse n�mero REAL (pois � f) ter�.
            printf("\n\t\t* %4d |  %15s      *", x, "----------");      //O comando if-else � um condicional. Se x>=0, ele executa o primeiro printf, caso contr�rio, ele executa o segundo
        x=x+1;                                                  //Nesse caso, usamos o if-else para evitar problemas quando x for negativo, j� que o sqrt(x) estaria indefinido (daria problema no programa)
    }                                                           //O %15s � um comando que escreve o que estiver em aspas (no caso "-") em 15 espa�os, justaposto � direita! (parecido com o "%4d"
    printf("\n\t\t********************************");
    printf("\n\n"); system("pause"); return 0;
}
