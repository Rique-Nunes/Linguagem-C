// ponto.c

#include <stdlib.h>
#include "ponto.h" // Inclui a própria interface para garantir consistência

// A definição COMPLETA e PRIVADA da struct.
struct ponto
{
    float x;
    float y;
};

Ponto *ponto_cria(float x, float y)
{
    Ponto *p = (Ponto *)malloc(sizeof(Ponto));
    if (p != NULL)
    {
        p->x = x;
        p->y = y;
    }
    return p;
}

void ponto_libera(Ponto *p)
{
    free(p);
}

void ponto_acessa(Ponto *p, float *x_retorno, float *y_retorno)
{
    *x_retorno = p->x;
    *y_retorno = p->y;
}

void ponto_atribui(Ponto *p, float novo_x, float novo_y)
{
    p->x = novo_x;
    p->y = novo_y;
}