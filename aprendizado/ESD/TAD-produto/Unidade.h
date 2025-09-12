// Unidade.h
#ifndef UNIDADE_H
#define UNIDADE_H

#include "Data.h"

/* Define o tipo tUnidade como um ponteiro para a estrutura interna */
typedef struct unidade tUnidade;

/* Funcao cria - Aloca e inicializa uma tUnidade.*/
tUnidade* unid_cria(int dia, int mes, int ano, int lote);

/* Funcao libera - Libera a memoria alocada para uma tUnidade. */
void unid_libera(tUnidade* unid);

/* Funcao exibe - Escreve na tela os dados da unidade. */
void unid_exibe(tUnidade* unid);

/* Funcao getDataFabricacao - Retorna a data de fabricacao de uma unidade. */
tData* unid_getDataFabricacao(tUnidade* unid);

/* Funcao getLote - Retorna o lote de uma unidade. */
int unid_getLote(tUnidade* unid);

/* Funcao setDataFabricacao - Atribui uma nova data de fabricacao para a unidade. */
void unid_setDataFabricacao(tUnidade* unid, tData* dataFabricacao);

/* Funcao setLote - Atribui um novo lote para a unidade. */
void unid_setLote(tUnidade* unid, int lote);

/* Funcao idade - Retorna a idade da unidade em dias, com base em uma data alvo. */
int unid_idade(tUnidade* unid, tData* dataAlvo);

/* Funcao ehMenor - Compara se uma unidade 'eh menor' que outra.
   Uma unidade eh menor se for mais recente. Em caso de empate, o lote menor desempata.
   Retorna 1 se unid1 < unid2, e 0 caso contrario. */
int unid_ehMenor(tUnidade* unid1, tUnidade* unid2);

/* Funcao getUnidade - Retorna uma string formatada com os dados da unidade. */
char* unid_getUnidade(tUnidade* unid);

#endif 