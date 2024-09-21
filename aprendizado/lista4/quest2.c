#include "stdio.h"
#include "stdlib.h"

void main()
{
    int soma = 0;
    printf("Vamos mostrar a serie de elementos: \n");
    for (int contador = 50; contador != 0; contador -= 1)
    {
        printf("%d,", 51 - contador); // 1 a 50
        printf("%d,", contador);      // 50 a 1
        soma += contador + (51 - contador);
    }
    printf("\nA soma total e %d", soma);
}
// for (int i = 1; i =<50; i++){
//      print("51 - i")
//      prinf("i")}