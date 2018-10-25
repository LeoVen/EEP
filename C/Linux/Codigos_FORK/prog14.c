#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc,char *argv[]) {
	pid_t   filho1, filho2;
	int estado, valor = 10;
	system("clear");
	printf("Processo-Pai: Iniciando a execucao.\n");
	
	filho1=fork();
	if ( filho1 == 0) {
	   printf("Processo-Filho 1: Iniciando a execucao.\n");
	   valor = valor + 5;
	   sleep(5);
	   printf("Processo-Filho 1: Encerrando a execucao.\n");
	   exit(0);
	}

	filho2=fork();
	if ( filho2 == 0) {
	   printf("Processo-Filho 2: Iniciando a execucao.\n");
	   valor = valor - 2;
	   sleep(5);
	   printf("Processo-Filho 2: Encerrando a execucao.\n");
	   exit(0);
	}

	waitpid(filho1,estado,0);
	waitpid(filho2,estado,0);

	printf("O valor de VALOR e %d.\n",valor);
	printf("Processo-Pai: Encerrando a execucao.\n");
	return 0;
}
