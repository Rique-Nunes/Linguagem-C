#include <stdio.h>

int verificador(char arquivo[], char escolhido);

void main()
{
    printf("%d", verificador("teste.txt", '1'));
}

int verificador(char arquivo[], char escolhido)
{
    FILE *arq;
    char caracter;
    int contador;
    arq = fopen(arquivo, "r");

    if (arq == NULL)
    {
        fclose(arq);
        return 0;
    }
    while (fscanf(arq, " %c", &caracter) != EOF)
    {
        if (caracter == escolhido)
        {
            contador++;
        }
    }
    fclose(arq);
    return contador;
}