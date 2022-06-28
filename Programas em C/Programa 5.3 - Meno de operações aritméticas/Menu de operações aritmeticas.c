/*************************************
 *  Programa que oferece um menu de  *
 *  operacoes aritmeticas            *
 *************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*  Cabecalho, declaracoes e oferecimento de servico  */

int main ()
{       // Inicio da funcao main
 	char c, opcao, lixo; float n1, n2, result;
  	printf("C A L C U L O S    A R I T M E T I C O S");
 	printf("\n\nResolver algum calculo (s/n)? ");
	scanf("%c%c", &c, &lixo);
 	while(c == 's' || c == 'S')
    {
/*  Apresentacao de um menu de calculos aritmeticos  */

		printf("\n\nDigitar:");
 		printf("\n\n\tS ou s para soma");
    	printf("\n\tT ou t para subtracao");
     	printf("\n\tM ou m para multiplicacao");
    	printf("\n\tD ou d para divisao");
     	printf("\n\tQ ou q para elevar ao quadrado");
     	printf("\n\tR ou r para extrair a raiz quadrada");
     	printf("\n\nSua opcao: "); scanf ("%c%c", &opcao, &lixo);

        switch (opcao)
        {
            case 'S': case 's':  // Soma de 2 numeros
                printf("\n\tDigite os operandos: ");
                scanf("%f%f%c", &n1, &n2, &lixo);
                result = n1 + n2;
                printf("\n\tResultado: %g", result);
                break;
            case 'T': case 't': // Subtracao entre 2 numeros
                printf("\n\tDigite os operandos: ");
                scanf("%f%f%c", &n1, &n2, &lixo);
                result = n1 - n2;
                printf("\n\tResultado: %g", result);
                break;
            case 'M': case 'm': // Multiplicacao de 2 numeros
                printf("\n\tDigite os operandos: ");
                scanf("%f%f%c", &n1, &n2, &lixo);
                result = n1 * n2;
                printf("\n\tResultado: %g", result);
                break;
            case 'D': case 'd':  // Divisao entre 2 numeros
                printf("\n\tDigite os operandos: ");
                scanf("%f%f%c", &n1, &n2, &lixo);
                if(n2 == 0)
                    printf("\n\tErro: tentativa de divisao por zero");
                else
                {
                    result = n1 / n2;
                    printf("\n\tResultado: %g", result);
                }
                break;
            case 'Q': case 'q':  // Quadrado de um numero
                printf("\n\tDigite o operando: ");
                scanf("%f%c", &n1, &lixo);
                result = n1 * n1;
                printf("\n\tResultado: %g", result);
                break;
            case 'R': case 'r':  // Raiz quadrada de um numero
                printf("\n\tDigite o operando: ");
                scanf("%f%c", &n1, &lixo);
                if(n1 < 0)
                    printf("\n\tErro: sqrt de numero negativo");
                else
                {
                    result = sqrt (n1);
                    printf("\n\tResultado: %g", result);
                }
                break;
            default:         // Erro na digitacao da opcao
                printf("\n\tErro na opcao");
        }
        /*  Novo oferecimento de servico  */

 		printf("\n\nResolver outro calculo (s/n)? ");
    	scanf("%c%c", &c, &lixo);
	}

/*  Fechamento da tela  */

 	printf ("\n\n"); system ("pause"); return 0;

}       //Fim da funcao main

