#include "stdio.h"
#include "stdlib.h"

void main()
{
    int n, y, count;
    printf("digite o valor maximo da conta: ");
    scanf("%d", &n);
    printf("digite o valor que quer ver os multiplos: ");
    scanf("%d", &y);
    for (int i = y; i < n; i += y)
    {
        printf("%d:%d\n", y, i);
    }
}