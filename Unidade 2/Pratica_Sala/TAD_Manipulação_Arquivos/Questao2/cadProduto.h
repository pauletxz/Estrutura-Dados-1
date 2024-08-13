#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto Produto;

FILE * open_file(char * name, char* modo);

Produto * criarProduto (int codigo, char descricao[], int estoque);

void adcionarProdutoNoEstoque (Produto * produto);

void exibirEstoque();