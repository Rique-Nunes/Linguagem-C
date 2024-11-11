/*Fazer uma função que, dados dois números inteiros num1 e
num2, determine se num2 é uma potência de num1.
Nota: apresentar a main chamando a função implementada.*/

#include <stdio.h>

int testando(int num1, int num2);

void main()
{
    int primeiro, segundo, teste;
    printf("digite o primeiro numero: ");
    scanf("%d", &primeiro);
    printf("digite o segundo numero para testar: ");
    scanf("%d", &segundo);
    // por algum motivo não consigo testar direto no if
    teste = testando(primeiro, segundo);

    if (teste == 1)
    {
        printf("e potencia");
    }
    else
    {
        printf("nao e potencia");
    }
}

int testando(int num1, int num2)
{
    int pont = 1, resultado;

    // se num2 for 0 e qualquer numero elevado a 0 é 1
    if (num2 == 0)
    {
        return 1;
    }
    // qualquer numero sobre 1 dá 1
    if (num1 == 1)
    {
        return 1;
    }
    // esqueci
    if (num1 == 0 && num2 != 0)
    {
        return 0;
    }

    // testando
    while (pont < num2)
    {
        pont *= num1;
    }

    if (pont == num2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}