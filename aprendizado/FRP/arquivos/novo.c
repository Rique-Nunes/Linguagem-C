/* 
   FAETERJ-Rio
   Fundamentos de Programação - FPR - Manhã
   Professor Leonardo Vianna
   Data: 22/05/2025
   
   Arquivos
   
   Desenvolver uma função que, dado um arquivo texto, copie o seu 
   conteúdo para outro.
*/

//importação de bibliotecas
#include <stdio.h>

//Protótipos das funções
int copiarArquivo (char nomeArqDestino[], char nomeArqOrigem[]);

//main
void main ()
{
	if (copiarArquivo ("novo.c", "copiarArquivo.c"))
	{
		printf ("Arquivo copiado com sucesso!\n");
	}
	else
	{
		printf ("Erro na abertura dos arquivos!\n");
	}	
}

//implementação das funções
int copiarArquivo (char nomeArqDestino[], char nomeArqOrigem[])
{
	//declaração de variáveis
	char caracter;
	FILE *arqO, *arqD;  
	
	//abrindo os arquivos
	arqO = fopen (nomeArqOrigem, "r");	
	arqD = fopen (nomeArqDestino, "w");
	
	//verificando se ocorreu erro na abertura dos arquivos
	if (!arqO || !arqD)  //ou if ((arqO == NULL) || (arqD == NULL))
	{
		fclose (arqO);
		fclose (arqD);
		
		return 0;
	}
	else
	{
		//copiando o conteúdo do arquivo origem para o destino
		while (fscanf (arqO, "%c", &caracter) != EOF)   //eof - end of file
		{
			fprintf (arqD, "%c", caracter);
		}
		
		//fechando os arquivos
		fclose (arqO);
		fclose (arqD);
		
		return 1;
	}
}
