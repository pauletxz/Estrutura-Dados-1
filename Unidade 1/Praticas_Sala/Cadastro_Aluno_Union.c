#include <stdio.h>
#include <stdlib.h>


typedef union documentos {
    char CPF [11];
    long int RG;
    long int SUS;
    long int tituloEleitor;
    char passaporte[11];

}Documentos;

typedef struct pessoa
{
    char nome[50];
    Documentos doc;
    int matricula;

}Pessoa;

void preencherPessoa(Pessoa * pessoa){
    printf("Informe o nome:\t");
    scanf(" %[^\n]",&pessoa->nome);

    printf("Infome a matrícula:\t");
    scanf("%d",&pessoa->matricula);

    printf("Infome o RG:\t");
    scanf("%ld",&pessoa->doc.RG);

    printf("Informe o CPF:\t");
    scanf(" %[^\n]",&pessoa->doc.CPF);

    printf("Informe o SUS:\t");
    scanf("%ld",&pessoa->doc.SUS);

    printf("Informe o titulo de eleitor:\t");
    scanf("%ld",&pessoa->doc.tituloEleitor);

    printf("Informe o passaporte:\t");
    scanf("%s",&pessoa->doc.passaporte);
}

void imprimirPessoa(Pessoa * pessoa){
    printf("Nome:  %s\n",pessoa->nome);
    printf("Matricula: %d\n",pessoa->matricula);
    printf("CPF: %s\n",pessoa->doc.CPF);
    printf("RG: %ld\n",pessoa->doc.RG);
    printf("SUS: %ld\n",pessoa->doc.SUS);
    printf("Titulo de eleitor: %ld\n",pessoa->doc.tituloEleitor);
    printf("Passaporte:  %s\n",pessoa->doc.passaporte);
    
}

int main(void){
    Pessoa pessoa;
    preencherPessoa(&pessoa);
    imprimirPessoa(&pessoa);

    return 0;
}