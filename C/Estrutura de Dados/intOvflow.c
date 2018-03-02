/*
	Leonardo Vencovsky
	Data: 28/02/20218
	Aula: Estrutura de Dados
	EEP
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
	long i;
	int sum = 0;

	for (i = 1 ; ; i++) {
		sum += i;
		printf("%d\n", sum);
	}

	return 0;
}