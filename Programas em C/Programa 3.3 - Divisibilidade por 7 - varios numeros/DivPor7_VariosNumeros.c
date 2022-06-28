#include <stdio.h>
#include <stdlib.h>

int main ()
{
    char testar, lixo; int dvdo;
    printf("DIVISIBILIDADE POR 7");
    printf("\n\nTestar divisibilidade? (s/n): ");
    scanf("%c%c", &testar, &lixo);
    while(testar == 's' || testar == 'S')
    {
        printf("\n\tDigite o dividendo seguido de <enter>: ");
        scanf("%d%c", &dvdo, &lixo);
        if(dvdo % 7 == 0)
            printf("%d eh divisivel por 7", dvdo);
        else
            printf("%d nao eh divisivel por 7", dvdo);
        printf("\n\nTestar divisibilidade? (s/n): ");
        scanf("%c%c", &testar, &lixo);
    }
    printf("\n\n"); system("pause"); return 0;
}
