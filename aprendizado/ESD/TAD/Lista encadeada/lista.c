// Em ListaEncadeada.c
#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>
// Cria uma lista vazia
ListaEncadeada *cria_lista_encadeada()
{
    ListaEncadeada *li = (ListaEncadeada *)malloc(sizeof(ListaEncadeada));
    if (li != NULL)
    {
        *li = NULL; // O conteúdo do ponteiro da lista é NULL
    }
    return li;
}

// Libera a memória, nó por nó
void libera_lista_encadeada(ListaEncadeada *li)
{
    if (li != NULL)
    {
        No *no_atual;
        while ((*li) != NULL)
        {
            no_atual = *li;
            *li = (*li)->proximo;
            free(no_atual);
        }
        free(li);
    }
}

// Em ListaEncadeada.c

int insere_lista_encadeada_inicio(ListaEncadeada *li, int valor)
{
    if (li == NULL)
        return 0;

    No *novo_no = (No *)malloc(sizeof(No));
    if (novo_no == NULL)
        return 0;

    novo_no->dado = valor;
    novo_no->proximo = (*li); // O novo nó aponta para o antigo início
    *li = novo_no;            // A lista agora começa no novo nó

    return 1;
}

// Em ListaDuplamenteEncadeada.c

int remove_lista_dupla(ListaDuplamenteEncadeada *li, int valor)
{
    if (li == NULL || (*li) == NULL)
        return 0;

    NoDuplo *no_atual = *li;
    // Procura o nó a ser removido
    while (no_atual != NULL && no_atual->dado != valor)
    {
        no_atual = no_atual->proximo;
    }

    if (no_atual == NULL)
        return 0; // Não encontrou

    // Se o nó a ser removido é o primeiro
    if (no_atual->anterior == NULL)
    { // ou (no_atual == *li)
        *li = no_atual->proximo;
    }
    else
    {
        // O vizinho de trás agora aponta para o vizinho da frente
        no_atual->anterior->proximo = no_atual->proximo;
    }

    // Se o nó a ser removido não é o último
    if (no_atual->proximo != NULL)
    {
        // O vizinho da frente agora aponta para o vizinho de trás
        no_atual->proximo->anterior = no_atual->anterior;
    }

    free(no_atual);
    return 1;
}