#include "stdio.h"
#include "stdlib.h"
#include "math.h"

void main()
{
    float valor, desconto, prestacao, prestacao_juro;
    printf("Vamos calcular as promocoes\ndigite o preco do produto: ");
    scanf("%f", &valor);

    desconto = valor - (valor * 0.1);
    printf("O pagamento a vista e: %f", desconto);
    prestacao = valor / 5;
    printf("\nO pagamento parcelado em 5x a parcela fica: %f", prestacao);
    prestacao_juro = (valor + valor * 0.2) / 10;
    printf("\nO pagamento parcelado em 10x a parcela fica: %f", prestacao_juro);
}