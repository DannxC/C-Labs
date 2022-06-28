#include <stdio.h>
#include <stdlib.h>

typedef struct st st;
struct st
{
    int a;
    st *prox;
};

int main()
{
    st *p;
    p = (st *)malloc(sizeof(st));
    p->a = 2;
    printf("%4d", p->a);
    printf("\n\n"); system("pause"); return 0;
}
