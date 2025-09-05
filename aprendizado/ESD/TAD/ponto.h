// ponto.h

// Esconde os detalhes da struct. Quem incluir este arquivo só saberá que "Ponto" existe.
typedef struct ponto Ponto;

// --- Protótipos das Funções Públicas ---

// Cria um novo ponto com as coordenadas (x, y)
Ponto* ponto_cria(float x, float y);

// Libera a memória alocada para um ponto
void ponto_libera(Ponto* p);

// Acessa as coordenadas de um ponto e as armazena em variáveis fornecidas
void ponto_acessa(Ponto* p, float* x_retorno, float* y_retorno);

// Atribui novas coordenadas a um ponto existente
void ponto_atribui(Ponto* p, float novo_x, float novo_y);