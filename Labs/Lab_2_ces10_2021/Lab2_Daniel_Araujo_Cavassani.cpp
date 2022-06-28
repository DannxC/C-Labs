#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
    int x, m, n;                                                        //m é o limite inferior, n é o limite superior
    printf("Digite os limites inferior e superior: ");
    scanf("%d%d", &m, &n);
    printf("\n\t***********************************************************************");  //início da moldura
    printf("\n\t*       x *   x^4-20x^2+5 *       sen(x) *                  x^7/ln(x) *");
    printf("\n\t* ------------------------------------------------------------------- *");
    x=m;
    while(x<=n)
    {
        printf("\n\t*    %4d *  %12d *   %10.7f * ", x, x*x*x*x-20*x*x+5, sin(x*3.14159/180));  //para a função seno, x é visto em graus!
        if(x<=1)
            printf("                %10s *", "----------");             //condição de existencia da ultima coluna da tabela!
        else                                                            //lembrar que, para x inteiro, x>=2 é a CE
            printf(" %25.7f *", pow(x, 7)/log(x));
        x=x+1;
    }
    printf("\n\t***********************************************************************");  //fim da moldura
    printf("\n\n");
    system("pause");
    return 0;
}
