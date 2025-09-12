#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Representa��o do TAD: TData
//Feito pela professora
// Interface
//-----------

typedef struct data tData;

/* Fun��es exportadas */
/* Fun��o cria - Aloca e retorna uma data dia/m�s/ano */
tData* dta_cria(int dia, int mes, int ano);

/* Fun��o libera � Libera  mem�ria de uma Data criada */
void dta_libera(tData* p);

/* Fun��o acessa - Retorna os valores de uma Data */
void dta_acessa(tData* p, int* dia, int* mes, int* ano);

/* Fun��o atribui - Atribui novos valores � Data */
void dta_atribui(tData* p, int dia, int mes, int ano);

/* Fun��o Intervalo - Retorna a data ap�s X dias */
tData* dta_intervalo(tData* p1, int X);

/* Fun��o Exibe � Escreve na tela a data  no formato dd/mm/aaaa */
tData* dta_exibe(tData* p1);

/* Fun��o getData - Retorna uma string com os valores da data no formato dd/mm/aaaa*/
char* dta_getData(tData* p);

/* DIFERENÇA EM DIAS ENTRE DUAS DATAS*/
int dta_diferenca(tData* dt1, tData * dt2);

/* Funcao compara - Compara duas datas.
   Retorna:
   -1 se dt1 < dt2
    0 se dt1 == dt2
   +1 se dt1 > dt2 */
int dta_compara(tData* dt1, tData* dt2);
