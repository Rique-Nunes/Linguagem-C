/* 
   FAETERJ-Rio
   Fundamentos de Programação - FPR - Manhã
   Professor Leonardo Vianna
   Data: 21/05/2025
   
   Arquivos
   
   Exemplo 2: adicionando números ao final de um arquivo existente
   (append)
*/

//importação de bibliotecas
#include <stdio.h>

//Protótipos das funções

//main
void main ()
{
	//declaração de variáveis
	int i;
	FILE *arq;  //passo 1: declarar uma variável FILE*, que representará o arquivo sendo manipulado
	
	//Passo 2: associar a variável FILE* a um arquivo em disco + abrir o arquivo
	arq = fopen ("numeros.txt","a");	
	
	//verificando se ocorreu erro na abertura do arquivo
	if (arq == NULL)  //ou apenas:   if (!arq)
	{
		printf ("\n\nErro na abertura do arquivo!\n");
	}
	else
	{
		for (i=1;i<=1000;i++)
		{
			//Passo 3: manipulação do arquivo
			fprintf (arq, "%d\n", i);
		}
		
		//passo 4: fechar o arquivo
		fclose (arq);
	}
}

//implementação das funções

