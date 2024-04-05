#include<stdio.h>

int main(){
int nums = 0, num1=0, i=0, may=0, men=10000;
printf("\n\nIngrese la cantidad de numeros que desea aplicar: \n");
scanf("%d",&nums);
for(i=0;i<nums;i++)
{        
    printf("Escriba el numero:\n ");
    scanf("%d",&num1); 
    if(num1>may) 
    {
        may=num1;
    }   
    if(num1<men) 
    {
        men=num1; 
    }   
}
printf("\nEl numero mayor es: %d",may);
printf("\nEl numero menor es: %d",men);

}
