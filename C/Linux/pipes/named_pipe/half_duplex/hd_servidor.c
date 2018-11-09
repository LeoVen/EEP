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
    int fd, ret_val, count, numread;
    char buf[MAX_BUF_SIZE];

    /* Cria o named - pipe */
    ret_val = mkfifo(HALF_DUPLEX, 0777);

    if ((ret_val == -1) && (errno != EEXIST)) {
        perror("Error creating the named pipe");
        exit (1);
    }

    /* Abre o pipe para leitura */
    fd = open(HALF_DUPLEX, O_RDONLY);

    /* Le do pipe */
    numread = read(fd, buf, MAX_BUF_SIZE);

    //buf[numread] = '0';

    printf("Servidor Half Duplex : Li do pipe : %s\n", buf);

    /* Converte para maiusculas */
    count = 0;
    while (count < numread) {
        buf[count] = toupper(buf[count]);
        count++;
    }
    
    printf("Servidor Half Duplex : Texto convertido : %s\n", buf);
}
