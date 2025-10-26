// Arquivo: arvore.h

#pragma once // Um comando para evitar que este arquivo seja incluído várias vezes

// --- Definição dos Tipos ---

// Dizemos ao C que existe uma 'struct no', mas não como ela é.
// Isso é chamado de "tipo opaco".
typedef struct no No;

// O tipo 'Arvore' é um ponteiro para o nó raiz.
typedef No *Arvore;

// --- Protótipos das Funções Públicas ---

/**
 * @brief Insere um novo valor em uma Árvore Binária de Busca (ABB).
 * @param raiz A raiz da árvore (ou subárvore) onde queremos inserir.
 * @param valor O valor inteiro a ser inserido.
 * @return Um ponteiro para a raiz da árvore (que pode ter sido modificada).
 */
Arvore insere(Arvore raiz, int valor);

/**
 * @brief Imprime a árvore no percurso Pré-Ordem (Raiz, Esquerda, Direita).
 */
void percurso_pre_ordem(Arvore raiz);

/**
 * @brief Imprime a árvore no percurso Em-Ordem (Esquerda, Raiz, Direita).
 * Em uma ABB, este percurso imprime os valores em ordem crescente.
 */
void percurso_em_ordem(Arvore raiz);

/**
 * @brief Imprime a árvore no percurso Pós-Ordem (Esquerda, Direita, Raiz).
 */
void percurso_pos_ordem(Arvore raiz);

// Função para remover um nó da arvore nos 3 casos
// caso 1: é um nó folha, caso 2: é um nó que tem 1 filho, caso 3: é um nó que tem 2 filhosç
Arvore remove_no(Arvore raiz, int valor);

No *encontra_menor(Arvore raiz);

// Função para procurar um valor se ela existe na árvore
int procura_no(Arvore raiz, int valor);

// Função para liberar a arvore (primeiro temos que liberar os filhos e depois a propria raiz)

void libera_arvore(Arvore raiz);

int altura_arvore(Arvore raiz);

int maior(int a, int b);