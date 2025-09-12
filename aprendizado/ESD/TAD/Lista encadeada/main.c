#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

// É uma boa prática usar int main() e retornar 0
int main()
{
    // CORREÇÃO: 'lista' agora é do tipo ListaEncadeada*, ou seja, No**
    ListaEncadeada *lista = cria_lista_encadeada();

    // As chamadas agora passam o ponteiro No** diretamente, o que está correto
    insere_lista_encadeada_inicio(lista, 5);
    insere_lista_encadeada_inicio(lista, 10);
    insere_lista_encadeada_inicio(lista, 15);

    exibe_lista_encadeada(lista);

    // É crucial liberar a memória no final
    libera_lista_encadeada(lista);

    return 0;
}