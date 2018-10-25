#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main (int argc, char * argv[]) {
  key_t  key;
  int    shmid, tamanho=2048,retorno;
  system("clear");
  key=ftok("/tmp",'a');
  shmid=shmget(key, tamanho, 0);
  if ( shmid == -1 ) {
    printf("Não foi possível identificar o segmento de memória.\n");
  } else {
    retorno=shmctl(shmid,IPC_RMID,0);
    if ( retorno == 0 ) {
      printf("Segmento de memoria %d removido com sucesso.\n",shmid);
    } else {
      printf("Não foi possível remover o segmento de memória %d.\n",shmid);
    }
  }
  return 0;
}
