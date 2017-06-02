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
        printf("1 - Agregar pelicula\n");
        printf("2 - Borrar pelicula\n");
        printf("3 - Modificar pelicula\n");
        printf("4 - Generar pagina web\n");
        printf("5 - Salir\n");

        getValidInt("\nIngrese opcion: ", "\nERROR!, la opcion debe ser numerica.\n", "\nERROR!, Elija una opcion entre 1 y 5.\n", &opcion, 1, 5, 100);

    }while(!opcion);

    return opcion;
}

/**
 * \brief Inicializa un array con el valor recibido
 * \param Movie *auxMovie Es el array a ser inicializado
 * \param cantidadElementos indica la longitud del array
 * \param valor El valor a ser cargado en cada posicion del array
 * \return void
 */
void inicializarArray(Movie *auxMovie, int cantidadElementos, int valor)
{
    int i;

    for(i = 0; i < cantidadElementos; i++)
    {
        auxMovie[i].estado = valor;
        auxMovie[i].id = valor;
    }
}

/**
 * \brief Realiza una verificacion en el campo estado y devuelve un valor
 * \param Movie *auxMovie Es el array en el cual se trabaja
 * \param cantidadElementos Indica la longitud del array
 * \param valor Dato que se utiliza para realizar la verificacion
 * \return flag 1 si el campo estado contiene un valor distinto de cero (0), 0 si no hay cambios
 */
int indicadorEstado(Movie *auxMovie, int cantidadElementos, int valor)
{
    int i;
    int flag = 0;

    for(i = 0; i < cantidadElementos; i++)
    {
        if(auxMovie[i].estado == valor)
            flag = 1;
    }
    return flag;
}

/**
 * \brief Busca un espacio libre en un array para permitir el ingreso de datos
 * \param Movie auxMovie Es el array en el cual se busca
 * \param cantidadElementos indica la longitud del array
 * \param valor El valor a buscar en los elementos del array
 * \return auxiliar i Si encuentra un lugar libre, auxiliar -1 si no lo encuentra
 */
int buscarEspacioLibre(Movie *auxMovie, int cantidadElementos, int valor)
{
    int i;
    int auxiliar = -1;

    for(i = 0; i < cantidadElementos; i++)
    {
        if(auxMovie[i].estado == valor)
        {
            auxiliar = i;
            break;
        }
    }
    return auxiliar;
}

/**
 * \brief Obtiene el indice que coincide con el ID pasado por paramentro
 * \param Movie *auxMovie Es el array en el cual se busca
 * \param cantidadElementos Indica la longitud del array
 * \param valor Es el valor a buscar en los elementos del array
 * \return auxiliar i El indice donde se encuentra el elemento que coincide con el valor pasado por parametro, auxiliar -1 si no lo encuentra
 */
int buscarPorId(Movie *auxMovie, int cantidadElementos, int valor)
{
    int i;
    int auxiliar = -1;

    for(i = 0; i < cantidadElementos; i++)
    {
        if(auxMovie[i].id == valor)
        {
            auxiliar = i;
            break;
        }
    }
    return auxiliar;
}

/**
 * \brief Permite el ingreso de datos y realizar el alta de una pelicula
 * \param Movie *auxMovie Array en el cual se ingresan los datos
 * \return void
 */
