#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, div, soma;
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);
    printf("\nNumeros perfeitos entre 1 e %d:\n\n", n);
    i = 1;
    while (i<=n)
    {
        soma = 0;
        for(div = 1; div*2 <= i; div++)    //Comando que pode substituir um while: for(inicializa��o1, ini2, ini3,... ;
            if(i%div == 0)                 // for(inicializa��o1, ini2, ini3,... ; condi��o; atualiza��o1, att2, att3, ...)
                soma += div;               //    comandos;
        if(soma == i)                      //No caso: Inicializa��o > while(condi�ao){ comandos > att's }
            printf("%12d", i);
        i++;                               // " += " � um comando de atribui��o: " a += b " � o mesmo que " a = a + b "
    }             //i++ ou div++ � equivalente a " i = i+1 " ou " div = div+1 " AP�S a contabiliza��o do valor da expressao.
    printf("\n\n"); system("pause"); return 0;
}
