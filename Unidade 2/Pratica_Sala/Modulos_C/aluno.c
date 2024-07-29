#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

struct alunos {
    int idade, matricula;
    char nome[50];
};

void imprimir(Alunos * alunos) {
    printf("Nome: %s\n", alunos->nome);
    printf("Idade: %d\n", alunos->idade);
    printf("Matricula: %d\n", alunos->matricula);
}

void preencher(Alunos * alunos) {
    printf("Digite o nome do aluno:");
    scanf(" %[^\n]", alunos->nome);

    printf("Digite a idade do aluno: ");
    scanf("%d", &alunos->idade);

    printf("Digite a matricula do aluno: ");
    scanf("%d", &alunos->matricula);
}

Alunos * alocaAluno(void){
    Alunos * alunos = (Alunos *) malloc(sizeof(Alunos));
    if (alunos == NULL) {
        printf("Erro ao alocar memoria");
        exit(1);
    }
    return alunos;
}