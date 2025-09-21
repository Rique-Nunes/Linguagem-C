#include <stdio.h>
#include "lista_duplamente.h"

/*Projeto de uma lista duplamente encadeada circular com nó cabeça classificada e sem repetição*/
// 25.2 - AV1 - Atividade 4
/*Feito por HENRIQUE DA COSTA NUNES*/

int main()
{
    Lista *minha_lista = cria_lista();
    exibe_lista(minha_lista);

    printf("\nInserindo 50, 20, 80, 40...\n");
    insere_ordenado(minha_lista, 50);
    insere_ordenado(minha_lista, 20);
    insere_ordenado(minha_lista, 80);
    insere_ordenado(minha_lista, 40);
    exibe_lista(minha_lista);

    printf("\nTentando inserir 20 novamente...\n");
    insere_ordenado(minha_lista, 20);
    exibe_lista(minha_lista);

    printf("\nRemovendo o 40...\n");
    remove_elemento(minha_lista, 40);
    exibe_lista(minha_lista);

    printf("\nRemovendo o 99 (inexistente)...\n");
    remove_elemento(minha_lista, 99);
    exibe_lista(minha_lista);

    printf("\nbuscando um elemeneto da lista: \n");
    int valor = get_lista(minha_lista, 20);
    printf("%d", valor);

    printf("\nAlterando um elemeneto da lista: \n");
    int teste = alterar_lista(minha_lista, 20, 21);
    printf("%d\n", teste);
    exibe_lista(minha_lista);

    libera_lista(minha_lista);
    printf("\nLista liberada.\n");

    return 0;
}