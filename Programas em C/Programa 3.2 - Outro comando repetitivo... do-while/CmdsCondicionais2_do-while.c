#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n; char c, lixo;               // ->        // Para o scanf, tudo o que � digitado, inclusive <enter>, fica depositado
    printf("PAR OU IMPAR");                         // numa regi�o chamada "buffer do teclado". O computador s� espera essa
    do                                              // digita��o se o buffer estiver vazio.
    {
        printf("\n\nDigite um numero seguido de <enter>: ");    // " n%2 == 0 " l�-se: resto da divis�o de n por 2 � 0.
        scanf("%d%c", &n, &lixo);      // ->        // Depois da leitura para " n " e " c ", o <enter> fica no buffer e ser� usado
        if(n%2 == 0)                                // na pr�xima leitura.
            printf("\t%d eh par", n);               // Nos dois scanf's, o <enter> ser� lido e guardado na vari�vel " lixo ".
        else
            printf("\t%d eh impar", n);
        printf("\n\nVerificar paridade? (s/n): ");
        scanf("%c%c", &c, &lixo);      // ->        // Se a vari�vel " lixo " n�o fosse usada, o <enter> do primeiro scanf seria
    }                                               // lido para a vari�vel " c ", no segundo scanf.
    while(c == 's' || c == 'S');                    // A� o " do-while " se encerraria sem nova digita��o para a vari�vel " c ".
    printf("\n\n"); system("pause"); return 0;
}
