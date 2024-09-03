#include "cadProduto.h"

typedef struct produto {
    int codigo;
    char descricao[200];
    int estoque;
}Produto;

FILE * open_file(char * name, char* modo){
    FILE * arquivo = fopen(name, modo);
    if(arquivo== NULL){
        printf("Can't open this file\n");
        exit(1);
    }
    else{
        printf("File open\n");
    }

    return arquivo;
}

Produto * criarProduto (int codigo, char descricao[], int estoque){
    Produto * produto = (Produto*)malloc(sizeof(Produto));
    if (produto == NULL){
        printf("Memory error");
        exit(1);
    }
    produto->codigo = codigo;
    strcpy(produto->descricao, descricao);
    produto->estoque = estoque;

    return produto;
}

void adcionarProdutoNoEstoque (Produto * produto){
    FILE *arquivo;

    arquivo = open_file("estoque.bin", "ab");
    fwrite(produto, sizeof(Produto), 1, arquivo);
    fclose(arquivo);
}

void exibirEstoque (){
    Produto produto;
    FILE * arquivo;
    arquivo = open_file("estoque.bin", "rb");

    while(fread(&produto, sizeof(Produto), 1, arquivo) == 1){
        printf("%d\t%s\t%d\t", produto.codigo, produto.descricao, produto.estoque);
    }

    fclose(arquivo);
}