#include "stdio.h"
#include "stdlib.h"

void main()
{
    int n, y, count;
    printf("digite o valor maximo da conta: ");
    scanf("%d", &n);
    printf("digite o valor que quer ver os multiplos: ");
    scanf("%d", &y);
    for (int i = 1; i < n; i++)
    {
        printf("%d:%d\n", y, y * i);
    }
}