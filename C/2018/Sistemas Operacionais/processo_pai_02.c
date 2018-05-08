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
		printf("Processo-Filho: Iniciando a execucao\n");
		sleep(10);
		printf("Processo-Filho: Encerrando a execucao\n");
	}
	else {
		sleep(5);
		printf("Processo-Pai rodou Processo-Filho: %d\n", var);
		printf("Processo-Pai: Encerrando a execucao\n");
	}

	// Note nos sleep() : processos filhos podem continuar existindo sem o pai

	return 0;
}
