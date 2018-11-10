#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// Unamed pipe with full duplex
int main (int argc, char * argv[])
{
	int	fd[2];
	char msg_rcv[BUFSIZ], msg_svc[BUFSIZ]="OK", msg_sent[BUFSIZ], msg_received[BUFSIZ];

	// Creating an unamed
	pipe(fd);

	system("clear");

	if (fork() == 0)
	{
		// Reading from pipe
		read(fd[0], msg_received, BUFSIZ);

		printf("[Child-Process]: Received the message \"%s\" from the pipe.\n", msg_received);
        printf("[Child-Process]: Enter a message to be sent to the Parent-Process: ");

        // User input
        scanf("%[^\n]", msg_svc);
        
        // Write to pipe
        write(fd[1], msg_svc, strlen(msg_svc));

		exit(1);
	}

    printf("[Parent-Process]: Enter a message to be sent to the Child-Process: ");

    // User input
    scanf("%[^\n]", msg_sent);

    // Write to pipe
	write(fd[1], msg_sent, strlen(msg_sent));

	// Waiting for the child process to read the user input
	sleep(15);
	
	// Read from pipe
	read(fd[0], msg_rcv, BUFSIZ);
    
    printf("[Parent-Process]: Received the message \"%s\" from the pipe.\n", msg_rcv);
	
	return 0;
}
