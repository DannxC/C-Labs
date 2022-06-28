#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i; //int i: ‘i’ é uma variável inteira  OBS: é necessário declarar a variável, caso contrário, ela não será reconhecida!
    i=1;  //Variável: nome ao qual está associado um local na memória, cujo valor pode ser alterado durante a execução
    while(i<=5)
    {
        printf("Ola pessoal!\n");
        i=i+1;
    }
    printf("\n\n");
    system("pause");
    return 0;
}
