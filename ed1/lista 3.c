//1
#include <stdio.h>
#include <string.h>

struct conta
{
    char nome[50];
    int numero;
    float saldo;
};

struct conta criarConta()
{
struct conta c;
printf("Digite seu nome: \n");
scanf("%s", c.nome);

printf("Digite o numero da sua conta: \n");
scanf("%d", &c.numero);

c.saldo = 0.0;

return c;
};

void deposito(struct conta *c, float valor){
    if (valor < 0)
    {
        printf("Valor invalido\n");
    } else {
        c -> saldo += valor;
        printf("Deposito realizado\n");
    }
}

void checarSaldo(struct conta c){
    printf("Saldo disponivel: %.2f\n", c.saldo);
}

void sacar(struct conta *c, float valor){
    if (valor > 0 && valor <= c->saldo)
    {
        c ->saldo -= valor;
        printf("Sucesso.\n");
    } else {
        printf("Operação inválida.\n");
    }
}

void chegarNumero(struct conta c){
    printf("O numero da sua conta eh: %d\n", c.numero);
}

int main(){
    float valor;
    int opcao;
    struct conta minhaConta;
    int contaCriada = 0;

    do
    {
        printf("\nBem Vindo.\n");
        printf("\nMENU\n\n");
        printf("1. Criar Conta\n");
        printf("2. Depositar saldo\n");
        printf("3. Checar saldo\n");
        printf("4. Sacar saldo\n");
        printf("5. Checar numero da conta\n");
        printf("0. Sair.\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            minhaConta = criarConta();
            contaCriada = 1;
            break;

        case 2:
            if (contaCriada)
            {
                printf("Determine o valor a ser debitado: \n");
                scanf("%f", &valor);

                deposito(&minhaConta, valor);
            } else {
                printf("Erro.\n");
            }
            break;
            
        case 3:
            if (contaCriada)
            {
                checarSaldo(minhaConta);
            }else{
                printf("Voce deve ter uma conta.\n");
            }
            break;

        case 4:
            if (contaCriada)
            {
                printf("Determine o valor do saque: \n");
                scanf("%f", &valor);

                sacar(&minhaConta, valor);
            }
            break;

        case 5:
            if (contaCriada)
            {
                chegarNumero(minhaConta);
            } else {
                printf("Voce deve ter uma conta.\n");
            }
            break;

        case 0:
        break;
        
        default:
            printf("Erro.\n");
        }
    } while (opcao != 0);

return 0;
    
}

//descobrir como o funcionario volta às opções após criar a conta.





//2.
#include<stdio.h>
#include<string.h>

struct registro
{
    char nome[50];
    int idade;
    float salario;
    char sexo[20];
};

struct registro criarRegistro()
{
    struct registro r;
    printf("Digite seu nome: \n");
    scanf("%s", r.nome);//não se utiliza "&" para strings (char)

    printf("Informe sua idade: \n");
    scanf("%d", &r.idade);
    if (r.idade < 18)
    {
        printf("Idade invalida\n");
        r.idade = -1;//marcador de idade invalida
    }
    
    printf("Informe seu salario: \n");
    scanf("%f", &r.salario);

    int opcao;

    do
    {
        printf("selecione seu genero: \n\n");
        printf("1. Masculino\n");
        printf("2. Feminino\n");
        printf("3. Indefinido\n");
        printf("4. Outro\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            strcpy(r.sexo, "Masculino.\n");
            break;

            case 2:
            strcpy(r.sexo, "Feminino.\n");
            break;

            case 3:
            strcpy(r.sexo, "Eh complicado.\n");
            break;
        
            case 4:
            printf("Informe seu genero: \n");
            scanf("%s", r.sexo);
            break;

        default:
        printf("Erro.\n");
        opcao = -1;//força o loop a continuar.
        }
    } while (opcao == -1);//maneira mais fácil de fechar o loop.
    return r;

};

//função para chegagem do registro
void checarRegistro(struct registro r){
    printf("\n---REGISTRO---\n");
    printf("Nome: %s\n", r.nome);
    printf("Idade: %d\n", r.idade);
    printf("Genero: %s\n", r.sexo);
    printf("Salario: %.2f\n", r.salario);
}

int main(){
    int opcao;
    struct registro registroCriado;
    int meuRegistro = 0;

    do
    {
        printf("1. Criar registro\n");
        printf("2. Checar registro\n");
        printf("0. Sair");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            registroCriado = criarRegistro();
            meuRegistro = 1;
            printf("Sucesso.\n");
            break;

        case 2:
            if (meuRegistro)
            {
                checarRegistro(registroCriado);
            }else {
                printf("Crie um registro.\n");
            }
            break;

        case 0:
        break;

        default:
        printf("Erro\n");
            break;
        }
    } while (opcao != 0);
    
    return 0;
    
}




//3
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





//4
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




//5
//professora, não compreendi como fazer essa questão.




//6
#include <stdio.h>
#include <string.h>

struct produto {
    int codigo, quantidade;
    float valor;
    char nome[50];
};
typedef struct produto Produto;

Produto cadastrarProduto() {
    Produto p;

    printf("Digite o codigo do produto: \n");
    scanf("%d", &p.codigo);

    printf("Digite o nome do produto: \n");
    scanf("%s", p.nome);
    getchar();

    printf("Digite a quantidade em estoque: \n");
    scanf("%d", &p.quantidade);

    printf("Digite o valor do produto: \n");
    scanf("%f", &p.valor);

    return p;
}

void notaFiscal(Produto produtos[], int quantidades[], int totalProdutos[]){
    float valorTotal = 0;

    printf("\n---NOTA FISCAL---\n");
    for (int i = 0; i < totalProdutos; i++)
    {
        float valorProduto = produtos[i].valor * quantidades[i];
        printf("Produto: %s\n", produtos[i].nome);
        printf("Quantidade: %d\n", quantidades[i]);
        printf("Valor unitario: %.2f\n", produtos[i].valor);
        printf("Valor: %.2f\n", valorProduto);
        valorTotal += valorProduto;
    }
    printf("Valor total: R$%.2f\n", valorTotal);
}

int main(){
    Produto produtos[100];
    int quantidades[100];
    int totalProdutos = 0;
    int opcao;

    do {
        printf("\n1. Cadastrar produto\n");
        printf("2. Realizar venda\n");
        printf("3. Imprimir nota fiscal\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            if (totalProdutos < 100){
                produtos[totalProdutos] = cadastrarProduto();
                totalProdutos++;
                printf("Sucesso.\n");
            } else {
                printf("Limite atingido.");
            }
            break;

        case 2:
        if (totalProdutos > 0){
            int codigo, quantidade;
            printf("Digite o codigo do produto: \n");
            scanf("%d", &codigo);

            int encontrado = 0;
            for (int i = 0; i < totalProdutos; i++)
            {
                if (produtos[i].codigo == codigo) {
                    printf("Digite a quantidade a ser vendida: \n");
                    scanf("%d", &quantidade);
                } if (quantidade <= produtos[i].quantidade){
                    produtos[i].quantidade -= quantidade;

                    quantidades[i] = quantidade;

                    printf("Venda realizada com sucesso.\n");
                } else {
                    printf("Quantidade insuficiente em estoque.\n");
                }
                encontrado = 1;
                break;
            }
            if (!encontrado){
                printf("Produto nao encontrado.\n");
            } else {
                printf ("Nenhum produto cadastrado.\n");
            }
        }

case 3:
    if (totalProdutos > 0) {
        notaFiscal (produtos, quantidades, totalProdutos);
    } else {
        printf("Nenhum produto vendido!\n");
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






//7
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