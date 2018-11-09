#include <stdio.h>
#include <errno.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "fullduplex.h"

int main(int argc, char *argv[])
{
    int wrfd, rdfd, numread;
    char rdbuf[MAX_BUF_SIZE];

    if (argc != 2) {
        printf("Uso : %s texto_a_ser_enviado_ao_servidor\n", argv[0]);
        exit (1);
    }

    /* Abre o primeiro named pipe para escrita */
    wrfd = open(NP1, O_WRONLY);

    /* Abre o segundo named pipe para leitura */
    rdfd = open(NP2, O_RDONLY);

    /* Escreve no pipe */
    write(wrfd, argv[1], strlen(argv[1]));

    /* Le do pipe */
    numread = read(rdfd, rdbuf, MAX_BUF_SIZE);

    //rdbuf[numread] = '0';

    printf("Cliente Full Duplex : Li do Pipe : %s\n", rdbuf);
}
