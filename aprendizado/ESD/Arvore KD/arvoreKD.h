
#define ARVOREKD_H

// Dimensão dos pontos
#define K 2

// Estrutura do STruch
typedef struct NoKD {
    int ponto[K];
    
    struct NoKD *esq;
    
    struct NoKD *dir;
} NoKD;

// Cabeçalho das funções da KD
NoKD* inserirKD(NoKD *raiz, int ponto[], int profundidade);
NoKD* buscarKD(NoKD *raiz, int ponto[], int profundidade);
NoKD* removerKD(NoKD *raiz, int ponto[], int profundidade);

//para a remoção tem essas auxiliares aqui:
NoKD* encontrarMinNo(NoKD *raiz, int d, int profundidade);
void copiarPonto(int dest[], int src[]);

void imprimirKD(NoKD *raiz);
void liberarKD(NoKD *raiz);

// Construção balanceada
NoKD* construirBalanceada(int pontos[][K], int inicio, int fim, int profundidade);

// Vizinho mais próximo
NoKD* vizinhoMaisProximo(NoKD *raiz, int alvo[], int profundidade,
                         NoKD *melhor, double *melhorDist);


// Distância entre pontos
double distancia(int a[], int b[]);
// Função auxiliar
int iguais(int a[], int b[]);
int encontrarMin(NoKD *raiz, int d, int profundidade);
NoKD* removerNo(NoKD *raiz, int ponto[], int profundidade);

