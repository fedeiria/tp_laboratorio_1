#include "funciones.h"

int main(void)
{
    char salir = 'n';
    int opcion = 0;

    Movie auxMovie[MAX_MOVIE];

    inicializarArray(auxMovie, MAX_MOVIE, 0);
    cargarDatos(auxMovie);

    while(salir == 'n')
    {
        opcion = menu();

        switch(opcion)
        {
            case 1:
                agregarPelicula(auxMovie);
                break;
            case 2:
                borrarPelicula(auxMovie);
                break;
            case 3:
                modificarPelicula(auxMovie);
                break;
            case 4:
                generarPaginaWeb(auxMovie);
                break;
            case 5:
                guardarDatos(auxMovie);
                salir = 's';
                break;
        }
    }

    return 0;
}
