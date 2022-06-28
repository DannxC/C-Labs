#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, num, cont, somapares, soma3ou7, fat, maior, menor, fibo1, fibo2, fibo3; float soma, MA; char lixo;
    printf("Digite a quantidade de numeros que serao contabilizados: ");
    scanf("%d%c", &n, &lixo);
    while(n<=0)
    {
        printf("\nPor favor, digite novamente a quantidade de numeros que serao contabilizados: ");
        scanf("%d%c", &n, &lixo);
    }
    cont = 0;
    soma = 0;
    somapares = 0;
    soma3ou7 = 0;
    maior = 0;
    menor = 0;
    while(cont < n)
    {
        fat = 1;           //termo de comparação do fatorial
        fibo1 = 0;         //primeiro termo de fibonacci
        fibo2 = 1;         //segundo termo de fibonacci
        fibo3 = 0;         //termo de comparação de fibonacci (começa zerado)
        cont = cont + 1;   //contagem do numero em questao
        printf("\n\tDigite o numero (%d): ", cont);
        scanf("%d%c", &num, &lixo);
        soma = soma + num;                            //soma
        if(num >= 0 && num%2 == 0)
            somapares = somapares + num;              //soma dos pares
        if(num >= 0 && num%3 == 0 || num >= 0 && num%7 == 0)
            soma3ou7 = soma3ou7 + num;                //soma dos div por 3 ou 7
        while(num > 1 && fat < num)
        {
            fat = fat * fat + fat;
        }
        if(fat == num)
            printf("\tEh fatorial? Sim");
        else
            printf("\tEh fatorial? Nao");           //verificação se o num é ou nao fatorial
        if(cont == 1)
        {
            maior = num;
            menor = num;
        }
        if(num > maior)
            maior = num;                            //leitura do maior numero
        if(num < menor)
            menor = num;                            //leitura do menor numero
        while(fibo3 < num)
        {
            fibo3 = fibo2 + fibo1;
            fibo1 = fibo2;
            fibo2 = fibo3;
        }
        if(num == fibo3 && num > 0)
            printf("\n\tPertence a sequencia de Fibonacci? Sim\n");
        else
            printf("\n\tPertence a sequencia de Fibonacci? Nao\n");   //Fim da verificação do pertencimento à Fibonacci
    }
    MA = soma / n;
    printf("\n\n\t\tMedia aritmetica dos numeros: %f", MA);
    printf("\n\t\tSoma dos numeros divisiveis por 3 ou por 7: %d", soma3ou7);
    printf("\n\t\tSoma dos numeros pares: %d", somapares);
    printf("\n\t\tMaior dos numeros: %d", maior);
    printf("\n\t\tMenor dos numeros: %d", menor);
    printf("\n\n\n");
    system("pause");
    return 0;
}
