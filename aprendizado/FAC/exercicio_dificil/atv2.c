/*Desenvolver um programa que, dados dois números inteiros
(fornecidos pelo usuário), exiba os números
compreendidos entre a e b, porém “pulando” alguns dos valores
do intervalo, e, ao final, apresente a quantidade de
elementos exibidos, conforme os exemplos abaixo:
Exemplo 1:
a = 10
b = 30
Números exibidos:
10, 11, 13, 16, 20, 25
o proprio, +1, +2, +3 ,+4, +5
Além de exibir os valores acima, o programa deve apresentar,
nesse caso, o número 6 (pois 6 valores foram exibidos).
*/
#include "stdio.h"

void main()
{
    int a, b, cont = 0;

    printf("digite o primeiro numero: ");
    scanf("%d", &a);
    printf("digite o numero maximo: ");
    scanf("%d", &b);

    for (int i = a; i <= b; i += cont)
    {
        printf("%d\n", i);
        cont++;
    }
}