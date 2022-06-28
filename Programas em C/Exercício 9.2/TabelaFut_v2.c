#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Declarações: sobre um time e sobre uma tabela de times; sobre os resultados dos jogos */

typedef char cadeia[31];

typedef struct time time;
struct time
{
    cadeia nome;
    int pontos, vitorias, golspro, golscontra, saldogols;
};

typedef struct tabelatimes tabelatimes;
struct tabelatimes
{
    time VetorTimes[30];
    int ntimes;
};

typedef struct resultado resultado;
struct resultado
{
    int local, visitante;
};

/* Variaveis Globais */

tabelatimes TabTimes;
resultado Jogos[30][30];
FILE *filein, *fileout;

/* Prototipo das funções auxiliares */

void InicializarArquivos(void);
void LerArmazenarTimes(void);
void EscreverTimes(void);
void LerArmazenarJogos(void);
void EscreverJogos(void);
void PreencherTabTimes(void);
void EscreverTabTimes(void);

/* Função main: Abre e inicializa os arquivos de entrada e saída, le os times, armazenando-os, e escreve o conteudo da tabela de times;
   Além disso, lê, armazena e escreve os dados da matriz Jogos */

int main()
{
    InicializarArquivos();
    LerArmazenarTimes();
    EscreverTimes();
    LerArmazenarJogos();
    EscreverJogos();
    PreencherTabTimes(); //Falta
    EscreverTabTimes();
    printf("\n\n"); system("pause"); return 0;
}

/* Função InicializarArquivos: escreve avisos no video, abre os arquivos de entrada e saida e escreve titulo no arquivo de saida */

void InicializarArquivos()
{
    printf("RESULTADOS DE UM CAMPEONATO\n\n");
    printf("Entrada de dados no arquivo <CampeonatoEntrada.txt>\n\n");
    printf("Relatorio dos Resultados no arquivo <CampeonatoSaida.txt>\n\n");
    filein = fopen("CampeonatoEntrada.txt", "r");
    fileout = fopen("CampeonatoSaida.txt", "w");
    fprintf(fileout, "R E S U L T A D O S  D E  U M  C A M P E O N A T O\n\n");
}

/* Função LerArmazenarTimes: le os times do campeonato e os armazena na tabela de times, inicializando os dados sobre eles */

void LerArmazenarTimes()
{
    int i, len; char lixo;
    fscanf(filein, "%d%c", &TabTimes.ntimes, &lixo);
    for(i = 0; i <= TabTimes.ntimes - 1; i++)
    {
        fgets(TabTimes.VetorTimes[i].nome, 25, filein);
        len = strlen(TabTimes.VetorTimes[i].nome);
        TabTimes.VetorTimes[i].nome[len-1] = '\0';
        TabTimes.VetorTimes[i].pontos = TabTimes.VetorTimes[i].vitorias = TabTimes.VetorTimes[i].golspro = TabTimes.VetorTimes[i].golscontra = TabTimes.VetorTimes[i].saldogols = 0;
    }
}

/* Função EscreverTimes: escrever somente os times da Tabela de Times */

void EscreverTimes()
{
    int i;
    fprintf(fileout, "Listagem dos times:\n");
    fprintf(fileout, "\n                  Time\n----------------------");
    for(i = 0; i < TabTimes.ntimes; i++)
        fprintf(fileout, "\n%22s", TabTimes.VetorTimes[i].nome);
}

/* Funão LerArmazenarJogos: le os resultados dos jogos entre os times e os armazena na Matriz correspondente aos Jogos */

void LerArmazenarJogos()
{
    int i, j; char lixo;
    for(i = 0; i < TabTimes.ntimes; i++)
        for(j = 0; j < TabTimes.ntimes; j++)
            if(i != j)
                fscanf(filein, "%d%d", &Jogos[i][j].local, &Jogos[i][j].visitante);
}

/* Função EscreverJogos: escreve os jogos (a matriz) no arquivo de saida */

void EscreverJogos()
{
    int i, j;
    fprintf(fileout, "\n\nResultados dos jogos:\n\n");

    /* Cabeçalho da tabela */

    fprintf(fileout, "                          Ale     Bra     Est     Gra     Arg \n");

    /* Escrita de informações sobre os jogos */

    for(i = 0; i < TabTimes.ntimes; i++)
    {
        fprintf(fileout, "%22s", TabTimes.VetorTimes[i].nome);
        for(j = 0; j < TabTimes.ntimes; j++)
        {
            if(i == j)
                fprintf(fileout, "   #####");
            else
                fprintf(fileout, "   %d x %d", Jogos[i][j].local, Jogos[i][j].visitante);
        }
        fprintf(fileout, "\n");
    }
}

/* Função PreencherTabTimes: Alocar corretamente os valores para preencher a tabela de times */

void PreencherTabTimes()
{
    int i, j;
    for(i = 0; i < TabTimes.ntimes; i++)
        for(j = 0; j < TabTimes.ntimes; j++)
            if(i != j)
            {
                TabTimes.VetorTimes[i].golspro += Jogos[i][j].local;
                TabTimes.VetorTimes[j].golspro += Jogos[i][j].visitante;
                TabTimes.VetorTimes[i].golscontra += Jogos[i][j].visitante;
                TabTimes.VetorTimes[j].golscontra += Jogos[i][j].local;
                if(Jogos[i][j].local > Jogos[i][j].visitante)
                {
                    TabTimes.VetorTimes[i].pontos += 3;
                    TabTimes.VetorTimes[i].vitorias++;
                }
                else if(Jogos[i][j].local == Jogos[i][j].visitante)
                {
                    TabTimes.VetorTimes[i].pontos++;
                    TabTimes.VetorTimes[j].pontos++;
                }
                else
                {
                    TabTimes.VetorTimes[j].pontos += 3;
                    TabTimes.VetorTimes[j].vitorias++;
                }
        }
        for(i = 0; i < TabTimes.ntimes; i++)
            TabTimes.VetorTimes[i].saldogols = TabTimes.VetorTimes[i].golspro - TabTimes.VetorTimes[i].golscontra;
}

/* Função EscreverTabTimes: escreve todo o conteudo da tabela de times */

void EscreverTabTimes()
{
    int i;
    fprintf(fileout, "\nTabela de desempenho dos times:\n\n");

    /* Cabeçalho da tabela */

    fprintf(fileout, "%22s | %9s | %9s | %9s | %9s | %9s\n", "Time", "Pontos", "Vitorias", "G Pro", "G Contra", "Saldo G");
    fprintf(fileout, "----------------------------------------------------------------------------------\n");

    /* Escrita de informações sobre os times */

    for(i = 0; i <= TabTimes.ntimes - 1; i++)
        fprintf(fileout, "%22s | %9d | %9d | %9d | %9d | %9d\n", TabTimes.VetorTimes[i].nome, TabTimes.VetorTimes[i].pontos, TabTimes.VetorTimes[i].vitorias, TabTimes.VetorTimes[i].golspro, TabTimes.VetorTimes[i].golscontra, TabTimes.VetorTimes[i].saldogols);
}
