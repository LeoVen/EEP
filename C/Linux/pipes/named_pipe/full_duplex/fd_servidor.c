#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    // Creates the first named pipe
    ret_val = mkfifo(NP1, 0666);

    if ((ret_val == -1) && (errno != EEXIST))
    {
        perror("Error creating the named pipe");

        exit (1);
    }

    // Creates the second named pipe
    ret_val = mkfifo(NP2, 0666);

    if ((ret_val == -1) && (errno != EEXIST))
    {
        perror("Erro ao criar o named pipe");

        exit (1);
    }

    // Opens the first named pipe for reading
    rdfd = open(NP1, O_RDONLY);

    // Opens the second named pipe for writing
    wrfd = open(NP2, O_WRONLY);

    // Reads from the first pipe
    numread = read(rdfd, buf, MAX_BUF_SIZE);

    //buf[numread] = '0';

    printf("Full Duplex Server: Read from pipe: %s\n", buf);

    // Converting to uppercase
    count = 0;

    while (count < numread)
    {
        buf[count] = toupper(buf[count]);

        count++;
    }

    // Writes the converted text into the second pipe
    write(wrfd, buf, strlen(buf));
}
