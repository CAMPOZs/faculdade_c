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