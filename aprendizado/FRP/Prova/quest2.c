#include <stdio.h>

void questao02(int vet[], int n);
void funcao02(int vet[], int i, int f);
int funcao01(int vet[], int n, int p1, int p2);

void questao02(int vet[], int n)
{
    int i, resp, num;
    for (i = 0; i < n - 1; i++) // n = 7
    {
        resp = funcao01(vet, n, i + 1, i); // i = 0, 1, 2, 3, 4, 5
        if (resp != i)  // resp = 0
        {
            num = vet[resp];
            funcao02(vet, resp, i + 1);
            vet[i] = num;
        }
    }
}

void funcao02(int vet[], int f, int i) // i = 0 f = 5
{
    if (f >= i) //5 >= 1
    {
        vet[f] = vet[f - 1]; //vet[5] = vet[5-1]
        funcao02(vet, f - 1, i); //(vet, 4, 0) //(vet, 3, 0) //(vet, 2, 0) //(vet, 1, 0)
    }
}

int funcao01(int vet[], int n, int p1, int p2) //{2,3,5,7,8,9} p1 = 0, p2 = n
{   
    if (p1 < n)//0 < 6
    {
        if (vet[p1] < vet[p2]) //vet[0] < vet[6]
        {
            return funcao01(vet, n, p1 + 1, p1); //funcao01(vet, 6, 0+1, 0)
        }
        else
        {
            return funcao01(vet, n, p1 + 1, p2);
        }
    }
    else
    {
        return p2;
    }
}

int main()
{
    int vet[] = {9, 5, 8, 2, 10, 5, 7};
    int n = sizeof(vet) / sizeof(vet[0]);

    printf("Vetor original: ");
    for (int i = 0; i < n; i++)
        printf("%d ", vet[i]);
    printf("\n");

    questao02(vet, n);

    printf("Vetor ordenado: ");
    for (int i = 0; i < n; i++)
        printf("%d ", vet[i]);
    printf("\n");

    return 0;
}
