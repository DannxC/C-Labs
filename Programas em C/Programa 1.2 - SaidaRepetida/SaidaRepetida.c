#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i; //int i: �i� � uma vari�vel inteira  OBS: � necess�rio declarar a vari�vel, caso contr�rio, ela n�o ser� reconhecida!
    i=1;  //Vari�vel: nome ao qual est� associado um local na mem�ria, cujo valor pode ser alterado durante a execu��o
    while(i<=5)
    {
        printf("Ola pessoal!\n");
        i=i+1;
    }
    printf("\n\n");
    system("pause");
    return 0;
}
