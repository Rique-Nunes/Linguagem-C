/*Fazer uma função que exiba a tabuada de
potências de um número n, no intervalo de 1 a
9. Se o número não estiver neste intervalo, o
código 0 deve ser retornado; caso contrário,
retorna-se 1.*/

#include "stdio.h"
int tabuada(int numero)
{
    int pow = 1;
    for (int i = 0; i <= 9; i++)
    {
        printf("%d:%d = %d\n", numero, i, pow);
        pow *= numero;
    }
}
void main()
{
    int numero;
    printf("digite o valor de n:");
    scanf("%d", &numero);
    tabuada(numero);
}