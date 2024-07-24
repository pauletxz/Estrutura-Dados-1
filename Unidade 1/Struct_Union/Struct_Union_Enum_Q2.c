#include <stdio.h>

typedef union tipos{
    
    char alimento[20];
    char bebida[20];
    char eletronico[20];

}Tipos;

typedef struct produtos{
    char nome[50];
    float preco;
    Tipos tipo;
}Produtos;


int main(void){
    Produtos produtos;
}