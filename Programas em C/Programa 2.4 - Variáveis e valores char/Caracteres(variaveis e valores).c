#include <stdio.h>
#include <stdlib.h>

int main ()
{
    char c;                         //Variável do tipo caractere: destina-se a guardar um caractere num dado momento
    printf("Digite uma tecla: ");
    scanf("%c", &c);                //A variável ‘c’ recebe a representação interna do caractere correspondente a essa tecla
    printf("decimal=%d, caractere=%c", c, c); //Nesse caso, o %d associado a uma variavel do tipo "char" serve para indicar,
    printf("\n\n"); system("pause");          //no alfabeto utilizado, qual a "coordenada" que esse "char" está ligada. De
    return 0;                                 //acordo com o ASCII, por exemplo, um decimal está associado a cada caractere
}                                             //EX: ASCII('K')=75 ; ASCII('&')=38 ; ASCII('{')=123
                                              //Em suma, esses valores decimais são as representações internas dos caracteres
/*/Caractere é um símbolo de grafia

Exemplos de caracteres:

Letras maiúsculas e minúsculas: A, B, ... , Z, a, b, ... , z
Dígitos decimais: 0, 1, 2, ... , 8, 9
Operadores aritméticos: +, -, *, /
Separadores: (, ), [, ], {, }
Caracteres de pontuação: .  ,  ;  !  ?  :
Caracteres especiais: @, #, $, %, &
Caracteres de controle: muda linha (nl), tabulação (ht), etc/*/
