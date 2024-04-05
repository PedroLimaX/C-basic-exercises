#include <stdio.h>

int main()
{
    int numero1, numero2, producto;
    int residuo, mcd, mcm;

    printf("Agregue el primer numero 1: ");
    scanf("%d", &numero1);

    printf("Agregue el primer numero 2: ");
    scanf("%d", &numero2);

    producto = numero1 * numero2;

    do
    {
        residuo = numero1 % numero2;

        if (residuo != 0)
        {
            numero1 = numero2;
            numero2 = residuo;
        }
        else
        {
            mcd = numero2;
        }

    } while (residuo != 0);

    mcm = producto / mcd;

    printf("El MCM es: %d\n", mcm);


    return 0;
}
