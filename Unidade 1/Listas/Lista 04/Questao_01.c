#include <stdio.h>

#define MAX 100 

int dentroLimites(int x, int y, int linhas, int colunas) {
    return (x >= 0 && x < linhas && y >= 0 && y < colunas);
}

int calcularCosta(int mapa[MAX][MAX], int linhas, int colunas) {
    int costa = 0;
    int direcoes[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int count1 = 0; count1 < linhas; count1++) {
        for (int count2 = 0; count2 < colunas; count2++) {

            if (mapa[count1][count2] == 1) {
                for (int count3 = 0; count3 < 4; count3++) {
                    int x = count1 + direcoes[count3][0];
                    int y = count2 + direcoes[count3][1];
                    if (dentroLimites(x, y, linhas, colunas) && mapa[x][y] == 0) {
                        costa++;
                        break;
                    }
                }
            }
        }
    }

    return costa;
}

int main() {
    int linhas, colunas;
    
    printf("Digite o número de linhas do mapa: ");
    scanf("%d", &linhas);
    printf("Digite o número de colunas do mapa: ");
    scanf("%d", &colunas);

    int mapa[MAX][MAX];
    
    printf("Digite o mapa (0 para água, 1 para terra):\n");
    for (int count1 = 0; count1 < linhas; count1++) {
        for (int count2 = 0; count2 < colunas; count2++) {
            scanf("%d", &mapa[count1][count2]);
        }
    }

    int costa = calcularCosta(mapa, linhas, colunas);
    printf("A extensão da costa nlogônica é: %d\n", costa);

    return 0;
}
