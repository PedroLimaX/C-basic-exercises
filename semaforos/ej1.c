#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <semaphore.h>

int x=0;
sem_t semaforo;
void *fhilo1(void *arg){
	int i;
	for(i=0;i<3;i++){
		sem_wait(&semaforo);
		x=x+1;
		sem_post(&semaforo);
		printf("Suma 1\n");
		sleep (random()%3);
	}
	pthread_exit (NULL);
}
void *fhilo2(void *arg){
	int i;
	for(i=0;i<3;i++){
		sem_wait(&semaforo);
		x=x-1;
		sem_post(&semaforo);
		printf("Resta 1\n");
		sleep (random()%3);
	}
	pthread_exit (NULL);
}
main(){
	pthread_t hilo1, hilo2;
	time_t t;
	srandom(time(&t));
	printf("Valor inicial de x: %d \n",x);
	sem_init(&semaforo,0,1);
	pthread_create(&hilo1, NULL, fhilo1, NULL);
	pthread_create(&hilo2, NULL, fhilo2, NULL);
	pthread_join(hilo1,NULL);
	pthread_join(hilo2,NULL);
	sem_destroy(&semaforo);
	printf("Valor final de x: %d \n", x);
	exit(0);
}

