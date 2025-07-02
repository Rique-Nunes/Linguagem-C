/*Faça uma função que, dado um arquivo A
contendo números reais, um por linha, crie um
novo arquivo B contendo os mesmos
elementos de A, porém ordenados
decrescentemente e sem repetição.
*/

#include <stdio.h>
int qual_maior(char arquivo[], float *valor, int limite);
void ordenador(char arquivo[]);

void main()
{
    ordenador("teste.txt");
}

void ordenador(char arquivo[])
{
    FILE *arq, *temp;
    float numero, valor;
    float limite = 10000;

    arq = fopen(arquivo, "r");
    temp = fopen("ordenado.txt", "w");

    if (!arq || !temp)
    {
        fclose(arq);
        fclose(temp);
    }
    while (qual_maior(arquivo, &valor, limite) == 1)
    {
        fprintf(temp, "%.2f\n", valor);
        limite = valor;
    }
    printf("terminou");
}

int qual_maior(char arquivo[], float *valor, int limite)
{
    FILE *arq;
    float numero;

    arq = fopen(arquivo, "r");
    if (!arq)
    {
        fclose(arq);
        return -1;
    }
    *valor = 0;

    while (fscanf(arq, "%f", &numero) != EOF)
    {
        if (numero < limite)
        {
            if (numero > *valor)
            {
                *valor = numero;
            }
        }
    }
    if (*valor == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}