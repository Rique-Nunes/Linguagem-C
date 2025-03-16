/*: Elabore um programa que
calcule a média ponderada de n elementos.*/
#include <stdio.h>

void main()
{
    float numero, peso, produto = 0, soma = 0, qtd = 0;
    char pare = 'n';
    while (pare == 'n')
    {
        printf("digite o numero: ");
        scanf("%f", &numero);
        printf("digite o peso: ");
        scanf("%f", &peso);
        produto = numero * peso;
        soma += produto;
        qtd += 1;
        printf("quer parar: ");
        scanf(" %c", &pare);
    }
    printf("total da media: %.2f", soma / qtd);
}
