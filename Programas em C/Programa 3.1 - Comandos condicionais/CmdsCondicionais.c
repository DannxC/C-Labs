#include <stdio.h>
#include <stdlib.h>

int main()
{
    char estahfrio;
    printf("Estah frio? (s/n): ");
    scanf("%c", &estahfrio);
    if(estahfrio == 's' || estahfrio == 'S') // " == " � usado para comparar dois valores!
        printf("\n\tVista seu casaco!!");    // lembrando que o " = " � usado para atribuir uma express�o a uma vari�vel...
    else                                     // " || " � o operador " or ", entre duas condi��es.
        printf("\n\tDeixe seu casaco no guarda-roupas!!");  // OBS: " && " � o operador " and " entre duas condi��es!
    printf("\n\n"); system("pause");
    return 0;
}
