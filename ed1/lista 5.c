//1
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;       
    int *vetor;   
    int soma = 0;   
    
    printf("Digite a quantidade de elementos: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Quantidade invalida de elementos.\n");
        return 1;
    }
    
    vetor = (int*)malloc(n * sizeof(int));
    
    if (vetor == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return 1;
    }
    
    printf("Digite os %d elementos do vetor:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    
    for (int i = 0; i < n; i++) {
        soma += vetor[i];
    }
    
    printf("A soma dos elementos do vetor eh: %d\n", soma);
    
    free(vetor);
    
    return 0;
}

//2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARACTERES 51 

int main() {
    int n;              
    char **nomes;       
    char buffer[MAX_CARACTERES];

    printf("Digite a quantidade de nomes: ");
    scanf("%d", &n);
    getchar(); 

    if (n <= 0) {
        printf("Quantidade invalida de nomes.\n");
        return 1;
    }

    nomes = (char **)malloc(n * sizeof(char *));
    if (nomes == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        nomes[i] = (char *)malloc(MAX_CARACTERES * sizeof(char));
        if (nomes[i] == NULL) {
            printf("Erro na alocacao de memoria para o nome %d.\n", i+1);
            
            for (int j = 0; j < i; j++) {
                free(nomes[j]);
            }
            free(nomes);
            return 1;
        }
    }

    printf("Digite os %d nomes (maximo de %d caracteres cada):\n", n, MAX_CARACTERES-1);
    for (int i = 0; i < n; i++) {
        printf("Nome %d: ", i+1);
        fgets(buffer, MAX_CARACTERES, stdin);
        
        buffer[strcspn(buffer, "\n")] = '\0';
        
        strcpy(nomes[i], buffer);
    }

    printf("Nomes armazenados:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %s\n", i+1, nomes[i]);
    }

    for (int i = 0; i < n; i++) {
        free(nomes[i]);
    }
    free(nomes);

    return 0;
}

//3
#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;       
    int **matriz;  

    printf("Digite o numero de linhas (m): ");
    scanf("%d", &m);
    printf("Digite o numero de colunas (n): ");
    scanf("%d", &n);


    if (m <= 0 || n <= 0) {
        printf("Dimensoes invalidas. Use valores positivos.\n");
        return 1;
    }

    matriz = (int **)malloc(m * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro na alocacao de memoria para linhas.\n");
        return 1;
    }

    for (int i = 0; i < m; i++) {
        matriz[i] = (int *)malloc(n * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro na alocacao de memoria para colunas.\n");
    
            for (int j = 0; j < i; j++) {
                free(matriz[j]);
            }
            free(matriz);
            return 1;
        }
    }

    printf("Digite os elementos da matriz %dx%d:\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Matriz %dx%d:\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5d ", matriz[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}

//4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 100

typedef struct {
    char nome[MAX_NOME];
    int idade;
} Aluno;

int main() {
    int quantidade;
    Aluno *alunos = NULL;
    char buffer[MAX_NOME];

    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &quantidade);
    getchar(); 

    if (quantidade <= 0) {
        printf("Quantidade invalida de alunos.\n");
        return 1;
    }

    alunos = (Aluno*)malloc(quantidade * sizeof(Aluno));
    if (alunos == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return 1;
    }

    printf("Cadastro de alunos:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("Aluno %d:\n", i + 1);
        
        printf("Nome: ");
        fgets(buffer, MAX_NOME, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        strcpy(alunos[i].nome, buffer);
    
        printf("Idade: ");
        scanf("%d", &alunos[i].idade);
        getchar();
    }

    printf("Alunos cadastrados:\n");
    printf("---------------------------------\n");
    printf("%-30s | %s\n", "Nome", "Idade");
    printf("---------------------------------\n");
    
    for (int i = 0; i < quantidade; i++) {
        printf("%-30s | %d\n", alunos[i].nome, alunos[i].idade);
    }
    printf("---------------------------------\n");

    free(alunos);

    return 0;
}