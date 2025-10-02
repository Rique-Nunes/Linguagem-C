// Arquivo: main.c

#include <stdio.h>
#include "pilha_encadeada.h"

int main()
{
    // Cria a pilha
    tpilhaencadeada *minha_pilha = pilha_cria();
    int valor_removido;

    printf("Pilha criada. Está vazia? %s\n", pilha_vazia(minha_pilha) ? "Sim" : "Nao");

    // Empilhando elementos (Push)
    printf("\nEmpilhando 10...\n");
    pilha_push(minha_pilha, 10);
    printf("Empilhando 20...\n");
    pilha_push(minha_pilha, 20);
    printf("Empilhando 30...\n");
    pilha_push(minha_pilha, 30);

    printf("Pilha está vazia? %s\n", pilha_vazia(minha_pilha) ? "Sim" : "Nao");

    // Desempilhando elementos (Pop)
    printf("\nDesempilhando um valor...\n");
    if (pilha_pop(minha_pilha))
    {
        printf(" -> Valor removido: %d (O último que entrou)\n", valor_removido); // Deve ser 30
    }

    printf("Desempilhando outro valor...\n");
    if (pilha_pop(minha_pilha))
    {
        printf(" -> Valor removido: %d\n", valor_removido); // Deve ser 20
    }

    printf("Empilhando 99...\n");
    pilha_push(minha_pilha, 99);

    printf("Desempilhando o último valor...\n");
    if (pilha_pop(minha_pilha))
    {
        printf(" -> Valor removido: %d\n", valor_removido); // Deve ser 99
    }

    // Libera toda a memória usada pela pilha
    pilha_libera(minha_pilha);
    printf("\nMemória da pilha liberada.\n");

    return 0;
}