#include <stdio.h>
#include <stdlib.h>

typedef struct alunos {
    int idade, matricula;
    char nome[50];
}Alunos;

void imprimir(struct alunos Aluno);
void capturar(struct alunos *Aluno);

int main(void) {
    struct alunos Aluno;
    capturar(&Aluno);
    imprimir(Aluno);
    return 0;
}

void imprimir(struct alunos Aluno) {
    printf("Nome: %s\n", Aluno.nome);
    printf("Idade: %d\n", Aluno.idade);
    printf("Matricula: %d\n", Aluno.matricula);
}

void capturar(struct alunos *Aluno) {
    printf("Digite o nome do aluno:);
    scanf("%s", Aluno->nome); 
    printf("Digite a idade do aluno: ");
    scanf("%d", &Aluno->idade); 

    printf("Digite a matricula do aluno: ");
    scanf("%d", &Aluno->matricula); 
}