#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

#define MAX 10

struct fila {
    int inicio;
    int fim;
    int numeroElementos;
    int dados[MAX];
};

Fila* filaCria(void) {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->inicio = 0;
    f->fim = 0;
    f->numeroElementos = 0;
    return f;
}

void filaInsere(Fila* f, int v) {
    if (filaCheia(f)) {
        printf("Capacidade da fila estourou!"); 
        exit(1); // aborta programa
    }
    f->dados[f->fim] = v;
    f->fim = incrementa(f->fim);
    f->numeroElementos++;
}

int filaRemove(Fila* f) {
    if (filaVazia(f)) {
        printf("Fila vazia!"); 
        exit(1); // aborta programa
    }

    int elemento = f->dados[f->inicio];
    f->inicio = incrementa(f->inicio);
    f->numeroElementos--;
    return elemento;
}   

int filaVazia(Fila* f) {
    return (f->inicio == f->numeroElementos);
}

int filaCheia(Fila* f) {
    return (f->numeroElementos == MAX);
}

void filaLibera(Fila* f) {
    free(f);
}



void filaImprime(Fila* f) {
    int i;
    printf("Fila: \" ");
    for (i =0; i<f->numeroElementos; i++)
        printf("%d ", f->dados[incrementa(i)]);
    printf("\"\n");
}

int incrementa(int i) {
    return (i + 1) % MAX;
}