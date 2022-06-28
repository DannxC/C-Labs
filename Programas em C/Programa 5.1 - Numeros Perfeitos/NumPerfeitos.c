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
        for(div = 1; div*2 <= i; div++)    //Comando que pode substituir um while: for(inicialização1, ini2, ini3,... ;
            if(i%div == 0)                 // for(inicialização1, ini2, ini3,... ; condição; atualização1, att2, att3, ...)
                soma += div;               //    comandos;
        if(soma == i)                      //No caso: Inicialização > while(condiçao){ comandos > att's }
            printf("%12d", i);
        i++;                               // " += " é um comando de atribuição: " a += b " é o mesmo que " a = a + b "
    }             //i++ ou div++ é equivalente a " i = i+1 " ou " div = div+1 " APÓS a contabilização do valor da expressao.
    printf("\n\n"); system("pause"); return 0;
}
