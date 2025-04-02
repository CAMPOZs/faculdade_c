/*Faça um programa em linguagem C, que implemente um tipo Conta. Esse tipo terá como valores um nome do titular, 
um número da conta e um saldo. Implemente funções para manipular o tipo de dado criado, como uma função para depósito, 
consultar saldo e realizar uma retirada. O seu programa deve permitir que o usuário informe os dados da conta e escolha 
as operações disponíveis*/

#include <stdio.h>

struct conta
{
    char nome[30];
    int numero;
    float saldo;
};

struct conta criarConta()
{
    struct  conta c;
    printf("Digite seu nome: \n");
    scanf("%s", c.nome);

    printf("Digite o numero da sua conta: \n");
    scanf("%d", &c.numero);

    c.saldo = 0.0;

    return c;
};

void deposito(struct conta *c, float valor){
    if (valor <= 0)
    {
        printf("Valor invalido.\n");
    }else{
        c -> saldo += valor;
        printf("Deposito realizado.\n");
        printf("Seu saldo atual eh %.2f\n", c->saldo);
    }
}

void saldo(struct conta c){
    printf("Seu saldo atual eh %.2f\n", c.saldo);
}

void sacar(struct conta *c, float valor){
    if (valor <= 0)
    {
        printf("Valor invalido.\n");
    }else{
        c -> saldo -= valor;
        printf("Roubamos seu dinheiro.\n");
        printf("Seu saldo atual eh %.2f\n", c->saldo);
    }
}

void numero(struct conta c){
    printf("O numero da sua conta eh %d", c.numero);
}

void menu(){

    printf("\nBem Vindo.\n");
    printf("\nMENU\n\n");
    printf("1. Criar Conta\n");
    printf("2. Depositar saldo\n");
    printf("3. Checar saldo\n");
    printf("4. Sacar saldo\n");
    printf("5. Checar numero da conta\n");
    printf("0. Sair.\n");
}

int main(){
    float valor;
    int opcao;
    struct conta minhaConta;
    int contaCriada = 0;
    
    do{
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
            printf("Digite o valor desejado: \n");
            scanf("%f", &valor);

            deposito(&minhaConta, valor);
        }else{
            printf("Crie uma conta.\n");
        }
        break;
            
    case 3: 
    if (contaCriada)
    {
        saldo(minhaConta);
    }else{
        printf("Crie uma conta.\n");
    }
    break;
    
    case 4: 
        if (contaCriada)
        {
            printf("Digite o valor desejado: \n");
            scanf("%f", &valor);

            sacar(&minhaConta, valor);
        }else{
            printf("Crie uma conta.\n");
        }
        break;
        
    case 5: 
    if (contaCriada)
    {
        numero(minhaConta);
    }else{
        printf("Crie uma conta.\n");
    }
    break;
    
    case 0:
    printf("Saindo...\n");
    break;

    default:
        break;
    }

} while (opcao != 0);

return 0;
}