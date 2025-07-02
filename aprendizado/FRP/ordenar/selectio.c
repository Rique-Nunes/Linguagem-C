#include <stdio.h>

// teste para o método de ordenação

// selection

void selection(int valores[], int tamanho);
void main()
{

    int valores[3] = {6, 3, 1};
    selection(valores, 3);

    for (int i = 0; i < 3; i++)
    {
        printf("%d", valores[i]);
    }
}

void selection(int valores[], int tamanho)
{
    int i, j, min;
    int aux;
    for (i = 0; i < tamanho - 1; i++)
    {
        min = i;
        for (j = i + 1; j < tamanho; j++)
        {
            if (valores[j] < valores[min])
            {
                min = j;
            }
        }
        aux = valores[i];
        valores[i] = valores[min];
        valores[min] = aux;
    }
}