#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    No* lista = NULL;

    inserirNoInicio(&lista, 10);
    inserirNoFim(&lista, 20);
    inserirNoInicio(&lista, 5);
    exibirLista(lista);

    int pos = buscar(lista, 10);
    printf("Posicao de 10: %d\n", pos);

    removerValor(&lista, 10);
    exibirLista(lista);

    inserirApos(lista, 5, 15);
    exibirLista(lista);

    return 0;
}