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
    int wrfd, rdfd, numread;
    
    char rdbuf[MAX_BUF_SIZE];

    if (argc != 2)
    {
        printf("Usage: %s message_to_be_sent_to_the_server\n", argv[0]);

        exit (1);
    }

    // Opens the first named pipe for writing
    wrfd = open(NP1, O_WRONLY);

    // Opens the second named pipe for reading
    rdfd = open(NP2, O_RDONLY);

    // Writes in the first pipe
    write(wrfd, argv[1], strlen(argv[1]));

    // Reads from the second pipe
    numread = read(rdfd, rdbuf, MAX_BUF_SIZE);

    //rdbuf[numread] = '0';

    printf("Full Duplex Client: Read from pipe: %s\n", rdbuf);
}
