#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int num1, num2, a, b, res;
    printf("Ingrese el primer numero\n");
    scanf("%d",&num1);
    printf("Ingrese el segundo numero\n");
    scanf("%d",&num2);

    if (num1>num2) {
        a = num1;
        b = num2;
    } else {
        a = num2;
        b = num1;
    }
    do {
        res = b;
        b = a%b;
        a = res;
    } while (b!=0);
    printf("El MCD entre %d y %d es: %d",num1,num2,res);
    return 0;
}
