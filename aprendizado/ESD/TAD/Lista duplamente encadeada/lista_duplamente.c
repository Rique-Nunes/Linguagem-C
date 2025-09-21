#include <stdio.h>
#include <stdlib.h>
#include "lista_duplamente.h"

struct no
{
    int dado;
    struct no *proximo;
    struct no *anterior;
};

struct lista
{
    No *cabeca;
    int quantidade;
};

// Criação da lista
Lista *cria_lista()
{
    Lista *li = (Lista *)malloc(sizeof(Lista));
    if (li == NULL)
        return NULL;

    li->cabeca = (No *)malloc(sizeof(No));
    if (li->cabeca == NULL)
    {
        free(li);
        return NULL;
    }

    li->quantidade = 0;
    li->cabeca->proximo = li->cabeca;
    li->cabeca->anterior = li->cabeca;

    return li;
}

// Inserir na lista ordenadamente

int insere_ordenado(Lista *li, int valor)
{
    if (li == NULL)
        return 0;

    No *atual = li->cabeca->proximo;

    while (atual != li->cabeca && atual->dado < valor)
    {
        atual = atual->proximo;
    }

    if (atual != li->cabeca && atual->dado == valor)
    {
        printf("-> Valor %d ja existe na lista. Insercao nao permitida.\n", valor);
        return 0;
    }

    No *novo_no = (No *)malloc(sizeof(No));
    if (novo_no == NULL)
        return 0;
    novo_no->dado = valor;

    No *anterior = atual->anterior;

    anterior->proximo = novo_no;
    novo_no->anterior = anterior;
    novo_no->proximo = atual;
    atual->anterior = novo_no;

    li->quantidade++;
    return 1;
}

// Remover um elemento

int remove_elemento(Lista *li, int valor)
{
    if (li == NULL || li->quantidade == 0)
        return 0;

    No *atual = li->cabeca->proximo;

    while (atual != li->cabeca && atual->dado != valor)
    {
        atual = atual->proximo;
    }

    if (atual == li->cabeca)
    {
        printf("-> Valor %d nao encontrado para remocao.\n", valor);
        return 0;
    }

    No *anterior = atual->anterior;
    No *proximo = atual->proximo;

    anterior->proximo = proximo;
    proximo->anterior = anterior;

    free(atual);
    li->quantidade--;
    return 1;
}

// GET de um elemento
int get_lista(Lista *li, int valor)
{
    if (li == NULL || li->quantidade == 0)
    {
        return 0;
    }

    No *atual = li->cabeca->proximo;

    while (atual != li->cabeca && atual->dado != valor)
    {
        atual = atual->proximo;
    }
    if (atual == li->cabeca)
    {
        printf("-> Valor %d nao encontrado na lista.\n", valor);
        return 0;
    }
    return atual->dado;
}

// get tamanho da lista
int get_tamanho(Lista *li)
{
    return li->quantidade;
}

int alterar_lista(Lista *li, int valor_antigo, int valor_novo)
{
    if (li == NULL || li->quantidade == 0)
    {
        return 0;
    }
    No *atual = li->cabeca->proximo;

    while (atual != li->cabeca && atual->dado != valor_antigo)
    {
        atual = atual->proximo;
    }
    if (atual == li->cabeca)
    {
        printf("-> Valor %d nao encontrado na lista.\n", valor_antigo);
        return 0;
    }
    atual->dado = valor_novo;
    return 1;
}

// Exibir a Lista

void exibe_lista(Lista *li)
{
    if (li == NULL || li->quantidade == 0)
    {
        printf("Lista: [ VAZIA ]\n");
        return;
    }
    printf("Lista: [ ");
    No *atual = li->cabeca->proximo;
    while (atual != li->cabeca)
    {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("]\n");
}

// Liberação da lista
void libera_lista(Lista *li)
{
    if (li != NULL)
    {
        No *atual = li->cabeca->proximo;
        while (atual != li->cabeca)
        {
            No *no_a_liberar = atual;
            atual = atual->proximo;
            free(no_a_liberar);
        }
        free(li->cabeca);
        free(li);
    }
}