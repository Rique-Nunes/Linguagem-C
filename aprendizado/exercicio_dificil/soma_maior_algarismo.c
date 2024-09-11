#include "stdio.h"
#include "stdlib.h"

void main()
{
    int num1, num2, maiornum1 = 0, maiornum2 = 0;
    printf("Ola digite o primeiro numero: ");
    scanf("%d", &num1);
    printf("\nDigite o segundo numero: ");
    scanf("%d", &num2);
    if ((num1 >= 1 && num1 <= 999) && (num2 >= 1 && num2 <= 999))
    {
        /*maior algarismo 1*/
        while (num1 > 0)
        { 
            if (num1 % 10 > maiornum1)
            {
                maiornum1 = num1 % 10;
            }
            num1 = num1 / 10;
        }
        /*maior algarismo 2*/
        while (num2 > 0)
        {
            if (num2 % 10 > maiornum2)
            {
                maiornum2 = num2 % 10;
            }
            num2 = num2 / 10;   
        }
        if (maiornum1 > maiornum2)
        {
            printf("Ou seja %d - %d = %d", maiornum1, maiornum2, maiornum1 - maiornum2);
        }
        else
        {
            printf("Ou seja %d - %d = %d", maiornum2, maiornum1, maiornum2 - maiornum1);
        }
    }
    else
    {
        printf("O valor que voce digitou ou e maior que 999 ou menor que 1");
    }
    system("pause"); //uso isso pois as vezes preciso ver a saída pelo executável 
}
/* Nesta versão voce consegue pegar e usar os 3 algarismos na ordem que quiser
PEGANDO AS UNIDADES DO NUMERO 1
for (int num1; num1 >= 100;)
{
    num1 = num1 - 100;
    num1comeco = +1;
}
for (int num1; num1 >= 10;)
{
    num1 = num1 - 10;
    num1meio = +1;
}
for (int num1; num1 > 1;)
{
    num1 = num1 - 1;
    num1final = +1;
}
 PEGANDO AS UNIDADES DO NUMERO 2
for (int num2; num2 >= 100;)
{
    num2 = num2 - 100;
    num2comeco = +1;
}
for (int num2; num2 >= 10;)
{
    num2 = num2 - 10;
    num2meio = +1;
}
for (int num2; num2 > 1;)
{
    num2 = num2 - 1;
    num2final = +1;
}
*/