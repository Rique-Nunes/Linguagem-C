/*Dados um vetor de reais (cujos elementos
estão ordenados crescentemente) e um
número x, retornar a posição da primeira
ocorrência de x (caso encontre-se no vetor) ou
a posição na qual deveria estar (caso contrário).
*/
#include <stdio.h>

int tester(float lista[], float numero, int tamanho);

void main()
{
    float lista[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, num;
    int resultado;
    printf("digite o numero: ");
    scanf("%f", &num);

    resultado = tester(lista, num, 9);
    printf("\n%d e a posicao dele", resultado);
}

int tester(float lista[], float numero, int tamanho)
{
    int maior = 0;
    for (int i = 0; i < tamanho; i++)
    {
        // 0 1 2 3 4 5 6 7 8
        if (lista[i] == numero)
        {
            return i;
        }
        if (lista[i] > numero)
        {
            maior = i;
        }
    }
    if (maior == 0)
    {
        return tamanho + 1;
    }
    else
    {
        return maior - 1;
    }
}