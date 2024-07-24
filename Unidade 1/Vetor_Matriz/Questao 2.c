#include <stdio.h>
#include <stdlib.h>

int main(void){

    // Variaveis e entradas de dados
    int linha, colunas;
    printf("Informe o número de linhas e colunas: ");
    scanf("%d %d", &linha, &colunas);

    // Alocacão dinamica da matriz 
    int **matriz = (int **)malloc(linha * sizeof(int *));
    if (matriz == NULL){
        printf("Erro ao alocar memória\n");
        exit(1);
    }
    for (int count = 0; count < linha; count++){
        matriz[count] = (int *)malloc(colunas * sizeof(int));
        if (matriz[count] == NULL){ 
            printf("Erro ao alocar memória\n");
            exit(1);
        }
    }

    // Elementos da matriz
    printf("Informe os elementos da matriz:\n");
    for (int count = 0; count < linha; count++){
        for (int count = 0; count < colunas; count++){
            scanf("%d", &matriz[count][count]);
        }
    }

    // Exibicão da matriz (Padrão)
    printf("Matriz original:\n");
    for (int count = 0; count < linha; count++){
        for (int count = 0; count < colunas; count++){
            printf("%d\t", matriz[count][count]);
        }
        printf("\n");
    }

    // Exibição da matriz (Transposta)
    printf("Matriz transposta:\n");
    for (int count = 0; count < colunas; count++){
        for (int count = 0; count < linha; count++){
            printf("%d\t", matriz[count][count]);
        }
        printf("\n");
    }

    // Liberação de memória
    for (int count = 0; count < linha; count++){
        free(matriz[count]);
    }
    free(matriz);

    return 0;
}