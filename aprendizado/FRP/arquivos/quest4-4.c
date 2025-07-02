#include <stdio.h>

int verificador(char arquivo[]);

void main()
{
    printf("%d", verificador("teste.txt"));
}

int verificador(char arquivo[])
{
    FILE *arq;
    int caractere;
    int posicao_i = 0;
    arq = fopen(arquivo, "r");

    if (arq == NULL)
    {
        fclose(arq);
        return -1;
    }

    while (fscanf(arq, "%d", &caractere) != EOF)
    {
        if (caractere < posicao_i)
        {
            return 0;
        }
        else
        {
            posicao_i = caractere;
        }
    }
    return 1;
}