/*Crie uma função que conte quantas letras 'a' existem em uma string*/

#include "stdio.h"

int conter(char string[], int tamanho);
void main()
{
    char letras[4];
    scanf("%s", letras);
    printf("%s", letras);
    printf("%d", conter(letras, 4));
}

int conter(char string[], int tamanho)
{
    if (tamanho < 0)
    {
        return 0;
    }
    if (string[tamanho] == 'a')
    {
        return 1 + conter(string, tamanho - 1);
    }
    else
    {
        return 0 + conter(string, tamanho - 1);
    }
}