#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fruta {
    char nome[50];
    float valorKg;
} Fruta;

typedef struct no {
    Fruta *fruta;
    struct no *ant;
    struct no *prox;
} No;

No *criaNo(char *nomeDaFruta, float valorKgDaFruta) {
    No *novaFruta = (No *)malloc(sizeof(No));
    if (novaFruta == NULL) {
        printf("Sem Memoria");
        exit(1);
    } else {
        printf("Memoria Alocada!\n Fruta armazenada\n");
        novaFruta->fruta = (Fruta *)malloc(sizeof(Fruta));
        if (novaFruta->fruta == NULL) {
            printf("Sem Memoria para a fruta");
            free(novaFruta);
            exit(1);
        }
        strcpy(novaFruta->fruta->nome, nomeDaFruta);
        novaFruta->fruta->valorKg = valorKgDaFruta;
        novaFruta->prox = NULL;
        novaFruta->ant = NULL;
    }
    return novaFruta;
}

No *inserirNoInicio(No *lista, char *nomeDaFruta, float valorPorKg) {
    No *novaFruta = criaNo(nomeDaFruta, valorPorKg);
    if (lista == NULL) {
        lista = novaFruta;
    } else {
        novaFruta->prox = lista;
        lista->ant = novaFruta;
        lista = novaFruta;
    }
    return lista;
}

void exibirListaDeFrutas(No *lista) {
    if (!lista) {
        printf("Lista Vazia\n");
        return;
    }
    No *contador = lista;
    while (contador != NULL) {
        printf("%s - R$ %.2f\n", contador->fruta->nome, contador->fruta->valorKg);
        contador = contador->prox;
    }
}

int main() {
    No *lista = NULL;
    lista = inserirNoInicio(lista, "Banana", 3.50);
    lista = inserirNoInicio(lista, "Maçã", 4.20);
    exibirListaDeFrutas(lista);
    return 0;
}
