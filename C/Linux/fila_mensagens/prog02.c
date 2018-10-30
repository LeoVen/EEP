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
  printf("Digite a mensagem: ");
  gets(mensagem);
  msgsnd(msgid,mensagem,sizeof(mensagem),0);
  return 0;
}
