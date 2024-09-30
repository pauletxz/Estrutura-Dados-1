#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
 


struct lista2{
    int info;
    struct lista2* ant;
    struct lista2* prox;
};

Lista2* lst_insere(Lista2 *l, int v){

    Lista2* novo = (Lista2*) malloc(sizeof(Lista2));
    if (novo == NULL)
    {
        printf("[ERRO] memoria insuficiente!");
        exit(1);
    }
    novo->info = v;
    novo->prox = l;
    novo->ant = NULL;
    if(l!=NULL)
        l->ant = novo;
    return novo;
}



Lista2 * lst_insere_ordenado(Lista2 *l, int v){
    //inserção de elementos ordenados na lista duplamente encadeada
    Lista2 * novo = (Lista2*) malloc(sizeof(Lista2));
    novo->info = v;
    Lista2 * ant = NULL;
    Lista2 * p = l;
    while(p!=NULL && p->info < v){
        ant = p;
        p = p->prox;
    }
    if(ant==NULL){
        novo->prox = l;
        novo->ant = NULL;
        l->ant = novo;
        return novo;
    }
    else{
        novo->prox = ant->prox;
        novo->ant = ant;
        ant->prox = novo;
        if(p!=NULL)
            p->ant = novo;
        return l;
    }

}


void lst_imprime(Lista2*l){
	Lista2*p;
	for(p=l; p!=NULL; p=p->prox){
		printf(" Info = %d \n", p->info);
	}

}

Lista2* lst_busca(Lista2 *l, int v){

    Lista2 *p;
    for(p=l; p!=NULL; p=p->prox){
        if(p->info ==v)
			return p;
    }
    return NULL;

}

Lista2* lst_retira(Lista2 *l, int v){
    Lista2* p = lst_busca(l,v);

    if(p->prox!=NULL)
        p->prox->ant=p->ant;
    if(l==NULL)
        return l;
    if(p==l)
        l=p->prox;
    else
        p->ant->prox = p->prox;
    return l;

}