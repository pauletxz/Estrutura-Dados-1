#ifndef FILA_H
#define FILA_H

typedef struct fila Fila;

Fila* filaCria(void);

void filaInsere(Fila* f, int v);

int filaRemove(Fila* f);

int filaVazia(Fila* f);

int filaCheia(Fila* f);

void filaLibera(Fila* f);

void filaImprime(Fila* f);

int incrementa(int i);

#endif