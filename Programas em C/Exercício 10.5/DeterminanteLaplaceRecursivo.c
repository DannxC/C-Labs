#include <stdio.h>
#include <stdlib.h>

/* Defini��es de variaveis */

typedef struct matquadrada matquadrada;
struct matquadrada
{
    int n;
    double elem[10][10];
};

/* Declara��es */

void LerMatQuadrada(matquadrada *);
void EscreverMatQuadrada(matquadrada *);
matquadrada MenorComplementar(matquadrada *, int, int);
double Det(matquadrada *);

/* Fun��o main */

int main()
{
    matquadrada A;
    LerMatQuadrada(&A);
    printf("\nMatriz A:\n\n");
    EscreverMatQuadrada(&A);
    printf("\nDeterminante de A: %.3lf", Det(&A));
    printf("\n\n"); system("pause"); return 0;
}

/* Fun��o LerMatQuadrada: Le do arquivo de entrada (matriz 10x10) uma matriz quadrada de dimensao nxn a partir da 10x10 */

void LerMatQuadrada(matquadrada *Mat)
{
    int i, j; char x;
    FILE *ff;
    ff = fopen("input.txt", "r");
    printf("Digite a dimensao n da matriz (1 <= n <= 10): ");
    scanf("%d", &(*Mat).n);
    for(i = 0; i <= (*Mat).n - 1; i++)
    {
        for(j = 0; j <= (*Mat).n - 1; j++)
            fscanf(ff, "%lf", &(*Mat).elem[i][j]);
        do
            fscanf(ff, "%c", &x);
        while(x != '\n');
    }
    fclose(ff);
}

/* Fun��o EscreverMatQuadrada: Serve para escrever no arquivo de saida a matriz quadrada escolhida */

void EscreverMatQuadrada(matquadrada *Mat)
{
    int i, j;
    for(i = 0; i <= (*Mat).n - 1; i++)
    {
        printf("\t");
        for(j = 0; j <= (*Mat).n - 1; j++)
            printf(" %5.0lf", (*Mat).elem[i][j]);
        printf("\n");
    }
}

/* Fun��o MenorComplementar: Calcula o menor complementar (i, j) da matriz quadrada dada */

matquadrada MenorComplementar(matquadrada *C, int i, int j)
{
    matquadrada D;
    int p, q;
    D.n = (*C).n - 1;
    for(p = 0; p <= (*C).n - 1; p++)
    {
        if(p < i - 1)
            for(q = 0; q <= (*C).n - 1; q++)
            {
                if(q < j - 1)
                    D.elem[p][q] = (*C).elem[p][q];
                else if(q > j - 1)
                    D.elem[p][q - 1] = (*C).elem[p][q];
            }
        else if(p > i - 1)
            for(q = 0; q <= (*C).n - 1; q++)
            {
                if(q < j - 1)
                    D.elem[p - 1][q] = (*C).elem[p][q];
                else if(q > j - 1)
                    D.elem[p - 1][q - 1] = (*C).elem[p][q];
            }
    }
    return D;
}

/* Fun��o Det: Calcula o determinante de uma matriz quadrada qualquer (por laplace recursivo) */

double Det(matquadrada *A)
{
    double d; int i;
    matquadrada B;
    if((*A).n < 1)
        d = -999999999;
    else if((*A).n == 1)
        d = (*A).elem[0][0];
    else if((*A).n == 2)
        d = (*A).elem[0][0] * (*A).elem[1][1] -(*A).elem[1][0] * (*A).elem[0][1];
    else if((*A).n == 3)
        d = (*A).elem[0][0] * (*A).elem[1][1] * (*A).elem[2][2] + (*A).elem[0][1] * (*A).elem[1][2] * (*A).elem[2][0] + (*A).elem[0][2] * (*A).elem[1][0] * (*A).elem[2][1] - (*A).elem[0][1] * (*A).elem[1][0] * (*A).elem[2][2] - (*A).elem[0][0] * (*A).elem[1][2] * (*A).elem[2][1] - (*A).elem[0][2] * (*A).elem[1][1] * (*A).elem[2][0];
    else
        for(d = 0, i = 0; i < (*A).n; i++)
        {
            B = MenorComplementar(A, 0, i + 1);
            if(i % 2 == 0)
                d += (*A).elem[0][i] * Det(&B);
            else
                d -= (*A).elem[0][i] * Det(&B);
        }
    return d;
}
