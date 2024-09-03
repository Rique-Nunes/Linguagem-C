#include "stdlib.h"
#include "stdio.h"
#include "math.h"

void main()
{
    int planeta; /*int indica a variavel como tipo inteiro*/
    float massa, peso, gravidade;
    printf("Vamos calcular seu peso em qualquer planeta\nDigite seu peso: ");
    scanf("%f", &massa);
    printf("Agora digite o planeta para determinar seu peso: ");
    scanf("%d", &planeta);
    switch (planeta) /*o switch representa as variações de uma variavel 
                        com número inteiro pode assumir*/
    {
    case 1: /*caso seja 1 ele executa o que tiver depois dos dois pontos
            alerta! se não tiver o "break;" para parar o código ele testará todos os outros*/
        gravidade = 0.37;
        break;
    case 2:
        gravidade = 0.88;
        break;
    case 3:
        gravidade = 0.38;
        break;
    case 4:
        gravidade = 2.64;
        break;
    case 5:
        gravidade = 1.15;
        break;
    case 6:
        gravidade = 1.17;
        break;
    default:
        printf("erro");
    }
    peso = (massa / 10) * gravidade;
    printf("o seu peso neste planeta e: %f ", peso);
}