void agregarPelicula(Movie *auxMovie)
{
    char auxTitulo[MAX_CHARS];
    char auxGenero[MAX_CHARS];
    char auxDescripcion[MAX_CHARS_LENGTH];
    int flag;
    int auxId;
    int lugarLibre;
    int auxPuntaje;
    int auxDuracion;

    lugarLibre = buscarEspacioLibre(auxMovie, MAX_MOVIE, 0);

    if(lugarLibre == -1)
    {
        system("cls");
        printf("\n********** AGREGAR PELICULA **********\n\n");
        printf("No hay lugares libres.\n");
    }
    else
    {
        system("cls");
        printf("\n********** AGREGAR PELICULA **********\n\n");

        do{
            flag = 0;
            getValidInt("Ingrese ID para la pelicula: ", "\nERROR!, El ID debe ser numerico.\n\n", "\nERROR ID valido entre 1 y 1000.\n\n", &auxId, 1, 1000, 10);
            if(buscarPorId(auxMovie, MAX_MOVIE, auxId) != -1)
            {
                printf("\nEl ID: %d ya existe.\n\n", auxId);
                flag = 1;
            }
        }while(flag == 1);

        auxMovie[lugarLibre].id = auxId;

        getValidAlphanumeric("\nIngrese nombre de la pelicula: ", "\nERROR!, solo se aceptan letras y numeros.\n", "\nERROR!, el titulo debe contener un minimo de 2 caracteres y un maximo de 30 caracteres.\n", auxTitulo, 1, 31, 10);
        strcpy(auxMovie[lugarLibre].titulo, auxTitulo);

        getValidString("\nIngrese genero: ", "\nERROR!, solo se aceptan letras.\n", "\nERROR!, el campo debe contener un minimo de 2 caracteres y un maximo de 30 caracteres.\n", auxGenero, 2, 31, 10);
        strcpy(auxMovie[lugarLibre].genero, auxGenero);

        getValidAlphanumeric("\nIngrese descripcion: ", "\nERROR!, ingrese solo letras y numeros.\n\n", "\nERROR!, se permite un minimo de 5 caracteres y un maximo de 150.\n", auxDescripcion, 5, 150, 10);
        strcpy(auxMovie[lugarLibre].descripcion, auxDescripcion);

        getValidInt("\nIngrese puntaje: ", "\nERROR!, el campo debe ser numerico.\n", "\nERROR!, puntaje valido: 1 a 10.\n", &auxPuntaje, 1, 10, 10);
        auxMovie[lugarLibre].puntaje = auxPuntaje;

        getValidInt("\nIngrese duracion: ", "\nERROR!, el campo debe ser numerico.\n", "\nERROR!, la opcion debe ser mayor a 0 y menor a 240.\n", &auxDuracion, 1, 240, 10);
        auxMovie[lugarLibre].duracion = auxDuracion;

        printf("\nIngrese link de imagen de la pelicula: ");
        fflush(stdin);
        gets(auxMovie[lugarLibre].linkImagen);

        auxMovie[lugarLibre].estado = 1;
    }

    printf("\n");
    system("pause");
}

/**
 * \brief Permite realizar una modificacion de una pelicula a traves del ingreso del ID
 * \param Movie *auxMovie Array en el cual se realiza la modificacion
 * \return void
 */
