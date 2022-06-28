#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
	int x, m, n;
	printf ("Digite os limites inferior e superior da tabela: ");
	scanf ("%d%d", &m, &n);
	printf ("\n   x        sqrt(x)");
   	printf ("\n---------------------");
	x = m;
	while (x <= n) {
   		if (x >= 0)
			printf ("\n%4d%15.8f", x, sqrt(x));
      	else
            		printf ("\n%4d%15s", x, "----------");
		x = x + 1;
	}
	printf ("\n\n"); system ("pause"); return 0;
}
