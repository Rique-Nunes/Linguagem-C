/*Implementar uma função que, dadas duas matrizes
de reais mat1 e mat2, com as mesmas dimensões,
determine se as matrizes possuem os mesmos
elementos, na mesma quantidade. Caso afirmativo,
a função deverá retornar 1; caso contrário, 0.*/

#include "stdio.h"
#include "string.h"

void ordernador(float mat1[], int tamanho);
int verificador(float mat1[], float mat2[], int tamanho);
void main()
{
    float mate1[6] = {2, 4, 2, 1, 5, 2};
    float mate2[6] = {1, 2, 2, 2, 4, 5};

    ordernador(mate1, 6);
    ordernador(mate2, 6);

    printf("%d", verificador(mate1, mate2, 6));
}

//Ordena os vetores
void ordernador(float mat1[], int tamanho)
{
    int i, j;
    float vet[0];

    int trocou;
    do
    {
        trocou = 0;
        for (i = 0; i < tamanho - 1; i++)
        {
            if (mat1[i] > mat1[i + 1])
            {
                if (mat1[i] > mat1[i + 1])
                {
                    vet[0] = mat1[i + 1];
                    mat1[i + 1] = mat1[i];
                    mat1[i] = vet[0];
                    trocou = 1;
                    break;
                }
            }
        }
    } while (trocou);
}

//Compara os vetores
int verificador(float mat1[], float mat2[], int tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        if (mat1[i] != mat2[i])
        {
            return 0;
        }
    }
    return 1;
}
