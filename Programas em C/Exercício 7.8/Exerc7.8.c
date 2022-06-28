#include <stdio.h>
#include <stdlib.h>

int main()
{

/* Declaracoes de variaveis e atribuicao dos arquivos de entrada e saida */

    int A[10][10], B[10][10], m, n, i, j, x, y, cont[10], menor[10], impar[10]; float aux, MedQuad[10];
    FILE *FileIn, *FileOut;
    FileIn = fopen("Matriz.txt", "r");
    FileOut = fopen("MatrizSaida.txt", "w");

/* Escrita amigavel em video-texto */

    printf("Informacoes sobre matriz:");
    printf("\n\n\tMatriz de entrada no arquivo Matriz");
    printf("\n\n\tMatriz de saida no arquivo MatrizSaida");

/* Utilizando-se do arquivo de entrada: dimensionamento das matrizes A e B; e leitura dos elementos de A */

    fscanf(FileIn, "%d%d", &m, &n);
    for(i = 0; i <= m-1; i++)
        for(j = 0; j <= n-1; j++)
            fscanf(FileIn, "%d", &A[i][j]);

/* Montagem da tabela: elementos de A; media dos quadrados dos elementos de cada linha; quantidade de termos impares de cada linha */

    fprintf(FileOut, "Matriz A:\n\n");
    fprintf(FileOut, "                                              Elementos |   MedQuad | Impares\n");
    fprintf(FileOut, "--------------------------------------------------------|-----------|--------");
    for(i = 0; i <= m-1; i++)
    {
        fprintf(FileOut, "\nLinh: %d", i);
        for(j = 0, aux = 0, impar[i] = 0; j <= n-1; j++)
        {
            fprintf(FileOut, "%8d", A[i][j]);
            aux += A[i][j] * A[i][j];           //Variavel auxiliar para o calculo da media dos quadrados
            if(abs(A[i][j]) % 2 == 1)           //Contagem dos termos impares
                impar[i]++;
        }
        MedQuad[i] = aux/n;                     //Media dos quadrados
        fprintf(FileOut, " |%10.2f |%8d", MedQuad[i], impar[i]);        //Escrita no arquivo de saida
    }
    fprintf(FileOut, "\n");
    fprintf(FileOut, "--------------------------------------------------------|-----------|--------");      //Fim da montagem da primeira parte da tabela

/* Continuacao da tabela */

/* Quantidade de termos maiores que zero por coluna */

    fprintf(FileOut, "\n> Zero:");
    for(j = 0; j <= n-1; j++)
    {
        for(i = 0, cont[j] = 0; i <= m-1; i++)
        {
            if(A[i][j] > 0)
                cont[j]++;
        }
        fprintf(FileOut, "%8d", cont[j]);       //Escrita no arquivo de saida
    }

/* Menor elemento de cada coluna */

    fprintf(FileOut, "\nMenor :");
    for(j = 0; j <= n-1; j++)
    {
        for(i = 0, menor[j] = A[0][j]; i <= m-1; i++)
            if(A[i][j] < menor[j])
                menor[j] = A[i][j];
        fprintf(FileOut, "%8d", menor[j]);      //Escrita no arquivo de saida
    }

/* Calculo dos elementos de B */

    for(i = 0; i <= m-1; i++)
        for(j = 0; j <= n-1; j++)
        {
            for(x = 0, aux = 0; x <= m-1; x++)
                for(y = 0; y <= n-1; y++)
                    if(abs(x - i) == abs(y - j))    //Condicao para somar os elementos das duas diagonais
                        aux += A[x][y];             //Variavel auxiliar para o calculo dos elementos de B
            B[i][j] = aux;
        }

/* Escrita de B no arquivo de saida */

    fprintf(FileOut, "\n\n\nMatriz B:\n\n");
    fprintf(FileOut, "                                              Elementos");
    fprintf(FileOut, "\n-------------------------------------------------------");
    for(i = 0; i <= m-1; i++)
    {
        fprintf(FileOut, "\nLinh: %d", i);
        for(j = 0, aux = 0, impar[i] = 0; j <= n-1; j++)
            fprintf(FileOut, "%8d", B[i][j]);
    }
    fprintf(FileOut, "\n-------------------------------------------------------");

/* Fim da execucao do programa */

    printf("\n\n"); system("pause"); return 0;
}
