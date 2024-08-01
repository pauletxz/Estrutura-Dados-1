#include <stdio.h>
#include <stdlib.h>

#define MAX_PESSOAS 10

typedef struct pessoa{
    int idade;
    char nome[50];
    int doc;
}Pessoa;

void preencher(Pessoa * pessoa){

    printf("Digite o nome: ");
    scanf(" %[^\n]",&pessoa->nome);

    printf("Digite a idade: ");
    scanf("%d",&pessoa->idade);

    printf("Digite o documento: ");
    scanf("%d",&pessoa->doc);
}

void exibir(Pessoa * pessoa){
    printf("Nome: %s\n", pessoa->nome);
    printf("Idade: %d\n",&pessoa->idade);
    printf("Numero Documento: %d\n",&pessoa->doc);

}

void maiorMenorIdade(Pessoa * pessoa, int numPessoas){
    int maior = pessoa[0].idade;
    int menor = pessoa[0].idade;
    int i;
    for (i = 1; i < numPessoas; i++) {
        if (pessoa[i].idade > maior) {
            maior = pessoa[i].idade;}
    if (pessoa[i].idade < menor) {
        menor = pessoa[i].idade;}
}
}

int main(void){
    Pessoa pessoas[MAX_PESSOAS];
    int i;
    for (i = 0; i < MAX_PESSOAS; i++) {
        preencher(&pessoas[i]);}

    exibir(&pessoas[0]);
    maiorMenorIdade(pessoas, MAX_PESSOAS);
    
}