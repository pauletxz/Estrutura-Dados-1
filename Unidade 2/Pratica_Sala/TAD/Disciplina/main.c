#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "disciplina.h"

int main (void){
    Disciplina * disciplina;
    Aluno * aluno;

    criarDisciplina();
    criarAluno();

    matriculaDisciplina(&aluno, &disciplina);
    excluirDisciplina(&disciplina);
    excluirAluno(&aluno);

    return 0;
}