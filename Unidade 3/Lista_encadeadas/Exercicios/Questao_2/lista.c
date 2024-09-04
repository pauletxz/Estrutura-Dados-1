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

void exibirLista(No* cabeca) {
    No* temp = cabeca;
    while (temp != NULL) {
        printf("%d -> ", temp->valor);
        temp = temp->proximo;
    }
    printf("NULL\n");
}

void removerPrimeiro(No** cabeca) {
    if (*cabeca != NULL) {
        No* temp = *cabeca;
        *cabeca = (*cabeca)->proximo;
        free(temp);
    }
}

int buscar(No* cabeca, int valor) {
    int posicao = 0;
    No* temp = cabeca;
    while (temp != NULL) {
        if (temp->valor == valor) {
            return posicao;
        }
        temp = temp->proximo;
        posicao++;
    }
    return -1; // Valor não encontrado
}

void removerValor(No** cabeca, int valor) {
    No* temp = *cabeca;
    No* anterior = NULL;
    while (temp != NULL && temp->valor != valor) {
        anterior = temp;
        temp = temp->proximo;
    }
    if (temp == NULL) return; // Valor não encontrado
    if (anterior == NULL) {
        *cabeca = temp->proximo; // Remover o primeiro nó
    } else {
        anterior->proximo = temp->proximo; // Remover nó do meio ou final
    }
    free(temp);
}

void inserirApos(No* cabeca, int valor, int novoValor) {
    No* temp = cabeca;
    while (temp != NULL && temp->valor != valor) {
        temp = temp->proximo;
    }
    if (temp != NULL) {
        No* novoNo = criarNo(novoValor);
        novoNo->proximo = temp->proximo;
        temp->proximo = novoNo;
    }
}