// Desenvolver uma função recursiva que
// determine o número de caracteres comuns
// entre duas strings s1 e s2.

#include "stdio.h"
#include "string.h"

int caractere(char s1[], char s2[], int i, int j);

void main()
{
    char str1[] = "osso";
    char str2[] = "ovos"; // String de teste
    int tamanho = strlen(str1);

}

int caractere(char s1[], char s2[], int i, int j)
{
    if ((i < 0) || (j < 0))
    {
        return 0;
    }
    caractere(s1, s2, i - 1, j - 1);
    if (s1[i] == s2[j])
    {
        return 1;
    }

}
//falhou!