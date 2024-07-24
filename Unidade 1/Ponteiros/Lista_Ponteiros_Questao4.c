#include <stdio.h>
#include <math.h>

// Função para cálcular a aréa e o perimetro de um hexágono
void calcula_hexagono(float l, float *area, float *perimetro) {
    
    // Cálculo da área
    *area = (3 * pow(l, 2) * sqrt(3)) / 2;
    
    // Cálculo do perímetro
    *perimetro = 6 * l;

}

int main(void){

    float lado, area, perimetro;

    //Entrada de Dados
    printf("Informe o comprimento do lado do hexágono: ");
    scanf("%f", &lado);

    // Chama a Funçao 
    calcula_hexagono(lado, &area, &perimetro);

    //Resultados
    printf("Área do hexágono: %f\n", area);
    printf("Perímetro do hexágono: %f\n", perimetro);

    return 0;
}