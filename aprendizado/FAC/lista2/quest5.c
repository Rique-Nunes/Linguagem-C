#include "stdio.h"
#include "stdlib.h"

void main()
{
    int codigo;
    float qtd, preco, pedido;

    printf("Digite o codigo do produto: \n");
    scanf("%d", &codigo);
    printf("Digite a quantidade do produto: \n");
    scanf("%f", &qtd);

    switch (codigo)
    {
    case 100:
        pedido = qtd * 3.50;
        break;
    case 101:
        pedido = qtd * 4.50;
        break;
    case 102:
        pedido = qtd * 5.20;
        break;
    case 103:
        pedido = qtd * 3.0;
        break;
    case 104:
        pedido = qtd * 4.0;
        break;
    case 105:
        pedido = qtd * 2.50;
        break;
    default:
        printf("Erro nos valores digitados");
        break;
    }

    printf("O valor do pedido e: %f", pedido);
}
