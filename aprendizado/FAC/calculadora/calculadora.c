#include <stdio.h>
#include <stdlib.h>
#include "aritmetica.h"


int main(){
    int x, y, z;
    char ch;
    printf("digite uma operacao matematica (+,-,*,/): ");
    ch = getchar();
    printf("primeiro numero \n");
    scanf("%d", &x);
    printf("segundo numero \n");
    scanf("%d", &y);
    switch (ch) {
    
    case '+': z = soma(x, y); break;
    case '-': z = subtracao(x,y); break;
    case '*': z = produto(x,y); break;
    case '/': if (x == 0 || y == 0){
        z = 0; break;
    }else{
    z = divisao(x,y); break;
    }
    default: printf("nada \n");
    }

printf("resultado = %d\n", z);

system("pause");
return 0;
}