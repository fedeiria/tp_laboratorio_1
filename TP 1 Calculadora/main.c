#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir = 's';
    int opcion;
    float valor1 = 0, valor2 = 0;

    while(seguir == 's')
    {
        opcion = menu(valor1, valor2);

        switch(opcion)
        {
        case 1:
            valor1 = ingresoNumero();
                break;
        case 2:
            valor2 = ingresoNumero();
                break;
        case 3:
            suma(valor1, valor2);
                break;
        case 4:
            resta(valor1, valor2);
                break;
        case 5:
            division(valor1, valor2);
                break;
        case 6:
            multiplicacion(valor1, valor2);
                break;
        case 7:
            factorial(valor1);
                break;
        case 8:
            todosCalculos(valor1, valor2);
                break;
        case 9:
            seguir = 'n';
                break;
        default:
            printf("\nERROR! Elija una opcion entre 1 y 9.\n\n");
            system("pause");
        }
    }
    return 0;
}
