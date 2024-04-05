/*Elabore un algoritmo que calcule la suma de los números múltiplos de X existentes en una secuencia de números proporcionados por el usuario. La secuencia termina con 0*/

#include <stdio.h>
#include <string.h>
int main()
{
      int principal, i ,j, n, num[100], suma=0;
      printf("Ingresa el numero principal:");
      scanf("%d",&principal);
      i=0;
      do{
      	printf("Ingresa los numeros a clasificar (escribe -0 para terminar): ");
      	scanf("%d",&n);
      	num[i]=n;
      	i++;
      }
      while(n!=0);
	
      		for(j=0;j<i;j++){
      		if((num[j]%principal)==0){
      			suma=suma+ num[j];
		}
		
      	
      }
      printf("La suma de los multiplos del numero principal (%d) es: %d \n",principal,suma);
      return (0);
}
