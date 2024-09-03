#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
    char nome[50];
    int idade;
    double nota1;
    double nota2;
    double nota3;
    double media;
}Aluno;

int main(void){
    Aluno aluno;
    FILE * arquivo = fopen (nomes.txt, r);
    if (arquivo == NULL){
        printf("Erro ao abrir arquivo");
    }
    else{
        printf("Arquivo Aberto");
    }
    while(fread(&aluno, sizeof(Aluno),1,arquivo) == 1){
        printf("%s %d %lf %lf %lf %lf\n", aluno.nome, &aluno.idade, &aluno.nota1, &aluno.nota2, &aluno.nota3, &aluno.media) 
    }
}