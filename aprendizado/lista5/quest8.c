/*Fazer um programa que auxilie o órgão
regulador no cálculo do total de recursos
arrecadados com a aplicação de multas de
trânsito.
O programa deve ler as seguintes
informações para cada motorista:
 O número da carteira de motorista;
 Número de multas;
 Valor de cada uma das multas.
Deve ser exibido o valor da dívida de cada
motorista e ao final da leitura o total de
recursos arrecadados (somatório de todas
as multas). O programa também deverá
apresentar o número da carteira do
motorista que obteve o maior número de
multas. */

#include "stdio.h"

void main()
{
    int carteira, multa, multa_soma = 0, multas_totais = 0, qtd_multas, maior_multa = 0, maior_carteira = 0;
    char encerra;
    while (encerra != 's')
    {
        printf("digite o numero da carteira: ");
        scanf("%d", &carteira);
        printf("digite a quantidade de multas: ");
        scanf("%d", &qtd_multas);
        for(int i = 0; i < qtd_multas; i++){
           printf("digite o valor da multa: ");
           scanf("%d", &multa);
           multa_soma += multa;
        }
        printf("divida: %d", multa_soma);
        if (qtd_multas > maior_multa)
        {
            maior_carteira = carteira;
            maior_multa = qtd_multas;
        }
        multas_totais += multa_soma;
        printf("\nencerrar programa? (s/n)");
        scanf("%s", &encerra);
    }
    printf("arrecadacao total: %d\n", multas_totais);
    printf("a carteira %d, teve a maior multa sendo de %d multas totais", maior_carteira, maior_multa);
}