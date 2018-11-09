#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int	fd[2];
	char	msg_rcv[BUFSIZ], msg_svc[BUFSIZ]="OK", mensagem_enviada[BUFSIZ], mensagem_recebida[BUFSIZ];

	pipe(fd);

	system("clear");

	if (fork() == 0) {
		read(fd[0],mensagem_recebida,BUFSIZ);
		printf("PROCESSO-FILHO: Recebi a mensagem \"%s\" pelo pipe.\n",mensagem_recebida);
        printf("PROCESSO-FILHO: Entre sua mensagem a ser enviada para o processo-pai: ");
        scanf("%[^\n]", msg_svc);
        write(fd[1],msg_svc,strlen(msg_svc));
		exit(1);
	}

    printf("PROCESSO-PAI: Entre sua mensagem a ser enviada para o processo-filho: ");
    scanf("%[^\n]", mensagem_enviada);
	write(fd[1],mensagem_enviada,strlen(mensagem_enviada));
	sleep(15);
	read(fd[0],msg_rcv,BUFSIZ);
    printf("PROCESSO-PAI: Recebi a mensagem \"%s\" pelo pipe.\n",msg_rcv);
	return 0;
}
