#include <stdio.h>

typedef enum diaSemana {

    Segunda,
    Terca,
    Quarta,
    Quinta,
    Sexta,
    Sabado,
    Domingo

}DiaSemana;

int main(void){
    DiaSemana dias;
    dias = Segunda;

    printf("Dia da semana : %d",dias);
    
    return 0;  

}