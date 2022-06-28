#include <stdio.h>  //A função "printf" pertence a esse arquivo da biblioteca C
#include <stdlib.h>  //A função "system" pertence a esse arquivo da biblioteca C

int main ()
{
    printf("Ola Pessoal!\n");  //Escreve no vídeo o que estiver entre aspas ("----"), exceto as aspas
    printf("Ola Pessoal!");  //Sem o \n na linha anterior, ele escreveria "Ola Pessoal!Ola Pessoal!", sem pular linha
    printf("\n\n");  //Para cada \n, o cursor do video vai para o início da linha seguinte
    system("pause");  //Emite a mensagem “Pressione qualquer tecla para continuar …” e fica esperando a digitação
    return(0);
}
