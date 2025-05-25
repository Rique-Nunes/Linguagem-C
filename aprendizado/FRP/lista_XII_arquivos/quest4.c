/*Desenvolver uma função que, dado um arquivo
texto contendo números, determine se estes
encontram-se ordenados crescentemente.*/

#include <stdio.h>
int ordernador(char arquivo[]);

void main()
{
    printf("%d", ordernador("teste.txt"));
}

int ordernador(char arquivo[])
{
    FILE *arq;
    int numero, teste = 0;
    arq = fopen(arquivo, "r");

    while (fscanf(arq, "%d", &numero) != EOF)
    {
        if (numero < teste)
        {
            return 0;
        }
        teste = numero;
    }
    fclose(arq);
    return 1;
}