#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n; char c, lixo;               // ->        // Para o scanf, tudo o que é digitado, inclusive <enter>, fica depositado
    printf("PAR OU IMPAR");                         // numa região chamada "buffer do teclado". O computador só espera essa
    do                                              // digitação se o buffer estiver vazio.
    {
        printf("\n\nDigite um numero seguido de <enter>: ");    // " n%2 == 0 " lê-se: resto da divisão de n por 2 é 0.
        scanf("%d%c", &n, &lixo);      // ->        // Depois da leitura para " n " e " c ", o <enter> fica no buffer e será usado
        if(n%2 == 0)                                // na próxima leitura.
            printf("\t%d eh par", n);               // Nos dois scanf's, o <enter> será lido e guardado na variável " lixo ".
        else
            printf("\t%d eh impar", n);
        printf("\n\nVerificar paridade? (s/n): ");
        scanf("%c%c", &c, &lixo);      // ->        // Se a variável " lixo " não fosse usada, o <enter> do primeiro scanf seria
    }                                               // lido para a variável " c ", no segundo scanf.
    while(c == 's' || c == 'S');                    // Aí o " do-while " se encerraria sem nova digitação para a variável " c ".
    printf("\n\n"); system("pause"); return 0;
}
