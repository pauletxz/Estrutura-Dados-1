#include "cadPruduto.c"

main(void){
    Produto * produto =criarProduto(123,"cadeira",10);
    adcionarProdutoNoEstoque(produto);
    exibirEstoque("estoque.bin");

    return 0;

}