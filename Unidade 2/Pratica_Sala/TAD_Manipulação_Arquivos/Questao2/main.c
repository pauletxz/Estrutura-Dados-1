#include "cadProduto.h"

main (void){
    Produto * produto;
    produto =criarProduto(123,"cadeira",10);
    adcionarProdutoNoEstoque(produto);
    exibirEstoque("estoque.bin");

    return 0;

}