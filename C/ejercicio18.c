#include <stdio.h>
float a[100], b[100], c[100], numa,numb;
int lon;
float prod_esc=0;

int main()
{
        printf("Longitud de ambas secuencias: ");
        scanf("%d", &lon);
        printf("Ingrese la primer secuencia de numeros: \n");
	for(int i=0;i<lon;i++){
		scanf("%f", &numa);
		a[i]=numa;
	}
        printf("Ingrese la segunda secuencia de numeros: \n");
	for(int j=0;j<lon;j++){
		scanf("%f", &numb);
		b[j]=numb;
	}
	
	for(int k=0;k<lon;k++){
		c[k]=(a[k])*(b[k]);
		prod_esc+= c[k];
	}
	printf("El producto escalar es: %f\n", prod_esc);
	return 0;
}
