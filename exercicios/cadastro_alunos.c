#include <stdio.h>
#include <string.h>

struct aluno {
    char nome[80];
    char matricula[8];
    char turma;
    float p1;
    float p2;
    float p3;
    float media;
};
typedef struct aluno Aluno;

// Função para criar um aluno
struct aluno criarAluno() {
    struct aluno a;

    printf("Digite seu nome: \n");
    fgets(a.nome, sizeof(a.nome), stdin);
    a.nome[strcspn(a.nome, "\n")] = '\0'; 

    printf("Digite sua matricula: \n");
    fgets(a.matricula, sizeof(a.matricula), stdin);
    a.matricula[strcspn(a.matricula, "\n")] = '\0'; 

    printf("Digite sua turma: \n");
    scanf(" %c", &a.turma);

    printf("Digite a nota da prova um: \n");
    scanf("%f", &a.p1);

    printf("Digite a nota da prova dois: \n");
    scanf("%f", &a.p2);

    printf("Digite a nota da prova tres: \n");
    scanf("%f", &a.p3);

    a.media = (a.p1 + a.p2 + a.p3) / 3;
    printf("Sua média eh: %.2f\n", a.media);

    while (getchar() != '\n');

    return a;
}

// Função para checar os dados do aluno
void checarAluno(struct aluno a) {
    printf("\n--- REGISTRO ---\n");
    printf("Nome: %s\n", a.nome);
    printf("Matricula: %s\n", a.matricula);
    printf("Turma: %c\n", a.turma);
    printf("Notas: %.2f, %.2f, %.2f\n", a.p1, a.p2, a.p3);
    printf("Média: %.2f\n", a.media);
    printf("----------------\n");
}

int main() {
    int opcao;
    struct aluno alunoCriado;
    int euAluno = 0; 

    do {
        printf("\n1. Registrar aluno\n");
        printf("2. Checar registro.\n");
        printf("0. Sair.\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

    
        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                alunoCriado = criarAluno();
                euAluno = 1; 
                printf("Registro criado com sucesso.\n");
                break;

            case 2:
                if (euAluno) {
                    checarAluno(alunoCriado); 
                } else {
                    printf("Nenhum registro encontrado. Crie um registro primeiro.\n");
                }
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}