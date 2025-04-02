#include <stdio.h>
#include <string.h>

struct Estudante {
    char sobrenome[50];
    char nome[50];
    float nota;
};

struct Funcionario {
    char sobrenome[50];
    char nome[50];
    float pagamento;
};

void aplicarAumento(struct Estudante alunos[], int totalAlunos, struct Funcionario empregados[], int totalEmpregados) {
    for (int i = 0; i < totalEmpregados; i++) {
        for (int j = 0; j < totalAlunos; j++) {
            if (strcmp(empregados[i].sobrenome, alunos[j].sobrenome) == 0 &&
                strcmp(empregados[i].nome, alunos[j].nome) == 0) {
                
                if (alunos[j].nota > 3.0) {
                    empregados[i].pagamento *= 1.10;
                    printf("Aumento dado a %s %s. Novo pagamento: R$ %.2f\n",
                           empregados[i].nome, empregados[i].sobrenome, empregados[i].pagamento);
                }
                break;
            }
        }
    }
}

int main() {
    struct Estudante alunos[] = {
        {"Silva", "Joao", 3.5},
        {"Santos", "Maria", 2.8},
        {"Oliveira", "Carlos", 4.0}
    };
    int totalAlunos = sizeof(alunos) / sizeof(alunos[0]);

    struct Funcionario empregados[] = {
        {"Silva", "Joao", 5000.0},
        {"Santos", "Maria", 4500.0},
        {"Oliveira", "Carlos", 6000.0}
    };
    int totalEmpregados = sizeof(empregados) / sizeof(empregados[0]);

    aplicarAumento(alunos, totalAlunos, empregados, totalEmpregados);

    return 0;
}