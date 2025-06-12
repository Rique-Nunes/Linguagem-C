/*
	FAETERJ-RIO
	Fundamentos de Programa��o - Manh�
	Data: 11/06/2025
	
	Ponteiros
*/

//importa��o de bibliotecas
#include <stdio.h>

//main
void main ()
{
	//declara��o de vari�veis
	int *p;
	int v[5] = {1,2,3,4,5}; //
	int i;
	
	p = v;
	
	for (i=0;i<5;i++)
	{
		printf ("%p - %d\n", p, *p);
		p++;
	}
}
