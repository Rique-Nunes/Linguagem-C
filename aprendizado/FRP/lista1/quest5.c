//Implementar uma função que, dada uma matriz
//Mm×n, gere um vetor V de tamanho n, onde
//cada elemento do vetor consiste na soma dos
//elementos de uma coluna de M. Ou seja, o
//elemento V[0] consiste na soma dos elementos
//da primeira coluna de M, o elemento V[1]
//consiste na soma dos elementos da segunda
//coluna de M, e assim por diante.


#include <stdio.h>
void somador(int linha, int coluna, int matA[linha][coluna], int vetB[coluna]);
void main()
{
    int vetB[3] = {0};
    int matA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    somador(3,3, matA, vetB);
    for (int j = 0; j < 3; j++)
        {
            printf("%d",vetB[j]);
        }
}

void somador(int linha, int coluna, int matA[linha][coluna], int vetB[coluna]){
    int i, j, somar = 0;

    for (i = 0; i < coluna; i++)
    {
        somar = 0; //esqueci de resetar a variavel para ser usada por outra coluna 
        for(j = 0; j < linha; j++){
            somar += matA[j][i]; //errei em colocar linha e coluna nos paremtros em vez de i e j 
        }
        vetB[i] = somar; //esqueci de usar i como paramentro
    }
}


