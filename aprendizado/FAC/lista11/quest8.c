/*Faça uma função que, dado um vetor de
números inteiros, exiba para cada um de seus
elementos a quantidade de vezes que o mesmo
aparece no vetor.
Exemplo:
Vetor = {3,5,1,3,2,5,7,3,4,7,6,1}
Saída:
3: 3 vezes
5: 2 vezes
1: 2 vezes
2: 1 vez
7: 2 vezes
4: 1 vez
6: 1 vez*/

#include <stdio.h>

void exibeQuantidadeDeElementos(int vetor[], int tamanho);

void main()
{
    int vetor[7] = {3, 5, 1, 3, 2, 5, 7};
    int tamanho = 7;
    exibeQuantidadeDeElementos(vetor, tamanho);
}

void exibeQuantidadeDeElementos(int vetor[], int tamanho)
{
    int cont = 0, i, j, h;
    for (i = 0; i < tamanho; i++)
    {
        for (j = 0; j < tamanho; j++)
        {
            if (vetor[i] == vetor[j])
            {
                cont++;
            }
        }
        for (h = 0; h < cont; h++)
        {
            printf("%d\n", vetor[i]);
        }
        cont = 0;
    }
}