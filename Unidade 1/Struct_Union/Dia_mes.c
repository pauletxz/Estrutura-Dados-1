#include <stdio.h>

typedef enum diames{
    Janeiro = 1;
    Fevereiro,
    Marco,
    Abril,
    Maio,
    Junho,
    Julho,
    Agosto,
    Setembro,
    Outubro,
    Novembro,
    Dezembro
}DiaMes;

typedef enum diasemana {

    Segunda = 2;
    Terca,
    Quarta,
    Quinta,
    Sexta,
    Sabado,
    Domingo,

}DiaSemana;

int main(void){
    DiaSemana dias;
    DiaMes mes;

    printf("Informe o dia da semana: 2-8 \t");
    scanf("%d",&dias);

    printf("Infomee um mes: 1 - 12");
    scanf("%d",&mes);
    switch (mes) {

        case Janeiro:
        printf("Janeiro");
        break;

        case Fevereiro:
        printf("Fevereiro");
        break;

        case Marco:
        printf("Marco");
        break;

        case Abril:
        printf("Abril");
        break;

        case Maio:
        printf("Maio");
        break;

        case Junho:
        printf("Junho");
        break;

        case Julho:
        printf("Julho");
        break;

        case Agosto:
        printf("Agosto");
        break;

        case Setembro:
        printf("Setembro");
        break;

        case Outubro:
        printf("Outubro");
        break;

        case Novembro:
        printf("Novembro");
        break;

        case Dezembro:
        printf("Dezembro");
        break;

        default:
        printf("Mês inválido");
        break;

        }
    
    switch (dias){
        case Segunda :
        printf ("Segunda-Feira");
        break;

        case Terca :
        printf ("TerÃ§a-Feira");
        break;

        case Quarta: 
        printf("Quarta-Feira");
        break;

        case Quinta:
        printf("Quinta-Feira");
        break;

        case Sexta:
        printf("Sexta-Feira");
        break;

        case Sabado:
        printf("Sabado");
        break;

        case Domingo:
        printf("Domingo");
        break;

        default:
        printf("Dia Invalido");
        break
    }
    
    return 0;  

}