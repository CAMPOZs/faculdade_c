#include <stdio.h>
#include <stdlib.h>
#include<

typedef struct no {
    int dado;
    struct no *proximo;
}no;

typedef struct {
    no *topo;     
    int tamanho;   
} Pilha;

Pilha* criar_pilha() {
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));  
    if (p != NULL) {  
        p->topo = NULL;  
        p->tamanho = 0;  
    }
    return p; 
}

bool pilha_vazia(Pilha *p) {
    return (p == NULL || p->topo == NULL);
}
