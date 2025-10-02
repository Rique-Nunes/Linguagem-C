// Arquivo: fila_sequencial.c

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAX 5 // Um tamanho pequeno para testar o comportamento circular

typedef struct
{
    int dados[TAMANHO_MAX];
    int inicio;     // Índice do primeiro elemento da fila
    int fim;        // Índice ONDE o próximo elemento será inserido
    int quantidade; // Número de elementos na fila
} FilaSequencial;

// --- Funções do TAD Fila Sequencial ---

FilaSequencial *cria_fila_seq()
{
    FilaSequencial *f = (FilaSequencial *)malloc(sizeof(FilaSequencial));
    if (f != NULL)
    {
        f->inicio = 0;
        f->fim = 0;
        f->quantidade = 0;
    }
    return f;
}

void libera_fila_seq(FilaSequencial *f)
{
    free(f);
}

int fila_seq_cheia(FilaSequencial *f)
{
    return (f->quantidade == TAMANHO_MAX);
}

int fila_seq_vazia(FilaSequencial *f)
{
    return (f->quantidade == 0);
}

// A operação ENQUEUE (Enfileirar)
int enqueue_seq(FilaSequencial *f, int valor)
{
    if (f == NULL || fila_seq_cheia(f))
    {
        return 0; // Falha
    }

    // Coloca o valor na posição livre indicada pelo 'fim'
    f->dados[f->fim] = valor;

    // A "mágica" circular: avança o 'fim' e dá a volta se necessário
    f->fim = f->fim + 1;
    if (f->fim == TAMANHO_MAX)
    {
        f->fim = 0;
    }

    f->quantidade++;
    return 1; // Sucesso
}

// A operação DEQUEUE (Desenfileirar)
int dequeue_seq(FilaSequencial *f, int *valor_removido)
{
    if (f == NULL || fila_seq_vazia(f))
    {
        return 0; // Falha
    }

    // Pega o valor da posição indicada pelo 'inicio'
    *valor_removido = f->dados[f->inicio];

    // A "mágica" circular: avança o 'inicio' e dá a volta se necessário
    f->inicio = f->inicio + 1;

    if (f->inicio == TAMANHO_MAX)
    {
        f->inicio = 0;
    }
    f->quantidade--;
    return 1; // Sucesso
}

// --- Testando a Fila Sequencial ---
int main()
{
    FilaSequencial *minha_fila = cria_fila_seq();
    int valor;

    printf("Enfileirando 10, 20, 30...\n");
    enqueue_seq(minha_fila, 10);
    enqueue_seq(minha_fila, 20);
    enqueue_seq(minha_fila, 30);
    // Fila: [10, 20, 30, _, _], inicio=0, fim=3

    printf("Desenfileirando um elemento...\n");
    if (dequeue_seq(minha_fila, &valor))
    {
        printf(" -> Valor removido: %d (O primeiro que entrou)\n", valor); // Deve ser 10
    }
    // Fila: [_, 20, 30, _, _], inicio=1, fim=3

    printf("Enfileirando 40, 50, 60...\n");
    enqueue_seq(minha_fila, 40);
    enqueue_seq(minha_fila, 50);
    // Fila: [_, 20, 30, 40, 50], inicio=1, fim=0 (deu a volta!)
    if (!enqueue_seq(minha_fila, 60))
    {
        printf(" -> Falha ao inserir 60: Fila cheia!\n");
    }

    printf("\nEsvaziando a fila para ver a ordem:\n");
    while (!fila_seq_vazia(minha_fila))
    {
        dequeue_seq(minha_fila, &valor);
        printf(" -> Valor removido: %d\n", valor); // Deve sair na ordem: 20, 30, 40, 50
    }

    libera_fila_seq(minha_fila);
    return 0;
}