#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da lista encadeada
typedef struct no {
    int info;
    struct no* prox;
} Lista;

// Função para criar uma lista vazia
Lista* cria_lista() {
    return NULL;
}

// Função para inserir um elemento no início da lista
Lista* insere(Lista* l, int valor) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = l;
    return novo;
}

// Função 1: Retorna o número de nós com valores maiores que n
int maiores(Lista* l, int n) {
    int count = 0;
    while (l != NULL) {
        if (l->info > n) {
            count++;
        }
        l = l->prox;
    }
    return count;
}

// Função 2: Retorna o ponteiro para o último nó da lista
Lista* ultimo(Lista* l) {
    if (l == NULL) return NULL;
    while (l->prox != NULL) {
        l = l->prox;
    }
    return l;
}

// Função 3: Concatena duas listas
Lista* contatena(Lista* l1, Lista* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    Lista* p = l1;
    while (p->prox != NULL) {
        p = p->prox;
    }
    p->prox = l2;
    return l1;
}

// Função 4: Remove todas as ocorrências de n da lista
Lista* retira_n(Lista* l, int n) {
    Lista* anterior = NULL;
    Lista* atual = l;

    while (atual != NULL) {
        if (atual->info == n) {
            if (anterior == NULL) {
                l = atual->prox; // Remove o primeiro elemento
            } else {
                anterior->prox = atual->prox;
            }
            Lista* temp = atual;
            atual = atual->prox;
            free(temp);
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }
    return l;
}

// Função para imprimir a lista
void imprime_lista(Lista* l) {
    Lista* p = l;
    while (p != NULL) {
        printf("%d -> ", p->info);
        p = p->prox;
    }
    printf("NULL\n");
}

// Função principal (main) para testar as funções
int main() {
    Lista* l1 = cria_lista();
    Lista* l2 = cria_lista();

    // Inserindo elementos nas listas
    l1 = insere(l1, 3);
    l1 = insere(l1, 5);
    l1 = insere(l1, 7);
    l1 = insere(l1, 9);
    l2 = insere(l2, 2);
    l2 = insere(l2, 4);
    l2 = insere(l2, 6);
    
    printf("Lista 1: ");
    imprime_lista(l1);

    printf("Lista 2: ");
    imprime_lista(l2);

    // Testando a função maiores
    int count = maiores(l1, 4);
    printf("\nNúmero de elementos maiores que 4 na Lista 1: %d\n", count);

    // Testando a função ultimo
    Lista* ult = ultimo(l1);
    if (ult != NULL) {
        printf("Último elemento da Lista 1: %d\n", ult->info);
    }

    // Testando a função contatena
    Lista* lista_concatenada = contatena(l1, l2);
    printf("\nLista concatenada: ");
    imprime_lista(lista_concatenada);

    // Testando a função retira_n
    lista_concatenada = retira_n(lista_concatenada, 5);
    printf("\nLista após remover o número 5: ");
    imprime_lista(lista_concatenada);

    return 0;
}
