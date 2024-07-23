#include <stdio.h>
#include <stdlib.h>

int main(void){
    int tamannho;
    printf("Informe o tamanho do vetor");
    scanf("%d",&tamannho);
    int * vetor = (int *)calloc(tamannho,sizeof(int));
    if (vetor == NULL){
        printf("Erro ao alocar memoria");
        exit (1);
    }
    else{
        printf("Memoria alocada com sucesso!!!");
    }
    
    printf("informe os elementos do vetor");
    for( int count = 0; count < tamannho; count ++){
        scanf("%d",&vetor[count]);
    }
    printf("Vetor Inverso\n");
    for(int count = tamannho -1; count >= 0; count --){
        printf("%d\n",vetor[count]);
    }
    free (vetor);

    return 0;
}