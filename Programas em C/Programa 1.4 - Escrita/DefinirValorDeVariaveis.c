#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n; float preco;  //float preco define "preco" como variavel real
    printf("Numero de cadernos:");
    scanf("%d",&n);
    printf("Preco do caderno:");  //(%f) Espera a digita��o de um n�mero real;
    scanf("%f",&preco);           //(&preco) L� o n�mero digitado, guardando-o no endere�o "preco"
    printf("O preco de %d cadernos eh %g", n, n*preco);  //(%g) escreve o valor de �n*preco� (real) em decimal, com o n�mero
    printf("\n\n");                                      //m�nimo necess�rio de casas ap�s o ponto (2 casas p�s v�rgula);
    system("pause");                                     //(%d) escreve o valor de �n� (inteiro) em decimal
    return 0;
}
