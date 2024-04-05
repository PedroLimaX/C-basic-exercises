#include <stdio.h>
#include <string.h>

int i=0, j=0;
float sueldotemp=0;
char nombretemp[127];
struct empleados{
	char nombre[127];
	int categ;
	int horas;
	float pagohora;
	float sueldo;
}
datosempleado[5];

int main()
{
	printf("Importante: Se cambio la cantidad de empleados de 50 por 5 ya que se registran 4 datos por cada uno, y si registra 50 empleados tendria que registrar 200 datos en total :)");
	for(i=0;i<5;i++){
		printf("\n\nEmpleado %d\n", (i+1));
	      	printf("Nombre:");
	      	scanf("%s", datosempleado[i].nombre);
	      	
	      	printf("Categoria:");
	      	scanf("%d", &datosempleado[i].categ);
	      	
	      	printf("Horas trabajadas:");
	      	scanf("%d", &datosempleado[i].horas);
	      	
	      	printf("Pago por Hora:");
	      	scanf("%f", &datosempleado[i].pagohora);
	      	
	      	datosempleado[i].sueldo = datosempleado[i].horas * datosempleado[i].pagohora;
	      	
	}

	for(int j=0;j<5; j++){
		for(int k=0;k<3-1;k++){
			if(datosempleado[k].sueldo < datosempleado[k+1].sueldo){
			
				sueldotemp = datosempleado[k].sueldo;
				strcpy(nombretemp, datosempleado[k].nombre);
				
				datosempleado[k].sueldo=datosempleado[k+1].sueldo;
				strcpy(datosempleado[k].nombre, datosempleado[k+1].nombre);
				
				datosempleado[k+1].sueldo=sueldotemp;
				strcpy(datosempleado[k+1].nombre, nombretemp);
			}
		}
		
	}
	printf("\n\nEmpleado\tSueldo\n");
	for(j=0;j<5;j++){
		printf("%s \t %.2f\n", datosempleado[j].nombre, datosempleado[j].sueldo);
	}
      return (0);
}
