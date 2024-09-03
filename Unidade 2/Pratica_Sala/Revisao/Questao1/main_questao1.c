#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 10000

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int buscaSequencial(int *entrada, int tamanho) {
    int maior = entrada[0];
    for (int i = 1; i < tamanho; i++) {
        if (entrada[i] > maior) {
            maior = entrada[i];
        }
    }
    return maior;
}

int buscaBinaria(int vet[], int maior, int tamanho) {
    qsort(vet, tamanho, sizeof(int), compare);
    int inicio = 0, final = tamanho - 1;
    while (inicio <= final) {
        int meio = inicio + (final - inicio) / 2;
        if (vet[meio] == maior) {
            return vet[meio];
        } else if (vet[meio] < maior) {
            inicio = meio + 1;
        } else {
            final = meio - 1;
        }
    }
    return -1;
}

int main(void) {
    int entrada[TAMANHO];

    for (int count = 0; count < TAMANHO; count++) {
        entrada[count] = rand();
    }

    clock_t tempo_inicial = clock();
    int maior_sequencial = buscaSequencial(entrada, TAMANHO);
    double tempo_final_sequencial = (double)(clock() - tempo_inicial) / CLOCKS_PER_SEC;
    tempo_final_sequencial *= 1000; // milliseconds

    tempo_inicial = clock();
    int maior_binario = buscaBinaria(entrada, maior_sequencial, TAMANHO);
    double tempo_final_binario = (double)(clock() - tempo_inicial) / CLOCKS_PER_SEC;
    tempo_final_binario *= 1000; // milliseconds

    printf("Maior elemento (sequencial): %d\n", maior_sequencial);
    printf("Tempo de execução (sequencial): %.2f ms\n", tempo_final_sequencial);
    printf("Maior elemento (binário): %d\n", maior_binario);
    printf("Tempo de execução (binário): %.2f ms\n", tempo_final_binario);

    return 0;
}
