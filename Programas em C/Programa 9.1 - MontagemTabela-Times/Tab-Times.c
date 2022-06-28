#include <stdio.h>
#include <stdio.h>
#include <string.h>

/* Declarações sobre um time e sobre uma tabela de times */

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

/* Variaveis Globais */

tabelatimes TabTimes;
FILE *filein, *fileout;

/* Prototipo das funções auxiliares */

void InicializarArquivos(void);
void LerArmazenasTimes(void);
void EscreverTabTimes(void);

/* Função main: Abre e inicializa os arquivos de entrada e saída, le os times, armazenando-os, e escreve o conteudo da tabela de times */

int main()
{
    InicializarArquivos();
    LerArmazenarTimes();
    EscreverTabTimes();
    printf("\n\n"); system("pause"); return 0;
}

/* Função InicializarArquivos: escreve avisos no video, abre os arquivos de entrada e saida e escreve titulo no arquivo de saida */

void InicializarArquivos()
{
    printf("RESULTADOS DE UM CAMPEONATO\n\n");
    printf("Entrada de dados no arquivo <Campeonato.dat>\n\n");
    printf("Relatoriodos Resultados no arquivo <TabCampeonato.txt>\n\n");
    filein = fopen("Campeonato.txt", "r");
    fileout = fopen("TabCampeonato.txt", "w");
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

/* Função EscreverTabTimes: escreve todo o conteudo da tabela de times */

void EscreverTabTimes()
{
    int i;
    fprintf(fileout, "Tabela de desempenho dos times:\n\n");

/* Cabeçalho da tabela */

    fprintf(fileout, "%22s | %9s | %9s | %9s | %9s | %9s\n", "Time", "Pontos", "Vitorias", "G Pro", "G Contra", "Saldo G");
    fprintf(fileout, "----------------------------------------------------------------------------------\n");

/* Escrita de informações sobre os times */

    for(i = 0; i <= TabTimes.ntimes - 1; i++)
        fprintf(fileout, "%22s | %9d | %9d | %9d | %9d | %9d\n", TabTimes.VetorTimes[i].nome, TabTimes.VetorTimes[i].pontos, TabTimes.VetorTimes[i].vitorias, TabTimes.VetorTimes[i].golspro, TabTimes.VetorTimes[i].golscontra, TabTimes.VetorTimes[i].saldogols);
}
