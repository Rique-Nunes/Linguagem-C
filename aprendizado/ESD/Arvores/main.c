// Arquivo: main.c

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h" // A main SÓ precisa incluir a interface!

int main()
{
    // 1. Cria a árvore (começa como vazia)
    // 'minha_arvore' é do tipo 'Arvore' (que é No*)
    Arvore minha_arvore = NULL;

    printf("Inserindo valores: 60, 20, 10, 40, 30, 50, 70\n\n");

    // 2. Insere os valores
    // Esta lógica de atribuição é OBRIGATÓRIA para este modelo
    minha_arvore = insere(minha_arvore, 60);
    minha_arvore = insere(minha_arvore, 20);
    minha_arvore = insere(minha_arvore, 10);
    minha_arvore = insere(minha_arvore, 40);
    minha_arvore = insere(minha_arvore, 30);
    minha_arvore = insere(minha_arvore, 50);
    minha_arvore = insere(minha_arvore, 70);

    // 3. Mostra os percursos (as leituras)

    printf("--- Percursos da Arvore ---\n");

    printf("Pre-Ordem (Raiz, Esq, Dir):\n");
    percurso_pre_ordem(minha_arvore);
    printf("\n\n");

    printf("Em-Ordem (Esq, Raiz, Dir) -> (deve ser crescente):\n");
    percurso_em_ordem(minha_arvore);
    printf("\n\n");

    printf("Pos-Ordem (Esq, Dir, Raiz):\n");
    percurso_pos_ordem(minha_arvore);
    printf("\n\n");

    printf("procura o 20 %d", procura_no(minha_arvore, 20));

    printf("a altura da arvore é %d", altura_arvore(minha_arvore));

    
    libera_arvore(minha_arvore);
    return 0;
}