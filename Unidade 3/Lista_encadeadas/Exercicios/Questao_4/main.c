#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    No* lista = NULL; // Inicializando a lista vazia

    inserirNoInicio(&lista, 10);
    inserirNoFim(&lista, 20);
    inserirNoInicio(&lista, 5);
    exibirLista(lista);

    int pos = buscar(lista, 10);
    printf("Posição de 10: %d\n", pos);

    removerValor(&lista, 10);
    exibirLista(lista);

    removerPrimeiro(&lista);
    exibirLista(lista);

    removerUltimo(&lista);
    exibirLista(lista);

    return 0;
}