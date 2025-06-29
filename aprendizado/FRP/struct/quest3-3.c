#include <stdio.h>

int verificador(char arquivo[]);

void main()
{
    printf("%d", verificador("teste.txt"));
}

int verificador(char arquivo[])
{
    FILE *arq;
    char caractere;
    int contador = 0;
    arq = fopen(arquivo, "r");

    if (arq == NULL)
    {
        fclose(arq);
        return -1;
    }

    while (fscanf(arq, "%c", &caractere) != EOF)
    {
        caractere = toupper(caractere);
        if ((caractere >= 'A') && (caractere <= 'Z'))
        {
            contador++;
        }
    }
    fclose(arq);
    return contador;
}