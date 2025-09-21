#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int info;
    struct lista *prox;
};

typedef struct lista Lista;

// FUN��O PARA INSERIR NO IN�CIO
Lista *insere(Lista *l, int i)
{
    Lista *novo;
    novo = (Lista *)malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}

Lista *insere_ordenado(Lista *l, int v)
{
    // 1. Aloca o novo no
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->info = v;

    Lista *ant = NULL;
    Lista *p = l;

    // 2. Procura a posicao de insercao
    while (p != NULL && p->info < v)
    {
        ant = p;
        p = p->prox;
    }

    // 3. Conecta o novo no na lista
    if (ant == NULL)
    { // Insere no inicio da lista
        novo->prox = l;
        l = novo;
    }
    else
    { // Insere no meio ou final da lista
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return l;
}

// FUN��O PARA IMPRIMIR ELEMENTOS DA LISTA
void imprime(Lista *l)
{
    Lista *p;
    for (p = l; p != NULL; p = p->prox)
    {
        printf("%d ", p->info);
    }
}

// FUN��O PARA RETIRAR UM VALOR DA LISTA
Lista *retira(Lista *l, int v)
{
    Lista *ant = NULL;
    Lista *p = l;

    while (p != NULL && p->info != v)
    {
        ant = p;
        p = p->prox;
    }

    if (p == NULL)
    {
        return l;
    }

    if (ant == NULL)
    {
        l = p->prox;
    }
    else
    {
        ant->prox = p->prox;
    }

    free(p);
    return l;
}

int main()
{
    Lista *l;
    l = NULL;
    l = insere(l, 75);
    l = insere(l, 30);
    l = insere(l, 12);
    l = insere_ordenado(l, 43);
    imprime(l);
    l = retira(l, 75);
    printf("\n");
    imprime(l);

    return 0;
}