#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Declaracoes do tipo logic e do tipo cadeia de caracteres */

typedef char logic;
const logic True = 1, False = 0;
typedef char cadeia[30];

/* Declaracoes da struct numero */

typedef struct numero numero;
struct numero
{
    cadeia valnabase;
    int base, valdecimal;
    logic valido;
};

/* Declaracoes da struct tabela */

typedef struct tabela tabela;
struct tabela
{
    numero VetNum[51]; int ntab, soma; logic existe;
};

/* Funcao main, declaracoes, e abertura dos arquivos input e output */

int main()
{
    numero num; tabela TabNum; int n, h, i, j; char bases[20] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    FILE *FileIn, *FileOut;
    FileIn = fopen("input.txt", "r");
    FileOut = fopen("output.txt", "w");

/* Leitura, no arquivo "input.txt", da quantidade de pares numeros-base, dos numeros e das bases */

    fscanf(FileIn, "%d", &TabNum.ntab);
    for(h = 0; h < TabNum.ntab; h++)
    {
        fscanf(FileIn, " %s%d", num.valnabase, &num.base);

/* Verificacao da correcao da base (validade do numero) */

        for(i = 0, num.valido = True; i < strlen(num.valnabase) && num.valido == True; i++)
            for(j = 0, num.valido = False; j < num.base; j++)
                if(num.valnabase[i] ==  bases[j])
                {
                    num.valido = True;
                    break;
                }

/* Calculo do valor em decimal de um numero correto */

        if(num.valido == True)
            for(i = 0, num.valdecimal = 0; i < strlen(num.valnabase); i++)
                for(j = 0; j < num.base; j++)
                    if(num.valnabase[i] == bases[j])
                    {
                        num.valdecimal = num.base*num.valdecimal + j;
                        break;
                    }

/* Guardar os valores lidos na variavel do tipo tabela */

        TabNum.VetNum[h] = num;
    }

/* Escrita, no arquivo "output.txt", da tabela */

    fprintf(FileOut, "C O N V E R S O E S  D E  B A S E S  P A R A  A  B A S E  10");
    fprintf(FileOut, "\n\nForam realizadas %d conversoes:\n", TabNum.ntab);
    for(i = 0; i < TabNum.ntab; i++)
    {
        if(TabNum.VetNum[i].valido == True)
            fprintf(FileOut, "\n(%s)%d = (%d)10", TabNum.VetNum[i].valnabase, TabNum.VetNum[i].base, TabNum.VetNum[i].valdecimal);
        else
            fprintf(FileOut, "\n(%s)%d = Dados incompativeis", TabNum.VetNum[i].valnabase, TabNum.VetNum[i].base);
    }

/* Verificando se existe ou nao a soma de numeros validos (isto eh, se ha ao menos um numero valido */

    for(i = 0, TabNum.existe == False; i < TabNum.ntab; i++)
        if(TabNum.VetNum[i].valido == True)
        {
            TabNum.existe = True;
            break;
        }

/* Calculo da soma dos valores decimais dos numeros validos, bem como sua impressao no final da tabela */

    if(TabNum.existe == True)
    {
        for(i = 0, TabNum.soma = 0; i < TabNum.ntab; i++)
            if(TabNum.VetNum[i].valido == True)
                TabNum.soma += TabNum.VetNum[i].valdecimal;
        fprintf(FileOut, "\n\nSoma dos numeros validos: (%d)10", TabNum.soma);
    }
    else
        fprintf(FileOut, "\n\nSoma dos numeros validos: nao existem numeros validos");

/* Fechamento dos arquivos e Encerramento do programa */

    fclose(FileIn);
    fclose(FileOut);
    printf("\n\n\n"); system("pause"); return 0;
}
