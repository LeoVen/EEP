#include <stdio.h>
#include <errno.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "fullduplex.h"

int main(int argc, char *argv[])
{
    int rdfd, wrfd, ret_val, count, numread;
    char buf[MAX_BUF_SIZE];

    /* Cria o primeiro named pipe */
    ret_val = mkfifo(NP1, 0666);

    if ((ret_val == -1) && (errno != EEXIST)) {
        perror("Erro ao criar o named pipe");
        exit (1);
    }

    /* Cria o segundo named pipe */
    ret_val = mkfifo(NP2, 0666);

    if ((ret_val == -1) && (errno != EEXIST)) {
        perror("Erro ao criar o named pipe");
        exit (1);
    }

    /* Abre o primeiro named pipe para leitura */
    rdfd = open(NP1, O_RDONLY);

    /* Abre o segundo named pipe para escrita */
    wrfd = open(NP2, O_WRONLY);

    /* Le do primeiro pipe */
    numread = read(rdfd, buf, MAX_BUF_SIZE);

    //buf[numread] = '0';

    printf("Servidor Full Duplex : Li do pipe : %s\n", buf);

    /* Converte texto para maiusculo */
    count = 0;
    while (count < numread) {
        buf[count] = toupper(buf[count]);
        count++;
    }

    /* Escreve o texto convertido no segundo pipe */    
    write(wrfd, buf, strlen(buf));
}
