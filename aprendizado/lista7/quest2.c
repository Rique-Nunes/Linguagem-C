/*Um fazendeiro realizou um
tratamento sobre sua plantação de café
que gerou um crescimento constante de C
% em sua produção, por ano.
Considerando que atualmente sua
produção anual seja de M u.p.,
implementar um programa que determine
a quantidade de anos necessária para que
a produção duplique.
*/

#include <stdio.h>

void main()
{
    int producao_inicial, producao, tempo = 0;
    float porcentagem;

    printf("digite a producao atual do ano: ");
    scanf("%d", &producao_inicial);
    printf("digite a porcentagem do crescimento: ");
    scanf("%f", &porcentagem);
    producao = producao_inicial;
    do
    {
        producao = producao + ((porcentagem / 100) * producao);
        tempo += 1;
    } while (producao <= (producao_inicial * 2));

    printf("demorou %d anos", tempo);
}