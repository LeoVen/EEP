#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    if (argc != 2)
    {
        printf("Usage: %s message_to_be_sent_to_the_server\n", argv[0]);
        exit (1);
    }

    // Opens pipe to write only
    fd = open(HALF_DUPLEX, O_WRONLY);

    // Writes to the pipe the first parameter
    write(fd, argv[1], strlen(argv[1]));
}
