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

#define TAMANHO 512

int main(int argc, char *argv[])
{
	// Estrutura usada para obter informacoes da fila de mensagens e obter
	// o PID do processo
	struct msqid_ds fila_info;

	// Obter informacoes do sistema
	struct sysinfo info;

	// Obter informacoes do SO
	struct utsname uts;

	// Usado como resultado das funcoes para detectar erros
	int resultado;

	// Comando lido da fila de mensagens
	char comando_lido[TAMANHO];

	// Resultado do servidor a ser escrito no segmento de memoria
	char resultado_servidor[TAMANHO];

	// PID tirado da fila de mensagens (PID destino)
	pid_t dest_pid = 0;

	// Se foi um comando valido
	bool cvalido = false;

	// Pegar data e tempo atual
	time_t now;
	struct tm *ct;

	// Criando fila de mensagem
	key_t chave_fila = ftok("/home", 'a');

	int id_fila = msgget(chave_fila, 0600 | IPC_CREAT);

	if (id_fila == -1)
		printf("Erro ao criar a fila de mensagens\n");

	// Criando segmentos de memoria
	key_t chave_resultado   = ftok("/home", 'b');
	key_t chave_destino = ftok("/home", 'd');

	int id_resultado   = shmget(chave_resultado, TAMANHO, 0600 | IPC_CREAT);
	int id_destino = shmget(chave_destino, sizeof(key_t), 0600 | IPC_CREAT);

	if (id_destino == -1 || id_destino == -1)
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

	while (1)
	{
		resultado = msgrcv(id_fila, comando_lido, sizeof(char) * TAMANHO, 0, 0);

		if (resultado == -1)
		{
			printf("Nao foi possivel recuperar a mensagem da fila\n");

			continue;
		}

		// Recuperando o PID do processo que enviou a mensagem
		resultado = msgctl(id_fila, IPC_STAT, &fila_info);

		if (resultado == 0)
			printf("Li mensagem do PID %d\n", fila_info.msg_lspid);
		else
		{
			printf("Nao pude recuperar informacoes da fila\n");

			continue;
		}

		dest_pid = fila_info.msg_lspid;

		cvalido = true;

		// Lista de comandos
		if (strcmp(comando_lido, "date") == 0)
		{
			time(&now);

			ct = localtime(&now);

			strftime(resultado_servidor, TAMANHO, "%d/%m/%Y", ct);
		}
		else if (strcmp(comando_lido, "time") == 0)
		{
			time(&now);

			ct = localtime(&now);

			strftime(resultado_servidor, TAMANHO, "%X", ct);
		}
		else if (strcmp(comando_lido, "nodename") == 0)
		{
			uname(&uts);

			sprintf(resultado_servidor, "%s", uts.nodename);
		}
		else if (strcmp(comando_lido, "sysname") == 0)
		{
			uname(&uts);

			sprintf(resultado_servidor, "%s", uts.sysname);
		}
		else if (strcmp(comando_lido, "release") == 0)
		{
			uname(&uts);

			sprintf(resultado_servidor, "%s", uts.release);
		}
		else if (strcmp(comando_lido, "version") == 0)
		{
			uname(&uts);

			sprintf(resultado_servidor, "%s", uts.version);
		}
		else if (strcmp(comando_lido, "machine") == 0)
		{
			uname(&uts);

			sprintf(resultado_servidor, "%s", uts.machine);
		}
		else if (strcmp(comando_lido, "process") == 0)
		{
			sysinfo(&info);

			sprintf(resultado_servidor, "%d", info.procs);
		}
		else if (strcmp(comando_lido, "freeram") == 0)
		{
			sysinfo(&info);

			sprintf(resultado_servidor, "%ld Kb", info.freeram * info.mem_unit / 1024);
		}
		else if (strcmp(comando_lido, "totalram") == 0)
		{
			sysinfo(&info);

			sprintf(resultado_servidor, "%ld Kb", info.totalram * info.mem_unit / 1024);
		}
		else if (strcmp(comando_lido, "uptime") == 0)
		{
			sysinfo(&info);

			int days, hours, mins;
			long int  seconds = info.uptime % 60;

			days = info.uptime / 86400;
		    hours = (info.uptime / 3600) - (days * 24);
			mins = (info.uptime / 60) - (days * 1440) - (hours * 60);

			char *h = (hours < 10) ? "0" : "";
			char *m = (mins < 10) ? "0" : "";
			char *s = (seconds < 10) ? "0" : "";

			sprintf(resultado_servidor, "%d - %s%d:%s%d:%s%ld", days, h, hours, m, mins, s, seconds);
		}
		else if (strcmp(comando_lido, "processors") == 0)
		{
			sprintf(resultado_servidor, "%d", get_nprocs());
		}
		else if (strcmp(comando_lido, "shutdown") == 0)
		{
			printf("Shutdown\n");

			cvalido = false;

			break;
		}
		else 
		{
			printf("Comando invalido do PID %d\n", dest_pid);

			*mem_pid = -1; // Comando invalido

			cvalido = false;
		}

		if (cvalido)
		{
			// Copiar para o segmento
			strcpy(mem_conteudo, resultado_servidor);

			// Colocar o pid do destino no segmento
			*mem_pid = dest_pid;
		}
	}

	// Desassociando ponteiros
	shmdt(mem_pid);
	shmdt(mem_conteudo);

	// Removendo a fila
	resultado = msgctl(id_fila, IPC_RMID, 0);

	if (resultado != 0)
		printf("Erro ao remover a fila de id %d\n", id_fila);

	// Removendo segmentos de memoria
	resultado = shmctl(id_resultado, IPC_RMID, 0);

    if (resultado != 0)
        printf("Nao foi possivel remover o segmento de memoria de id %d.\n", id_resultado);

    resultado = shmctl(id_destino, IPC_RMID, 0);

    if (resultado != 0)
        printf("Nao foi possivel remover o segmento de memoria de id %d.\n", id_destino);

	return 0;
}
