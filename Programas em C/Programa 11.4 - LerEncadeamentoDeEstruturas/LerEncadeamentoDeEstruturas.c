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

/* Fun��o main */

int main()
{
    int i, n;
    pontst p, q;

    /* Aloca��o da estrutura-l�der */

    p = (st *)malloc(sizeof(st));

    /* Leitura do numero de estruturas */

    printf("Digite o numero de elementos do encadeamento: ");
    scanf("%d", &n);

    /* Forma��o e preenchimento do encadeamento de estruturas */

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

    /* Escrita do conteudo do encadeamento de estruturas */

    printf("\n\nConteudo do encadeamento:\n\n\t");
    for(q = p->prox; q != NULL; q = q->prox)
        printf("%4d", q->a);

    /* Fechamento da tela e encerramento */

    printf("\n\n"); system("pause"); return 0;
}

