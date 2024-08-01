#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    // Variaveis e entradas de dados
    int tamannho;
    printf("Informe o tamanho do vetor");
    scanf("%d",&tamannho);

    // Alocação dinamica da vetor
    int * vetor = (int *)malloc(tamannho*sizeof(int));
    if (vetor == NULL){
        printf("Erro ao alocar memoria");
        exit (1);
    }
    else{
        printf("Memoria alocada com sucesso!!!");
    }
    
    // Elementos do vetor 
    printf("informe os elementos do vetor");
    for( int count = 0; count < tamannho; count ++){
        scanf("%d",&vetor[count]);
    }

    // Saida do vetor
    printf("Vetor Inverso\n");
    for(int count = tamannho -1; count >= 0; count --){
        printf("%d\n",vetor[count]);
    }

    // Liberação de memória
    free (vetor);

    return 0;
}