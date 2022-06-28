#include <stdio.h>
#include <stdlib.h>

int main ()
{
    char testar, lixo; int dvdo, dsor;
    printf("DIVISIBILIDADE POR 7");
    printf("\n\nTestar divisibilidade? (s/n): ");
    scanf("%c%c", &testar, &lixo);
    while(testar == 's' || testar == 'S')
    {
        printf("\n\tDigite o dividendo e o divisor seguido de <enter>: ");
        scanf("%d%d%c", &dvdo, &dsor, &lixo);
        while(dsor == 0)
        {
            printf("\n\tDigite novamente o divisor seguido de <enter>: ");
            scanf("%d%c", &dsor, &lixo);
        }
        if(dvdo % 7 == 0)
            printf("%d eh divisivel por %d", dvdo, dsor);
        else
            printf("%d nao eh divisivel por %d", dvdo, dsor);
        printf("\n\nTestar divisibilidade? (s/n): ");
        scanf("%c%c", &testar, &lixo);
    }
    printf("\n\n"); system("pause"); return 0;
}
