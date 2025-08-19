// criar um vetor que contenha entre os primeiros elementos os multiplos de um numero N
// e os ultimos os não multiplos
// 8,6,3,7,1,9,4
// 6,3,9, 8,7,1,4
// os tres primeiros são multiplos de 3 e o resto não são.
#include <stdio.h>

void ordem (int vetA[],int vetB[], int tamanho, int numero );

void main(){
int vet_a[7] = {8,6,3,7,1,9,4};
int vet_b[7], num;

printf("digite o numero: ");
scanf("%d", &num);

ordem(vet_a, vet_b, 7, num);

for(int i= 0; i< 7; i++){
    printf("%d\n", vet_b[i]);
    }
}

void ordem (int vetA[],int vetB[], int tamanho, int numero ){
    int cont = 0;
    for(int i= 0; i< tamanho; i++){
        if((vetA[i] % numero) == 0){
            vetB[cont] = vetA[i];
            cont++;
        }
    }
    for(int i= 0; i< tamanho; i++){
        if((vetA[i] % numero) != 0){
            vetB[cont] = vetA[i];
            cont++;
        }
    }
}