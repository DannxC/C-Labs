//Exercício está descrito no slide "CES10 Prat 1 2021"

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int aluno, nalunos, ncadernos, ncanetas, nlapis, nborrachas; float pcaderno, pcaneta, plapis, pborracha;
    printf("Digite o numero de alunos: "); scanf("%d", &nalunos);
    printf("\n"); aluno=1;
    while(aluno <= nalunos)
    {
        printf("Aluno %d:\n\n\n\t", aluno);
        printf("Numero de cadernos: "); scanf("%d", &ncadernos); printf("\t");
        printf("Preco do caderno: "); scanf("%f", &pcaderno); printf("\n\t");      //fim do ciclo de cadernos
        printf("Numero de canetas: "); scanf("%d", &ncanetas); printf("\t");
        printf("Preco do caderno: "); scanf("%f", &pcaneta); printf("\n\t");       //fim do ciclo de canetas
        printf("Numero de lapis: "); scanf("%d", &nlapis); printf("\t");
        printf("Preco do lapis: "); scanf("%f", &plapis); printf("\n\t");          //fim do ciclo de lapis
        printf("Numero de borrachas: "); scanf("%d", &nborrachas); printf("\t");
        printf("Preco do borrachas: "); scanf("%f", &pborracha); printf("\n\t");   //fim do ciclo de borrachas
        printf("Aluno %d:\n\t\t", aluno);
        printf("%d cadernos a R$%g cada\n\t\t", ncadernos, pcaderno);
        printf("%d canetas a R$%g cada\n\t\t", ncanetas, pcaneta);
        printf("%d lapis a R$%g cada\n\t\t", nlapis, plapis);             //fim da enumeração da lista dos itens
        printf("%d borracha a R$%g cada\n\n\t", nborrachas, pborracha);   //com seus devidos preços
        printf("Gasto total: %g", ncadernos*pcaderno+ncanetas*pcaneta+nlapis*plapis+nborrachas*pborracha);
        printf("\n\n\n");
        aluno = aluno+1;
    }
    printf("\n\n"); system("pause"); return 0;
}
