/*Faça um programa que leia
um número real x e um número inteiro y.
Em seguida, o programa deve ler 100
números reais e calcular quantos destes
estão no intervalo definido por [x-y,x+y].
*/

#include <stdio.h>

void main()
{
    int y, qtd_numeros = 0;
    float x, numero;

    printf("digite o numero x: ");
    scanf("%f", &x);
    printf("digite o numero y: ");
    scanf("%d", &y);

    for (int i = 1; i < 100; i++)
    {
        printf("digite o numero: ");
        scanf("%f", &numero);

        if (((x - y) <= numero) && (numero <= (x + y)))
        {
            qtd_numeros += 1;
        }
    }
    printf("a quantidade de numeros e: %d", qtd_numeros);
}