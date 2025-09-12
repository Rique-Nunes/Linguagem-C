#ifndef PRODUTO_H
#define PRODUTO_H

#include "Unidade.h"

/* Define o tipo tProduto como um ponteiro para a estrutura interna */
typedef struct produto tProduto;

/* Funcao cria - Aloca e inicializa uma estrutura tProduto. */
tProduto* prod_cria(const char* identificacao, const char* codigoBarras, double preco);

/* Funcao libera - Libera a memoria de um tProduto e de todas as suas unidades. */
void prod_libera(tProduto* prod);

/* Funcao exibe - Escreve na tela os dados de um produto e de todas as suas unidades. */
void prod_exibe(tProduto* prod);

/* Funcao adicionaUnidade - Adiciona uma unidade a um produto. */
void prod_adicionaUnidade(tProduto* prod, tUnidade* unid);

/* Funcao ehSemelhante - Verifica se um produto eh semelhante a outro (mesma identificacao). */
int prod_ehSemelhante(tProduto* prod1, tProduto* prod2);

/* Funcao reajuste - Reajusta o preco do produto em um percentual. */
void prod_reajuste(tProduto* prod, double percentual);

/* Funcao getIdentificacao - Retorna a identificacao do produto. */
char* prod_getIdentificacao(tProduto* prod);

/* Funcao getPreco - Retorna o preco do produto. */
double prod_getPreco(tProduto* prod);

/* Funcao getQtUnidades - Retorna a quantidade de unidades do produto. */
int prod_getQtUnidades(tProduto* prod);

/* Funcao getUnidades - Retorna o vetor de ponteiros para as unidades. */
tUnidade** prod_getUnidades(tProduto* prod);

/* Funcao getProduto - Retorna uma string formatada com os dados do produto. */
char* prod_getProduto(tProduto* prod);

/* Funcao saoIguais - Verifica se dois produtos sao exatamente iguais. */
int prod_saoIguais(tProduto* prod1, tProduto* prod2);


void setIdentificacao(tProduto *produto, char nova_identificacao[];

void setCodigobarra(tProduto *produto, char nova_codigobarra[]);

void setpreco(tProduto *produto, double novo_preco);

void setQtdunidades(tProduto *produto, int nova_quantidade);

#endif 