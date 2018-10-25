#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* filho (void* null) {
   printf("Processo-Filho: Iniciando Execucao.\n");
   sleep(5);
   printf("Processo-Filho: Encerrando Execucao.\n");	
}

main() {
  pthread_t	thread_id;
  system("clear");
  printf("Processo-Pai: Iniciando Execucao.\n");
  pthread_create(&thread_id,NULL,&filho,NULL);
  sleep(10);
  printf("Processo-Pai: Encerrando Execucao.\n");  
} 
