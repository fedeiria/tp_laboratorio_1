#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "validaciones.h"

/**
 * \brief Muestra un menu con opciones
 * \return opcion Devuelve el valor ingresado
 */
int menu(void)
{
    int opcion;

    do{
        system("cls");
        printf("************** MENU **************\n\n");
        printf("1 - Agregar una persona\n");
        printf("2 - Borrar una persona\n");
        printf("3 - Imprimir lista ordenada por nombre\n");
        printf("4 - Imprimir un grafico de edades\n");
        printf("5 - Salir\n");

        getValidInt("\nIngrese opcion: ", "\nERROR!, la opcion debe ser numerica.\n", "\nERROR!, Elija una opcion entre 1 y 5.\n", &opcion, 1, 5, 100);

    }while(!opcion);

    return opcion;
}

/**
 * \brief Inicializa un array de persona con el valor recibido
 * \param Epersona persona Es el array a ser inicializado
 * \param cantidadElementos indica la longitud del array
 * \param valor El valor a ser cargado en cada posicion del array
 * \return void
 */
void inicializarArrayEstado(EPersona persona[], int cantidadElementos, int valor)
{
    int i;

    for(i = 0; i < cantidadElementos; i++)
    {
        persona[i].estado = valor;
        persona[i].edad = valor;        // Inicializo edad en cero (0) para el grafico
    }
}

/**
 * \brief Realiza una verificacion en el campo estado y devuelve un valor
 * \param EPersona persona Es el array en el cual se trabaja
 * \param cantidadElementos Indica la longitud del array
 * \param valor Dato que se utiliza para realizar la verificacion
 * \return flag 1 si el campo estado contiene un valor distinto de cero (0), 0 si no hay cambios
 */
int indicadorEstado(EPersona persona[], int cantidadElementos, int valor)
{
    int i;
    int flag = 0;

    for(i = 0; i < cantidadElementos; i++)
    {
        if(persona[i].estado == valor)
            flag = 1;
    }
    return flag;
}

/**
 * \brief Busca un espacio libre en un array persona para permitir el ingreso de datos
 * \param Epersona persona Es el array en el cual se busca
 * \param cantidadElementos indica la longitud del array
 * \param valor El valor a buscar en los elementos del array
 * \return returnAux i Si encuentra un lugar libre, returnAux -1 si no lo encuentra
 */
int buscarEspacioLibre(EPersona persona[], int cantidadElementos, int valor)
{
    int i;
    int returnAux = -1;

    for(i = 0; i < cantidadElementos; i++)
    {
        if(persona[i].estado == valor)
        {
            returnAux = i;
            break;
        }
    }
    return returnAux;
}

/**
 * \brief Obtiene el indice que coincide con el dni pasado por paramentro
 * \param Epersona persona Es el array en el cual se busca
 * \param cantidadElementos Indica la longitud del array
 * \param valor Es el valor a buscar en los elementos del array
 * \return returnAux i El indice donde se encuentra el elemento que coincide con el valor pasado por parametro, returnAux -1 si no lo encuentra
 */
int buscarPorDni(EPersona persona[], int cantidadElementos, long int valor)
{
    int i;
    int returnAux = -1;

    for(i = 0; i < cantidadElementos; i++)
    {
        if(persona[i].dni == valor)
        {
            returnAux = i;
            break;
        }
    }
    return returnAux;
}

/**
 * \brief Ordena el registro de personas de forma ascendente (A - Z)
 * \param Epersona persona Array el cual se trabaja para ordenar el registro
 * \param cantidadelementos Indica la longitud del array
 * \return void
 */
void ordenarRegistro(EPersona persona[], int cantidadElementos)
{
    int i, j;
    EPersona auxDato;

    for(i = 0; i < cantidadElementos - 1; i++)
    {
        for(j = i + 1; j < cantidadElementos; j++)
        {
            if(strcmp(persona[i].nombre, persona[j].nombre) > 0)
            {
                auxDato = persona[i];
                persona[i] = persona[j];
                persona[j] = auxDato;
            }
        }
    }
}

