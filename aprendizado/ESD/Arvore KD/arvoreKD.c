#include <stdio.h>
#include <stdlib.h>
#include <math.h> //para calculos de distancia do NN
#include "arvoreKD.h"

int dimensao_ordenacao = 0;

void copiarPonto(int dest[], int src[]) {
    for (int i = 0; i < K; i++)
        dest[i] = src[i];
}

int iguais(int a[], int b[]) {
    for (int i = 0; i < K; i++)
        if (a[i] != b[i]) return 0;
    return 1;
}


// INSERÇÃO

NoKD* inserirKD(NoKD *raiz, int ponto[], int profundidade) {
    if (raiz == NULL) {
        NoKD *novo = malloc(sizeof(NoKD));
        copiarPonto(novo->ponto, ponto);
        novo->esq = novo->dir = NULL;
        return novo;
    }

    int cd = profundidade % K;

    if (ponto[cd] < raiz->ponto[cd])
        raiz->esq = inserirKD(raiz->esq, ponto, profundidade + 1);
    else
        raiz->dir = inserirKD(raiz->dir, ponto, profundidade + 1);

    return raiz;
}

// BUSCA EXATA

NoKD* buscarKD(NoKD *raiz, int ponto[], int profundidade) {
    if (raiz == NULL) return NULL;
    if (iguais(raiz->ponto, ponto)) return raiz;

    int cd = profundidade % K;

    if (ponto[cd] < raiz->ponto[cd])
        return buscarKD(raiz->esq, ponto, profundidade + 1);
    else
        return buscarKD(raiz->dir, ponto, profundidade + 1);
}


// ENCONTRAR O MÍNIMO NA DIMENSÃO 

NoKD* encontrarMinNo(NoKD *raiz, int d, int profundidade) {
    if (raiz == NULL) return NULL;

    int cd = profundidade % K;

    if (cd == d) {
        if (raiz->esq == NULL)
            return raiz;
        return encontrarMinNo(raiz->esq, d, profundidade + 1);
    }

    NoKD *minAtual = raiz;
    NoKD *minEsq = encontrarMinNo(raiz->esq, d, profundidade + 1);
    NoKD *minDir = encontrarMinNo(raiz->dir, d, profundidade + 1);

    if (minEsq && minEsq->ponto[d] < minAtual->ponto[d])
        minAtual = minEsq;

    if (minDir && minDir->ponto[d] < minAtual->ponto[d])
        minAtual = minDir;

    return minAtual;
}


// REMOÇÃO COMPLETA

NoKD* removerKD(NoKD *raiz, int ponto[], int profundidade) {
    if (raiz == NULL) return NULL;

    int cd = profundidade % K;

    // Caso 1: encontramos o nó a remover
    if (iguais(raiz->ponto, ponto)) {

        // Caso A: Nó tem subárvore direita
        if (raiz->dir != NULL) {
            NoKD *min = encontrarMinNo(raiz->dir, cd, profundidade + 1);
            copiarPonto(raiz->ponto, min->ponto);
            raiz->dir = removerKD(raiz->dir, min->ponto, profundidade + 1);
            return raiz;
        }

        // Caso B: Só subárvore esquerda
        else if (raiz->esq != NULL) {
            NoKD *min = encontrarMinNo(raiz->esq, cd, profundidade + 1);
            copiarPonto(raiz->ponto, min->ponto);
            raiz->esq = removerKD(raiz->esq, min->ponto, profundidade + 1);
            return raiz;
        }

        // Caso C: Nó folha
        free(raiz);
        return NULL;
    }

    // descer na árvore
    if (ponto[cd] < raiz->ponto[cd])
        raiz->esq = removerKD(raiz->esq, ponto, profundidade + 1);
    else
        raiz->dir = removerKD(raiz->dir, ponto, profundidade + 1);

    return raiz;
}

double distancia(int a[], int b[]) {
    double soma = 0;
    for (int i = 0; i < K; i++) {
        double diff = a[i] - b[i];
        soma += diff * diff;
    }
    return sqrt(soma);
}


int compararPontos(const void *a, const void *b) {
    const NoKD *p1 = a;
    const NoKD *p2 = b;

    if (p1->ponto[dimensao_ordenacao] < p2->ponto[dimensao_ordenacao]) return -1;
    if (p1->ponto[dimensao_ordenacao] > p2->ponto[dimensao_ordenacao]) return  1;
    return 0;
}



NoKD* construirBalanceada(int pontos[][K], int inicio, int fim, int profundidade) {
    if (inicio > fim) return NULL;

    int cd = profundidade % K;
    int meio = (inicio + fim) / 2;
    dimensao_ordenacao = profundidade % K;


   qsort(&pontos[inicio], fim - inicio + 1, sizeof(pontos[0]), compararPontos);


    NoKD *raiz = malloc(sizeof(NoKD));
    copiarPonto(raiz->ponto, pontos[meio]);

    raiz->esq = construirBalanceada(pontos, inicio, meio - 1, profundidade + 1);
    raiz->dir = construirBalanceada(pontos, meio + 1, fim, profundidade + 1);

    return raiz;
}

//NN

NoKD* vizinhoMaisProximo(NoKD *raiz, int alvo[], int profundidade,
                         NoKD *melhor, double *melhorDist) {

    if (raiz == NULL) return melhor;

    double d = distancia(raiz->ponto, alvo);
    if (d < *melhorDist) {
        *melhorDist = d;
        melhor = raiz;
    }

    int cd = profundidade % K;

    NoKD *lado1, *lado2;
    if (alvo[cd] < raiz->ponto[cd]) {
        lado1 = raiz->esq;
        lado2 = raiz->dir;
    } else {
        lado1 = raiz->dir;
        lado2 = raiz->esq;
    }

    melhor = vizinhoMaisProximo(lado1, alvo, profundidade + 1,
                                melhor, melhorDist);

    double distPlano = abs(alvo[cd] - raiz->ponto[cd]);

    if (distPlano < *melhorDist) {
        melhor = vizinhoMaisProximo(lado2, alvo, profundidade + 1,
                                    melhor, melhorDist);
    }

    return melhor;
}



// Impressão
void imprimirKD(NoKD *raiz) {
    if (raiz == NULL) return;
    printf("(%d,%d)\n", raiz->ponto[0], raiz->ponto[1]);
    imprimirKD(raiz->esq);
    imprimirKD(raiz->dir);
}

// Libera memória
void liberarKD(NoKD *raiz) {
    if (!raiz) return;
    liberarKD(raiz->esq);
    liberarKD(raiz->dir);
    free(raiz);
}
