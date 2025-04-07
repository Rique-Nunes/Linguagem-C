/*
Dada uma string s, desenvolver uma função
recursiva que determine se s é ou não um palíndromo.
*/
#include "stdio.h"
#include "string.h"

int palindromo(char string[], int i, int j);

void main()
{
    char string[] = "osso"; // String de teste
    int tamanho = strlen(string);

    if (palindromo(string, 0, tamanho - 1))
    {
        printf("e um palindromo\n");
    }
    else
    {
        printf("Nao e um palindromo\n");
    }

}

int palindromo(char string[], int i, int j)
{
    if (i >= j)
    {
        return 1;
    }
    if (string[i] == string[j])
    {
        return palindromo(string, i + 1, j - 1);
    }
    else
    {
        return 0;
    }
}