/**
 * \brief Elabora un grafico de barras de las edades ingresadas en el programa
 * \param hasta18 Recibe por parametro las edades menores a 19 a�os
 * \param de19a35 Recibe por parametro las edades entre 19 y 35 a�os
 * \param mayorDe35 Recibe por parametro las edades mayores a 35 a�os
 * \return void
 */
void graficoDeBarras(int hasta18, int de19a35, int mayorDe35)
{
    int i;
    int flag = 0;
    int mayor;

    if(hasta18 >= de19a35 && hasta18 >= mayorDe35)
        mayor = hasta18;

    else if(de19a35 >= hasta18 && de19a35 >= mayorDe35)
        mayor = de19a35;

    else
        mayor = mayorDe35;

    system("cls");

    printf("\n********** GRAFICO DE EDADES **********\n\n");

    for(i = mayor; i > 0; i--)
    {
        printf("%02d|", i);

        if(i > 0 && i <= hasta18)
            printf("*");

        if(i > 0 && i <= de19a35)
        {
            flag = 1;
            printf("\t*");
        }
        if(i > 0 && i <= mayorDe35)
        {
            if(flag == 0)
                printf("\t\t*");

            if(flag == 1)
                printf("\t*");
        }

        printf("\n");
    }
    printf("--+-----------------");
    printf("\n  |<18\t 19-35\t>35");
    printf("\n   %d\t %d\t%d\n\n", hasta18, de19a35, mayorDe35);
    system("pause");
}

/**
 * \brief Permite el ingreso de datos y realizar el alta de una persona
 * \param Epersona persona Array en el cual se ingresan los datos
 * \return void
 */
void agregarPersona(EPersona persona[])
{
    char auxNombre[LONGITUD_CADENA];
    int flag;
    int auxEdad;
    int lugarLibre;
    long int auxDni;

    lugarLibre = buscarEspacioLibre(persona, CANTIDAD_ELEMENTOS, 0);

    if(lugarLibre == -1)
    {
        system("cls");
        printf("\n********** AGREGAR PERSONA **********\n\n");
        printf("No hay lugares libres.\n");
    }
    else
    {
        system("cls");
        printf("\n********** AGREGAR PERSONA **********\n\n");
        getValidString("Ingrese nombre: ", "\nERROR!, el nombre debe estar compuesto por letras.\n\n", "\nERROR!, Solo se permite un minimo de 3 caracteres y un maximo de 50 caracteres.\n\n", auxNombre, 2, 51, 100);
        fflush(stdin);
        strcpy(persona[lugarLibre].nombre, auxNombre);
        getValidInt("Ingrese edad: ", "\nERROR!, la edad debe ser numerica.\n\n", "\nERROR!, la edad debe ser mayor a cero (0) y menor a sesenta y seis (66).\n\n", &auxEdad, 1, 65, 100);
        persona[lugarLibre].edad = auxEdad;

        do{
            flag = 0;
            getValidLongInt("Ingrese DNI (sin puntos): ", "\nERROR!, el DNI debe contener solo numeros.\n\n", "\nERROR de longitud del DNI, debe contener entre 7 y 8 numeros.\n\n", &auxDni, 1000000, 99000000, 100);
            if(buscarPorDni(persona, CANTIDAD_ELEMENTOS, auxDni) != -1)
            {
                printf("\nEl DNI: %ld ya existe.\n\n", auxDni);
                flag = 1;
            }
        }while(flag == 1);

        persona[lugarLibre].dni = auxDni;
        persona[lugarLibre].estado = 1;
    }

    printf("\n");
    system("pause");
}

/**
 * \brief Permite realizar una baja logica de una persona a traves del ingreso del DNI
 * \param Epersona persona Array en el cual se realiza la baja logica
 * \return void
 */
