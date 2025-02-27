//Fazer uma função que, dada uma matriz Mn×n,
//determine se ela é simétrica.

#include <stdio.h>
void resultado(int linha, int coluna, int matA[linha][coluna]);
int verificador(int linha, int coluna);
void main()
{
    int teste;
    int matA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    teste = verificador(3,3);
    printf("%d ola mundo", teste);
}

int verificador(int linha, int coluna){
    int i, j, colum = 0, lina=0;
    for(i = 0; i <linha; i++){
        lina++;
    }
    for(j = 0; j < coluna; j++){
        colum++;
    }
    if(linha == coluna){
        return 1;
    }
    else{
        return 0;
    }
}



void resultado(int linha, int coluna, int matA[linha][coluna])
{
    int i, j;
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            //printf("%d", matA[i][j]);
        }
    }
}
