/*Elaborar uma função que, dado um conjunto de
300 valores inteiros, distribua-os em 2 vetores
conforme forem pares ou ímpares.*/

#include <stdio.h>

void parImpar(int lista[], int tamanho, int par[], int impar[]);
void qtdsParImpar(int *quantidade_par, int *quantidade_impar, int lista[], int tamanho);

void main()
{
    int qtd_par, qtd_impar;
    int lista[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    qtdsParImpar(&qtd_par, &qtd_impar, lista, 9);

    int lista_pares[qtd_par], lista_impares[qtd_impar];

    parImpar(lista, 9, lista_pares, lista_impares);

    for (int i = 0; i < qtd_par; i++)
    {
        printf("par: %d\n", lista_pares[i]);
    }

    for (int j = 0; j < qtd_par; j++)
    {
        printf("impar: %d\n", lista_impares[j]);
    }
}

void parImpar(int lista[], int tamanho, int par[], int impar[])
{
    int indice_par = 0;
    int indice_impar = 0;

    for (int i = 0; i < tamanho; i++)
    {
        if (lista[i] % 2 == 0)
        {
            par[indice_par] = lista[i];
            indice_par++;
        }
        else
        {
            impar[indice_impar] = lista[i];
            indice_impar++;
        }
    }
}

void qtdsParImpar(int *quantidade_par, int *quantidade_impar, int lista[], int tamanho)
{

    int qtd_par = 0, qtd_impar = 0;

    for (int i = 0; i < tamanho; i++)
    {
        if (lista[i] % 2 == 0)
        {
            qtd_par++;
        }
        else
        {
            qtd_impar++;
        }
    }
    *quantidade_par = qtd_par;
    *quantidade_impar = qtd_impar;
}