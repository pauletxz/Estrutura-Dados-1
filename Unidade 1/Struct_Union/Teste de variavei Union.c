#include <stdio.h>

union tipos{
    int inteiro;
    float real;
    char letra;
};
typedef union tipos Tipos;

int main(void){
    Tipos variavel;
    variavel.inteiro = 2;
    printf("%d \n", "%f\n", "%c\n", variavel.inteiro, variavel.real,variavel.letra);
    variavel.real = 3.5;
    printf("%d \n", "%f\n", "%c\n", variavel.inteiro, variavel.real,variavel.letra);
    variavel.letra = 's';
    printf("%d \n", "%f\n", "%c\n", variavel.inteiro, variavel.real,variavel.letra);
    

    return 0;
}