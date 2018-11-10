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
    int fd, ret_val, count, numread;
    
    char buf[MAX_BUF_SIZE];

    // Creates a Half-duplex Named Pipe
    ret_val = mkfifo(HALF_DUPLEX, 0777);

    if ((ret_val == -1) && (errno != EEXIST))
    {
        perror("Error creating the named pipe");
        
        exit (1);
    }

    // Opens the pipe for reading only
    fd = open(HALF_DUPLEX, O_RDONLY);

    // Read from pipe
    numread = read(fd, buf, MAX_BUF_SIZE);

    //buf[numread] = '0';

    printf("Half Duplex Server: Read from pipe: %s\n", buf);

    // Converting to uppercase
    count = 0;

    while (count < numread)
    {
        buf[count] = toupper(buf[count]);

        count++;
    }
    
    printf("Half Duplex Server: Converted text: %s\n", buf);
}
