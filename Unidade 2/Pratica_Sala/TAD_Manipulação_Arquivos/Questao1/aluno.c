#include "aluno.h"

typedef struct aluno
{
    int matricula;
    char nome[50];
    float media;
}Aluno;

FILE * open_file(char * name, char* modo){
    FILE * arquivo = fopen(name, modo);
    if(arquivo== NULL){
        printf("Can't open this file");
        exit(1);
    }
    else{
        printf("File open");
    }

    return arquivo;
}

Aluno * criarAluno(int mat, char nomeAluno[], float mediaAluno){
    
    Aluno * aluno = malloc(sizeof*aluno);
    if (aluno == NULL){
        printf("Memory allocation failed");
        exit(1);
    }
    aluno->matricula= mat;
    strcpy(aluno->nome, nomeAluno);
    aluno->media= mediaAluno;
    return aluno;
}

void salvarAlunoEmArquivo (Aluno * aluno){
    FILE * arquivo;

    arquivo = open_file("alunos.txt", "a");
    fprintf(arquivo, "Nome:%s\t Matricula:%d\t Media:%.1f\n", aluno->nome, aluno->matricula, aluno->media);
    fclose(arquivo);
}

void exibirAluno (char nomeDoArquivo){
    Aluno aluno;
    FILE * arquivo;

    arquivo = open_file(nomeDoArquivo, "a");

    while(fscanf(arquivo,"Nome:%s\t Matricula:%d\t Media:%.1f\n", aluno.nome, &aluno.matricula, &aluno.media) != EOF){
        printf("Nome:%s\t Matricula:%d\t Media:%f\n", aluno.nome, aluno.matricula, aluno.media);
    }
    fclose(arquivo);
}