void modificarPelicula(Movie *auxMovie)
{
    char auxTitulo[MAX_CHARS];
    char auxGenero[MAX_CHARS];
    char auxDescripcion[MAX_CHARS_LENGTH];
    int auxId;
    int estado;
    int respuesta;
    int busquedaId;
    int auxPuntaje;
    int auxDuracion;

    system("cls");
    printf("\n********** MODIFICAR PELICULA **********\n\n");

    do{
        estado = indicadorEstado(auxMovie, MAX_MOVIE, 1);

        if(estado != 1)
        {
            printf("No hay registros cargados.\n\n");
            break;
        }

        getValidInt("Ingrese ID de la pelicula a modificar: ", "\nERROR!, el ID debe ser numerico.\n\n", "\nERROR de longitud, ID valido: 1 a 1000.\n\n", &auxId, 1, 1001, 10);

        busquedaId = buscarPorId(auxMovie, MAX_MOVIE, auxId);

        if(busquedaId == -1)
        {
            printf("\nNo se encontro el ID.\n\n");
            system("pause");
        }
        else
        {
            printf("\n****** DATOS DE LA PELICULA ******\n");
            printf("\nID: %d\nTitulo: %s\nGenero: %s\nDescripcion: %s\nPuntaje: %d\nDuracion: %d\n", auxMovie[busquedaId].id, auxMovie[busquedaId].titulo, auxMovie[busquedaId].genero, auxMovie[busquedaId].descripcion, auxMovie[busquedaId].puntaje, auxMovie[busquedaId].duracion);

            getValidAlphanumeric("\nIngrese nombre de la pelicula: ", "\nERROR!, solo se aceptan letras y numeros.\n", "\nERROR!, el titulo debe contener un minimo de 2 caracteres y un maximo de 30 caracteres.\n", auxTitulo, 1, 31, 10);
            strcpy(auxMovie[busquedaId].titulo, auxTitulo);

            getValidString("\nIngrese genero: ", "\nERROR!, solo se aceptan letras.\n", "\nERROR!, el campo debe contener un minimo de 2 caracteres y un maximo de 30 caracteres.\n", auxGenero, 2, 31, 10);
            strcpy(auxMovie[busquedaId].genero, auxGenero);

            getValidAlphanumeric("\nIngrese descripcion: ", "\nERROR!, ingrese solo letras y numeros.\n\n", "\nERROR!, se permite un minimo de 5 caracteres y un maximo de 150.\n", auxDescripcion, 5, 150, 10);
            strcpy(auxMovie[busquedaId].descripcion, auxDescripcion);

            getValidInt("\nIngrese puntaje: ", "\nERROR!, el campo debe ser numerico.\n", "\nERROR!, puntaje valido: 1 a 10.\n", &auxPuntaje, 1, 10, 10);
            auxMovie[busquedaId].puntaje = auxPuntaje;

            getValidInt("\nIngrese duracion: ", "\nERROR!, el campo debe ser numerico.\n", "\nERROR!, la opcion debe ser mayor a 0 y menor a 240.\n", &auxDuracion, 1, 240, 10);
            auxMovie[busquedaId].duracion = auxDuracion;

            printf("\nIngrese link de imagen de la pelicula: ");
            fflush(stdin);
            gets(auxMovie[busquedaId].linkImagen);

            printf("\nPelicula modificada.\n\n");
            system("pause");
        }

        system("cls");
        printf("\n********** MODIFICAR PELICULA **********\n");
        getValidInt("\nDesea modificar otra pelicula?\n\n1 - si\n\n2 - no\n\nIngrese opcion: ", "\nERROR!, la opcion debe ser numerica: 1 - si | 2 - no\n\n", "\nERROR!, responda solamente 'si' | 'no'.\n\n", &respuesta, 1, 3, 100);
        printf("\n");

    }while(respuesta == 1);

    system("pause");
}

/**
 * \brief Permite realizar una baja logica de una pelicula a traves del ingreso del ID
 * \param Movie *auxMovie Array en el cual se realiza la baja logica
 * \return void
 */
void borrarPelicula(Movie *auxMovie)
{
    int auxId;
    int estado;
    int respuesta;
    int busquedaId;
    int confirmacion;

    system("cls");
    printf("\n********** BORRAR PELICULA **********\n\n");

    do{
        estado = indicadorEstado(auxMovie, MAX_MOVIE, 1);

        if(estado != 1)
        {
            printf("No hay registros cargados.\n\n");
            break;
        }

        getValidInt("Ingrese ID a dar de baja: ", "\nERROR!, el ID debe ser numerico.\n\n", "\nERROR de longitud de ID, ID valido 1 a 1000.\n\n", &auxId, 1, 1001, 10);

        busquedaId = buscarPorId(auxMovie, MAX_MOVIE, auxId);

        if(busquedaId == -1)
        {
            printf("\nNo se encontro el ID.\n\n");
            system("pause");
        }
        else
        {
            printf("\n****** DATOS DE LA PELICULA ******\n");
            printf("\nID: %d\nTitulo: %s\nGenero: %s\nDescripcion: %s\nPuntaje: %d\nDuracion: %d\n", auxMovie[busquedaId].id, auxMovie[busquedaId].titulo, auxMovie[busquedaId].genero, auxMovie[busquedaId].descripcion, auxMovie[busquedaId].puntaje, auxMovie[busquedaId].duracion);
            getValidInt("\nDesea eliminar la pelicula? \n\n1 - si\n\n2 - no\n\nIngrese opcion: ", "\nERROR!, la opcion debe ser numerica: 1 - si | 2 - no\n\n", "\nERROR!, responda solamente 'si' | 'no'.\n\n", &confirmacion, 1, 3, 100);
            if(confirmacion == 1)
            {
                auxMovie[busquedaId].estado = 0;
                auxMovie[busquedaId].id = 0;
                printf("\nPelicula eliminada.\n\n");
                system("pause");
            }
            else
            {
                printf("\nAccion cancelada.\n\n");
                system("pause");
            }
        }

        system("cls");
        printf("\n********** BORRAR PELICULA **********\n");
        getValidInt("\nDesea buscar / borrar otra pelicula?\n\n1 - si\n\n2 - no\n\nIngrese opcion: ", "\nERROR!, la opcion debe ser numerica: 1 - si | 2 - no\n\n", "\nERROR!, responda solamente 'si' | 'no'.\n\n", &respuesta, 1, 3, 100);
        printf("\n");

    }while(respuesta == 1);

    system("pause");
}

