//1
#include <stdio.h>
#include <stdlib.h>
#define TAM 3

typedef struct
{
    int topo;
    int dado[TAM];

}pilha;

pilha p;

void inciarPilha(pilha *p){
    p -> topo = -1;
}

int full (pilha *p){
    if (p -> topo == TAM -1)
    {
        return 1;
    } else {
        return 0;
    }
}

int empty(pilha *p){
    if (p -> topo == -1)
    {
        return 1;
    } else {
        return 0;
    }

void inserir (pilha *pilha, int valor){
    if (full(pilha) == 1)
    {
        printf("\nPilha cheia.\n");
    } else {
        pilha -> topo++;
        pilha -> v[p -> topo] = valor;
    }
    
}
}