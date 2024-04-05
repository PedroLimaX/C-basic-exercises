#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
/*SE DEFINIRAN 3 HILOS POR DEFECTO*/
#define num_threads 3

typedef struct interval{
  int iter;
  int ini;
  int fin;
  } t_interval;

int suma_parcial[num_threads];
int suma = 0;

void *hilo(void *arg){
  int i;
  int ini1,fin1, itera;

  t_interval *inter;

  inter = ((t_interval *) (arg));

  itera = inter->iter;
  ini1 = inter->ini;
  fin1 = inter->fin;
  suma_parcial[itera] = 0;

  for(i=ini1;i<=fin1;i++){
    suma_parcial[itera] = suma_parcial[itera] + i;
  }

  printf("Hilo %d\t Suma parcial = %d\n",itera,suma_parcial[itera]);
  pthread_exit(0);
}

int main(){

  pthread_t thread[num_threads];

  int ini,fin;
  int i,elem,inicio;

  t_interval param[num_threads];

  printf("Inicio del intervalo: ");
  scanf("%d",&ini);

  printf("Fin del intervalo: ");
  scanf("%d",&fin);
  printf("La suma se dividirá en 3 hilos\n\n");
  elem = ((fin-ini)+1)/num_threads;

  inicio=ini;
  for (i=0;i<num_threads;i++){
    param[i].iter = i;
    param[i].ini = inicio;
    if (i==(num_threads-1)) param[i].fin = fin;
    else param[i].fin = param[i].ini + elem;
    pthread_create(&thread[i], NULL, hilo, (void *) &param[i]);
    printf("Hilo : Iteracion No %d\t Inicio: %d\t Fin: %d\n",param[i].iter,
    param[i].ini,param[i].fin);
    inicio = param[i].fin+1;
  }
  for (i=0; i<num_threads; i++) pthread_join(thread[i],NULL);

  for (i=0; i<num_threads; i++) suma = suma + suma_parcial[i];

  printf("\nSuma Final = %d\n",suma);
  printf("\nEjercicios elaborados por:\n Pedro Degante Lima\n Axel E Marin Robles\n Sebastian Castañeda Alvarado");
  pthread_exit (0);
}