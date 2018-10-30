#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main (int argc, char * argv[]) {
  key_t   key;
  int     msgid;
  char    mensagem[80];
  system("clear");
  key=ftok("/home",'a');
  msgid=msgget(key,0);
  msgrcv(msgid,mensagem,sizeof(mensagem),0,0);
  printf("Recuperei a mensagem %s da fila %d.\n",mensagem,msgid);
  return 0;
}
