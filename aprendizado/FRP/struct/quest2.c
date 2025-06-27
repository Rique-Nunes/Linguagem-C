#include <stdio.h>
#include <string.h>

typedef struct
{
    int dia;
    int mes;
} tdata;

typedef struct
{
    char nome[30];
    tdata data;
} tpessoa;
int qtd_mes(tpessoa pessoas[], int m, int tamanho);
void main()
{
    tpessoa pessoas[2] = {{"HENRIQUE", 01, 12}, {"VICTOR", 15, 04}};
    printf("%d", qtd_mes(pessoas, 12, 2));
}

int qtd_mes(tpessoa pessoas[], int m, int tamanho)
{
    int i, contador = 0;
    for (i = 0; i < tamanho; i++)
    {
        if (pessoas[i].data.mes == m)
        {
            contador++;
        }
    }
    return contador;
}
