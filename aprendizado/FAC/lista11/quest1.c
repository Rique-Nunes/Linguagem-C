/*
Analise o código apresentado a seguir e forneça
todos os valores exibidos durante a execução
do programa:
*/
#include <stdio.h>
// pega o vetor e seu tamanho, e um limitador
// ele vai diminuindo o tamanho -1, em -2 até esse limitador e
// a cada 2 posições ele vai duplicando o valor da posição vetor i
void funcao01(int v[], int tam, int pos)
{
    int i;
    for (i = tam - 1; i >= pos; i -= 2)
    {
        v[i] = v[i] * 2;
    }
}

// incrementa x
void funcao02(int v[], int j)
{
    v[j]++;
}

// só mostra o vetor
void funcao03(int v[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        printf("%d,", v[i]);
    }
    printf("\n");
}

int main()
{
    int i, vet[5] = {1, 2, 3, 4, 5};
    int quant = 5;
    for (i = 0; i < quant; i++)
    {
        // quando i for par
        if (i % 2 == 0)
        {
            funcao01(vet, quant, i);
        }
        else
        {
            funcao02(vet, i);
        }
        funcao03(vet, quant);
    }
}
