#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main () {
  key_t   key;
  int     msgid, retorno;
  system("clear");
  key=ftok("/home",'a');
  msgid=msgget(key,0);
  retorno=msgctl(msgid,IPC_RMID,0);
  if ( retorno == 0) {
      printf("A fila de mensagens %d foi removida.\n",msgid);
  } else {
      printf("A fila de mensagens %d não foi removida.\n",msgid);
  }
  return 0;
}
