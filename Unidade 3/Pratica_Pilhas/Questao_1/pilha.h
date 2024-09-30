#include "pilha.c"

typedef struct pilha Pilha;

Pilha* pilhaCria(void);

void pilhaPush(Pilha* p, float v);

float pilhaPop(Pilha* p);

int pilhaVazia(Pilha* p);

void pilhaLibera(Pilha* p);w