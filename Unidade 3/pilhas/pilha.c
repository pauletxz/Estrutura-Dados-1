#include <stdio.h>
#define N 50

typedef struct pilha
{
  int n;
  float vet[N];
}Pilha;

Pilha* pilhaCria(void){
  Pilha* p = (Pilha*)malloc(sizeof(Pilha));
  p->n = 0;
  return p;
}

void pilhaPush(Pilha* p, float v) {
  if (p->n == N) {
    printf("Capacidade da pilha estourou.");
    exit(1);}
p->vet[p->n] = v;
p->n++;
}

int pilhaVazia( Pilha* p) {
  return p->n == 0;
}

float pilhaPop(Pilha* p){
  float v;
  if (pilhaVazia(p)) {
    printf("Pilha vazia.");
    exit(1);
  }
  v = p->vet[p->n-1];
  p->n--;
  return v;
}

void pilhaLibera(Pilha* p){
  free(p);
}

void pilhaImprimir(Pilha* p){
  for(int i = p->n - 1; i >= 0; i--){
    printf("%f ", p->vet[i]);
    }
}