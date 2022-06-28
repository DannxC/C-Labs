#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Declarações: sobre um time e sobre uma tabela de times; sobre os resultados dos jogos; de uma variável lógica */

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

typedef char logic; const logic True = 1, False = 0;

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
void OrdenarTabTimes(void);
void EscreverClassificacaoFinal(void);
void FecharArquivos(void);

/* Função main: Abre e inicializa os arquivos de entrada e saída, le os times, armazenando-os, e escreve o conteudo da tabela de times;
   Além disso, lê, armazena e escreve os dados da matriz Jogos */

int main()
{
    InicializarArquivos();
    LerArmazenarTimes();
    EscreverTimes();
    LerArmazenarJogos();
    EscreverJogos();
    PreencherTabTimes();
    EscreverTabTimes();
    OrdenarTabTimes();
    EscreverClassificacaoFinal();
    FecharArquivos();
    printf("\n\n"); system("pause"); return 0;
}

/* Função InicializarArquivos: escreve avisos no video, abre os arquivos de entrada e saida e escreve titulo no arquivo de saida */

void InicializarArquivos()
{
    printf("RESULTADOS DE UM CAMPEONATO\n\n");
    printf("Entrada de dados no arquivo <CampeonatoEntrada.txt>\n\n");
    printf("Relatorio dos Resultados no arquivo <CampeonatoSaida.txt>\n\n");
    filein = fopen("input.txt", "r");
    fileout = fopen("output.txt", "w");
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

/* Função OrdenarTabTimes: Ordenar de forma decrescente os times pela seguinte prioridade: 1)Pontos 2)Vitorias 3)SaldoGols 4)GolsMarcados 5)Ordem Alfabetica ; Método: Buble-Sort adaptado*/

void OrdenarTabTimes()
{
    int i, p; logic trocou; time aux;

    /* Ordenação por Buble-Sort Adaptado */

    for(trocou = True, p = 1; p <= TabTimes.ntimes - 1 && trocou == True; p++)
        for(trocou = False, i = TabTimes.ntimes - 1; i >= p; i--)
        {

            /* Pontos */

            if(TabTimes.VetorTimes[i-1].pontos < TabTimes.VetorTimes[i].pontos)
            {
                aux = TabTimes.VetorTimes[i];
                TabTimes.VetorTimes[i] = TabTimes.VetorTimes[i-1];
                TabTimes.VetorTimes[i-1] = aux;
                trocou = True;
            }

            /* Vitorias */

            else if(TabTimes.VetorTimes[i-1].pontos == TabTimes.VetorTimes[i].pontos)
            {
                if(TabTimes.VetorTimes[i-1].vitorias < TabTimes.VetorTimes[i].vitorias)
                {
                    aux = TabTimes.VetorTimes[i];
                    TabTimes.VetorTimes[i] = TabTimes.VetorTimes[i-1];
                    TabTimes.VetorTimes[i-1] = aux;
                    trocou = True;
                }

                /* Saldo de Gols */

                else if(TabTimes.VetorTimes[i-1].vitorias == TabTimes.VetorTimes[i].vitorias)
                {
                    if(TabTimes.VetorTimes[i-1].saldogols < TabTimes.VetorTimes[i].saldogols)
                    {
                        aux = TabTimes.VetorTimes[i];
                        TabTimes.VetorTimes[i] = TabTimes.VetorTimes[i-1];
                        TabTimes.VetorTimes[i-1] = aux;
                        trocou = True;
                    }

                    /* Gols Marcados */

                    else if(TabTimes.VetorTimes[i-1].saldogols == TabTimes.VetorTimes[i].saldogols)
                    {
                        if(TabTimes.VetorTimes[i-1].golspro < TabTimes.VetorTimes[i].golspro)
                        {
                            aux = TabTimes.VetorTimes[i];
                            TabTimes.VetorTimes[i] = TabTimes.VetorTimes[i-1];
                            TabTimes.VetorTimes[i-1] = aux;
                            trocou = True;
                        }

                        /* Ordem Alfabética */

                        else if(TabTimes.VetorTimes[i-1].golspro == TabTimes.VetorTimes[i].golspro)
                        {
                            if(TabTimes.VetorTimes[i-1].nome[0] >= TabTimes.VetorTimes[i].nome[0])
                            {
                                aux = TabTimes.VetorTimes[i];
                                TabTimes.VetorTimes[i] = TabTimes.VetorTimes[i-1];
                                TabTimes.VetorTimes[i-1] = aux;
                                trocou = True;
                            }
                        }
                    }
                }
            }

        }
}

/* Função EscreverClassificaçãoFinal: Escreve a tabela final com a ordem correta dos times */

void EscreverClassificacaoFinal()
{
    int i;

    /* Cabeçalho */

    fprintf(fileout, "\nClassificacao Final:");
    fprintf(fileout, "\n\n%22s | %9s | %9s | %9s | %9s", "Time", "pontos", "Vitorias", "Saldo G", "G Pro");
    fprintf(fileout, "\n----------------------------------------------------------------------");

    /* Times já ordenados ordem */

    for(i = 0; i <= TabTimes.ntimes - 1; i++)
        fprintf(fileout, "\n %d) %18s | %9d | %9d | %9d | %9d", i+1, TabTimes.VetorTimes[i].nome, TabTimes.VetorTimes[i].pontos, TabTimes.VetorTimes[i].vitorias, TabTimes.VetorTimes[i].saldogols, TabTimes.VetorTimes[i].golspro);
}

/* Função FecharArquivos: serve para fechar os arquivos utilizados nas variaveis filein e fileout */

void FecharArquivos()
{
    fclose(filein);
    fclose(fileout);
}
