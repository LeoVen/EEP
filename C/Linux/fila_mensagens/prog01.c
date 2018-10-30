#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main (int argc, char * argv[]) {
  key_t   key;
  int     msgid;
  system("clear");
  key=ftok("/home",'a');
  msgid=msgget(key,0600|IPC_CREAT);
  printf("O identificador da fila de mensagens e %d.\n",msgid);
  return 0;
}
