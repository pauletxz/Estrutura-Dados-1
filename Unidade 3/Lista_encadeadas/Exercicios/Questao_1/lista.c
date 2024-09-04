#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no* proximo;
} No;


No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->proximo = NULL;
    return novoNo;
}

void inserirNoInicio(No** cabeca, int valor) {
    No* novoNo = criarNo(valor);
    novoNo->proximo = *cabeca;
    *cabeca = novoNo;
}

void inserirNoFim(No** cabeca, int valor) {
    No* novoNo = criarNo(valor);
    if (*cabeca == NULL) {
        *cabeca = novoNo;
    } else {
        No* temp = *cabeca;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novoNo;
    }
}

// Função para exibir a lista
void exibirLista(No* cabeca) {
    No* temp = cabeca;
    while (temp != NULL) {
        printf("%d -> ", temp->valor);
        temp = temp->proximo;
    }
    printf("NULL\n");
}

// Função para remover o primeiro elemento da lista
void removerPrimeiro(No** cabeca) {
    if (*cabeca != NULL) {
        No* temp = *cabeca;
        *cabeca = (*cabeca)->proximo;
        free(temp);
    }
}