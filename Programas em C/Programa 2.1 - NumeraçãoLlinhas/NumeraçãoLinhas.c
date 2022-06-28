#include<stdio.h>
#include<stdlib.h>

int main ()
{
    int i, n;
    printf("Digite o numero de repeticoes: ");
    scanf("%d", &n);
    printf("\n\t\t************************");      //Seria uma simples moldura para a tabela que será gerada.
    printf("\n\t\t*   i | mensagem       *");      //Além disso, usamos a barra "|" para demarcar a separação de colunas!
    printf("\n\t\t*-----|----------------*");      //É importante ressaltar que o "|" deve ser coerente em todos os printf!
    i=1;
    while(i<=n)                              //Note que, se n>=10, ocorre um desalinhamento nas mensagens (se fosse o "%d").
    {                                        //Com o "%4d", o printf printa as linhas de forma alinhada, escrevendo o valor de "i"
        printf("\n\t\t*%4d | Ola pessoal!   *", i); //em 4 casas na tela. EX: "  23" tem 4 casas na tela, enquanto "23" apenas 2.
        i=i+1;                               //O "%4d", assim, escreve o valor de "i" de forma que este fique justaposto
    }                                        //à direita! se fosse "%-4d", o valor de "i" ficaria justaposto à esquerda.
    printf("\n\t\t************************");   //fim da moldura
    printf("\n\n"); system("pause"); return 0;  //NOTE QUE A PARTIR DE 5 ALGARISMOS, O NUMERO SE TORNA MUITO GRANDE
}                                               //IGNORANDO O "%4d". NESSE CASO, SERIA NECESSARIO POR "%5d" OU +
