/*Implementar uma função que, dado um
número inteiro, calcule (e retorne) a soma e a
média de seus divisores.*/

#include <stdio.h>

void calculo(int *soma, float *media, int numero){
    int i,cont= 0;
    *soma =0;
    for (i = 1; i<= numero; i++){
        if (numero%i==0){
            *soma += i;
            cont ++;
        }
    }
    *media = *soma / cont;
}
void main(){
    int numero, soma;
    float media;
    printf("digite: ");
    scanf("%d", &numero);
    calculo(&soma, &media, numero); 
    
    printf("soma: %d\n",soma);
    printf("media: %.2f\n", media);
}
