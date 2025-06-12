/*
	FAETERJ-RIO
	Fundamentos de Programação - Manhã
	Data: 11/06/2025
	
	Ponteiros
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//main
void main ()
{
	//declaração de variáveis
	char s[20];
	char *p;
	
	strcpy (s,"ALGORITMOS");
	
	p = s;
	
	while (*p != '\0')
	{
		printf ("%p - %c\n", p, *p);
		p++;
	}
}
