/*Construir um programa que permita ao usuário
calcular a área de uma figura geométrica. Para
isto, o usuário deverá escolher a figura desejada
([C]írculo, [R]etângulo, [Q]uadrado ou
[T]riângulo) e fornecer as informações
necessárias para que a área desta figura possa
ser calculada.
Notas:
1. Fórmulas para o cálculo das áreas:
a. Acírculo = π.raio2, onde π = 3.14159;
b. Aretângulo = base.altura;
c. Aquadrado = lado2
d. Atriângulo = (base.altura)/2.
2. Caso o usuário escolha uma opção inválida,
uma mensagem de erro deve ser exibida e a
execução do programa terminada.
*/

#include "stdio.h"
#include "stdlib.h"

void main()
{
    int figura;
    float valor1, valor2, pi = 3.14159;

    while (1)
    {
        printf("Bem-vindo ao sistema de calculo digite o numero equivalente a sua necessidade: ");
        printf("[1] círculo, [2] retangulo, [3]quadrado, [4]triangulo, [qualquer outra tecla]Parar o programa");
        scanf("%d", &figura);
        if (figura == 1)
        {
            printf("ok entao digite o raio: ");
            scanf("%f", &valor1);
            printf("valor: %f\n", (valor1 * valor1) * pi);
        }
        else if (figura == 2)
        {
            printf("ok entao digite a base: ");
            scanf("%f", &valor1);
            printf("digite a altura: ");
            scanf("%f", &valor2);
            printf("valor: %f\n", valor1 * valor2);
        }
        else if (figura == 3)
        {
            printf("ok entao digite a base: ");
            scanf("%f", &valor1);
            printf("valor: %f\n", valor1 * valor1);
        }
        else if (figura == 4)
        {
            printf("ok entao digite a base: ");
            scanf("%f", &valor1);
            printf("digite a altura: ");
            scanf("%f", &valor2);
            printf("valor: %f\n", (valor1 * valor2) / 2);
        }
        else
        {
            printf("Parando");
            break;
        }
    }
}