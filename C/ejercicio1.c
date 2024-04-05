#include <stdio.h>
#include <string.h>
int main()
{
      int principal, i ,j, n, num[100], pares[100], mult[100];
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
      
     
	printf("De los numeros ingresados, los numeros pares son: \n");
      	for(j=0;j<i;j++){
      		if((num[j]%2)==0){
      		printf("%i\n", num[j]);
		}
	}
      	
      		printf("De los numeros ingresados, los multiplos del numero principal (%d) son: \n",principal);
      		for(j=0;j<i;j++){
      		if((num[j]%principal)==0){
      			printf("%i\n", num[j]);
		}
      	
      }
      return (0);
}
