#include <stdio.h>
#include <stdlib.h>

#define MAX_FUNCIONARIOS 10

typedef struct funcionario{
    char nome[50];
    float salario;
    int id; 
    char cargo[50];
}Funcionario;

void preencher(Funcionario * funcionario){

    printf("Digite o nome do funcionario: ");
    scanf(" %[^\n]", funcionario->nome);

    printf("Digite o salario do funcionario: ");
    scanf("%f", &funcionario->salario);

    printf("Digite o id do funcionario: ");
    scanf("%d", &funcionario->id);

    printf("Digite o cargo do funcionario: ");
    scanf(" %[^\n]", funcionario->cargo);
}

void exibir(Funcionario * funcionario){
    printf("Nome: %s\n", funcionario->nome);
    printf("Cargo: %s \n", funcionario->cargo);
    printf("Identificacao: %d \n",funcionario->id);
    printf("Salario: %f \n",funcionario->salario);
}

void alterarSalario(Funcionario * funcionario){
    printf("Digite o novo salario do funcionario: ");
    scanf("%f",&funcionario->salario);
}

void maiorMenorSalario(Funcionario * funcionarios, int numFuncionarios) {
    float maiorSalario = funcionarios[0].salario;
    float menorSalario = funcionarios[0].salario;
    int indiceMaiorSalario = 0;
    int indiceMenorSalario = 0;

    for (int i = 1; i < numFuncionarios; i++) {
        if (funcionarios[i].salario > maiorSalario) {
            maiorSalario = funcionarios[i].salario;
            indiceMaiorSalario = i;
        }
        if (funcionarios[i].salario < menorSalario) {
            menorSalario = funcionarios[i].salario;
            indiceMenorSalario = i;
        }
    }

    printf("Funcionario com maior salario:\n");
    printf("Cargo: %s\n", funcionarios[indiceMaiorSalario].cargo);
    printf("Salario: %f\n", funcionarios[indiceMaiorSalario].salario);

    printf("Funcionario com menor salario:\n");
    printf("Cargo: %s\n", funcionarios[indiceMenorSalario].cargo);
    printf("Salario: %f\n", funcionarios[indiceMenorSalario].salario);
}
int main (void){
    Funcionario funcionarios[MAX_FUNCIONARIOS];
    int numFuncionarios = 0;
    int opcao = 0;

    printf("Quantos funcionarios deseja cadastrar? (Maximo %d)\n", MAX_FUNCIONARIOS);
    scanf("%d", &numFuncionarios);

    if (numFuncionarios > MAX_FUNCIONARIOS) {
        printf("Numero de funcionarios excede o limite!\n");
        return 1;
    }

    for (int i = 0; i < numFuncionarios; i++) {
        printf("Funcionario %d:\n", i + 1);
        preencher(&funcionarios[i]);
    }

    for (int i = 0; i < numFuncionarios; i++) {
        printf("Funcionario %d:\n", i + 1);
        exibir(&funcionarios[i]);
    }

    printf("Voce deseja alterar o salario de algum funcionario? (Digite 1 para alteracao ou digite 0 para finalizar o programa)\n");
    scanf("%d",&opcao);

    if(opcao == 1){
        int idFuncionario;
        printf("Digite o id do funcionario que deseja alterar o salario: \n");
        scanf("%d", &idFuncionario);

        for (int i = 0; i < numFuncionarios; i++) {
            if (funcionarios[i].id == idFuncionario) {
                alterarSalario(&funcionarios[i]);
                exibir(&funcionarios[i]);
                maiorMenorSalario(funcionarios, numFuncionarios);
                break;
            }
        }
    }

    return 0;
}