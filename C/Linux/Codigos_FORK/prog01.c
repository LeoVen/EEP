#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc,char *argv[]) {
	system("clear");
	printf("Processo-Pai: Iniciando a execucao.\n");
	fork();
	printf("Processo-Filho: Iniciando a execucao\n");
	sleep(10);
	printf("Processo-Filho: Encerrando a execucao\n");
	printf("Processo-Pai: Encerrando a execucao\n");
	return 0;
}
