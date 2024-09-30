typedef struct lista
{
  float info;
  struct lista *prox;
}Lista;

typedef struct pilha {
  Lista* prim;
}Pilha;

Pilha* criarPilha(void){
  Pilha = (Pilha*)malloc(sizeof(Pilha));
  Pilha->prim = NULL;
  return p;
}

Pilha* popPilha(Pilha* p){
  Lista* t;
  float v;
  if (vaziaPilha(p)) {
    printf("Pilha vazia!\n");
    exit(1);
  }
  t = p ->prim;
  v = t ->info;
  p->prim = t->prox;
  free(t);
  return v;
}

Pilha* pushPilha(Pilha* p, float v) {
  Lista* l = (Lista*)malloc(sizeof(Lista));
  l->info = v;
  l->prox = p->prim;
  p->prim = n;
}

Pilha* vaziaPilha(Pilha* p){

  if(p->prim == NULL){
    prinf("Pilha vazia");
    return 1;
}
}

Pilha liberarPilha(Pilha* p){
  Lista * q = p->prim;
  Lista * t;
  while (q != NULL){
    t = q->prox;
    free(q);
    q = t;
  }
  free(p)
}

Pilha imprimirPilha(Pilha* l){
  Lista *p;
  for(p=1->prim; p!=NULL;p=p->prox){
    printf("%f\n", p->info);
  }
}