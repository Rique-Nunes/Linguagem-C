typedef struct pilha tpilhaencadeada;
typedef struct no No;


//Criação da pilha
tpilhaencadeada* pilha_cria();

//Liberação da pilha
void pilha_libera(tpilhaencadeada *p);

//adiciona um valor a pilha
void pilha_push(tpilhaencadeada *p, int valor);

//Retira o valor do topo da pilha, retorna 1 se sucesso ou 0 para falha
int pilha_pop(tpilhaencadeada *p);

//Verifica e a pilha está vazia
int pilha_vazia(tpilhaencadeada *p);