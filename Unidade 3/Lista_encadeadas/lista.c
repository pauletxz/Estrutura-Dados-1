#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    struct no* prox;
} No;

No* cria_lista() {
    return NULL;
}

No* insere(No* l, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->info = valor;
    novo->prox = l;
    return novo;
}

int maiores(No* l, int n) {
    int count = 0;
    while (l != NULL) {
        if (l->info > n) {
            count++;
        }
        l = l->prox;
    }
    return count;
}

No* ultimo(No* l) {
    if (l == NULL) return NULL;
    while (l->prox != NULL) {
        l = l->prox;
    }
    return l;
}

No* concatena(No* l1, No* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    No* p = l1;
    while (p->prox != NULL) {
        p = p->prox;
    }
    p->prox = l2;
    return l1;
}

No* retiraOcorrecias(No* l, int n) {
    No* anterior = NULL;
    No* atual = l;

    while (atual != NULL) {
        if (atual->info == n) {
            if (anterior == NULL) {
                l = atual->prox; // Remove o primeiro elemento
            } else {
                anterior->prox = atual->prox;
            }
            No* temp = atual;
            atual = atual->prox;
            free(temp);
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }
    return l;
}

void imprimeLista(No* l) {
    No* p = l;
    while (p != NULL) {
        printf("%d -> ", p->info);
        p = p->prox;
    }
    printf("NULL\n");
}