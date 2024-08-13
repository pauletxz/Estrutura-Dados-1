#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;

FILE * open_file(char * name, char* modo);

Aluno * criarAluno(int mat, char nomeAluno[], float mediaAluno);

void salvarAlunoEmArquivo (Aluno * aluno);

void exibirAluno (char nomeDoArquivo);