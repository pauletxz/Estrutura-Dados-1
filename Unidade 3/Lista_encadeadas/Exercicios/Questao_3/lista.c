#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->proximo = NULL;
    return novoNo;
}

void inserirNoInicio(No** cabeca, int valor) {
    No* novoNo = criarNo(valor);
    if (*cabeca == NULL) {
        *cabeca = novoNo;
        novoNo->proximo = *cabeca; // Aponta para si mesmo, tornando-se circular
    } else {
        No* temp = *cabeca;
        while (temp->proximo != *cabeca) {  // Encontrar o último nó
            temp = temp->proximo;
        }
        temp->proximo = novoNo;
        novoNo->proximo = *cabeca;
        *cabeca = novoNo;
    }
}

void inserirNoFim(No** cabeca, int valor) {
    No* novoNo = criarNo(valor);
    if (*cabeca == NULL) {
        *cabeca = novoNo;
        novoNo->proximo = *cabeca;
    } else {
        No* temp = *cabeca;
        while (temp->proximo != *cabeca) {
            temp = temp->proximo;
        }
        temp->proximo = novoNo;
        novoNo->proximo = *cabeca;
    }
}

void exibirLista(No* cabeca) {
    if (cabeca == NULL) return;
    No* temp = cabeca;
    do {
        printf("%d -> ", temp->valor);
        temp = temp->proximo;
    } while (temp != cabeca);
    printf("(circular)\n");
}