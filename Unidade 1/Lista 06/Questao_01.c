#include <stdio.h>
#include <stdlib.h>

#define MAX_VAGAS 55
#define MAX_TURMAS 2

typedef struct {
    int mat;
    char nome[81];
    float notas[3];
    float media;
} Aluno;

typedef struct {
    char id;
    int vagas;
    Aluno* aluno[MAX_VAGAS];
} Turma;

Turma* turmas[MAX_TURMAS];
int num_turmas = 0;

Turma* criarTurma(char id);

void imprimirTurmas(Turma** turmas, int n);

Turma* procurarTurmas(Turma** turmas, int n, char id);

void matriculaAluno(Turma* turma, int mat, char* nome);

void lancaNotas(Turma* turma);

void imprimirAlunos(Turma* turma);

void liberarMemoria(Turma** turmas, int n);

void exibirMenu();

void entradasOpcao(int opcao);

int main() {
    int opcao;

    printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\n");
    printf("Este programa gerencia as turmas ofertadas, fornecendo as funcionalidades de matricula, lancamento de notas e listagem de alunos.\n");
    printf("Autor: Ada Lovelace Versao: 1.0\n");

    do {
        exibirMenu();
        scanf("%d", &opcao);
        entradasOpcao(opcao);
    } while (opcao != 6);

    liberarMemoria(turmas, num_turmas);
    return 0;
}

Turma* criarTurma(char id) {
    Turma* nova_turma = (Turma*)malloc(sizeof(Turma));
    if (nova_turma == NULL) {
        printf("Erro ao alocar memória para a turma.\n");
        return NULL;
    }
    nova_turma->id = id;
    nova_turma->vagas = MAX_VAGAS;

    for (int count = 0; count < MAX_VAGAS; count++) {
        nova_turma->aluno[count] = NULL;
    }

    return nova_turma;
}

void imprimirTurmas(Turma** turmas, int n) {
    for (int count = 0; count < n; count++) {
        if (turmas[count] != NULL) {
            printf("Turma %c - %d vagas disponiveis\n", turmas[count]->id, turmas[count]->vagas);
        }
    }
}

Turma* procurarTurmas(Turma** turmas, int n, char id) {
    for (int count = 0; count < n; count++) {
        if (turmas[count] != NULL && turmas[count]->id == id) {
            return turmas[count];
        }
    }
    return NULL;
}

void matriculaAluno(Turma* turma, int mat, char* nome) {
    if (turma->vagas > 0) {
        Aluno* a = (Aluno*)malloc(sizeof(Aluno));
        a->mat = mat;
        for (int count = 0; count < 3; count++) {
            a->notas[count] = 0.0;
        }
        a->media = 0.0;
        for (int count = 0; count < MAX_VAGAS; count++) {
            if (turma->aluno[count] == NULL) {
                turma->aluno[count] = a;
                turma->vagas--;
                break;
            }
        }
    } else {
        printf("Turma cheia!\n");
    }
}

void lancaNotas(Turma* turma) {
    for (int count = 0; count < MAX_VAGAS; count++) {
        if (turma->aluno[count] != NULL) {
            printf("Matricula: %d Aluno: %s\n", turma->aluno[count]->mat, turma->aluno[count]->nome);
            float soma = 0.0;
            for (int count = 0; count < 3; count++) {
                printf("Digite a nota %d: ", count + 1);
                scanf("%f", &(turma->aluno[count]->notas[count]));
                soma += turma->aluno[count]->notas[count];
            }
            turma->aluno[count]->media = soma / 3.0;
        }
    }
}

void imprimirAlunos(Turma* turma) {
    for (int count = 0; count < MAX_VAGAS; count++) {
        if (turma->aluno[count] != NULL) {
            printf("Matricula: %d\n", turma->aluno[count]->mat);
            printf("Nome: %s\n", turma->aluno[count]->nome);
            printf("Media: %.2f\n", turma->aluno[count]->media);
        }
    }
}

void liberarMemoria(Turma** turmas, int n) {
    for (int count = 0; count < n; count++) {
        for (int count = 0; count < MAX_VAGAS; count++) {
            if (turmas[count]->aluno[count] != NULL) {
                free(turmas[count]->aluno[count]);
            }
        }
        free(turmas[count]);
    }
}

void exibirMenu() {
    printf("MENU:\n");
    printf("1 - Criar turma\n");
    printf("2 - Listar turmas\n");
    printf("3 - Matricular aluno\n");
    printf("4 - Lancar notas\n");
    printf("5 - Listar alunos\n");
    printf("6 - Sair\n");
    printf("Digite sua opcao: ");
}

void entradasOpcao(int opcao) {
    char id;
    int mat;
    char nome[81];
    Turma* t;

    switch (opcao) {
        case 1:
            if (num_turmas < MAX_TURMAS) {
                printf("Criando nova turma...\n");
                printf("Digite um id: ");
                scanf(" %c", &id);
                turmas[num_turmas++] = criarTurma(id);
                printf("Turma %c criada com sucesso!\n", id);
            } else {
                printf("Numero maximo de turmas atingido!\n");
            }
            break;
        case 2:
            printf("Listando turmas...\n");
            imprimirTurmas(turmas, num_turmas);
            break;
        case 3:
            printf("Matriculando aluno...\n");
            printf("Digite o id da turma: ");
            scanf(" %c", &id);
            t = procurarTurmas(turmas, num_turmas, id);
            if (t != NULL) {
                printf("Digite a matricula: ");
                scanf("%d", &mat);
                printf("Digite o nome: ");
                scanf(" %[^\n]", nome);
                matriculaAluno(t, mat, nome);
                printf("Aluno matriculado com sucesso!\n");
            } else {
                printf("Turma inexistente!\n");
            }
            break;
        case 4:
            printf("Lancando notas...\n");
            printf("Digite o id da turma: ");
            scanf(" %c", &id);
            t = procurarTurmas(turmas, num_turmas, id);
            if (t != NULL) {
                lancaNotas(t);
            } else {
                printf("Turma inexistente!\n");
            }
            break;
        case 5:
            printf("Listando alunos...\n");
            printf("Digite o id da turma: ");
            scanf(" %c", &id);
            t = procurarTurmas(turmas, num_turmas, id);
            if (t != NULL) {
                imprimirAlunos(t);
            } else {
                printf("Turma inexistente!\n");
            }
            break;
        case 6:
            printf("Obrigado por usar este programa!\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }
}
