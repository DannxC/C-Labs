#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n; float preco;  //float preco define "preco" como variavel real
    printf("Numero de cadernos:");
    scanf("%d",&n);
    printf("Preco do caderno:");  //(%f) Espera a digitação de um número real;
    scanf("%f",&preco);           //(&preco) Lê o número digitado, guardando-o no endereço "preco"
    printf("O preco de %d cadernos eh %g", n, n*preco);  //(%g) escreve o valor de ‘n*preco’ (real) em decimal, com o número
    printf("\n\n");                                      //mínimo necessário de casas após o ponto (2 casas pós vírgula);
    system("pause");                                     //(%d) escreve o valor de ‘n’ (inteiro) em decimal
    return 0;
}
