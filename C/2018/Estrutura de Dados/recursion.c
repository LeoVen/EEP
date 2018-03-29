/*
	Leonardo Vencovsky
	Data: 28/02/20218
	Aula: Estrutura de Dados
	EEP
*/

#include <stdio.h>
#include <stdlib.h>

int a = 1;
int b = 1;

void function_a ();
void function_b ();

void function_a ()
{
	// int c = 1;
	a++;
	printf("a = %d\n", a);
	function_b ();
}

void function_b ()
{
	b++;
	printf("b = %d\n", b);
	function_a ();
}

int main(int argc, char const *argv[])
{
	function_a ();
	return 0;
}