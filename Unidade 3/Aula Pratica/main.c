#include "fruta.c"
#include <stdio.h>

int main(void){
  No * listaDeFrutas = NULL;
  int opcao;
  char nomeDaFruta[50];
  float valorPorKg;

  do{
      printf("1. Cadastrar Fruta\n");
      printf("2. Listar Frutas\n");
      printf("3. Sair\n");
      scanf("%d",&opcao);
      switch (opcao)
      {
      case 1:
      printf("Digite o nome da fruta: ");
      scanf("%s", nomeDaFruta);
      printf("Digite o valor da fruta por kg: ");
      scanf("%f", &valorPorKg);
      listaDeFrutas = inserirNoInicio(listaDeFrutas, nomeDaFruta, valorPorKg);
        break;

      case 2:
      printf("Lista de frutas:\n");
      printf("Nome\tValor\n");
      exibirListaDeFrutas(listaDeFrutas);
        break;
      
      default:
        break;
      }
  }while(opcao != 3);
  return 0;
}