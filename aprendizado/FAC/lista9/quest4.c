/*A função logarítmica é complementar à
potenciação. Ou seja, uma vez que 3
4 = 81,
podemos então afirmar que log381 = 4.
Generalizando, temos que:
baseexpoente = pot  logbasepot = expoente
Com base nessa descrição, pede-se o
desenvolvimento de uma função que, dados a e
b, calcule o valor de logab.
Nota: a sua solução deverá apresentar um valor
inteiro que, na verdade, será a solução aproximada
do logaritmo.
*/

// quantas vezes A tem que ser multiplicado por si mesmo para dar B
#include "stdio.h"
int logar(int a, int b)
{
    int pont = a, contador = 0;

    while (pont <= b)
    {
        pont *= a;
        contador++;
    }
    return contador;
}
void main()
{
    int a, b, contador;
    printf("digite o valor da base:");
    scanf("%d", &a);
    printf("digite o valor logaritmando:");
    scanf("%d", &b);
    contador = logar(a, b);
    printf("o resultado e %d", contador);
}