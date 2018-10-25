#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main (int argc, char * argv[]) {
  key_t  key;
  int    shmid, tamanho=2048;
  char   mensagem[80]="Oi mundo.", *shm;
  system("clear");
  key=ftok("/tmp",'a');
  shmid=shmget(key, tamanho, 0);
  if ( shmid == -1 ) {
    printf("Não foi possível identificar o segmento de memória.\n");
  } else {
    shm=shmat(shmid,0,0);
    strcpy(shm,mensagem);
    printf("Escrevendo %s no segmento %d.\n",mensagem,shmid);
    shmdt(shm);
  }
  return 0;
}
