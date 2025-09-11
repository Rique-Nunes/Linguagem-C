#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

    struct lista
{
    int dados[100];
    int quantidade;
};

Tlista *criaLista()
{
    Tlista *lista = (Tlista *)malloc(sizeof(Tlista));
    if (lista == NULL)
    {
        exit(1);
    }
    lista->quantidade = 0;
    return lista;
}
void insereLista(Tlista *lista, int valor)
{
    if ((lista == NULL) || (lista->quantidade == 100))
    {
        exit(1);
    }
    lista->dados[lista->quantidade] = valor;
    lista->quantidade++;
}

void insereLista2(Tlista *lista, int valor)
{
    if ((lista == NULL) || (lista->quantidade == 100))
    {
        exit(1);
    }
    for (int i = lista->quantidade; i > 0; i--)
    {
        lista->dados[i] = lista->dados[i - 1];
    }

    lista->dados[0] = valor; 
    lista->quantidade++;
}

void exibe_lista_sequencial(Tlista *li)
{
    if (li == NULL || li->quantidade == 0)
    {
        printf("Lista vazia ou nao existe.\n");
        return;
    }
    printf("Lista Sequencial: [ ");
    for (int i = 0; i < li->quantidade; i++)
    {
        printf("%d ", li->dados[i]);
    }
    printf("]\n");
}

void liberaLista(Tlista *lista)
{
    free(lista);
}
