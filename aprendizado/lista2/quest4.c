#include "stdio.h"
#include "stdlib.h"

void main()
{
    float percuso, km_l, preco_l, qtd_combustivel, custo_total;
    printf("De entrada do percuso: \n");
    scanf("%f", &percuso);
    printf("De a entrada do numero de litro/km do carro: \n");
    scanf("%f", &km_l);
    printf("De a entrada da cotacao atual da gasolina: \n");
    scanf("%f", &preco_l);
    qtd_combustivel = percuso / km_l;
    custo_total = qtd_combustivel * preco_l;
    printf("Resumindo ao final da viajem consumiu-se %f e o custo foi de: %f", qtd_combustivel, custo_total);
}