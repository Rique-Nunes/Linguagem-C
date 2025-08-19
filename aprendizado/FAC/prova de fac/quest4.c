// a posicao do vetor do menor numero, dado a partir de uma posicao inicial dada pelo usuario
// vet_a[7] = {8,6,3,7,1,9,4}
//             0 1 2 3 4 5 6
// o menor numero a partir da posicao 3 do vetor é a posicao 4 que tem valor 1.
#include <stdio.h>

int indice(int vet[], int tamanho, int numero, int *indice_menor);

void main(){
    int vet_a[7] = {8,6,3,7,1,9,4}, tamanho_vetor = 7, p, retorno;
    int posicao_menor;

    printf("digite a posicao inicial: ");
    scanf("%d", &p);

    retorno = indice(vet_a, tamanho_vetor, p, &posicao_menor);
    if(retorno == 1){
        printf("a posicao do menor numero e: %d", posicao_menor);
    }else{
        printf("posicao invalida");
    }
}

int indice(int vet[], int tamanho, int numero, int *indice_menor){
    int menor = 9999, posicao;
    if(numero >= tamanho){
        return 0;
    }
    
    for(int i = numero; i < tamanho; i++){
    if (vet[i] < menor){
        menor = vet[i];
        posicao = i;
    }
    }

    *indice_menor = posicao;

    return 1;
}