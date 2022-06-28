#include <stdio.h>
#include <stdlib.h>

int main()
{
    int aluno, numalunos, numcadernos; float preco;
    printf("Digite o numero de alunos: ");
    scanf("%d",&numalunos); printf("\n"); aluno=1;
    while(aluno<=numalunos)
    {
        printf("Aluno %d:\n\n\tPreco do caderno: ", aluno);  //O \t serve para dar espaço à direita!
        scanf("%f",&preco);
        printf("\tNumero de cadernos: "); scanf("%d", &numcadernos);
        printf("\tAluno %d: %d cadernos a R$%g cada; gasto total: R$%g\n\n", aluno, numcadernos, preco, numcadernos*preco);
        aluno = aluno + 1;
    }
    printf("\n\n"); system("pause"); return 0;
}
