#include <stdio.h>
#include <stdlib.h>
#include "pilha_encadeada.h"

struct no
{
    int dado;
    struct no *proximo;
};

struct pilha
{
    No *topo;
};

// --- Funções do TAD Pilha Encadeada ---

// Criação da pilha
tpilhaencadeada *cria_pilha_enc()
{
    tpilhaencadeada *p = (tpilhaencadeada *)malloc(sizeof(tpilhaencadeada));
    if (p != NULL)
    {
        p->topo = NULL; // A pilha começa vazia
    }
    return p;
}

// liberação
void pilha_libera(tpilhaencadeada *p)
{
    if (p != NULL)
    {
        No *no_atual = p->topo;

        while (no_atual != NULL)
        {
            No *liberado = no_atual;
            no_atual = no_atual->proximo;
            free(liberado);
        }
        free(p);
    }
}

// empilhar dados
void pilha_push(tpilhaencadeada *p, int valor)
{
    if (p == NULL)
    {
        return;
    }
    No *novo_no = (No *)malloc(sizeof(No));
    if (novo_no == NULL)
    {
        return;
    }
    novo_no->dado = valor;

    novo_no->proximo = p->topo;

    p->topo = novo_no;
}

// Desempelhar
int pilha_pop(tpilhaencadeada *p)
{
    if (p == NULL || p->topo == NULL)
    {
        return 1;
    }

    No *antigo_no = (No *)malloc(sizeof(No));
    antigo_no = p->topo;
    p->topo = antigo_no->proximo;

    free(antigo_no);
    return 0;
}