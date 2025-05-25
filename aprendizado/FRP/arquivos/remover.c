/* 
   FAETERJ-Rio
   Fundamentos de Programação - FPR - Manhã
   Professor Leonardo Vianna
   Data: 22/05/2025
   
   Arquivos
   
   Dado um arquivo texto contendo números inteiros, um por linha,
   desenvolver uma função que remova todas as ocorrências de um 
   valor.
*/

//importação de bibliotecas
#include <stdio.h>

//Protótipos das funções
int removerValores (char nomeArq[], int valor);

//main
void main ()
{	
	switch (removerValores ("novo.txt", 20))
	{
		case -1: printf ("Erro na abertura do arquivo!\n");
		         break;
			
		case 0:  printf ("Valor nao encontrado no arquivo!\n");
		         break;
			
		default: printf ("Remocoes realizadas com sucesso!\n");
	}
}

//implementação das funções
int removerValores (char nomeArq[], int valor)
{
	//declaração de variáveis
	int numero, cont = 0;
	FILE *arq, *temp;  
	
	//abrindo os arquivos
	arq = fopen (nomeArq, "r");	
	temp = fopen ("temp.txt", "w");
	
	//verificando se ocorreu erro na abertura dos arquivos
	if (!arq || !temp)  //ou if ((arq == NULL) || (temp == NULL))
	{
		fclose (arq);
		fclose (temp);
		
		return -1;
	}
	else
	{
		//lendo os dados do arquivo e promovendo as alterações
		while (fscanf (arq, "%d", &numero) != EOF)   //eof - end of file
		{
			if (numero != valor)
			{
				fprintf (temp, "%d\n", numero);
			}
			else
			{
				//atualizando o número de alterações realizadas
				cont++;
			}
		}

		//fechando os arquivos
		fclose (arq);
		fclose (temp);
		
		//apagando o arquivo original
		remove (nomeArq);
		
		//renomeando o temporário para o nome do arquivo original
		rename ("temp.txt", nomeArq);
		
		return cont;
	}
}
