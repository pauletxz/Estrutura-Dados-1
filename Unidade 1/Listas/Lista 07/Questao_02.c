#include <stdio.h>
#include <stdlib.h>

// Enum para representar os tipos de produtos
typedef enum {
    ALIMENTO,
    BEBIDA,
    ELETRONICO
} Tipo;

// Struct para representar um produto
typedef struct produto {
    char nome[20];
    float preco;
    Tipo tipo;
} Produto;

// Função para preencher os dados de um produto
void preencheProduto(Produto *p) {
    int opcao;

    printf("Cadastro de produto\n");
    printf("Nome: ");
    scanf(" %[^\n]", p->nome);
    printf("Preco: R$");
    scanf(" %f", &p->preco);
    printf("Tipo:\n  [1] Alimento\n  [2] Bebida\n  [3] Eletronico\n>> ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            p->tipo = ALIMENTO;
            break;
        case 2:
            p->tipo = BEBIDA;
            break;
        case 3:
            p->tipo = ELETRONICO;
            break;
    }
}

// Função para imprimir os dados de um produto
void imprimeProduto(Produto *p) {
    char *tipo_nome;

    switch (p->tipo) {
        case ALIMENTO:
            tipo_nome = "Alimento";
            break;
        case BEBIDA:
            tipo_nome = "Bebida";
            break;
        case ELETRONICO:
            tipo_nome = "Eletronico";
            break;
    }

    printf("DADOS DO PRODUTO\n");
    printf("Nome: %s\n", p->nome);
    printf("Preco: R$%.2f\n", p->preco);
    printf("Tipo: %s\n", tipo_nome);
}

// Função principal
int main() {
    // Aloca memória para um produto
    Produto *produto = malloc(sizeof(Produto));

    // Preenche os dados do produto
    preencheProduto(produto);

    // Imprime os dados do produto
    imprimeProduto(produto);

    // Libera a memória alocada
    free(produto);

    return 0;
}