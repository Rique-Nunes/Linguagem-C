// Unidade.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "Unidade.h"


struct unidade {
    tData* dataFabricacao;
    int lote;
};

/* Implementacao da funcao de criacao */
tUnidade* unid_cria(int dia, int mes, int ano, int lote) {
    tUnidade* unid = (tUnidade*) malloc(sizeof(struct unidade));
    if (unid == NULL) {
        printf("Erro de alocacao de memoria para Unidade!\n");
        exit(1);
    }

        unid->dataFabricacao = dta_cria(dia, mes, ano);
  
    
    unid->lote = lote;
    return unid;
}

/* Implementacao da funcao de liberacao de memoria */
void unid_libera(tUnidade* unid) {
    if (unid != NULL) {
        dta_libera(unid->dataFabricacao); /* Libera a data interna primeiro */
        free(unid); /* Libera a estrutura da unidade */
    }
}

/* Implementacao da funcao para exibir */
void unid_exibe(tUnidade* unid) {
    printf("Data de Fabricacao: ");
    dta_exibe(unid->dataFabricacao);
    printf(", Lote: %d", unid->lote);
}

/* Implementacao dos Getters */
tData* unid_getDataFabricacao(tUnidade* unid) {
    return unid->dataFabricacao;
}

int unid_getLote(tUnidade* unid) {
    return unid->lote;
}

/* Implementacao dos Setters */
void unid_setDataFabricacao(tUnidade* unid, tData* dataFabricacao) {
    dta_libera(unid->dataFabricacao);
    unid->dataFabricacao = dataFabricacao;
}

void unid_setLote(tUnidade* unid, int lote) {
    unid->lote = lote;
}

/* Implementacao da funcao de idade */
int unid_idade(tUnidade* unid, tData* dataAlvo) {
    return dta_diferenca(unid->dataFabricacao, dataAlvo);
}

/* Implementacao da funcao para comparar se eh menor */
int unid_ehMenor(tUnidade* unid1, tUnidade* unid2) {
    int dia1, mes1, ano1, dia2, mes2, ano2;
    dta_acessa(unid1->dataFabricacao, &dia1, &mes1, &ano1);
    dta_acessa(unid2->dataFabricacao, &dia2, &mes2, &ano2);

    /* Se as datas são idênticas, desempata pelo lote */
    if (dia1 == dia2 && mes1 == mes2 && ano1 == ano2) {
        return (unid1->lote < unid2->lote);
    }
    
    /* A unidade "menor" é a mais recente (fabricada há menos tempo) */
    if (ano1 > ano2) return 1;
    if (ano1 < ano2) return 0;
    
    if (mes1 > mes2) return 1;
    if (mes1 < mes2) return 0;
    
    if (dia1 > dia2) return 1;
    
    return 0;
}

/* Implementacao da funcao para obter string formatada */
char* unid_getUnidade(tUnidade* unid) {
    char* str = (char*) malloc(100 * sizeof(char));
    char* dataStr = dta_getData(unid->dataFabricacao);
    sprintf(str, "Data: %s, Lote: %d", dataStr, unid->lote);
    free(dataStr);
    return str;
}