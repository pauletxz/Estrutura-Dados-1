#include "fila.c"

int main(void){
    Fila* f = filaCria();
    filaInsere(f, 10);
    filaInsere(f, 20);
    filaInsere(f, 30);
    filaImprime(f);


    filaRemove(f);
    filaInsere(f, 40);
    filaImprime(f);
    filaLibera(f);
    return 0;
}