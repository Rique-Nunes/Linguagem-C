/*
	FAETERJ-RIO
	Fundamentos de Programação - Manhã
	Data: 11/06/2025
	
	Ponteiros
*/

//importação de bibliotecas
#include <stdio.h>

//main
void main ()
{
	//declaração de variáveis
	int *p;
	int v[5] = {1,2,3,4,5};
	int i;
	
	p = v;
	
	for (i=0;i<5;i++)
	{
		printf ("%d ", *(p+i));
	}
}
