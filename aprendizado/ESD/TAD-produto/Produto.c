// Produto.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Produto.h"


struct produto {
    char* identificacao;
    char* codigoBarras;
    double preco;
    int qtUnidades;
    tUnidade** unidades; /* Vetor de ponteiros para Unidade */
};

/* Implementacao da funcao de criacao */
tProduto* prod_cria(const char* identificacao, const char* codigoBarras, double preco) {
    tProduto* prod = (tProduto*) malloc(sizeof(struct produto));
    if (prod == NULL) {
        printf("Erro de alocacao para Produto!\n");
        exit(1);
    }

    prod->identificacao = (char*) malloc(strlen(identificacao) + 1);
    strcpy(prod->identificacao, identificacao);

    prod->codigoBarras = (char*) malloc(strlen(codigoBarras) + 1);
    strcpy(prod->codigoBarras, codigoBarras);
    
    prod->preco = preco;
    prod->qtUnidades = 0;
    prod->unidades = NULL; /* Começa sem unidades */

    return prod;
}

/* Implementacao da funcao de liberacao */
void prod_libera(tProduto* prod) {
    if (prod != NULL) {
        //Libera cada unidade dentro do vetor 
        for (int i = 0; i < prod->qtUnidades; i++) {
            unid_libera(prod->unidades[i]);
        }
        // Libera o vetor de ponteiros, as strings e a estrutura do produto 
        free(prod->unidades);
        free(prod->identificacao);
        free(prod->codigoBarras);
        free(prod);
    }
}

/* Implementacao da funcao de exibicao */
void prod_exibe(tProduto* prod) {
    printf("\n\n\n");
    printf("Produto: %s\n", prod->identificacao);
    printf("Codigo de Barras: %s\n", prod->codigoBarras);
    printf("Preco: R$ %.2f\n", prod->preco);
    printf("Quantidade de Unidades: %d\n", prod->qtUnidades);
    for (int i = 0; i < prod->qtUnidades; i++) {
        printf("  - Unidade %d: ", i + 1);
        unid_exibe(prod->unidades[i]);
        printf("\n");
    }
     printf("\n\n\n");
}

/* Implementacao da funcao que adiciona uma unidade ao produto */
void prod_adicionaUnidade(tProduto* prod, tUnidade* unid) {
    //Calcula o novo tamanho e o tamanho antigo do vetor em bytes
    int nova_qt = prod->qtUnidades + 1;
    size_t tamanho_antigo_bytes = prod->qtUnidades * sizeof(tUnidade*);
    size_t tamanho_novo_bytes = nova_qt * sizeof(tUnidade*);

    //Aloca um novo vetor com espaço suficiente para a nova quantidade
    tUnidade** novo_vetor = (tUnidade**) malloc(tamanho_novo_bytes);
    if (novo_vetor == NULL) {
        printf("Erro de alocacao para o novo vetor de unidades!\n");
        exit(1);
    }

    // Apenas copia se o vetor antigo nao estiver vazio
    if (prod->unidades != NULL) {
        memcpy(novo_vetor, prod->unidades, tamanho_antigo_bytes);
    }

    free(prod->unidades);

    // Faz o ponteiro 'unidades' do produto apontar para o novo vetor
    prod->unidades = novo_vetor;
    
    // Atualiza a quantidade e adiciona a nova unidade na última posição
    prod->qtUnidades = nova_qt;
    prod->unidades[prod->qtUnidades - 1] = unid;
}

/* Implementacao da funcao que verifica semelhança */
int prod_ehSemelhante(tProduto* prod1, tProduto* prod2) {
    return (strcmp(prod1->identificacao, prod2->identificacao) == 0);
}

/* Implementacao da funcao de reajuste de preco */
void prod_reajuste(tProduto* prod, double percentual) {
    prod->preco = prod->preco * (1 + (percentual / 100.0));
}

/* Implementacao dos Getters */
char* prod_getIdentificacao(tProduto* prod) {
    return prod->identificacao;
}

double prod_getPreco(tProduto* prod) {
    return prod->preco;
}

int prod_getQtUnidades(tProduto* prod) {
    return prod->qtUnidades;
}

tUnidade** prod_getUnidades(tProduto* prod) {
    return prod->unidades;
}

/* Implementacao da funcao que retorna string formatada */
char* prod_getProduto(tProduto* prod) {
    char* str = (char*) malloc(256 * sizeof(char));
    sprintf(str, "ID: %s, Preco: R$%.2f, Qtd: %d", prod->identificacao, prod->preco, prod->qtUnidades);
    return str;
}

/* Implementacao da funcao que verifica igualdade */
int prod_saoIguais(tProduto* prod1, tProduto* prod2) {
    if (strcmp(prod1->identificacao, prod2->identificacao) != 0) return 0;
    if (strcmp(prod1->codigoBarras, prod2->codigoBarras) != 0) return 0;
    if (prod1->preco != prod2->preco) return 0;
    if (prod1->qtUnidades != prod2->qtUnidades) return 0;
    return 1;
}



//set identificacao
void setIdentificacao(tProduto *produto, char nova_identificacao[]){
    free (produto->identificacao);
    int tamanho = strlen(nova_identificacao) + 1;
    
    produto->identificacao = (char*)malloc(tamanho * sizeof(char));
    if(produto->identificacao == NULL){
        exit(1);
    }
    
    strcpy(produto->identificacao, nova_identificacao);
}

//set codigobarra
void setCodigobarra(tProduto *produto, char nova_codigobarra[]){
    free(produto->codigobarra);
    
    int tamanho = strlen(nova_codigobarra) + 1;
    produto->codigobarra = (char *) malloc(tamanho * sizeof(char));
    if(produto->codigobarra == NULL){
        exit(1);
    }
    
    strcpy(produto->codigobarra, nova_codigobarra);
}

//set preco
void setpreco(tProduto *produto, float novo_preco){
    produto->preco = novo_preco;
}

//set qtd_unidade
void setQtdunidades(tProduto *produto, int nova_quantidade) {
    
    if (nova_quantidade < 0) {
        return;
    }


    if (nova_quantidade == 0) {
        free(produto->unidades);
        produto->unidades = NULL;
        produto->qtUnidades = 0;
        return;
    }


    tUnidade** novo_vetor = realloc(produto->unidades, nova_quantidade * sizeof(tUnidade*));

    if (novo_vetor == NULL) {
        printf("Erro ao redimensionar o vetor de unidades!\n");
        return;
    }

    produto->unidades = novo_vetor;
    produto->qtUnidades = nova_quantidade;
}