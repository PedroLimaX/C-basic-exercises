#include <stdio.h>
#include <string.h>
int main()
{
      int n, num[100], primos =0, noprimos=0, i=0;
      do{
      	printf("Ingresa los numeros a clasificar (escribe -0 para terminar): ");
      	scanf("%d",&n);
      	num[i]=n;
      	i++;
      }
      while(n!=0);
      	for(int j=0;j<i;j++){
		for (int x=2; x<num[j]/2; x++) {
			if (num[j] % x == 0) {
				noprimos++;
			}
			
		}
		
      }
      primos = i-noprimos;
      printf("De los numeros ingresados, %d son primos y %d no lo son \n", primos, noprimos);
      return (0);
}
