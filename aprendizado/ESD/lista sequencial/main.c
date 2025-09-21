#include <stdio.h>
#include "lista.h"
int main()
{
    tLista * lista;
    lista=lista_cria_vazia(5,1,1); //  classif , com repet
    //lista_inclui(lista,2);
    lista_inclui(lista,1);
    //lista_inclui(lista,2);
    lista_inclui(lista,1);
    lista_inclui(lista,5);
    lista_inclui(lista,5);
    lista_inclui(lista,5);

    
    lista_percorre(lista);
    
    
    lista_exclui(lista,1);
    
    lista_percorre(lista);
    
    return 0;
}