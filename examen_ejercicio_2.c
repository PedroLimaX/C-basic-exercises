#include<stdio.h>
#include<stdlib.h>

int main() {
	int pid, pid_b,x;
	printf("A: Soy el proceso padre y mi pid es: %d\n", getpid());
	x = 5;
	pid = fork();
	// En cuanto llamamos a fork se crea un nuevo proceso. En el proceso
	// padre 'pid' contendrá el pid del proceso hijo. En el proceso hijo
	// 'pid' valdrá 0. Eso es lo que usamos para distinguir si el código
	// que se está ejecutando pertenece al padre o al hijo.
	if (pid) // Este es el proceso padre
	{
		printf("A: Mi hijo tiene el pid: %d\n\n", pid);
		sleep(1);

		pid_b=fork();

		if(pid_b){//codigo del padre
			printf("B: Mi hijo tiene el pid: %d\n\n", pid_b);

			int pid_c;
			pid_c = fork();

			if(pid_c){//codigo padre
			
				printf("C: Mi hijo tiene el pid: %d\n\n", pid_c);	
				sleep(2);
			}
			else{//codigo del hijo

				int pid_d;
				pid_d = fork();

				if(pid_d){//codigo padre  proceso hijoa
					printf("D: Soy el proceso bisnieto D y mi pid es: %d\n",getpid());
					
					sleep(1);
				}
				else{
  					printf("\nEjercicios elaborados por:\n Pedro Degante Lima\n Axel E Marin Robles\n Sebastian Castañeda Alvarado");
				}
			}
		}
		else{//codigo del hijo
			printf("C: Soy el proceso nieto C y mi pid es: %d\n",getpid());
		}
	}
	else // Proceso hijo
	{
		printf("B: Soy el proceso hijo B y mi pid es: %d\n", getpid());
	}
  pthread_exit (0);
}