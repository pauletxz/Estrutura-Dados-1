#include <stdio.h>
#include <stdlib.h>


typedef union documentos {
    char CPF [11];
    long int RG;

}Documentos;

typedef struct pessoa
{
    char nome[50];
    Documentos doc;

}Pessoa;

void preencherPessoa(Pessoa * pessoa)
{
    int opcaoDocumento;
    printf("Informe o nome:\t");
    scanf(" %[^\n]",&pessoa->nome);
    printf("Infome 1 para CPF ou 2 para o RG: \t");
    scanf("%d",&opcaoDocumento);
    switch (opcaoDocumento)
    {
    case 1:
        printf("CPF:\t");
        scanf(" %[^\n]",pessoa->doc.CPF);
        break;
    case 2:
        printf("RG:\t");
        scanf("%ld",&pessoa->doc.RG);
        break;
    default:
        printf("Valor Invalido!");
        break;
    }
}

void imprimirPessoa(Pessoa * pessoa){
    printf("Nome: %s\n",pessoa->nome);
    printf("CPF: %s\n",pessoa->doc.CPF);
    printf("RG: %ld\n",pessoa->doc.RG);
    
}


int main(void){
    Pessoa pessoa;
    preencherPessoa(&pessoa);
    imprimirPessoa(&pessoa);

    return 0;
}