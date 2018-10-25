#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* filho (void* mensagem) {
   printf("Processo-Filho: Iniciando Execucao.\n");
   printf("Processo-Filho: A informacao recebida foi: %s\n", mensagem);
   sleep(5);
   printf("Processo-Filho: Encerrando Execucao.\n");	
}

main() {
  pthread_t	thread_id;
  system("clear");
  printf("Processo-Pai: Iniciando Execucao.\n");
  pthread_create(&thread_id,NULL,&filho,"Oi mundo.");
  pthread_join(thread_id,NULL);
  printf("Processo-Pai: Encerrando Execucao.\n");  
} 
