#include <stdio.h>
#include <stdlib.h>
#include "pilha.c"

int main(void){
  Pilha *pilha = pilhaCria();
  int it;
  for (it = 0; it < 10; it++) {
    pilhaPush(pilha, it);
  }
  while (!pilhaVazia(pilha)) {
      printf("%.0f\n", pilhaPop(pilha));
    }
    printf("\n");
    pilhaLibera(pilha);
    return 0;
}
