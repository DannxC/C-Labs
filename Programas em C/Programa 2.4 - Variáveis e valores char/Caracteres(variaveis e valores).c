#include <stdio.h>
#include <stdlib.h>

int main ()
{
    char c;                         //Vari�vel do tipo caractere: destina-se a guardar um caractere num dado momento
    printf("Digite uma tecla: ");
    scanf("%c", &c);                //A vari�vel �c� recebe a representa��o interna do caractere correspondente a essa tecla
    printf("decimal=%d, caractere=%c", c, c); //Nesse caso, o %d associado a uma variavel do tipo "char" serve para indicar,
    printf("\n\n"); system("pause");          //no alfabeto utilizado, qual a "coordenada" que esse "char" est� ligada. De
    return 0;                                 //acordo com o ASCII, por exemplo, um decimal est� associado a cada caractere
}                                             //EX: ASCII('K')=75 ; ASCII('&')=38 ; ASCII('{')=123
                                              //Em suma, esses valores decimais s�o as representa��es internas dos caracteres
/*/Caractere � um s�mbolo de grafia

Exemplos de caracteres:

Letras mai�sculas e min�sculas: A, B, ... , Z, a, b, ... , z
D�gitos decimais: 0, 1, 2, ... , 8, 9
Operadores aritm�ticos: +, -, *, /
Separadores: (, ), [, ], {, }
Caracteres de pontua��o: .  ,  ;  !  ?  :
Caracteres especiais: @, #, $, %, &
Caracteres de controle: muda linha (nl), tabula��o (ht), etc/*/
