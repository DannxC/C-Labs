#include <stdio.h>
#include <stdlib.h>

/* Definições de variaveis */

typedef struct matquadrada matquadrada;
struct matquadrada
{
    int n;
    double elem[10][10];
};

/* Variaveis globais */

int S[10], M[10], k;

/* Declarações */

void LerMatQuadrada(matquadrada *);
void EscreverMatQuadrada(matquadrada *);
matquadrada MenorComplementar(matquadrada *, int, int);
double Det(matquadrada *);

/* Função main */

int main()
{
    matquadrada A;
    printf("Calculo de determinante com instrumentacao\n");
    for(k = 0; k < 10; k++)
    {
        A.n = k + 1;
        S[k] = M[k] = 0;
        LerMatQuadrada(&A);
        printf("\nMatriz com dimensao %d:\n", k + 1);
        EscreverMatQuadrada(&A);
        printf("Valor do determinante: %20.0lf\n", Det(&A));
    }
    printf("\nNumeros de somas+subtracoes e multiplicacoes:\n\n");
    for(k = 0; k < 10; k++)
        printf("Dimensao:%4d%13d somas+subtracoes%9d multiplicacoes\n", k + 1, S[k], M[k]);
    printf("\n\n"); system("pause"); return 0;
}

/* Função LerMatQuadrada: Le do arquivo de entrada (matriz 10x10) uma matriz quadrada de dimensao nxn a partir da 10x10 */

void LerMatQuadrada(matquadrada *Mat)
{
    int i, j; char x;
    FILE *ff;
    ff = fopen("input.txt", "r");
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

/* Função EscreverMatQuadrada: Serve para escrever no arquivo de saida a matriz quadrada escolhida */

void EscreverMatQuadrada(matquadrada *Mat)
{
    int i, j;
    for(i = 0; i <= (*Mat).n - 1; i++)
    {
        printf("|");
        for(j = 0; j <= (*Mat).n - 1; j++)
            printf("%5.0lf", (*Mat).elem[i][j]);
        printf("|\n");
    }
}

/* Função MenorComplementar: Calcula o menor complementar (i, j) da matriz quadrada dada */

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

/* Função Det: Calcula o determinante de uma matriz quadrada qualquer (por laplace recursivo) */

double Det(matquadrada *A)
{
    double d; int i;
    matquadrada B;
    if((*A).n < 1)
        d = -999999999;
    else if((*A).n == 1)
        d = (*A).elem[0][0];
    else if((*A).n == 2)
    {
        d = (*A).elem[0][0] * (*A).elem[1][1] - (*A).elem[1][0] * (*A).elem[0][1];
        S[k] += 1;
        M[k] += 2;
    }
    else if((*A).n == 3)
    {
        d = (*A).elem[0][0] * (*A).elem[1][1] * (*A).elem[2][2] + (*A).elem[0][1] * (*A).elem[1][2] * (*A).elem[2][0] + (*A).elem[0][2] * (*A).elem[1][0] * (*A).elem[2][1] - (*A).elem[0][1] * (*A).elem[1][0] * (*A).elem[2][2] - (*A).elem[0][0] * (*A).elem[1][2] * (*A).elem[2][1] - (*A).elem[0][2] * (*A).elem[1][1] * (*A).elem[2][0];
        S[k] += 5;
        M[k] += 12;
    }
    else
        for(d = 0, i = 0; i < (*A).n; i++)
        {
            B = MenorComplementar(A, 1, i + 1);
            if(i % 2 == 0)
                d += (*A).elem[0][i] * Det(&B);
            else
                d -= (*A).elem[0][i] * Det(&B);
            S[k] += 1;
            M[k] += 1;
        }
    return d;
}
