#include <string.h>
#include <stdio.h>

int caractere(char arquivo[]);

void main()
{
    printf("%d", caractere("teste.txt"));
}

int caractere(char arquivo[])
{
    FILE *arq;
    int contador = 0;
    char caractere;
    arq = fopen(arquivo, "r");

    if (arq == NULL)
    {
        printf("Erro na abertura");
    }
    
    while (fscanf(arq, " %c", &caractere) != EOF)
    {
        contador++;
    }
    fclose(arq);
    return contador;
}