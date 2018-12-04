#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <stdbool.h>
#include <sys/sysinfo.h>
#include <sys/utsname.h>
#include <time.h>
#include <sys/types.h>
#include <sys/ipc.h>

void copyright()
{
	printf("╔══════════════════════════════════════════════════════════╗\n");
	printf("║ Copyright                                                ║\n");
	printf("║                                                          ║\n");
	printf("║     Leonardo Vencovsky   (https://github.com/LeoVen)     ║\n");
	printf("║                                                          ║\n");
	printf("╚══════════════════════════════════════════════════════════╝\n");
}

void help()
{
	printf("╔══════════════════════════════════════════════════════════╗\n");
	printf("║ Available Commands                                       ║\n");
	printf("║                                                          ║\n");
	printf("║ # Server                                                 ║\n");
	printf("║                                                          ║\n");
	printf("║     Command Name    Description                          ║\n");
	printf("║     ------------    -----------                          ║\n");
	printf("║     - date          Returns current date (dd/mm/yy)      ║\n");
	printf("║     - time          Returns current time (hh/mm/ss)      ║\n");
	printf("║     - nodename      Returns the node name                ║\n");
	printf("║     - sysname       Operating system name                ║\n");
	printf("║     - release       Operating system release version     ║\n");
	printf("║     - version       The operating system version         ║\n");
	printf("║     - machine       Hardware identifier                  ║\n");
	printf("║     - process       How many processes are running       ║\n");
	printf("║     - freeram       Total free ram in kilobytes          ║\n");
	printf("║     - totalram      Total RAM in kilobytes               ║\n");
	printf("║     - uptime        How long the machine is running      ║\n");
	printf("║     - processors    Amount of physical cores             ║\n");
	printf("║                                                          ║\n");
	printf("║ # Client                                                 ║\n");
	printf("║                                                          ║\n");
	printf("║     Command Name    Description                          ║\n");
	printf("║     ------------    -----------                          ║\n");
	printf("║     - copyright     Shows copyright                      ║\n");
	printf("║     - help          Shows this help menu                 ║\n");
	printf("║     - exit          Closes client program                ║\n");
	printf("║                                                          ║\n");
	printf("║ # ServerClient                                           ║\n");
	printf("║                                                          ║\n");
	printf("║     Command Name    Description                          ║\n");
	printf("║     ------------    -----------                          ║\n");
	printf("║     - shutdown      Closes both this client and server   ║\n");
	printf("║                                                          ║\n");
	printf("╚══════════════════════════════════════════════════════════╝\n");
}

#define TAMANHO 512

int main(int argc, char const *argv[])
{
	// Usado como resultado das funcoes para detectar erros
	int resultado;

	char entrada[TAMANHO];

	// Localizano a fila de mensagens
	key_t chave_fila = ftok("/home", 'a');
	
	int id_fila = msgget(chave_fila, 0);

	if (id_fila == -1)
		printf("Erro ao localizar a fila de mensagens\n");

	// PID do cliente
	pid_t client_pid = getpid();

	// Localizando segmentos de memoria
	key_t chave_resultado   = ftok("/home", 'b');
	key_t chave_destino = ftok("/home", 'd');

	int id_resultado = shmget(chave_resultado, 0, 0);
	int id_destino = shmget(chave_destino, 0, 0);

	if (id_resultado == -1 || id_destino == -1)
	{
		printf("Erro de segmento de memoria\n");

		return -1;
	}

	// Atribuindo ponteiros para os segmentos de memoria
	char *mem_conteudo = shmat(id_resultado, 0, 0);
	pid_t *mem_pid = shmat(id_destino, 0, 0);

	if (mem_conteudo == (char*)-1 || mem_pid == (pid_t*)-1)
	{
		printf("Nao foi possivel associar os ponteiros\n");

		return -1;
	}

	char c = ' ';
	int total;

	printf("Escreva help para obter uma lista de comandos\n");

	while (1)
	{
		total = 0;

		printf("> ");

		while (c != '\n')
		{
			c = getchar();

			if (total < TAMANHO - 1 && c != '\n')
				entrada[total++] = c;
		}

		c = ' ';

		entrada[total] = '\0';

		if (strcmp(entrada, "copyright") == 0)
		{
			copyright();
		}
		else if (strcmp(entrada, "help") == 0)
		{
			help();
		}
		else if (strcmp(entrada, "exit") == 0)
		{
			break;
		}
		// Enviando para o servidor
		else
		{
			// Enviando mensagem para a fila
			resultado = msgsnd(id_fila, entrada, sizeof(char) * TAMANHO, 0);

			if (resultado == -1)
			{
				printf("Erro ao enviar a mensagem para a fila de id %d\n", id_fila);

				continue;
			}

			// Isso irá parar tanto o cliente quanto o servidor
			if (strcmp(entrada, "shutdown") == 0)
				break;

			clock_t begin = clock();
			clock_t end;

			*mem_pid = 0;

			// Esperado resposta
			while (1)
			{
				if (*mem_pid == client_pid)
				{
					printf("%s\n", mem_conteudo);

					break;
				}

				if (*mem_pid == -1)
				{
					printf("Comando invalido\n");

					break;
				}

				end = clock();

				// Maximo de espera de 5 segundos
				if ((double)(end - begin)/CLOCKS_PER_SEC > 5.0)
				{
					printf("Timeout\n");

					break;
				}
			}
		}
	}

	shmdt(mem_pid);
	shmdt(mem_conteudo);

	return 0;
}