#include <stdio.h>
#include <stdlib.h>

typedef no No;

No* cria_lista;
/*Função para inserir um elemento no início da lista*/
No* insere(No* l, int valor);

/*Função maiores: Retorna o número de nós com valores maiores que n */
int maiores(No* l, int n);

/*Função ultimo: Retorna o ponteiro para o último nó da lista*/
No* ultimo(No* l);

/*Função concatena: Concatena duas listas*/
No* concatena(No* l1, No* l2);

/*Função retiraOcorrencias: Remove todas as ocorrências de n da lista*/
No* retiraOcorrecias(No* l, int n);

/*Função imprimeLista: Função para imprimir a lista*/
void imprime_lista(No* l);