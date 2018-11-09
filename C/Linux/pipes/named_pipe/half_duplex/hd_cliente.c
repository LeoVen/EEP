#include <stdio.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "halfduplex.h"

int main(int argc, char *argv[])
{
    int fd;

    if (argc != 2) {
        printf("Uso : %s mensagem_a_ser_enviada_ao_servidor\n", argv[0]);
        exit (1);
    }

    /* Abre o pipe para escrita */
    fd = open(HALF_DUPLEX, O_WRONLY);

    /* Escreve no pipe */
    write(fd, argv[1], strlen(argv[1]));
}
