/*Implementar um programa que exiba os N
    primeiros termos de uma
    PA(Progressão Aritmética) com primeiro termo a1 e razãor.
*/
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n, a1, r, termo =0;
    printf("Digite o primeiro termo da PA: ");
    scanf("%d", &a1);
    printf("Digite a razao da PA: ");
    scanf("%d", &r);
    printf("Digite o numero de termos da PA: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", a1 + ((i - 1) * r));
        //printf("%d\n",a1 + termo);
        //termo += r;
    }
}
