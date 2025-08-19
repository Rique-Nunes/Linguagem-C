//saber se os ambos os numeros possuem o mesmo numero de algarismos
//se tiverem mesma quantidade retorna 1, senão retorna 0
#include <stdio.h>

int algarismo(int n1, int n2);

void main(){
    int num1, num2;
    printf("escreva os numeros: ");
    scanf("%d", &num1);
    scanf("%d", &num2);
    printf("%d",algarismo(num1, num2)); 
}

int algarismo(int n1, int n2){
    int cont_n1 = 0, cont_n2 = 0;
    while (n1>0 || n2>0)
    {
        n1/=10;
        n2/=10;
        if (n1 != 0){
            cont_n1++;
        }
        if (n2 != 0){
            cont_n2++;
        }
    }
    if(cont_n1 == cont_n2){
        return 1;
    }else{
        return 0;
    }
    
}