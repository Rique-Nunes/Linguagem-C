#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *proximo;
} No;

typedef struct
{
    No *topo;

} PilhaEncadeada;

// --- Funções do TAD Pilha Encadeada ---

PilhaEncadeada *cria_pilha_enc()
{
    PilhaEncadeada *p = (PilhaEncadeada *)malloc(sizeof(PilhaEncadeada));
    if (p != NULL)
    {
        p->topo = NULL; // A pilha começa vazia
    }
    return p;
}