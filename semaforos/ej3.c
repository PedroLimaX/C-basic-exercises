#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <semaphore.h>

#define MAX_BUFFER 16 /*Tamanio del buffer*/
#define DATOS_A_PRODUCIR 10 /*Datos a producir*/
sem_t elementos; /*Elementos en el buffer*/
sem_t huecos; /*Huecos en el buffer*/
int buffer[MAX_BUFFER]; /*Buffer comun*/
void *Productor(void *arg){
	int pos = 0;
	int dato;
	int i;
	for(i=0;i<DATOS_A_PRODUCIR;i++){
		dato=i;
		printf("Producido %d\n",dato);
		sem_wait(&huecos);
		buffer[pos] = i;
		pos =(pos +1)%MAX_BUFFER;
		sem_post (&elementos);
		printf("Producido %d\n",dato);
		sleep(random()%3);
	}
	pthread_exit(0);
}
void *Consumidor(void *arg){
	int pos =0;
	int dato;
	int i;
	for(i=0; i<DATOS_A_PRODUCIR; i++){
		sem_wait(&elementos);
		dato = buffer[pos];
		pos = (pos+1)%MAX_BUFFER;
		sem_post(&huecos);
		printf("Consumido %d\n",dato);
		sleep(random()%3);
	}
	pthread_exit(0);
}
void main(void *arg){
	pthread_t hilo1, hilo2;
	time_t t;
	srandom(time(&t));
	sem_init(&elementos, 0,0);
	sem_init(&huecos, 0, MAX_BUFFER);
	
	pthread_create(&hilo1, NULL, Productor, NULL);
	pthread_create(&hilo2, NULL, Consumidor, NULL);

	pthread_join(hilo1, NULL);
	pthread_join(hilo2, NULL);
	sem_destroy(&huecos);
	sem_destroy(&elementos);
	
	exit(0);
}
