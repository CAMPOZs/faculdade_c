#include<stdio.h>
#include<stdlib.h>

/*1. Escreva um programa que aloque dinamicamente um vetor v e o preencha com v[i] = 100*i,
sendo que o número de elementos do vetor é lido do teclado.
A área de memória alocada deve ser definida em função do tamanho do vetor.*/
int main(){

    int n, i;

    printf("Informe o numero de elementos: \n");
    scanf("%d", &n);

    int *vetor = (int *) malloc(n * sizeof(int));

    if (vetor == NULL)
    {
        printf("Erro na alocacao de memoria.\n");
    }

    for ( i = 0; i < n; i++)
    {
        vetor[i] = 100 * i;
    }

    printf("Valores armazenados:\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d\n", vetor[i]);
    }
    printf("\n");
    free(vetor);
    return 0;
    
}

/*2. Mude o programa anterior, escrevendo funções separadas para:
a) a locar o vetor e preenchê-lo com zeros;
b) preencher o vetor;
c) imprimir o vetor.*/
#include<stdio.h>
#include<stdlib.h>

int preencherZero() {

    int n, i;

    printf("Informe o valor de elementos: \n");
    scanf("%d", &n);

    int *vetor = (int *)malloc(n * sizeof(int));

    if (vetor == NULL){
        printf("Erro.\n");
    }

    for ( i = 0; i < n; i++)
    {
        vetor[i] = 0;
    }
    
}

int preencherVetor() {

    int n, i;

    int vetor[i];

    printf("Digite %d numeros inteios:\n", n);
    for ( i = 0; i < n; i++)
    {
        scanf("%d", vetor[i]);
    }
    
}

int imprimirVetor(){

    int i, n;
    int vetor[i];

    printf("Valor armazenados no vetor:\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d", vetor[i]);
    }
    printf("\n");
    free(vetor);
    return 0;
    
}