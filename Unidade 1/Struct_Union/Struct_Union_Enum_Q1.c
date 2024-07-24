#include <stdio.h>

typedef enum genero{ 
    FEMININO = 1,
    MASCULINO
}Genero;

typedef struct pessoa{
    char nome[50];
    int idade;
    Genero genero;
}Pessoa;

void preencher (Pessoa * pessoa){

    printf("Digite o nome da pessoa: ");
    scanf(" %[^\n]", pessoa->nome);

    printf("Digite a idade da pessoa: ");
    scanf("%d", &pessoa->idade);

    printf("Digite o genero da pessoa, 1 para Femino e 2 para masculino: ");
    scanf("%d", &pessoa->genero);
}

void imprimir (Pessoa * pessoa ){
    
    printf("Nome: %s\n", pessoa->nome);
    printf("Idade: %d\n", pessoa->idade);
    switch 
    (pessoa->genero){

        case FEMININO:
        printf("Genero: Feminino\n");
        break;

        case MASCULINO:
        printf("Genero: Masculino\n");
        break;

        default:
        printf("Genero: Desconhecido\n");
        break;}
}

int main(void){

    Pessoa pessoa;
    preencher (&pessoa);
    imprimir (&pessoa);
    
    return 0;
}