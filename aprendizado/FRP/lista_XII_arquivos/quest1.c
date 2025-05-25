/*Desenvolver uma função que, dado um arquivo
texto, verifique o número de caracteres no
mesmo.*/

#include <stdio.h>

int verificador(char arquivo[]);

void main()
{
    printf("%d", verificador("teste.txt"));
}

int verificador(char arquivo[])
{
    FILE *arq;
    int number, cont = 0;
    arq = fopen(arquivo, "r");

    while (fscanf(arq, "%d", &number) != EOF)
    {
        cont++;
    }
    fclose(arq);
    return cont;
}