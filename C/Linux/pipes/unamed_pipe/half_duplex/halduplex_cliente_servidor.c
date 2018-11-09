#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

main()
{
    int fd[2];
    char msg_recebida[80],msg_enviada[80];

    system("clear");

    /* Criando o named pipe */
    pipe(fd);

    if (fork() == 0) {
       /* Lendo de um pipe */
       close(fd[1]);	
       read(fd[0], msg_recebida, 80);
       printf("Servidor Half Duplex : Mensagem recuperada do pipe : %s\n", msg_recebida);
       exit(1);
    } else {
      /* Escrevendo em um pipe */
      printf("Digite a mensagem: ");
      gets(msg_enviada);
      close(fd[0]);
      printf("Cliente Half Duplex : Mensagem enviada ao pipe : %s\n", msg_enviada);
      write(fd[1],msg_enviada,sizeof(msg_enviada));
      sleep(4);
    }
}
