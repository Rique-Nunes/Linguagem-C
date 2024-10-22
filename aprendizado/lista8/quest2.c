/*Implementar uma função que converta
determinada temperatura em graus Celsius
para graus Fahrenheit.*/

#include <stdio.h>

float converter(int celsus)
{
    int fahrenheit;

    fahrenheit = ((celsus * 9) / 5) + 32;
    return fahrenheit;
}
void main()
{
    float celusus;
    printf("digite a temp");
    scanf("%f", &celusus);
    printf("logo %.2f é %.2f", celusus, converter(celusus));
}