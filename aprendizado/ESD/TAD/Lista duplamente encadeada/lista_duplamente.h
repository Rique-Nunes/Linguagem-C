typedef struct lista Lista;
typedef struct no No;

// Criação da lista
Lista *cria_lista();
// Liberação da lista
void libera_lista(Lista *li);
// Inserir na lista ordenadamente
int insere_ordenado(Lista *li, int valor);
// Remover um elemento
int remove_elemento(Lista *li, int valor);
// Exibir a Lista
void exibe_lista(Lista *li);
// GET de um elemento
int get_lista(Lista *li, int valor);
// get tamanho da lista
int get_tamanho(Lista *li);
// alteração de um elemento da lista
int alterar_lista(Lista *li, int valor_antigo, int valor_novo);