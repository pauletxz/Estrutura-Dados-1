#include <stdio.h>
#include <stdlib.h>
#include "disciplina.c"

typedef struct aluno
{
    Disciplina *disciplina;
    char nome [50];
    int matricula;
    int numDisciplinas;

}Aluno;

Aluno * criarAluno (){
    Aluno *aluno = (Aluno*)malloc(sizeof(*aluno));
    if(aluno == NULL){
        printf("Erro ao alocar memória");
        exit(1);
    }

    printf("Digite o nome da disciplina: ");
    if (scanf("%99s", aluno->nome) != 1) {
        printf("Erro ao ler nome da disciplina\n");
        exit(1);
    }

    printf("Digite o código da disciplina: ");
    if (scanf("%d", &aluno->matricula) != 1) {
        printf("Erro ao ler código da disciplina\n");
        exit(1);
    }



    return aluno;
}

void matriculaDisciplina(Aluno * aluno , Disciplina * disciplina){
    aluno->numDisciplinas++;
    aluno->disciplina = (Disciplina*) realloc(aluno->disciplina, sizeof(Disciplina)*aluno->numDisciplinas);
}

void excluirAluno(Aluno * aluno){
    free(aluno);
}
