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

/* Função NovoEncadeamento: forma um novo encadeamento de estruturas, preenchendo-o e retornando um ponteiro para a sua estrutura-líder (ordem crescente) */

pontst NovoEncadeamento()
{
    int i, n, num;
    pontst p, q, r;

    /* Alocação da estrutura-líder, aterrando-a */

    p = (pontst)malloc(sizeof(st));
    p->prox = NULL;

    /* Leitura do número de estruturas */

    printf("Digite o numero de elementos do encadeamento: ");
    scanf("%d", &n);

    /* Formação e preenchimento do encadeamento de estruturas */

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
