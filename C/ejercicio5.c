#include <stdio.h>


int main (){
	
	
	int pesos;
	printf("Dijite su cantidad :"); scanf("%d", &pesos);
	
	printf("[%d]Billetes de 1000\n", pesos /1000);
	pesos %= 1000;
	printf("[%d]Billetes de 500\n", pesos /500);
	pesos %= 500;
	printf("[%d]Billetes de 200\n", pesos /200);
	pesos %= 200;
	printf("[%d]Billetes de 100\n", pesos /100);
	pesos %= 100;
	printf("[%d]Billetes de 50\n", pesos /50);
	pesos %= 50;
	printf("[%d]Billetes de 20\n", pesos /20);
	pesos %= 20;	
	printf("[%d]Monedas de 10\n", pesos /10);
	pesos %= 10;
	printf("[%d]Monedas de 5\n", pesos /5);
	pesos %= 5;
	printf("[%d]Monedas de 2\n", pesos /2);
	pesos %= 2;
	printf("[%d]Monedas de 1\n", pesos /1);
	pesos %= 1;
	
		
}
