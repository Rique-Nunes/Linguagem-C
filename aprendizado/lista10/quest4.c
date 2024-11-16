/*Fazer uma função que armazene em um vetor
os 50 primeiros termos da seguinte sequência:
S = 1, 2, 4, 7, 11, 16, ...
Nota: observem que a diferença entre o 1º e 2º
elementos é igual a 1, entre o 2º e 3º é igual a
2, entre o 3º e o 4º é igual a 3, e assim sucessivamente.*/

#include <stdio.h>

void seq(int lista[], int tamanho);

void main()
{
    int lista[50];

    seq(lista, 50);
    
    for (int i = 0; i < 50; i++)
    {
        printf("%d\n", lista[i]);
    }
}

void seq(int lista[], int tamanho)
{
    int sequencia = 1, razao = 1;

    for (int i = 0; i < tamanho; i++)
    {
        lista[i] = sequencia;
        sequencia += razao;
        razao++;
    }
}