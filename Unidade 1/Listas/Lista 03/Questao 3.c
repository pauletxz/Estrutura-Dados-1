#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){

    // Variaveis e entradas de dados
    int numero;
    printf("Informe um número: ");
    scanf("%d", &numero);
    int linha = numero, colunas = numero;

    // Alocacão dinamica da matriz 
    int **matriz = (int **)malloc(linha * sizeof(int *));
    if (matriz == NULL){
        printf("Erro ao alocar memória\n");
        exit(1);
    }
    for (int i = 0; i < linha; i++){
        matriz[i] = (int *)malloc(colunas * sizeof(int));
        if (matriz[i] == NULL){ 
            printf("Erro ao alocar memória\n");
            exit(1);
        }
    }

    // Elementos da matriz
    for (int i = 0; i < linha; i++){
        for (int j = 0; j < colunas; j++){
            matriz[i][j] = (int)floor(rand() / (RAND_MAX / 100.0) + 1);
        }
    }

    // Exibicão da matriz
    printf("Matriz:\n");
    for (int i = 0; i < linha; i++){
        for (int j = 0; j < colunas; j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }


    // Liberação de memória
    for (int i = 0; i < linha; i++){
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}