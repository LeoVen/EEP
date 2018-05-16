#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
	pid_t var;
	system("clear");

	printf("Processo-Pai: Iniciando a execucao.\n");

	// Var recebe o PID do processo filho
	// É retornado 0 (para o processo pai) quando o fork() retorna
	var = fork();

	if (var == 0) {
		printf("Processo-Filho: Iniciando a execucao.\n");
		printf("Processo-Filho: O valor de VAR e %d.\n", var);
		printf("Processo-Filho: O meu PID e %d.\n", getpid());
		printf("Processo-Filho: O PID do meu pai e %d.\n", getppid());
		sleep(5);
		printf("Processo-Filho: Encerrando a execucao.\n");
	}
	else {
		printf("Processo-Pai: O valor de VAR e %d.\n", var);
		printf("Processo-Pai: O meu PID e %d.\n", getpid());
		printf("Processo-Pai: O PID do meu pai e %d.\n", getppid());
		sleep(10);
		printf("Processo-Pai: Encerrando a execucao.\n");
	}

	// Note nos sleep() : processos filhos podem continuar existindo sem o pai

	return 0;
}
