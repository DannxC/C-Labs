#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int i, n;  //Vari�vel inteira �n�: destinada a guardar o n�mero de repeti��es a ser digitado
    printf("Digite o numero de repeticoes:");  //torna a leitura amig�vel: o operador saber� o que o programa fica esperando
    scanf("%d",&n);  //(%d) Espera a digita��o de um n�mero inteiro (%d);
    i=1;             //(&n) L� o n�mero digitado, guardando-o no endere�o da vari�vel �n�
    while (i<=n)
    {
        printf("Ola pessoal!\n");
        i=i+1;
    }
    printf("\n\n");
    system("pause");
    return 0;
}
