typedef struct circulo tCirculo;
#include "ponto.h"
/* Funções exportadas */

/* Função cria - Aloca e retorna um círculo com centro (x,y) e raio r */
tCirculo* circCria(int x,int y, float r); 

/* Função libera - Libera a memória de um círculo previamente criado */
void circ_libera(tCirculo* c);


/* Funções Set e Get - atribui/ acessa raio */
void circSetRaio(tCirculo* c, float r);
float circGetRaio(tCirculo * c); 

/* Função Area - Retorna o valor da área do círculo */
float circArea(tCirculo * c); 
/* Função Comprimento - Retorna o valor da circunferência (perímetro) */
float circComprimento(tCirculo *c);

/* Função Compara - determina pelo comprimento dos circulos */
int circCompara(tCirculo *c1, tCirculo *c2); 

/* Função getCirculo - Retorna uma string lo no formato (c:centro,r:raio)*/
char* circ_getCirculo(tCirculo* p);
/* Função exibe -Escreve na tela o círculo no formato (c:centro,r:raio)*/
void circ_exibe(tCirculo* p);

/* Função clona – cria um novo cículo igual ao recebido*/
//tCirculo* circ_clona(tCirculo* cO);
