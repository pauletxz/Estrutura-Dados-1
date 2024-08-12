#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.c"

main(void){
    Aluno *aluno = criarAluno(123, "Maria", 8.5);
    salvarAlunoEmArquivo(aluno);
    exibirAluno("alunos.txt");

    return 0;
}