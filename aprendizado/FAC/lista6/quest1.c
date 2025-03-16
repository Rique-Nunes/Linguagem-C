/*QUESTÃO 01: Faça um programa que leia
um número inteiro x e, em seguida, solicite
ao usuário outros 50 valores inteiros. Ao
final, o programa deve exibir o total de
múltiplos de x fornecidos*/

#include <stdio.h>

void main()
{
    int x, y, cont_multiplo = 0, soma_multiplos = 0;

    printf("digite o numero x: ");
    scanf("%d", &x);

    for (int i = 1; i <= 5; i++)
    {
        printf("digite outro numero: ");
        scanf("%d", &y);
        if ((y % x) == 0)
        {
            cont_multiplo += 1;
            soma_multiplos += y;
        }
    }
    printf("a quantidade de multiplos e: %d", cont_multiplo);
    printf("o total e %d", soma_multiplos);
}