/**
 * \brief Realiza el guardado de los datos introducidos en el programa antes de salir
 * \param Movie *auxMovie Array en el cual se realiza el guardado de los datos
 * \return void
 */
void guardarDatos(Movie *auxMovie)
{
    int guardar;
    FILE *pfile;

    getValidInt("\nDesea guardar los cambios?\n\n1 - SI\n2 - NO\n\nIngrese opcion: ", "\nERROR!, la opcion debe ser numerica.\n", "\nERROR!, ingrese solo 1 o 2.\n", &guardar, 1, 2, 10);

    if(guardar == 1)
    {
        pfile = fopen("bin.dat", "wb");

        if(pfile == NULL)
        {
            printf("ERROR!, no se pudo abrir el fichero.\n");
            system("pause");
        }
        else
        {
            fwrite(auxMovie, sizeof(Movie), MAX_MOVIE, pfile);
            fclose(pfile);
            printf("\nDatos guardados con exito.\n\n");
            system("pause");
        }
    }
    else if(guardar == 2)
    {
        printf("\nCambios sin guardar.\n\n");
        system("pause");
    }
}

/**
 * \brief Realiza la carga de datos al iniciar el programa
 * \param Movie *auxMovie Array en el cual se realiza la carga de datos
 * \return void
 */
void cargarDatos(Movie *auxMovie)
{
    FILE *pFile;

    pFile = fopen("bin.dat", "rb");

    if(pFile == NULL)
    {
        pFile = fopen("bin.dat", "wb");

        if(pFile == NULL)
        {
            printf("ERROR!, el archivo %s no pudo ser abierto.\n\n", DATA);
            system("pause");
        }
    }
    else
    {
        fread(auxMovie, sizeof(Movie), MAX_MOVIE, pFile);
    }

    fclose(pFile);
}

/**
 * \brief Genera una pagina web con los datos de las peliculas almacenadas en el programa
 * \param Movie *auxMovie Array en el cual se trabaja
 * \return void
 */
void generarPaginaWeb(Movie *auxMovie)
{
    int i;
    FILE *fileWeb;

    fileWeb = fopen(URL_WEB, "w");

    if(fileWeb == NULL)
    {
        printf("\nError al abrir el archivo %s.\n\n", URL_WEB);
        system("pause");
    }
    else
    {
        for(i = 0; i < MAX_MOVIE; i++)
        {
            if(auxMovie[i].estado == 1)
            {
                fprintf(fileWeb, "%s", WEB_PART_0);
                fprintf(fileWeb, "%s", auxMovie[i].linkImagen);
                fprintf(fileWeb, "%s", WEB_PART_1);
                fprintf(fileWeb, "%s", auxMovie[i].titulo);
                fprintf(fileWeb, "%s", WEB_PART_2);
                fprintf(fileWeb, "%s", auxMovie[i].genero);
                fprintf(fileWeb, "%s", WEB_PART_3);
                fprintf(fileWeb, "%d", auxMovie[i].puntaje);
                fprintf(fileWeb, "%s", WEB_PART_4);
                fprintf(fileWeb, "%d", auxMovie[i].duracion);
                fprintf(fileWeb, "%s", WEB_PART_5);
                fprintf(fileWeb, "%s", auxMovie[i].descripcion);
                fprintf(fileWeb, "%s", WEB_PART_6);
            }
        }

        fwrite(auxMovie, sizeof(Movie), MAX_MOVIE, fileWeb);
        printf("\nPagina web creada con exito.\n\n");
        system("pause");
    }

    fclose(fileWeb);
}
