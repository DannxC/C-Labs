#include <stdio.h>
#include <stdlib.h>

/* Definições de variaveis */

typedef struct matquadrada matquadrada;
struct matquadrada
{
    int n;
    double elem[10][10];
};

/* Declarações */

void LerMatQuadrada(matquadrada *);
void EscreverMatQuadrada(matquadrada *);
matquadrada MenorComplementar(matquadrada *, int, int);

/* Função main */

int main()
{
    matquadrada A, B; int i, j;
    LerMatQuadrada(&A);
    printf("\nMatriz A:\n\n");
    EscreverMatQuadrada(&A);
    printf("\nMatriz Menor Complementar (i, j) de A:\n\n");
    printf("Digite i e j: ");
    scanf("%d%d", &i, &j);
    printf("\n");
    B = MenorComplementar(&A, i, j);
    EscreverMatQuadrada(&B);
    printf("\n\n"); system("pause"); return 0;
}

/* Função LerMatQuadrada: Le do arquivo de entrada (matriz 10x10) uma matriz quadrada de dimensao nxn a partir da 10x10 */

void LerMatQuadrada(matquadrada *Mat)
{
    int i, j; char x;
    FILE *ff;
    ff = fopen("input.txt", "r");
    printf("Digite a dimensao n da matriz (1 <= n <= 10): ");
    scanf("%d", &Mat->n);       //OBS: Mat->n equivale a (*Mat).n ... ambos significam: campo n da estrutura cujo endereço está em Mat
    for(i = 0; i <= Mat->n - 1; i++)
    {
        for(j = 0; j <= Mat->n - 1; j++)
            fscanf(ff, "%lf", &Mat->elem[i][j]);
        do
            fscanf(ff, "%c", &x);
        while(x != '\n');
    }
}

/* Função EscreverMatQuadrada: Serve para escrever no arquivo de saida a matriz quadrada escolhida */

void EscreverMatQuadrada(matquadrada *Mat)
{
    int i, j;
    for(i = 0; i <= Mat->n - 1; i++)
    {
        printf("\t");
        for(j = 0; j <= Mat->n - 1; j++)
            printf(" %5.0lf", Mat->elem[i][j]);
        printf("\n");
    }
}

/* Função MenorComplementar: Calcula o menor complementar (i, j) da matriz quadrada dada */

matquadrada MenorComplementar(matquadrada *C, int i, int j)
{
    matquadrada D;
    int p, q;
    D.n = C->n - 1;
    for(p = 0; p <= C->n - 1; p++)
    {
        if(p < i - 1)
            for(q = 0; q <= C->n - 1; q++)
            {
                if(q < j - 1)
                    D.elem[p][q] = C->elem[p][q];
                else if(q > j - 1)
                    D.elem[p][q - 1] = C->elem[p][q];
            }
        else if(p > i - 1)
            for(q = 0; q <= C->n - 1; q++)
            {
                if(q < j - 1)
                    D.elem[p - 1][q] = C->elem[p][q];
                else if(q > j - 1)
                    D.elem[p - 1][q - 1] = C->elem[p][q];
            }
    }
    return D;
}
