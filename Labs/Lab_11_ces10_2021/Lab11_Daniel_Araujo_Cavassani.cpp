#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Declara��es dos tipos */

typedef struct celula celula;
typedef celula *pont;
struct celula
{
    int num;
    pont prox;
};
typedef pont numero;

/* Declara��es dos prot�tipos das fun��es auxiliares */

numero NovoEncadeamento();
void EscreverEncadeamento(numero);
numero SomaEncadeamentos(numero, numero);
numero MultiplicacaoEncadeamentos(numero, numero);

/* Fun��o Main */

int main()
{
    numero n1, n2, ns, nm;
    n1 = NovoEncadeamento();
    n2 = NovoEncadeamento();
    printf("\n\tNumero 1: ");
    EscreverEncadeamento(n1);
    printf("\n\tNumero 2: ");
    EscreverEncadeamento(n2);
    ns = SomaEncadeamentos(n1, n2);
    printf("\n\tSoma: ");
    EscreverEncadeamento(ns);
    nm = MultiplicacaoEncadeamentos(n1, n2);
    printf("\n\tMultiplicacao: ");
    EscreverEncadeamento(nm);
    printf("\n\n"); system("pause"); return 0;
}

/* Fun��o NovoEncadeamento: L� inteiros e transforma-os em estruturas encadeadas */

numero NovoEncadeamento()
{
    /* Declara��es locais */

    int i, j, len;
    char cad[101], cad2[25][5];
    numero n, p;
    n = (celula *)malloc(sizeof(celula));
    n->prox = NULL;
    printf("Digite um numero inteiro: ");
    scanf("%s", &cad);
    len = strlen(cad);

    /* Verifica��o da validade da cadeia numerica */

    for(i = 0; i < len; i++)
        if(cad[i] < '0' || cad[i] > '9')
        {
            n->prox = (celula *)malloc(sizeof(celula));
            n->prox->num = -1;
            n->prox->prox = NULL;
            return n;
        }

    /* Remo��o dos '0' a esquerda */

    for(i = 0, j = 0; i < len; i++)
    {
        if(cad[i] == '0')
            j++;
        else
            break;
    }
    if(len != j)
        for(i = j; i <= len; i++)
            cad[i-j] = cad[i];
    else
    {
        cad[0] = '0';
        cad[1] = '\0';
    }

    /* Dividir a cadeia em grupos de 4 caracteres */

    len = strlen(cad);
    if(len % 4 != 0)
    {
        for(j = 0; j < (len % 4); j++)
            cad2[0][j] = cad[j];
        cad2[0][len % 4] = '\0';
        for(i = 1; i <= len/4; i++)
        {
            for(j = 0; j < 4; j++)
                cad2[i][j] = cad[(len % 4) + 4*i - 4 + j];
            cad2[i][4] = '\0';
        }
    }
    else
        for(i = 0; i < len/4; i++)
        {
            for(j = 0; j < 4; j++)
                cad2[i][j] = cad[4*i + j];
            cad2[i][4] = '\0';
        }

    /* Forma��o do encadeamento n */

    if(len % 4 == 0)
        j = len/4;
    else
        j = len/4 + 1;
    for(i = j - 1, p = n; i >= 0; i--)
    {
        p->prox = (celula *)malloc(sizeof(celula));
        p = p->prox;
        p->num = atoi(cad2[i]);
    }
    p->prox = NULL;
    return n;
}

/* Fun��o EscreverEncadeamento: Serve para escrever, na tela, um numero em formato de encadeamento */

void EscreverEncadeamento(numero n)
{
    /* Declara��es locais */

    numero p;
    int i, j, k, len;
    char cad[101], cad2[25][5];

    /* Convers�o de int para string, com posterior formata��o interna das strings */

    for(p = n->prox, k = 0; p != NULL; k++, p = p->prox)
    {
        len = sprintf(cad2[k], "%d", p->num);
        if(p->prox != NULL)
            if(len < 4)
            {
                for(j = len; j >= 0; j--)
                    cad2[k][j + 4 - len] = cad2[k][j];
                for(j = 0; j < 4 - len; j++)
                    cad2[k][j] = '0';
            }
    }

    /* Concatena��o das strings */

    for(i = k - 1, cad[0] = '\0'; i >= 0; i--)
        strcat(cad, cad2[i]);

    /* Escrever no video */

    printf("%s", cad);
}

/* Fun��o SomaEncadeamentos: Retorna um numero em forma de encadeamento a partir da soma de dois outros numeros encadeados */

numero SomaEncadeamentos(numero n1, numero n2)
{
    /* Declara��es locais */

    numero ns, p1, p2, ps;
    int carry, aux;
    ns = (celula *)malloc(sizeof(celula));

    /* Soma */

    for(carry = 0, p1 = n1->prox, p2 = n2->prox, ps = ns; p1 != NULL || p2 != NULL;)
    {
        if(p1 != NULL && p2 != NULL)
        {
            aux = p1->num + p2->num + carry;
            carry = (aux >= 10000) ? 1 : 0;
            aux -= carry*10000;
            ps->prox = (celula *)malloc(sizeof(celula));
            ps = ps->prox;
            ps->num = aux;
            p1 = p1->prox;
            p2 = p2->prox;
        }
        else if(p1 !=  NULL && p2 == NULL)
        {
            aux = p1->num + carry;
            carry = (aux >= 10000) ? 1 : 0;
            aux -= carry*10000;
            ps->prox = (celula *)malloc(sizeof(celula));
            ps = ps->prox;
            ps->num = aux;
            p1 = p1->prox;
        }
        else if(p1 == NULL && p2 != NULL)
        {
            aux = p2->num + carry;
            carry = (aux >= 10000) ? 1 : 0;
            aux -= carry*10000;
            ps->prox = (celula *)malloc(sizeof(celula));
            ps = ps->prox;
            ps->num = aux;
            p2 = p2->prox;
        }
    }
    if(carry == 1)
    {
        ps->prox = (celula *)malloc(sizeof(celula));
        ps = ps->prox;
        ps->num = 1;
        ps->prox = NULL;
    }
    else
        ps->prox = NULL;
    return ns;
}

/* Fun��o MultiplicacaoEncadeamentos: Retorna um numero em forma de encadeamento a partir da multiplicacao de dois outros numeros encadeados */

numero MultiplicacaoEncadeamentos(numero n1, numero n2)
{
    /* Declara��es locais */

    numero aux, nm, p1, p2, paux;
    int carry, i, k;
    nm = (celula *)malloc(sizeof(celula));
    nm->prox = (celula *)malloc(sizeof(celula));
    nm->prox->num = 0;
    nm->prox->prox = NULL;

    /* Multiplica��o */

    for(k = 0, p1 = n1->prox; p1 != NULL; k++, p1 = p1->prox)
    {
        aux = (celula *)malloc(sizeof(celula));
        paux = aux;
        for(i = 0; i < k; i++)
        {
            paux->prox = (celula *)malloc(sizeof(celula));
            paux = paux->prox;
            paux->num = 0;
        }
        for(carry = 0, p2 = n2->prox; p2 != NULL; p2 = p2->prox)
        {
            paux->prox = (celula *)malloc(sizeof(celula));
            paux = paux->prox;
            paux->num = p2->num * p1->num + carry;
            carry = paux->num / 10000;
            paux->num -= carry * 10000;
        }
        if(carry > 0)
        {
            paux->prox = (celula *)malloc(sizeof(celula));
            paux->prox->num = carry;
            paux->prox->prox = NULL;
        }
        else
            paux->prox = NULL;
        nm = SomaEncadeamentos(nm, aux);
    }
    return nm;
}
