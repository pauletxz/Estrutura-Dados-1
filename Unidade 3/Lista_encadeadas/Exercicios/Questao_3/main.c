#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    No* lista = NULL; // Inicializando a lista vazia

    inserirNoInicio(&lista, 10);
    inserirNoFim(&lista, 20);
    inserirNoInicio(&lista, 5);
    exibirLista(lista);

    return 0;
}