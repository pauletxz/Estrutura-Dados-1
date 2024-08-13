#include "aluno.h"

main(void){
    Aluno *aluno = criarAluno(123, "Maria", 8.5);
    salvarAlunoEmArquivo(aluno);
    exibirAluno("alunos.txt");

    return 0;
}