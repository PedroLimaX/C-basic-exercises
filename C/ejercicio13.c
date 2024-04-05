#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[]){
	float a,b,c,d,y,x1,x2;
	printf("Resolucion de ecuacion cuadratica AX^2 + BX + C \n");
	printf("Escriba el valor de A: ");
	scanf("%f", &a);
	printf("Escriba el valor de B: ");
	scanf("%f", &b);
	printf("Escriba el valor de C: ");
	scanf("%f", &c);
	d=((b*b)-4*a*c);
	if (d>=0)
	{	if(a!=0){
			y=sqrt((b*b)-4*a*c);
			x1=(-b+y)/(2*a);
			x2=(-b-y)/(2*a);
			printf("Las raices de la ecuacion son:\n x1=%.2f \t x2=%.2f \n",x1,x2);
		}
		else{
			printf("la ecuacion no tiene raices en numeros reales \n");
		}
		
	}
	else{
		printf("la ecuacion no tiene raices en numeros reales \n");
	}
	return 0;
}
