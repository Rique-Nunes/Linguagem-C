#include "stdio.h"
int verificador(char arq[], char arq2[]);

void main()
{
    printf("%d", verificador("teste.txt", "teste2.txt"));
}

int verificador(char arquivo1[], char arquivo2[])
{
    int numero1, numero2, contador;
    FILE *arq1, *arq2;

    arq1 = fopen(arquivo1, "r");
    arq2 = fopen(arquivo2, "r");

    if (!arq1 || !arq2)
    {
        return 0;
    }

    while (fscanf(arq1, "%d", &numero1) != EOF)
    {
        contador = 0;
        rewind(arq2);
        while (fscanf(arq2, "%d", &numero2) != EOF)
        {
            if (numero1 == numero2)
            {
                contador++;
            }
        }
        if (contador == 0)
        {
            return 0;
        }
        if (contador > 1)
        {
            return 0;
        }
    }
    fclose(arq1);
    fclose(arq2);
    return 1;
}