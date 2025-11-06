
#include <stdio.h>
#include <stdlib.h>
#include "arvoce.h" // Inclui a própria interface

struct no
{
    int valor;
    struct no *esquerda;
    struct no *direita;
    int altura;
};

No *cria_no(int valor)
{
    No *novo_no = (No *)malloc(sizeof(No));
    if (novo_no != NULL)
    {
        novo_no->direita = NULL;
        novo_no->esquerda = NULL;
        novo_no->valor = valor;
        novo_no->altura = 0;
    }
    return novo_no;
}

// Em arvore.h, o protótipo seria:
// Arvore insere(Arvore raiz, int valor);
// (Como já corrigimos)

// Em arvore.c, a função completa:
Arvore insere(Arvore raiz, int valor)
{

    if (raiz == NULL)
    {
        return cria_no(valor);
    }

    if (valor < raiz->valor)
    {
        raiz->esquerda = insere(raiz->esquerda, valor);
    }
    else if (valor > raiz->valor)
    {
        raiz->direita = insere(raiz->direita, valor);
    }
    else
    {
        return raiz;
    }

    // --- 2. A "INTELIGÊNCIA" AVL (A PARTE NOVA) ---
    // Esta parte é executada "na volta" da recursão

    // A. Atualiza a altura do nó pai atual
    raiz->altura = 1 + maior(altura(raiz->esquerda), altura(raiz->direita));

    // B. Liga o "Sensor" (Calcula o Fator de Balanceamento)
    int fb = get_fator_balanceamento(raiz);

    // C. Verifica o Alarme e Conserta (o caso 30, 20, 10)

    // Se FB > 1 (pesado na ESQUERDA) e o valor foi inserido na ESQUERDA...
    // (É o nosso caso: FB(30) = +2 e 10 < 20)
    if (fb > 1 && valor < raiz->esquerda->valor)
    {
        printf("Detectado desequilibrio (+2) no no %d. Aplicando Rotacao a Direita...\n", raiz->valor);
        return rotacao_direita(raiz);
    }

    // (Aqui teriam os outros 3 casos de desequilíbrio,
    // como Rotação à Esquerda, Rotação Dupla, etc...)

    // 3. Retorna a raiz (modificada ou não)
    return raiz;
}

// Em arvore.c
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

No *rotacao_direita(No *A)
{
    // 1. Pega os filhos
    No *B = A->esquerda;
    No *T2 = B->direita;

    // 2. Executa a Rotação
    B->direita = A;
    A->esquerda = T2;

    // 3. Atualiza as alturas (IMPORTANTE!)
    // A altura de A deve ser atualizada PRIMEIRO
    A->altura = 1 + maior(altura(A->esquerda), altura(A->direita));
    B->altura = 1 + maior(altura(B->esquerda), altura(B->direita));

    // 4. Retorna a NOVA RAIZ da subárvore
    return B;
}

// Função para pegar a altura (evita erros com nós NULL)
int altura_no(No *no)
{
    if (no == NULL)
        return -1; // A altura de um nó nulo é -1
    return no->altura;
}

// A função do "SENSOR" - Fator de Balanceamento
int get_fator_balanceamento(No *no)
{
    if (no == NULL)
        return 0;
    // FB = altura(esquerda) - altura(direita)
    return altura(no->esquerda) - altura(no->direita);
}

void percurso_pre_ordem(Arvore raiz)
{
    if (raiz == NULL)
    {
        return;
    }
    printf("%d", raiz->valor);
    percurso_pre_ordem(raiz->esquerda);
    percurso_pre_ordem(raiz->direita);
}

void percurso_em_ordem(Arvore raiz)
{
    if (raiz == NULL)
    {
        return;
    }
    percurso_pre_ordem(raiz->esquerda);
    printf("%d", raiz->valor);
    percurso_pre_ordem(raiz->direita);
}

void percurso_pos_ordem(Arvore raiz)
{
    if (raiz == NULL)
    {
        return;
    }
    percurso_pre_ordem(raiz->esquerda);
    percurso_pre_ordem(raiz->direita);
    printf("%d", raiz->valor);
}

No *encontra_menor(Arvore raiz)
{
    No *atual = raiz;
    while (atual != NULL && atual->esquerda != NULL)
    {
        atual = atual->esquerda;
    }
    return atual;
}
// Função para remover um nó da arvore nos 3 casos
// caso 1: é um nó folha, caso 2: é um nó que tem 1 filho, caso 3: é um nó que tem 2 filhosç
Arvore remove_no(Arvore raiz, int valor)
{
    if (raiz == NULL)
    {
        return;
    }

    if (raiz->valor < valor)
    {
        raiz->esquerda = remove_no(raiz->esquerda, valor);
    }
    if (raiz->valor > valor)
    {
        raiz->direita = remove_no(raiz->direita, valor);
    }

    else
    {
        if ((raiz->direita == NULL) && (raiz->esquerda == NULL))
        {
            free(raiz);
            return NULL;
        }
        else if (raiz->direita == NULL)
        {
            No *temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        else if (raiz->esquerda == NULL)
        {
            No *temp = raiz->direita;
            free(raiz);
            return temp;
        }
        else
        {
            No *temp = encontra_menor(raiz->direita);

            raiz->valor = temp->valor;

            remove_no(raiz->direita, valor);
        }
    }
}

int procura_no(Arvore raiz, int valor)
{
    if (raiz == NULL)
    {
        return;
    }

    if (raiz->valor == valor)
    {
        printf("achou, ela existe");
        return 1;
    }

    if (raiz->valor > valor)
    {
        return procura_no(raiz->esquerda, valor);
    }

    else if (raiz->valor < valor)
    {
        return procura_no(raiz->direita, valor);
    }
}

void libera_arvore(Arvore raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    libera_arvore(raiz->esquerda);
    libera_arvore(raiz->direita);

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

// Em arvore.c

// Função para pegar a altura (evita erros com nós NULL)
int altura_no(No *no)
{
    if (no == NULL)
        return -1; // A altura de um nó nulo é -1
    return no->altura;
}

// A função do "SENSOR" - Fator de Balanceamento
int get_fator_balanceamento(No *no)
{
    if (no == NULL)
        return 0;
    // FB = altura(esquerda) - altura(direita)
    return altura(no->esquerda) - altura(no->direita);
}