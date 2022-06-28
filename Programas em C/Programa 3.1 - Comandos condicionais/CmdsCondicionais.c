#include <stdio.h>
#include <stdlib.h>

int main()
{
    char estahfrio;
    printf("Estah frio? (s/n): ");
    scanf("%c", &estahfrio);
    if(estahfrio == 's' || estahfrio == 'S') // " == " é usado para comparar dois valores!
        printf("\n\tVista seu casaco!!");    // lembrando que o " = " é usado para atribuir uma expressão a uma variável...
    else                                     // " || " é o operador " or ", entre duas condições.
        printf("\n\tDeixe seu casaco no guarda-roupas!!");  // OBS: " && " é o operador " and " entre duas condições!
    printf("\n\n"); system("pause");
    return 0;
}
