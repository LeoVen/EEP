#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc,char *argv[]) {
	pid_t   var;
	system("clear");
	printf("Processo-Pai: Iniciando a execucao.\n");
	var=fork();
	if ( var == 0) {
	   printf("Processo-Filho: Iniciando a execucao.\n");
	   printf("Processo-Filho: O valor de VAR e %d.\n",var);
	   printf("Processo-Filho: O meu PID e %d.\n",getpid());
	   sleep(5);
	   printf("Processo-Filho: Encerrando a execucao.\n");
	} else {
	   printf("Processo-Pai: O valor de VAR e %d.\n",var);
	   printf("Processo-Pai: O meu PID e %d.\n", getpid());
	   sleep(10);
	   printf("Processo-Pai: Encerrando a execucao.\n");
	}
	return 0;
}
