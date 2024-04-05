#include <stdio.h>
#include <string.h>
int main()
{
      float precio, kilos, descuento =0 ,subtotal, total;
      printf("Ingresa el precio del kg de manzana: ");
      scanf("%f",&precio);
      int i=0;
      do{
      	printf("Ingresa los kg comprados (escribe 0 para salir): ");
      	scanf("%f", &kilos);
      	if(kilos>2) {
      		if (kilos <5.01){
      			descuento = 0.10;
      		}
      	}
      	if(kilos>5) {
      		if (kilos <10.01){
      			descuento = 0.15;
      		}
      	}
      	if(kilos>10) {
		descuento = 0.20;
      	}
      	if(kilos<0){
      		printf("El numero que ingreso no es valido, vuelva a intentarlo\n");
      	}
      	else if (kilos!=0){
      		
      		subtotal = kilos * precio;
      		total = subtotal - (subtotal*descuento);
      		printf("\n\nSubtotal: %.2f \t Descuento: %.2f \t Total: %.2f pesos\n\n", subtotal, (subtotal *descuento), total);
	}
      	
      	i++;
      }
      while(kilos!=0);
      return (0);
}
