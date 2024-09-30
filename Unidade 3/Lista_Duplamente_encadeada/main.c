#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

int main(void){
    
    Lista2 *l = NULL;
    l = lst_insere(l, 3);
    l = lst_insere(l,5);
    l = lst_busca(l, 3);
    lst_imprime(l);
}