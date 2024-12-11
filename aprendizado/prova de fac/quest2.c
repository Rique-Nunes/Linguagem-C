//exibir a lista em pares de conjuntos
//vet[5] = {2,9,4,3,5};
//exibir: 2,9 2,4 2,3 2,5 9,4 9,3 9,5 4,3 4,5 3,5
#include <stdio.h>

int exibir_pares(int vet[], int tamanho);

void main(){
    int vet[5] = {2,9,4,3,5};

    exibir_pares(vet, 5);
}

int exibir_pares(int vet[], int tamanho){
    
    for(int i= 0; i< tamanho; i++){
        for(int j = i+1; j < tamanho; j++){
            printf("%d: %d\n", vet[i], vet[j]);
        }
    }
}
