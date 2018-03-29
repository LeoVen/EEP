/*
	Leonardo Vencovsky
	Data: 28/02/20218
	Aula: Estrutura de Dados
	EEP
*/

#include <stdio.h>

void f (int *a);
void g (int v[]);
void p (int v[]);

int main(int argc, char const *argv[])
{
	int a = 1;
	int v[4] = {1, 2, 3, 4};

	printf("%d\n\n", a);

	f (&a);

	// Naturalmente, vetores são ponteiros
	// para sua posição inicial na memória
	g (v);

	p (v);

	printf("\n%d\n", a);

	return 0;
}

void f (int *b)
{

	// *b += 1;

	// ++ tem preferência a *
	(*b)++;

}

void g (int v[])
{
	int i;

	for (i = 0; i < 4; i++) {
		v[i]++;
	}

}

void p (int v[])
{
	int i;

	for (i = 0; i < 4; i++) {
		printf("%d\n", v[i]);
	}
}