#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

int main(void) {
    Alunos * alunos = alocaAluno();
    preencher(alunos);
    imprimir(alunos);
    free(alunos);
    return 0;
}