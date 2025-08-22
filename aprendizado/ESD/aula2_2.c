#include <string.h>
#include <stdio.h>
struct al{
  int matr;
  char *nome;
};
typedef struct al tAl;


int main() {
  int x,y;
  tAl al1;
  
  tAl vAlE[3]; // est´ático
  tAl * vAlD;  // vetor de struct  diânamicamente alocado
  // vetor est´ático de ponteiros para struct 
  tAl* vetor[3];
  for(int i=0; < 3; i++){
    
  }
  
  // vetor din^âmico de ponteiros para struct
  
  
  al1.matr=1010;
  al1.nome=(char*) malloc(5 * sizeof(char));
  strcpy(al1.nome,"Lili");
  
  
  vAlD = (tAl*)malloc(3* sizeof(tAl));
 
  vAlD[0] = al1;
  vAlD[0].nome=(char*) malloc((strlen(al1.nome) + 1) * sizeof(char));
  strcpy(vAlD[0].nome,al1.nome);
  
  printf("\n Vetor dinâmico de structs");
  printf("\n Nome: %s ", vAlD[0].nome);
  printf("\n Matr: %d ", vAlD[0].matr);

  return 0;
}