#include "lista.h"

int main() {
    No* lista = NULL;

    inserirNoInicio(&lista, 10);
    inserirNoFim(&lista, 20);
    inserirNoInicio(&lista, 5);
    exibirLista(lista);

    removerPrimeiro(&lista);
    exibirLista(lista);

    return 0;
}