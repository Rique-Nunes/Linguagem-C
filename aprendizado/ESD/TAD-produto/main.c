// main.c
#include <stdio.h>
#include <stdlib.h>
#include "Data.h"
#include "Unidade.h"
#include "Produto.h"

/* Validade padrão para todos os produtos(não foi especificado) */
#define VALIDADE_EM_DIAS 60

int main() {
    /*vetor de ponteiros para produtos com dados exemplos */
    
    tProduto* p1 = prod_cria("Iogurte", "7891234567890", 5.50);
    tProduto* p2 = prod_cria("Leite", "7890987654321", 4.25);
    tProduto* p3 = prod_cria("Pao", "7891122334455", 8.00);

    /* Adicionando unidades aos produtos */
    prod_adicionaUnidade(p1, unid_cria(20, 7, 2025, 101));
    prod_adicionaUnidade(p1, unid_cria(1, 8, 2025, 102));

    prod_adicionaUnidade(p2, unid_cria(5, 9, 2025, 201));
    prod_adicionaUnidade(p2, unid_cria(8, 9, 2025, 202));

    prod_adicionaUnidade(p3, unid_cria(2, 9, 2025, 301));

    /* Vetor de estoque */
    int num_produtos = 3;
    tProduto* estoque[] = {p1, p2, p3};

    int dia, mes, ano;
    printf("Digite a data alvo (DD MM AAAA): ");
    scanf("%d %d %d", &dia, &mes, &ano);
    tData* dataAlvo = dta_cria(dia, mes, ano);
    
    printf("Data Alvo: ");
    dta_exibe(dataAlvo);
    printf(" (Assumindo validade de %d dias)\n\n", VALIDADE_EM_DIAS);

    /* Mostrar unidades que vencem na data alvo */
    for (int i = 0; i < num_produtos; i++) {
        tProduto* produto_atual = estoque[i];
        printf("Verificando produto: %s\n", prod_getIdentificacao(produto_atual));
        
        int qtUnidades = prod_getQtUnidades(produto_atual);
        tUnidade** unidades = prod_getUnidades(produto_atual);
        
        for (int j = 0; j < qtUnidades; j++) {
            tUnidade* unidade_atual = unidades[j];
            tData* dataFabricacao = unid_getDataFabricacao(unidade_atual);
            
            tData* dataVencimento = dta_intervalo(dataFabricacao, VALIDADE_EM_DIAS);
            
            if (dta_diferenca(dataVencimento, dataAlvo) == 1) {
                printf("  -> Unidade com lote %d VENCE HOJE!\n", unid_getLote(unidade_atual));
            }
            
            dta_libera(dataVencimento);
        }
    }

    printf("\nAPLICANDO DESCONTO EM PRODUTOS COM VENCIMENTO PROXIMO\n");

    /* Para produtos com unidades vencendo em 3 dias, aplicar desconto */
    for (int i = 0; i < num_produtos; i++) {
        tProduto* produto_atual = estoque[i];
        int aplicar_desconto = 0;

        int qtUnidades = prod_getQtUnidades(produto_atual);
        tUnidade** unidades = prod_getUnidades(produto_atual);

        for (int j = 0; j < qtUnidades; j++) {
    tData* dataFabricacao = unid_getDataFabricacao(unidades[j]);
    tData* dataVencimento = dta_intervalo(dataFabricacao, VALIDADE_EM_DIAS);

    if (dta_compara(dataVencimento, dataAlvo) >= 0) {
        
        /*Calcula a diferenca de dias */
        int dias_para_vencer = dta_diferenca(dataVencimento, dataAlvo) - 1;

        /* Verifica se a diferenca esta no intervalo de 0 a 3 dias */
        if (dias_para_vencer <= 3) {
            aplicar_desconto = 1;
            dta_libera(dataVencimento);
            break; 
        }
    }
    dta_libera(dataVencimento);
}

        if (aplicar_desconto) {
            printf("Produto '%s' tem unidade com vencimento proximo!\n", prod_getIdentificacao(produto_atual));
            printf("  Preco antigo: R$ %.2f\n", prod_getPreco(produto_atual));
            prod_reajuste(produto_atual, -25.0);
            printf("  NOVO PRECO com 25%% de desconto: R$ %.2f\n", prod_getPreco(produto_atual));
        }
    }
    
    /* Exibindo estado final do estoque */
    printf("\nESTADO FINAL DO ESTOQUE\n");
    for(int i = 0; i < num_produtos; i++) {
        prod_exibe(estoque[i]);
    }

    /* Liberando toda a memória alocada */
    dta_libera(dataAlvo);
    for (int i = 0; i < num_produtos; i++) {
        prod_libera(estoque[i]);
    }

    return 0;
}