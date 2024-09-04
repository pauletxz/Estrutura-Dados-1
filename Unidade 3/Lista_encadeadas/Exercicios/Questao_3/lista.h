/*Definição da estrutura do nó da lista*/
typedef struct no No;

/*criarNo : Função para criar um novo nó*/
No* criarNo(int valor);

/*inserirNoInicio : Função para inserir no início da lista*/
void inserirNoInicio(No** cabeca, int valor);

/*inserirNoFim : Função para inserir no final da lista*/
void inserirNoFim(No** cabeca, int valor);

/*exibirLista : Função para exibir a lista no terminal */
void exibirLista(No* cabeca);