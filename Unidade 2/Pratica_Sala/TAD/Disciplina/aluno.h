#include "disciplina.c"
#include <stdio.h>
#include <stdlib.h>

typedef struct aluno Aluno;

Aluno * criarAluno ();

void matriculaDisciplina(Aluno * aluno , Disciplina * disciplina);

void excluirAluno(Aluno * aluno);
