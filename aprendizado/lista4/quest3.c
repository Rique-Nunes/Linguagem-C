#include "stdio.h"
#include "stdio.h"

void main()
{
    float aplicacao, rendimento, montante, juro;
    int tempo;

    printf("Vamos ver quando uma aplicacao vale, de entrada no valor da aplicacao: ");
    scanf("%f", &aplicacao);
    printf("Quanto de rendimento: ");
    scanf("%f", &rendimento);
    printf("Quanto tempo de investimento (em anos): ");
    scanf("%d", &tempo);
    // existe a função pow(), porém estou fazendo sem ela, a única forma que pensei foi:
    tempo *= 12;
    /*for (int i = 0; i <= tempo; i++) tentativa de juros compostos
    {
        rendimento *= (1 + (rendimento / 100));
    }montante = aplicacao * rendimento;*/
    montante = aplicacao + (aplicacao * (rendimento / 100) * tempo); // juros simples
    printf("O montante resultante e: %.2f", montante);
}