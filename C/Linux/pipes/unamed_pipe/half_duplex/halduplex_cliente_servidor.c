#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// Unamed pipes with half duplex
int main (int argc, char * argv[])
{
    int fd[2];

    char msg_received[80], msg_sent[80];

    system("clear");

    // Creating an unamed pipe
    pipe(fd);

    // Always writing to 1 and reding from 0

    if (fork() == 0) {
        // Reading from a pipe

        // First closing channel 1 (write)
        close(fd[1]);

        // Reading from pipe 80 bytes
        read(fd[0], msg_received, 80);
        
        printf("Half Duplex Server: Recovered message from pipe : %s\n", msg_received);
        
        exit(1);
    }
    else
    {
        
        // Writing to pipe
        printf("Digite a mensagem: ");

        // Reading 80 bytes from user
        fgets(msg_sent, 80, stdin);

        // First closing channel 0 (read)
        close(fd[0]);

        printf("Half Duplex Client: Message sent to pipe : %s\n", msg_sent);
        
        // Writing to pipe
        write(fd[1], msg_sent, sizeof(msg_sent));
        
        sleep(4);
    }
}
