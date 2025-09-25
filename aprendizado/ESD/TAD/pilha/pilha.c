#include <stdio.h>
#include <stdlib.h>

#define tamanho_max 100

typedef struct {
    int dados[tamanho_max];
    int topo;
} PilhaSequencial;

PilhaSequencial* cria_pilha(){

    PilhaSequencial *p = (PilhaSequencial*) malloc(sizeof(PilhaSequencial));
    if(p != NULL){
        p->topo = 0;
    }
    return 0; 
}

void libera_pilha(PilhaSequencial *p){
    free(p);
}

int pilha_cheia(PilhaSequencial *p){
    return (p->topo == tamanho_max);
}

int pilha_vazia(PilhaSequencial *p){
    return (p->topo == 0);
}
//Operação PUSH significa empilhar na pilha
int push_seq(PilhaSequencial *p, int valor){
    if(p == NULL || pilha_cheia(p)){
        return 0;
    }
    p->dados[p->topo] = valor;
    p->topo ++;
    return 0;
}
//Operação POP (Desempilhar)
int pop_seq(PilhaSequencial *p, int *valor){
    if(p == NULL || pilha_vazia(p)){
        return 0;
    }
    p->topo --;
    *valor = 
}