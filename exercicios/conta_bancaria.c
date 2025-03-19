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