void borrarPersona(EPersona persona[])
{
    int estado;
    int respuesta;
    int busquedaDni;
    int confirmacion;
    long int auxDni;

    system("cls");
    printf("\n********** BORRAR PERSONA **********\n\n");

    do{
        estado = indicadorEstado(persona, CANTIDAD_ELEMENTOS, 1);

        if(estado != 1)
        {
            printf("No hay registros cargados.\n\n");
            break;
        }

        getValidLongInt("Ingrese DNI a dar de baja (sin puntos): ", "\nERROR!, el DNI debe contener solo numeros.\n\n", "\nERROR de longitud del DNI, debe contener entre 7 y 8 numeros.\n\n", &auxDni, 1000000, 99000000, 100);

        busquedaDni = buscarPorDni(persona, CANTIDAD_ELEMENTOS, auxDni);

        if(busquedaDni == -1)
        {
            printf("\nNo se encontro el DNI.\n\n");
            system("pause");
        }
        else
        {
            printf("\n****** DATOS DE LA PERSONA ******\n");
            printf("\nNombre: %s\nEdad: %d\nDNI: %ld\n", persona[busquedaDni].nombre, persona[busquedaDni].edad, persona[busquedaDni].dni);
            getValidInt("\nDesea eliminar el registro? \n\n1 - si\n\n2 - no\n\nIngrese opcion: ", "\nERROR!, la respuesta debe ser numerica: 1 - si | 2 - no\n\n", "\nERROR!, responda solamente 'si' | 'no'.\n\n", &confirmacion, 1, 3, 100);
            if(confirmacion == 1)
            {
                persona[busquedaDni].estado = 0;
                printf("\nRegistro eliminado.\n\n");
                system("pause");
            }
            else
            {
                printf("\nAccion cancelada.\n\n");
                system("pause");
            }
        }

        system("cls");
        printf("\n********** BORRAR PERSONA **********\n");
        getValidInt("\nDesea buscar / borrar otra persona? \n\n1 - si\n\n2 - no\n\nIngrese opcion: ", "\nERROR!, la respuesta debe ser numerica: 1 - si | 2 - no\n\n", "\nERROR!, responda solamente 'si' | 'no'.\n\n", &respuesta, 1, 3, 100);
        printf("\n");

    }while(respuesta == 1);

    system("pause");
}

/**
 * \brief Imprime una lista ordenada por nombre con los datos ingresados
 * \param Epersona persona Array a ser utilizado para imprimir la lista
 * \return void
 */
void imprimirLista(EPersona persona[])
{
    int i;
    int estado;

    ordenarRegistro(persona, CANTIDAD_ELEMENTOS);
    estado = indicadorEstado(persona, CANTIDAD_ELEMENTOS, 1);

    system("cls");
    printf("\n********** LISTA DE REGISTROS **********\n");

    if(estado != 1)
    {
        printf("\nNo hay registros cargados. Nada para mostrar.\n\n");
        system("pause");
    }

    for(i = 0; i < CANTIDAD_ELEMENTOS; i++)
    {
        if(persona[i].estado == 1)
        {
            printf("\nNombre: %s\nEdad: %d\nDNI: %ld\n", persona[i].nombre, persona[i].edad, persona[i].dni);
            system("pause");
        }
    }
}

/**
 * \brief Muestra un grafico de barras con estadisticas de las edades ingresadas
 * \param Epersona persona Array a ser utilizado para mostrar el grafico
 * \return void
 */
void imprimirGrafico(EPersona persona[])
{
    int i;
    int estado;
    int cantHasta18 = 0;
    int cantDe19a35 = 0;
    int cantMayor35 = 0;

    estado = indicadorEstado(persona, CANTIDAD_ELEMENTOS, 1);

    system("cls");
    printf("\n********** GRAFICO DE EDADES **********\n");

    if(estado != 1)
    {
        printf("\nNo hay registros cargados. Nada para mostrar.\n\n");
        system("pause");
    }
    else
    {
        for(i = 0; i < CANTIDAD_ELEMENTOS; i++)
        {
            if(persona[i].edad > 0 && persona[i].edad <= 18)
                cantHasta18++;

            else if(persona[i].edad >= 19 && persona[i].edad <= 35)
                cantDe19a35++;

            else if(persona[i].edad > 0 && persona[i].edad > 35)
                cantMayor35++;
        }

        graficoDeBarras(cantHasta18, cantDe19a35, cantMayor35);
    }
}
