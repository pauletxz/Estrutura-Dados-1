#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario
{
    char nome[50];
    char id;
    float salario;

}Funcionario;

int buscaBinaria(int lista[], int inicio, int fim, int elemento) {
    int meio;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (lista[meio] == elemento) {
            return meio;
        }
        if (lista[meio] < elemento) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

void adcionarFuncionario(Funcionario * funcionario){

    printf("Digite o nome do funcionario");
    fgets(funcionario->nome, 50, stdin);

    printf("Digite o id do funcionario");
    scanf("%d", &funcionario->id);

    printf("Digite o salario do funcionario");
    scanf("%f", &funcionario->salario);

}

void removerFuncionario(Funcionario * funcionario){

    printf("Digite o id do funcionario que deseja remover");
    scanf("%d", &funcionario->id);
}

void buscarFuncionario(Funcionario * funcionario){

    printf("Digite o id do funcionario que deseja buscar");
    scanf("%d", &funcionario->id);
}