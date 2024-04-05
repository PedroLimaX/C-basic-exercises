#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define TAM_BUFFER 16
#define DATOS_A_PRODUCIR 10

sem_t elementos, huecos;
sem_t mutex1, mutex2;
sem_t prioridad;

int nconsumidores=0, nproductores=0;
int buffer[TAM_BUFFER];
int posprod=0, poscons=0;
void *f_productor(void*arg){
	int i, dato;
	for(i=1; i<DATOS_A_PRODUCIR; i++){
		sem_wait(&huecos);
		sem_wait(&prioridad);
		sem_wait(&mutex2);
		nproductores=nproductores+1;
		sem_post(&mutex2);
		sem_wait(&mutex1);
		buffer[posprod]=i;
		posprod=(posprod+1)%TAM_BUFFER;
		printf("Producido %d \n", i);
		sem_post(&mutex1);
		sem_post(&elementos);
		sem_wait(&mutex2);
		if(nconsumidores==0) sem_post(&prioridad);
		nproductores=nproductores+1;
		sem_post(&mutex2);
	}
	pthread_exit(0);
}

void *f_consumidor (void *arg){
	int i, dato;
	for(i=1; i<DATOS_A_PRODUCIR;i++){
		sem_wait(&elementos);
		sem_wait(&mutex2);
		nconsumidores=nconsumidores+1;
		sem_post(&mutex2);
		sem_wait(&mutex1);
		dato=buffer[poscons];
		poscons=(poscons+1) % TAM_BUFFER;
		printf("Consumido %d \n", i);
		sem_post(&mutex1);
		sem_post(&huecos);
		sem_wait(&mutex2);
		nconsumidores=nconsumidores-1;
		if((nconsumidores ==0) & (nproductores !=0)) sem_post(&prioridad);
		sem_post (&mutex2);
	}
	pthread_exit(0);
}

void main(){
	pthread_t productor1, productor2;
	pthread_t consumidor1, consumidor2;
	sem_init(&elementos, 0,0); sem_init (&huecos,0,TAM_BUFFER);
	sem_init(&mutex1, 0,1); sem_init (&mutex2,0,1);
	sem_init(&prioridad,0,1);
	pthread_create(&productor1, NULL, f_productor, NULL);
	pthread_create(&productor2, NULL, f_productor, NULL);
	pthread_create(&consumidor1, NULL, f_consumidor, NULL);
	pthread_create(&consumidor1, NULL, f_consumidor, NULL);
	
	pthread_join(productor1,NULL);
	pthread_join(productor2,NULL);
	pthread_join(consumidor1,NULL);
	pthread_join(consumidor2,NULL);
	
	sem_destroy(&elementos); sem_destroy(&huecos);
	sem_destroy(&mutex1); sem_destroy(&mutex2);
	sem_destroy(&prioridad);
	exit(0);
}
