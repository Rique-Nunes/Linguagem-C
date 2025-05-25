/* 
   FAETERJ-Rio
   Fundamentos de Programação - FPR - Manhã
   Professor Leonardo Vianna
   Data: 21/05/2025
   
   Arquivos
   
   Exemplo 3: lendo o conteudo de um arquivo e exibindo-o na tela
*/

//importação de bibliotecas
#include <stdio.h>

//Protótipos das funções

//main
void main ()
{
	//declaração de variáveis
	int numero;
	FILE *arq;  //passo 1: declarar uma variável FILE*, que representará o arquivo sendo manipulado
	
	//Passo 2: associar a variável FILE* a um arquivo em disco + abrir o arquivo
	arq = fopen ("numeros.txt","r");	
	
	//verificando se ocorreu erro na abertura do arquivo
	if (arq == NULL)  //ou apenas:   if (!arq)
	{
		printf ("\n\nErro na abertura do arquivo!\n");
	}
	else
	{
		while (fscanf (arq, "%d\n", &numero) != EOF)   //eof - end of file
		{
			//Passo 3: manipulação do arquivo			
			printf ("%d\n", numero);
		}
		
		//passo 4: fechar o arquivo
		fclose (arq);
	}
}

//implementação das funções

