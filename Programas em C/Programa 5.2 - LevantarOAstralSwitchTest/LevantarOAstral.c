#include <stdio.h>
#include <stdlib.h>

int main ()
{
	char c, lixo; int n;
	printf ("Levantar o astral? (s/n): "); scanf ("%c", &c);
  	for(; c == 's' || c == 'S'; scanf ("%c", &c))
  	{
		printf ("\n\tDigite um numero de 1 a 7: "); scanf ("%d%c", &n, &lixo);
		switch (n)                                                      //switch(n) faz com que vc escolha, dentre algumas
		{                                                               //possibilidades, para continuar um comando.
   			case 1: printf("\n\tVoce eh inteligente"); break;
			case 2: printf("\n\tVoce eh campeao"); break;
			case 3: printf("\n\tVoce estah com tudo"); break;
			case 4: printf("\n\tSeu destino eh vencer"); break;
			case 5: printf("\n\tTudo coopera para seu sucesso"); break;
			case 6: printf("\n\tA vida sorri para voce"); break;
			case 7: printf("\n\tNada pode impedir sua vitoria"); break;
			default: printf("\n\tO numero deve ser de 1 a 7");
		}
		printf ("\n\nLevantar o astral? (s/n): ");
	}
    	printf ("\n\n"); system ("pause"); return 0;
}
