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

/*removerPrimeiro : Função para remover o primeiro elemento da lista*/
void removerPrimeiro(No** cabeca);

/*buscar :  Procura um valor espec´ıfico na lista e retorna a posição dele*/
int buscar(No* cabeca, int valor);

/*removerValor : Remove o n´o com o valor especificado da lista*/
void removerValor(No** cabeca, int valor);

/*inserirApos : Insere um novo valor ap´os um valor existente na lista*/
void inserirApos(No* cabeca, int valor, int novoValor);