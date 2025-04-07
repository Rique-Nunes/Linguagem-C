// Desenvolver uma função recursiva que, dada
// uma string, exiba - a invertida.

#include <stdio.h>
#include <string.h>

void inverte_string(char str[], int tamanho);

void main()
{
    char string[] = "avenida"; // String de teste
    int tamanho = strlen(string);
    inverte_string(string, tamanho - 1);
}

void inverte_string(char str[], int tamanho)
{
    if (tamanho >= 0)
    {
        printf("%c", str[tamanho]);
        inverte_string(str, tamanho - 1);
    }
}