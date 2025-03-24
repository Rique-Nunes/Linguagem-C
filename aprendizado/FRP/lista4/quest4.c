// Desenvolver uma função que remova de uma
// string s os caracteres compreendidos entre as posições p1 e p2.
// Caso p1 ou p2 seja uma posição inválida,a função deverá retornar o valor 0 e a remoção de
// caracteres solicitada não será realizada;
// caso contrário, deverá retornar 1 e proceder com o que foi pedido.

#include <stdio.h>
#include <string.h>

int transposta(char string[], int p1, int p2);
void resultado(char s1[]);

void main()
{
    char s1[] = "abcdefgh";
    int p1 = 2, p2 = 3, teste;
    teste = transposta(s1, p1, p2);
    printf("%d\n    ", teste);
    resultado(s1);
}
int transposta(char string[], int p1, int p2)
{
    int i, j, inicio, fim, tamanho = strlen(string);
    if (p1 < 0 || p2 < 0 || p1 >= tamanho || p2 >= tamanho)
    {
        return 0; // Posições inválidas
    }
    if (p1 < p2)
    {
        inicio = p1;
        fim = p2;
    }
    else
    {
        inicio = p2;
        fim = p1;
    }

    for (i = inicio, j = fim + 1; j <= tamanho; j++, i++)
    {
        string[i] = string[j];
    }

    return 1;
}

void resultado(char s1[])
{
    int j;
    for (j = 0; j < strlen(s1); j++)
    {
        printf("%c ", s1[j]);
    }
    printf("\n");
}