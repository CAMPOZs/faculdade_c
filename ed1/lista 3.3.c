#include <stdio.h>
#include <string.h>

struct registro {
    char nome[50];
    int idade;
    float salario;
    char sexo[20];
};

struct registro criarRegistro() {
    struct registro r;

    printf("Digite seu nome: \n");
    scanf("%s", r.nome);

    printf("Informe sua idade: \n");
    scanf("%d", &r.idade);
    if (r.idade < 18) {
        printf("Idade invalida\n");
        r.idade = -1;
    }

    printf("Informe seu salario: \n");
    scanf("%f", &r.salario);

    int opcao;
    do {
        printf("\nSelecione seu genero: \n");
        printf("1. Masculino\n");
        printf("2. Feminino\n");
        printf("3. Indefinido\n");
        printf("4. Outro\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                strcpy(r.sexo, "Masculino");
                break;
            case 2:
                strcpy(r.sexo, "Feminino");
                break;
            case 3:
                strcpy(r.sexo, "Indefinido");
                break;
            case 4:
                printf("Informe seu genero: \n");
                scanf("%s", r.sexo);
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                opcao = -1;
                break;
        }
    } while (opcao == -1);

    return r;
}

void atribuirSalario(struct registro *r, float valor) {
    if (valor >= 0) {
        r->salario = valor;
        printf("Salario atribuido com sucesso!\n");
    } else {
        printf("Valor de salario invalido. O salario nao pode ser negativo.\n");
    }
}

void checarRegistro(struct registro r) {
    printf("\n--- REGISTRO ---\n");
    printf("Nome: %s\n", r.nome);
    printf("Idade: %d\n", r.idade);
    printf("Salario: %.2f\n", r.salario);
    printf("Sexo: %s\n", r.sexo);
    printf("----------------\n");
}

int main() {
    int opcao;
    struct registro registroCriado;
    int meuRegistro = 0;
    float novoSalario;

    do {
        printf("\n1. Criar registro\n");
        printf("2. Checar registro\n");
        printf("3. Atribuir salario\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                registroCriado = criarRegistro();
                meuRegistro = 1;
                printf("Registro criado com sucesso!\n");
                break;

            case 2:
                if (meuRegistro) {
                    checarRegistro(registroCriado);
                } else {
                    printf("Crie um registro primeiro.\n");
                }
                break;

            case 3:
                if (meuRegistro) {
                    printf("Digite o valor do salario a ser atribuido: ");
                    scanf("%f", &novoSalario);
                    atribuirSalario(&registroCriado, novoSalario);
                } else {
                    printf("Crie um registro primeiro.\n");
                }
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}