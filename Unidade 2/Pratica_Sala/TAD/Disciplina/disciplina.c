#include <stdio.h>
#include <stdlib.h>

typedef struct disciplina {
    char nome[100];
    int codigo;
} Disciplina;

Disciplina* criarDisciplina() {
    Disciplina* disciplina = (Disciplina*)malloc(sizeof(*disciplina));
    if (disciplina == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }

    printf("Digite o nome da disciplina: ");
    if (scanf("%99s", disciplina->nome) != 1) {
        printf("Erro ao ler nome da disciplina\n");
        exit(1);
    }

    printf("Digite o código da disciplina: ");
    if (scanf("%d", &disciplina->codigo) != 1) {
        printf("Erro ao ler código da disciplina\n");
        exit(1);
    }

    return disciplina;
}

void excluirDisciplina(Disciplina* disciplina) {
    free(disciplina);
}