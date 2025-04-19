/*Implementar uma função recursiva que,
    dados uma string str e um caracter ch,
    remova de str todas as ocorrências de ch,
    retornando o total de remoções realizadas.
*/

#include "stdio.h"
#include "string.h"
int removedor_str(int quant, char str[], char caractere, int *cont);

void main()
{
    char string[] = "testando";
    int tamanho = strlen(string), contador = 0, teste;
    char caractere_rev = 't';
    printf("%s", string);
    removedor_str(tamanho - 1, string, caractere_rev, &contador);
    printf("\nremocoes: %d", contador);
    printf("\n%s", string);
}

int removedor_str(int quant, char str[], char caractere, int *cont)
{
    if (quant < 0)
    {
        return 0;
    }
    *cont += removedor_str(quant - 1, str, caractere, cont);
    if (str[quant] == caractere)
    {
        for (int i = quant; i < strlen(str); i++)
        {
            str[i] = str[i + 1];
            //banana
            //b - a, a - n, n - a, a - n, n - a, a - \0
        }
        return 1;
    }
    else
    {
        return 0;
    }
}