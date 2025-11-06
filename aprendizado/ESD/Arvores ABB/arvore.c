// Arquivo: arvore.c

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h" // Inclui a própria interface

// --- Definição Real (Privada) da Struct ---
// Agora sim revelamos como é o nó.
struct no
{
    int valor;
    struct no *esquerda;
    struct no *direita;
};

// --- Função Auxiliar (Privada) ---
// Não está no .h porque só o 'insere' precisa dela.
No *cria_no(int valor)
{
    No *novo_no = (No *)malloc(sizeof(No));
    if (novo_no != NULL)
    {
        novo_no->valor = valor;
        novo_no->esquerda = NULL;
        novo_no->direita = NULL;
    }
    return novo_no;
}

// --- Implementação das Funções Públicas ---

Arvore insere(Arvore raiz, int valor)
{
    // Caso Base: a árvore está vazia, cria o nó aqui.
    if (raiz == NULL)
    {
        return cria_no(valor);
    }

    // Caso Recursivo: decide para onde ir
    if (valor < raiz->valor)
    {
        raiz->esquerda = insere(raiz->esquerda, valor);
    }
    else if (valor > raiz->valor)
    {
        raiz->direita = insere(raiz->direita, valor);
    }
    // Se (valor == raiz->valor), não faz nada (não permite duplicatas).

    return raiz;
}

void percurso_em_ordem(Arvore raiz)
{
    if (raiz == NULL)
    {
        return;
    }
    percurso_em_ordem(raiz->esquerda);
    printf("%d ", raiz->valor);
    percurso_em_ordem(raiz->direita);
}

void percurso_pre_ordem(Arvore raiz)
{
    if (raiz == NULL)
    {
        return;
    }
    printf("%d ", raiz->valor);
    percurso_pre_ordem(raiz->esquerda);
    percurso_pre_ordem(raiz->direita);
}

void percurso_pos_ordem(Arvore raiz)
{
    if (raiz == NULL)
    {
        return;
    }
    percurso_pos_ordem(raiz->esquerda);
    percurso_pos_ordem(raiz->direita);
    printf("%d ", raiz->valor);
}

/*
 Encontra o nó com o menor valor em uma subárvore.
 (Usado para encontrar o substituto na remoção).
*/

No *encontra_menor(Arvore raiz)
{
    No *atual = raiz;
    // Continua indo para a esquerda até o 'esquerda' ser NULL
    while (atual != NULL && atual->esquerda != NULL)
    {
        atual = atual->esquerda;
    }
    return atual; // Retorna o nó mais à esquerda (o menor)
}

Arvore remove_no(Arvore raiz, int valor)
{
    // Caso base
    if (raiz == NULL)
    {
        return NULL;
    }

    // Procurar o nó
    if (valor < raiz->valor)
    {
        raiz->esquerda = remove_no(raiz->esquerda, valor);
    }
    else if (valor > raiz->valor)
    {
        raiz->direita = remove_no(raiz->direita, valor);
    }
    // Resolver os 3 casos
    else
    { // o nó não tem filhos a direita nem a esquerda
        if ((raiz->direita == NULL) && (raiz->esquerda == NULL))
        {
            // libera
            free(raiz);
            // o pai dele recebe NULL como endereço
            return NULL;
        }
        // se o esquerda estiver vazio então o filho é o da direita
        else if (raiz->esquerda == NULL)
        {
            No *temp = raiz->direita;
            free(raiz);
            return temp;
        }
        // se o da direita estiver vazio então o filho é o da esquerda
        else if (raiz->direita == NULL)
        {
            No *temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        /*
        Queremos remover o 20 dessa árvore, porém ele tem 2 filhos:
             ( 60 )
            /      \
          ( 20 )    ( 70 )
         /      \
       ( 10 )  ( 40 )
              /      \
            ( 30 )  ( 50 )
           /      /
         ( 25 )   ( 45 )
           \
           ( 28 )

        Depois de buscar o menor valor a direita do 20, nós sobrescrevemos o 20 pelo menor (que não tem nenhum filho a esquerda)
             ( 60 )
            /      \
          ( 25 )    ( 70 )  <-- Valor copiado!
         /      \
       ( 10 )  ( 40 )
              /      \
            ( 30 )  ( 50 )
           /      /
         ( 25 )   ( 45 )      <-- Este é o nó que vamos remover
           \
           ( 28 )

        Agora só falta remover o 25, então chamamos a recursiva onde o 25 entraria ou no caso 1 (0 filhos) ou no caso 2 (1 filho)
        obs: se ele tivesse 2 filhos então ele não seria o menor porque ele teria um filho a esquerda

             ( 60 )
            /      \
          ( 25 )    ( 70 )  <-- 25 que é a Cópia
         /      \
       ( 10 )  ( 40 )
              /      \
            ( 30 )  ( 50 )
           /      /
         ( 28 )   ( 45 )      <-- "Neto" adotado pela recursão
            */
        else
        {
            // A função encontra menor procura o menor nó a direita do nó que queremos remover
            No *substituto = encontra_menor(raiz->direita);

            // Na raiz que queremos remover, em vez de dar free nós substituimos o valor pelo menor na direita do "Nó removido"
            raiz->valor = substituto->valor;

            // dai nós chamamos novamente que vai cair no caso 1 ou 2, porque se ele é o menor nó, então ou vai ter 1 filho ou nenhum
            remove_no(raiz->direita, valor);
        }
    }
}

// mesma recursão do inserir basicamente, porém sem atribuição, só consulta
int procura_no(Arvore raiz, int valor)
{
    // se for nula retorna
    if (raiz == NULL)
    {
        return 0;
    }
    // se for a que procuramos retorna que achou
    if (raiz->valor == valor)
    {
        printf("achou, ela existe");
        return 1;
    }

    // senão, se for menor procura na esquerda
    if (valor < raiz->valor)
    {
        return procura_no(raiz->esquerda, valor);
    }

    // senão, se for maior procura na direita
    else if (valor > raiz->valor)
    {
        return procura_no(raiz->direita, valor);
    }
}

// liberação da árvore, vamos liberar seus filhos (se tiver) e depois a própria raiz
void libera_arvore(Arvore raiz)
{
    // se já estiver fazia, ela volta
    if (raiz == NULL)
    {
        return;
    }

    // procura se tem filho na esquerda, mais se tiver vazio vai voltar sem nada
    libera_arvore(raiz->esquerda);

    // procura se tem filho na direta, mais se tiver vazio vai voltar sem nada
    libera_arvore(raiz->direita);

    // se ela não for vazia e ja passou pelas duas recurções então é só dar free
    free(raiz);
}

// Altura da árvore
int maior(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int altura_arvore(Arvore raiz)
{
    if (raiz == NULL)
    {
        return -1;
    }

    int altura_esquerda = altura_arvore(raiz->esquerda);
    int altura_direita = altura_arvore(raiz->direita);

    return 1 + maior(altura_esquerda, altura_direita);
}