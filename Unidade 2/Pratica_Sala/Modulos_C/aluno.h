//*Arquivo cabecalho para tipo abstrato de dados (TAD) Aluno */

typedef struct alunos Alunos;

//*Funcao para imprimir uma struct Alunos. A Funcao recebe um endereco para aluno e imprime os dados*/
void imprimir(Alunos * alunos);

//*Funcoa para preencher uma struct Alunos. A funcao recebe um endereco para aluno*/
void preencher(Alunos * alunos);

//*Funcao que aloca dinamicamente uma struct alno na memoria*/
Alunos * alocaAluno(void);