// Arquivo: lista_completa.c

#include <stdio.h>
#include <stdlib.h>

// --- A Estrutura do Nó ---
// Cada "vagão" do nosso trem.
typedef struct no
{
    int dado;
    struct no *proximo;
    struct no *anterior;
} No;

// --- A Estrutura da Lista (O "Controle Central") ---
// Contém o nó cabeça e a quantidade de elementos.
typedef struct lista
{
    No *cabeca; // O nó sentinela, ponto de partida.
    int quantidade;
} Lista;

// Arquivo: lista_completa.c (continuação)

Lista *cria_lista()
{
    // Aloca a estrutura principal da lista
    Lista *li = (Lista *)malloc(sizeof(Lista));
    if (li == NULL)
        return NULL;

    // Aloca o nó cabeça (sentinela)
    li->cabeca = (No *)malloc(sizeof(No));
    if (li->cabeca == NULL)
    {
        free(li);
        return NULL;
    }

    // Inicializa a lista como vazia
    li->quantidade = 0;
    // O nó cabeça aponta para si mesmo, indicando que a lista está vazia.
    li->cabeca->proximo = li->cabeca;
    li->cabeca->anterior = li->cabeca;

    return li;
}

// Arquivo: lista_completa.c (continuação)

// Retorna 1 se inseriu, 0 se não inseriu (valor já existia)
int insere_ordenado(Lista *li, int valor)
{
    if (li == NULL)
        return 0;

    // Começamos a busca a partir do primeiro nó real (o próximo do cabeça)
    No *atual = li->cabeca->proximo;

    // 1. Percorrer a lista para encontrar a posição
    // O loop para quando chegamos ao fim (voltamos ao cabeça) OU
    // encontramos um elemento maior que o nosso.
    while (atual != li->cabeca && atual->dado < valor)
    {
        atual = atual->proximo;
    }

    // 2. Verificar se o elemento já existe
    // Se o loop parou e o elemento atual é igual ao que queremos inserir...
    if (atual != li->cabeca && atual->dado == valor)
    {
        printf("-> Valor %d ja existe na lista. Insercao nao permitida.\n", valor);
        return 0; // Não insere
    }

    // 3. Criar e preencher o novo nó
    No *novo_no = (No *)malloc(sizeof(No));
    if (novo_no == NULL)
        return 0;
    novo_no->dado = valor;

    // 4. Conectar o novo nó
    // O nó anterior ao 'atual' será o anterior do 'novo_no'
    No *anterior = atual->anterior;

    anterior->proximo = novo_no;
    novo_no->anterior = anterior;
    novo_no->proximo = atual;
    atual->anterior = novo_no;

    li->quantidade++;
    return 1;
}

// Arquivo: lista_completa.c (continuação)

int remove_elemento(Lista *li, int valor)
{
    if (li == NULL || li->quantidade == 0)
        return 0;

    No *atual = li->cabeca->proximo;

    // Procura o elemento
    while (atual != li->cabeca && atual->dado != valor)
    {
        atual = atual->proximo;
    }

    // Se percorreu tudo e não achou (voltou para o cabeça)
    if (atual == li->cabeca)
    {
        printf("-> Valor %d nao encontrado para remocao.\n", valor);
        return 0;
    }

    // Lógica de remoção: "bypassar" o nó atual
    No *anterior = atual->anterior;
    No *proximo = atual->proximo;

    anterior->proximo = proximo;
    proximo->anterior = anterior;

    // Libera a memória do nó removido
    free(atual);
    li->quantidade--;
    return 1;
}

// Arquivo: lista_completa.c (continuação)

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
        free(li->cabeca); // Libera o nó sentinela
        free(li);         // Libera a estrutura da lista
    }
}

// Arquivo: lista_completa.c (continuação)

int main()
{
    Lista *minha_lista = cria_lista();
    exibe_lista(minha_lista);

    printf("\nInserindo 50, 20, 80, 40...\n");
    insere_ordenado(minha_lista, 50);
    insere_ordenado(minha_lista, 20);
    insere_ordenado(minha_lista, 80);
    insere_ordenado(minha_lista, 40);
    exibe_lista(minha_lista);

    printf("\nTentando inserir 20 novamente...\n");
    insere_ordenado(minha_lista, 20);
    exibe_lista(minha_lista);

    printf("\nRemovendo o 40...\n");
    remove_elemento(minha_lista, 40);
    exibe_lista(minha_lista);

    printf("\nRemovendo o 99 (inexistente)...\n");
    remove_elemento(minha_lista, 99);
    exibe_lista(minha_lista);

    libera_lista(minha_lista);
    printf("\nLista liberada.\n");

    return 0;
}