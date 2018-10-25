#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

void* filho (void* mensagem) {
   printf("Processo-Filho: Iniciando Execucao.\n");
   printf("Processo-Filho: o conteudo da variavel MENSAGEM e: %s\n", mensagem);
   strcpy(mensagem,"MSG do Proc. Filho");
   sleep(5);
   printf("Processo-Filho: o conteudo da variavel MENSAGEM e: %s\n", mensagem);
   printf("Processo-Filho: Encerrando Execucao.\n");	
}

main() {
  pthread_t	thread_id;
  char mensagem[80]="MSG do Proc. Pai";
  system("clear");
  printf("Processo-Pai: Iniciando Execucao.\n");
  printf("Processo-Pai: o conteudo da variavel MENSAGEM e: %s\n", mensagem);
  pthread_create(&thread_id,NULL,&filho,&mensagem);
  pthread_join(thread_id,NULL);
  printf("Processo-Pai: o conteudo da variavel MENSAGEM e: %s\n", mensagem);
  printf("Processo-Pai: Encerrando Execucao.\n");  
} 
