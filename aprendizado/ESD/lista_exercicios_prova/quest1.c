/*Qual o valor de y no final do programa abaixo?  (fonte Marcia Marra)
Escreva um comentário em cada comando de atribuição explicando o que ele faz
e o valor da variável à esquerda do '=' após sua execução.
*/
#include <stdio.h>
int main()
{
    int y, *p, x;          // inicializando as variavies inteiras y, x e o ponteiro para um inteiro p
    y = 0;                 // y tem valor 0
    p = &y;                // p tem o endereço de inteiro do y
    x = *p;                // x recebe o valor do endereço armazando no p, ou seja y, x vale 0
    x = 4;                 // x vale 4
    (*p)++;                // p tem o endereço de y, logo está somando y+1, y vale 1 agora
    x--;                   // x vale 3
    (*p) += x;             // p com o endereço de y recebe x, então y=1 recebe + 3, y = 4
    printf("y = %i\n", y); // y = 4
    return (0);
}
