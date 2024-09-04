#include "lista.c"

int main() {
    No* l1 = cria_lista();
    No* l2 = cria_lista();

    // Inserindo elementos nas listas
    l1 = insere(l1, 2);
    l1 = insere(l1, 1);
    l1 = insere(l1, 3);
    
    printf("Lista 1: ");
    imprimeLista(l1);

    printf("Lista 2: ");
    imprimeLista(l2);

    // Testando a função maiores
    int count = maiores(l1, 4);
    printf("\nNúmero de elementos maiores que 4 na Lista 1: %d\n", count);

    // Testando a função ultimo
    No* ult = ultimo(l1);
    if (ult != NULL) {
        printf("Último elemento da Lista 1: %d\n", ult->info);
    }

    // Testando a função concatena
    No* listaConcatenada = concatena(l1, l2);
    printf("\nLista concatenada: ");
    imprimeLista(listaConcatenada);

    // Testando a função retiraOcorrecias
    listaConcatenada = retiraOcorrecias(listaConcatenada, 5);
    printf("\nLista após remover o número 5: ");
    imprimeLista(listaConcatenada);

    return 0;
}
