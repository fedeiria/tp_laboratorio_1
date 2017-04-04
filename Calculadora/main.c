#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir = 's';
    int opcion = 0;
    float valor1 = 0, valor2 = 0, resultado;

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
            resultado = suma(valor1, valor2);
            printf("\nResultado Suma: %.2f\n\n", resultado);
            system("pause");
                break;
        case 4:
            resultado = resta(valor1, valor2);
            printf("\nResultado Resta: %.2f\n\n", resultado);
            system("pause");
                break;
        case 5:
            resultado = division(valor1, valor2);
            printf("\nResultado Division: %.2f\n\n", resultado);
            system("pause");
                break;
        case 6:
            resultado = multiplicacion(valor1, valor2);
            printf("\nResultado Multiplicacion: %.2f\n\n", resultado);
            system("pause");
                break;
        case 7:
            resultado = factorial(valor1);
            printf("\nResultado Factorial: %.0f\n\n", resultado);
            system("pause");
                break;
        case 8:
            resultado = todosCalculos(valor1, valor2);
            system("pause");
                break;
        case 9:
            seguir = 'n';
                break;
        }
    }
    return 0;
}
