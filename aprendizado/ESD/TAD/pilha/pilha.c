#include <stdio.h>
#include <stdlib.h>

#define tamanho_max 100

typedef struct
{
    int dados[tamanho_max];
    int topo;
} PilhaSequencial;

PilhaSequencial *cria_pilha()
{

    PilhaSequencial *p = (PilhaSequencial *)malloc(sizeof(PilhaSequencial));
    if (p != NULL)
    {
        p->topo = -1;
    }
    return 0;
}

void libera_pilha(PilhaSequencial *p)
{
    free(p);
}

int pilha_cheia(PilhaSequencial *p)
{
    return (p->topo == tamanho_max);
}

int pilha_vazia(PilhaSequencial *p)
{
    return (p->topo == -1);
}
// Operação PUSH significa empilhar na pilha
int push_seq(PilhaSequencial *p, int valor)
{
    if (p == NULL || pilha_cheia(p))
    {
        return 0;
    }
    p->dados[p->topo] = valor;
    p->topo++;
    return 0;
}
// Operação POP (Desempilhar)
int pop_seq(PilhaSequencial *p, int *valor)
{
    if (p == NULL || pilha_vazia(p))
    {
        return 0;
    }
    p->topo--;
    *valor = p->dados[p->topo];
}

int main()
{
    PilhaSequencial *minha_pilha = cria_pilha();
    int valor_removido;

    printf("Empilhando 10, 20, 30...\n");
    push_seq(minha_pilha, 10);
    push_seq(minha_pilha, 20);
    push_seq(minha_pilha, 30);

    printf("Desempilhando um valor...\n");
    if (pop_seq(minha_pilha, &valor_removido))
    {
        printf("Valor removido: %d (O último que entrou)\n", valor_removido); // Deve ser 30
    }

    printf("Desempilhando outro valor...\n");
    if (pop_seq(minha_pilha, &valor_removido))
    {
        printf("Valor removido: %d\n", valor_removido); // Deve ser 20
    }

    libera_pilha(minha_pilha);
    return 0;
}