// Arquivo: fila_sequencial.c

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAX 8 // Um tamanho pequeno para testar o comportamento circular

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

int primfila(FilaSequencial *f)
{
    return f->dados[f->inicio];
}

// A operação ENQUEUE (Enfileirar)
int enfileirar(FilaSequencial *f, int valor)
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
int desifileirar(FilaSequencial *f, int *valor_removido)
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

// -- Pilha Code --

typedef struct
{
    int dados[TAMANHO_MAX];
    int topo;
} PilhaSequencial;

PilhaSequencial *cria_pilha()
{
    PilhaSequencial *p = (PilhaSequencial *)malloc(sizeof(PilhaSequencial));
    if (p != NULL)
    {
        p->topo = 0; // Topo começa em 0 (próxima posição livre)
    }
    return p; // CORREÇÃO: Retorna o ponteiro alocado
}

int pilha_cheia(PilhaSequencial *p)
{
    return (p->topo == TAMANHO_MAX); // Compara com o tamanho máximo
}

int pilha_vazia(PilhaSequencial *p)
{
    return (p->topo == 0); // Vazia se o topo estiver em 0
}

int push_seq(PilhaSequencial *p, int valor)
{
    if (p == NULL || pilha_cheia(p))
    {
        return 0; // Falha
    }
    // CORREÇÃO: Insere na posição do topo e DEPOIS incrementa
    p->dados[p->topo] = valor;
    p->topo++;
    return 1; // Sucesso
}

int pop_seq(PilhaSequencial *p, int *valor)
{
    if (p == NULL || pilha_vazia(p))
    {
        return 0; // Falha
    }
    // CORREÇÃO: DECREMENTA o topo primeiro para apontar para o último item
    p->topo--;
    *valor = p->dados[p->topo];
    return 1; // Sucesso
}
/*O objetivo é fazer uma função que inverta a ordem de uma fila com base na posição dada
pelo usuário, isso indique que caso o usuario digite 5 numa fila de (1,2,3,4,5,6,7,8)
O resultado da fila deve ser (5,6,7,8,1,2,3,4)

Para fazer isso dividir em partes, onde primeiro lemos a fila atual e colocamos em uma fila temporária
ao chegar no elemento da fila, a partir daqui colocamos os elementos em uma pilha
ao fim, simplismente colocando os elementos da pilha na fila final e os da fila reserva na fila final
*/
FilaSequencial *processafila(int n, FilaSequencial *fila)
{
    // A função agora retorna um ponteiro

    if (fila == NULL || fila_seq_vazia(fila))
        return NULL;

    // recursos temporários
    FilaSequencial *fila_temp = cria_fila_seq();
    PilhaSequencial *pilha_temp = cria_pilha();

    // resultado que será exportado
    FilaSequencial *final = cria_fila_seq();

    // Verifica se as alocações deram certo
    if (!fila_temp || !pilha_temp || !final)
    {
        free(fila_temp);
        free(pilha_temp);
        free(final);
        return NULL;
    }

    int i;

    // loop de execução para enfileirar na temporaria até achar o valor
    while (!fila_seq_vazia(fila))
    {
        desifileirar(fila, &i);
        if (i == n)
        {
            break; // Achou o elemento de rotação
        }
        enfileirar(fila_temp, i);
    }

    // Coloca o elemento de rotação e o resto na pilha
    push_seq(pilha_temp, i);
    while (desifileirar(fila, &i))
    {
        push_seq(pilha_temp, i);
    }

    // Monta a fila final: primeiro a pilha, depois a fila temporária
    while (pop_seq(pilha_temp, &i))
    {
        enfileirar(final, i);
    }
    while (desifileirar(fila_temp, &i))
    {
        enfileirar(final, i);
    }

    // Libera os recursos temporários para evitar vazamento de memória
    libera_fila_seq(fila_temp);

    return final; // Retorna o ponteiro para a fila final
}

// --- Testando a Fila Sequencial ---
/*
int main()
{
    FilaSequencial *minha_fila = cria_fila_seq();
    int valor;

    printf("Enfileirando 10, 20, 30...\n");
    enfileirar(minha_fila, 10);
    enfileirar(minha_fila, 20);
    enfileirar(minha_fila, 30);
    // Fila: [10, 20, 30, _, _], inicio=0, fim=3

    printf("Desenfileirando um elemento...\n");
    if (desifileirar(minha_fila, &valor))
    {
        printf(" -> Valor removido: %d (O primeiro que entrou)\n", valor); // Deve ser 10
    }
    // Fila: [_, 20, 30, _, _], inicio=1, fim=3

    printf("Enfileirando 40, 50, 60...\n");
    enfileirar(minha_fila, 40);
    enfileirar(minha_fila, 50);
    // Fila: [_, 20, 30, 40, 50], inicio=1, fim=0 (deu a volta!)
    if (!enfileirar(minha_fila, 60))
    {
        printf(" -> Falha ao inserir 60: Fila cheia!\n");
    }

    printf("\nEsvaziando a fila para ver a ordem:\n");
    while (!fila_seq_vazia(minha_fila))
    {
        desifileirar(minha_fila, &valor);
        printf(" -> Valor removido: %d\n", valor); // Deve sair na ordem: 20, 30, 40, 50
    }

    printf("\nProcessando a fila para rotacionar a partir do elemento 50...\n");

    // A chamada agora recebe o ponteiro retornado
    FilaSequencial *fila_final = processafila(30, minha_fila);

    if (fila_final != NULL)
    {
        printf("\nFila Final (rotacionada):\n");
        int valor;
        while (desifileirar(fila_final, &valor))
        {
            printf(" -> %d", valor);
        }
        printf("\n");
        libera_fila_seq(fila_final);
    }
    else
    {
        printf("Processamento falhou.\n");
    }

    // Libera a fila original (que agora está vazia)
    libera_fila_seq(minha_fila);

    return 0;
}
*/

int main()
{
    FilaSequencial *minha_fila = cria_fila_seq();

    printf("Enfileirando 10, 20, 30, 40, 50, 60, 70, 80...\n");
    for (int i = 1; i <= 8; i++)
    {
        enfileirar(minha_fila, i * 10);
    }
    // Fila original: (10, 20, 30, 40, 50, 60, 70, 80)

    printf("\nProcessando a fila para rotacionar a partir do elemento 50...\n");

    // A chamada agora recebe o ponteiro retornado
    FilaSequencial *fila_final = processafila(50, minha_fila);

    if (fila_final != NULL)
    {
        printf("\nFila Final (rotacionada):\n");
        int valor;
        while (desifileirar(fila_final, &valor))
        {
            printf(" -> %d", valor);
        }
        printf("\n");
        libera_fila_seq(fila_final);
    }
    else
    {
        printf("Processamento falhou.\n");
    }

    // Libera a fila original (que agora está vazia)
    libera_fila_seq(minha_fila);

    return 0;
}