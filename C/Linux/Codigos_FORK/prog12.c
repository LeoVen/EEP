#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc,char *argv[]) {
	pid_t   var;
	int estado;
	system("clear");
	printf("Processo-Pai: Iniciando a execucao.\n");
	var=fork();
	if ( var == 0) {
	   printf("Processo-Filho: Iniciando a execucao.\n");
	   sleep(5);
	   printf("Processo-Filho: Encerrando a execucao.\n");
	   exit(0);
	}
	waitpid(var,estado,0);
	printf("Processo-Pai: Encerrando a execucao.\n");
	return 0;
}
