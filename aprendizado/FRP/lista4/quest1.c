/*Implementar uma função que, dada uma string
s, determine a quantidade de caracteres
distintos em s.*/

#include <stdio.h>
#include <string.h>

int qtd_carecter(char string[]);

void main()
{
    char strang[10];
    int resultado;
    printf("Digite uma string: ");
    gets(strang);
    resultado = qtd_carecter(strang);
    printf("quantidade de caracteres e: %d\n", resultado);
}

int qtd_carecter(char string[])
{
    int i, cont = 0, tamanho = strlen(string);
    for (i = 0; i < tamanho; i++)
    {
        if (string[i] != '\0')
        {
            cont++;
            for (int j = i + 1; j < tamanho; j++)
            {
                if (string[j] == string[i])
                {
                    string[j] = '\0';
                }
            }
        }
    }
    return cont;
}