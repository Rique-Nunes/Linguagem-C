#include "stdio.h"
#include "stdlib.h"
#include "math.h"

void main()
{
    float peso, altura, imc;
    printf("Fazendo o calculo do IMC, \nDigite o peso:");
    scanf("%f", &peso);
    printf("Digite a altura: ");
    scanf("%f", &altura);

    imc = peso / pow(altura, 2);
    printf("O seu IMC e %f \n", imc);
    if (imc < 18.5)
    {
        printf("Sua condicao e abaixo do esperado");
    }
    else if (imc < 25.0)
    {
        printf("Seu peso e ideal");
    }
    else if (imc < 30.0)
    {
        printf("Sua condicao e sobrepeso");
    }
    else if (imc < 35.0)
    {
        printf("Sua condicao e Obesidade grau 1");
    }
    else if (imc < 40)
    {
        printf("Sua condicao e Obesidade grau 2");
    }
    else
    {
        printf("Sua condicao e Obesidade grau 3");
    }
}