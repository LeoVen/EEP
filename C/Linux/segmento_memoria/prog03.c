#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main (int argc, char * argv[]) {
  key_t  key;
  int    shmid, tamanho=2048;
  char   *shm;
  system("clear");
  key=ftok("/tmp",'a');
  shmid=shmget(key, tamanho, 0);
  if ( shmid == -1 ) {
    printf("Não foi possível identificar o segmento de memória.\n");
  } else {
    shm=shmat(shmid,0,0);    
    sleep(100);
    printf("Recuperando %s do segmento %d.\n",shm,shmid);
    shmdt(shm);
  }
  return 0;
}
