#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    char *sexo, *opiniao;
    int i, contFeminino = 0, contMasculino = 0;

    printf("Digite o número de pessoas entrevistadas: ");
    scanf("%d", &n);

    sexo = (char *) malloc(n * sizeof(char));
    opiniao = (char *) malloc(n * sizeof(char));

    if (sexo == NULL || opiniao == NULL) {
        printf("Erro ao alocar memória!\n");
        exit (1);
    }

    for (i = 0; i < n; i++) {
        printf("Digite o sexo da pessoa %d (M para Masculino, F para Feminino): ", i + 1);
        scanf(" %c", &sexo[i]);

        printf("Digite a opinião da pessoa %d (Digite S se gostou do produto ou N caso nao tenha gostado): ", i + 1);
        scanf(" %c", &opiniao[i]);

        if (sexo[i] == 'F' && opiniao[i] == 'S') {
            contFeminino++;
        }

        if (sexo[i] == 'M' && opiniao[i] == 'N') {
            contMasculino++;
        }
    }

    float porcentagemFeminino = (float) contFeminino / n * 100;
    float porcentagemMasculino = (float) contMasculino / n * 100;

    printf("Porcentagem de pessoas do sexo feminino que gostaram do produto: %.2f%%\n", porcentagemFeminino);
    printf("Porcentagem de pessoas do sexo masculino que não gostaram do produto: %.2f%%\n", porcentagemMasculino);

    free(sexo);
    free(opiniao);

    return 0;
}