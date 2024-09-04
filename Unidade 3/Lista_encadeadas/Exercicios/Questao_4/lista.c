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
        novoNo->proximo = *cabeca;
    } else {
        No* temp = *cabeca;
        while (temp->proximo != *cabeca) {
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

int buscar(No* cabeca, int valor) {
    if (cabeca == NULL) return -1;
    No* temp = cabeca;
    int posicao = 0;
    do {
        if (temp->valor == valor) {
            return posicao;
        }
        temp = temp->proximo;
        posicao++;
    } while (temp != cabeca);
    return -1; // Valor não encontrado
}

void removerValor(No** cabeca, int valor) {
    if (*cabeca == NULL) return;

    No* temp = *cabeca;
    No* anterior = NULL;
    
    // Encontre o nó a ser removido
    do {
        if (temp->valor == valor) break;
        anterior = temp;
        temp = temp->proximo;
    } while (temp != *cabeca);

    if (temp->valor != valor) return; // Valor não encontrado

    if (temp == *cabeca) { // Remover o primeiro nó
        No* ultimo = *cabeca;
        while (ultimo->proximo != *cabeca) {
            ultimo = ultimo->proximo;
        }
        if (temp == temp->proximo) { // Único nó na lista
            *cabeca = NULL;
        } else {
            *cabeca = temp->proximo;
            ultimo->proximo = *cabeca;
        }
    } else { // Remover um nó intermediário ou final
        anterior->proximo = temp->proximo;
    }
    free(temp);
}

void removerPrimeiro(No** cabeca) {
    if (*cabeca != NULL) {
        removerValor(cabeca, (*cabeca)->valor);
    }
}

void removerUltimo(No** cabeca) {
    if (*cabeca == NULL) return;

    No* temp = *cabeca;
    No* anterior = NULL;
    while (temp->proximo != *cabeca) {
        anterior = temp;
        temp = temp->proximo;
    }

    if (anterior != NULL) {
        anterior->proximo = *cabeca;
    } else { // Apenas um nó na lista
        *cabeca = NULL;
    }
    free(temp);
}