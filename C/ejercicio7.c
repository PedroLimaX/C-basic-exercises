#include <stdio.h>

int main(){
	
	float total_compra,total_compra1,total_compra2
	,descuento,descuento1
	,precio1,precio2,precio3,precio4,precio5;
	
	printf("Digite el total del precio:");
	scanf("%f",&descuento);
	
	 if(descuento<500){
		descuento= descuento;		
		printf("El precio es:%.2f",descuento);
	}
	
	else if(descuento>=500 && descuento<=1000){
		descuento = descuento-(descuento *0.5);
		printf("Su precio es:%.2f",descuento);
}
	
	else if(descuento>1000 && descuento<=7000){
		descuento = descuento-(descuento* 0.11);
		printf("Su precio es:%.2f",descuento);
	}
		else if(descuento>7000 && descuento<=15000){
		descuento = descuento-(descuento* 0.20);
		printf("Su precio es:%.2f",descuento);
	}
		else if(descuento>20000){
		descuento = descuento-(descuento* 0.25);
		printf("Su precio es:%.2f",descuento);
	}

	else
	printf("Dijite un numero");
	
}
