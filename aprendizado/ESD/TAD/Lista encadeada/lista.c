#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>

ListaEncadeada *cria_lista_encadeada()
{
    ListaEncadeada *li = (ListaEncadeada *)malloc(sizeof(ListaEncadeada));
    if (li != NULL)
    {
        *li = NULL;
    }
    return li;
}

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

int insere_lista_encadeada_inicio(ListaEncadeada *li, int valor)
{
    if (li == NULL)
        return 0;

    No *novo_no = (No *)malloc(sizeof(No));
    if (novo_no == NULL)
        return 0;

    novo_no->dado = valor;
    novo_no->proximo = (*li);
    *li = novo_no;

    return 1;
}

void exibe_lista_encadeada(ListaEncadeada *li)
{
    if (li == NULL || (*li) == NULL)
    {
        printf("Lista vazia ou nao existe.\n");
        return;
    }
    printf("Lista Encadeada: [ ");
    No *no_atual = *li;
    while (no_atual != NULL)
    {
        printf("%d ", no_atual->dado);
        no_atual = no_atual->proximo;
    }
    printf("]\n");
}