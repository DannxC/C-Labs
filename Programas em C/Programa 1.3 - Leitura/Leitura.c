#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int i, n;  //Variável inteira ‘n’: destinada a guardar o número de repetições a ser digitado
    printf("Digite o numero de repeticoes:");  //torna a leitura amigável: o operador saberá o que o programa fica esperando
    scanf("%d",&n);  //(%d) Espera a digitação de um número inteiro (%d);
    i=1;             //(&n) Lê o número digitado, guardando-o no endereço da variável ‘n’
    while (i<=n)
    {
        printf("Ola pessoal!\n");
        i=i+1;
    }
    printf("\n\n");
    system("pause");
    return 0;
}
