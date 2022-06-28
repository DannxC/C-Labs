#include <stdio.h>
#include <stdlib.h>

/* Declarações dos tipos */

typedef struct st st;
struct st
{
    int a;
    st *prox;
};

typedef st *pontst;

/* Declarações dos prototipos das funções auxiliares */

pontst NovoEncadeamento(void);
void EscreverEncadeamento(pontst);

/* Função main */

int main()
{
    pontst x;

    /* Formação de um encadeamento */

    printf("Formacao de um encadeamento:\n\n");
    x = NovoEncadeamento();

    /* Escrita do conteudo do encadeamento formado */

    printf("\nConteudo do encadeamento:\n\n\t");
    EscreverEncadeamento(x);

    /* Encerramento */

    printf("\n\n"); system("pause"); return 0;
}

/* Função NovoEncadeamento: forma um novo encadeamento de estruturas, preenchendo-o e retornando um ponteiro para a sua estrutura-líder */

pontst NovoEncadeamento()
{
    int i, n;
    pontst p, q;

    /* Alocação da estrutura-líder */

    p = (pontst)malloc(sizeof(st));

    /* Leitura do número de estruturas */

    printf("Digite o numero de elementos do encadeamento: ");
    scanf("%d", &n);

    /* Formação e preenchimento do encadeamento de estruturas */

    if(n > 0)
    {
        printf("\nDigite os elementos: ");
        for(q = p, i = 1; i <= n; i++)
        {
            q->prox = (pontst)malloc(sizeof(st));
            q = q->prox;
            scanf("%d", &q->a);
        }
        q->prox = NULL;
    }
    else
        p->prox = NULL;

    /* Retornando o ponteiro para a estrutura-líder */

    return p;
}

/* Função EscreverEncadeamento: escreve o conteúdo do encadeamento de estruturas acoplado ao parâmetro p */

void EscreverEncadeamento(pontst p)
{
    pontst q;
    for(q = p->prox; q != NULL; q = q->prox)
        printf("%4d", q->a);
}
