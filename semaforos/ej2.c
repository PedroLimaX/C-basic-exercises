#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <semaphore.h>

sem_t semaforo;
void *Escribe (char c, int nc){
	int i;
	for(i=0;i<nc;i++){
		printf("%c \n", c);
		sleep (random()%3);
	}
}
void *fhilo1(void *p){
	Escribe ('A', 3);
	sem_wait(&semaforo);
	Escribe ('C', 2);
	pthread_exit(NULL);
}
void *fhilo2(void *p){
	Escribe ('B', 5);
	sem_post(&semaforo);
	pthread_exit(NULL);
}
main(){
	pthread_t hilo1, hilo2;
	time_t t;
	srandom(time(&t));
	sem_init(&semaforo,0,0);
	pthread_create(&hilo1, NULL, fhilo1, NULL);
	pthread_create(&hilo2, NULL, fhilo2, NULL);
	pthread_join(hilo1, NULL);
	pthread_join(hilo2, NULL);
	sem_destroy(&semaforo);
	exit(0);
}

