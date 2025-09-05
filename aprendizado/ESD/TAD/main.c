// main.c

#include <stdio.h>
#include "ponto.h" // Só precisamos incluir a interface!

int main()
{
    float x_val, y_val;

    Ponto *p1 = ponto_cria(2.0, 3.0);
    Ponto *p2 = ponto_cria(5.0, 7.0);

    ponto_acessa(p1, &x_val, &y_val);
    printf("Coordenadas do ponto p1: (%.2f, %.2f)\n", x_val, y_val);

    ponto_atribui(p2, 1.0, 9.0);
    ponto_acessa(p2, &x_val, &y_val);
    printf("Novas coordenadas do ponto p2: (%.2f, %.2f)\n", x_val, y_val);

    ponto_libera(p1);
    ponto_libera(p2);

    return 0;
}