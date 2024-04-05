#include <stdio.h>

int main(){
	
	int num =0, i =0, suma=0;
	printf("Ingrese un número");
	scanf("%d",&num);
	
	for(i=1;i<num;i++){
		if(num%i==0)
		suma=suma+i;
		
	}
	if(suma==num)
		printf("El numero es perfecto");
		else
		printf("El numero no es perfecto");
	
}
