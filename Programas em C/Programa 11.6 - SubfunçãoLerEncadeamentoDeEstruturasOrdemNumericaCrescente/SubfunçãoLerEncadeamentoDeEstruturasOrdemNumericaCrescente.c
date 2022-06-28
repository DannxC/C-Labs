#include <stdio.h>
#include <stdlib.h>

/* Declara��es dos tipos */

typedef struct st st;
struct st
{
    int a;
    st *prox;
};

typedef st *pontst;

/* Declara��es dos prototipos das fun��es auxiliares */

pontst NovoEncadeamento(void);
void EscreverEncadeamento(pontst);

/* Fun��o main */

int main()
{
    pontst x;

    /* Forma��o de um encadeamento */

    printf("Formacao de um encadeamento:\n\n");
    x = NovoEncadeamento();

    /* Escrita do conteudo do encadeamento formado */

    printf("\nConteudo do encadeamento:\n\n\t");
    EscreverEncadeamento(x);

    /* Encerramento */

    printf("\n\n"); system("pause"); return 0;
}

/* Fun��o NovoEncadeamento: forma um novo encadeamento de estruturas, preenchendo-o e retornando um ponteiro para a sua estrutura-l�der (ordem crescente) */

pontst NovoEncadeamento()
{
    int i, n, num;
    pontst p, q, r;

    /* Aloca��o da estrutura-l�der, aterrando-a */

    p = (pontst)malloc(sizeof(st));
    p->prox = NULL;

    /* Leitura do n�mero de estruturas */

    printf("Digite o numero de elementos do encadeamento: ");
    scanf("%d", &n);

    /* Forma��o e preenchimento do encadeamento de estruturas */

    if(n > 0)
    {
        printf("\nDigite os elementos: ");
        for(i = 1; i <= n; i++)
        {
            scanf("%d", &num);
            q = p;
            while(q->prox != NULL && q->prox->a < num)
                q = q->prox;
            r = q->prox;
            q->prox = (pontst)malloc(sizeof(st));
            q->prox->a = num;
            q->prox->prox = r;
        }
    }

    /* Retornando o ponteiro para a estrutura-l�der */

    return p;
}

/* Fun��o EscreverEncadeamento: escreve o conte�do do encadeamento de estruturas acoplado ao par�metro p */

void EscreverEncadeamento(pontst p)
{
    pontst q;
    for(q = p->prox; q != NULL; q = q->prox)
        printf("%4d", q->a);
}
