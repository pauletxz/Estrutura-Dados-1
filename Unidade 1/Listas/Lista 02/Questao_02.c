#include <stdio.h>
#include <stdlib.h>
#define NUM_ALUNOS 10

// Função para calcular a nota de um aluno baseado nas respostas e no gabarito
float calcularNota(char respostas[], char gabarito[], int N) { 
    float nota = 0;
    for (int count = 0; count < N; count++) {
        if (respostas[count] == gabarito[count]) {
            nota += 10.0 / N;
        }
    }
    return nota;
}
// Função para calcular a porcentagem de aprovação dos alunos
float calcularAprovacao(float notas[], int n_alunos) {
    int aprovados = 0;
    for (int count = 0; count < n_alunos; count++) {
        if (notas[count] >= 6) {
            aprovados++;
        }
    }
    return (aprovados / (float) n_alunos) * 100;
}

int main() {
    int N;
    printf("Digite o numero de questoes: ");
    scanf("%d", &N);

    char gabarito[N];
    for (int count = 0; count < N; count++) {
        printf("Digite a resposta correta para a questao %d: ", count + 1);
        scanf(" %c", &gabarito[count]);
    }

    float notas[NUM_ALUNOS];
    for (int count = 0; count < NUM_ALUNOS; count++) {
        char respostas[N];
        for (int count = 0; count < N; count++) {
            printf("Digite a resposta do aluno %d para a questao %d: ", count + 1, count + 1);
            scanf(" %c", &respostas[count]);
        }
        notas[count] = calcularNota(respostas, gabarito, N);
        printf("Nota do aluno %d: %.2f\n", count + 1, notas[count]);
    }

    // Calcula a porcentagem de aprovação dos alunos e exibe a porcentagem de aprovação
    float porcentagem_aprovacao = calcularAprovacao(notas, NUM_ALUNOS);
    printf("Porcentagem de aprovação: %.2f%%\n", porcentagem_aprovacao);

    return 0;
}