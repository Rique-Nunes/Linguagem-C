// Arquivo: fila_dupla.c
#include <stdio.h>
#include <stdlib.h>

// --- Definições das Structs ---
typedef struct no
{
    int dado;
    struct no *proximo;
    struct no *anterior;
} No;

typedef struct
{
    No *inicio; // Ponteiro para o primeiro nó
    No *fim;    // Ponteiro para o último nó
} FilaDupla;

// --- Funções do TAD Fila Duplamente Encadeada ---

FilaDupla *cria_fila_dupla()
{
    FilaDupla *f = (FilaDupla *)malloc(sizeof(FilaDupla));
    if (f != NULL)
    {
        f->inicio = NULL;
        f->fim = NULL;
    }
    return f;
}

void libera_fila_dupla(FilaDupla *f)
{
    if (f != NULL)
    {
        No *no_atual = f->inicio;
        while (no_atual != NULL)
        {
            No *no_a_liberar = no_atual;
            no_atual = no_atual->proximo;
            free(no_a_liberar);
        }
        free(f);
    }
}

int fila_dupla_vazia(FilaDupla *f)
{
    return (f->inicio == NULL);
}

// A operação ENQUEUE (Enfileirar no FIM)
void enqueue_dupla(FilaDupla *f, int valor)
{
    if (f == NULL)
        return;

    No *novo_no = (No *)malloc(sizeof(No));
    if (novo_no == NULL)
        return;

    novo_no->dado = valor;
    novo_no->proximo = NULL; // O novo nó é sempre o último

    if (fila_dupla_vazia(f))
    {
        // Se a fila está vazia, o novo nó é o início e o fim
        novo_no->anterior = NULL;
        f->inicio = novo_no;
        f->fim = novo_no;
    }
    else
    {
        // Se já tem gente na fila
        novo_no->anterior = f->fim; // O anterior do novo é o antigo fim
        f->fim->proximo = novo_no;  // O antigo fim aponta para o novo
        f->fim = novo_no;           // O novo nó se torna o novo fim
    }
}

// A operação DEQUEUE (Desenfileirar do INÍCIO)
int dequeue_dupla(FilaDupla *f, int *valor_removido)
{
    if (f == NULL || fila_dupla_vazia(f))
    {
        return 0; // Falha
    }

    No *no_a_remover = f->inicio;
    *valor_removido = no_a_remover->dado;

    // O início da fila avança para o próximo
    f->inicio = no_a_remover->proximo;

    // Se a fila não ficou vazia, o novo início não tem anterior
    if (f->inicio != NULL)
    {
        f->inicio->anterior = NULL;
    }
    else
    {
        // Se a fila ficou vazia, o fim também deve ser NULL
        f->fim = NULL;
    }

    free(no_a_remover);
    return 1;
}

// --- Testando a Fila Duplamente Encadeada ---
int main()
{
    FilaDupla *minha_fila = cria_fila_dupla();
    int valor;

    printf("Enfileirando 10, 20, 30...\n");
    enqueue_dupla(minha_fila, 10);
    enqueue_dupla(minha_fila, 20);
    enqueue_dupla(minha_fila, 30);

    printf("Desenfileirando um elemento...\n");
    if (dequeue_dupla(minha_fila, &valor))
    {
        printf(" -> Valor removido: %d (O primeiro que entrou)\n", valor); // Deve ser 10
    }

    printf("Desenfileirando outro elemento...\n");
    if (dequeue_dupla(minha_fila, &valor))
    {
        printf(" -> Valor removido: %d\n", valor); // Deve ser 20
    }

    libera_fila_dupla(minha_fila);
    return 0;
}