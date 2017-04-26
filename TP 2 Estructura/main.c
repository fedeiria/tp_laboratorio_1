#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define CANTIDAD_ELEMENTOS 20

int main()
{
    char salir = 'n';
    int opcion = 0;

    EPersona persona[CANTIDAD_ELEMENTOS];

    inicializarArrayEstado(persona, CANTIDAD_ELEMENTOS, 0);

    while(salir == 'n')
    {
        opcion = menu();

        switch(opcion)
        {
            case 1:
                altaPersona(persona);
                break;
            case 2:
                borrarPersona(persona);
                break;
            case 3:
                imprimirLista(persona);
                break;
            case 4:
                imprimirGrafico(persona);
                break;
            case 5:
                salir = 's';
                break;
        }
    }

    return 0;
}
