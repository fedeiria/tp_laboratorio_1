#ifndef FUNCIONES
#define FUNCIONES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIE 100
#define MAX_CHARS 31
#define MAX_CHARS_LENGTH 512
#define DATA "bin.dat"
#define URL_WEB "index.html"
#define WEB_PART_0 "<!-- Repetir esto para cada pelicula --><article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='"
#define WEB_PART_1 "'alt=''></a><h3><a href='#'>"
#define WEB_PART_2 "</a></h3><ul><li>Género:"
#define WEB_PART_3 "</li><li>Puntaje:"
#define WEB_PART_4 "</li><li>Duración:"
#define WEB_PART_5 "</li></ul><p>"
#define WEB_PART_6 "\n</p></article><!-- Repetir esto para cada pelicula →"

typedef struct{

    char titulo[MAX_CHARS];
    char genero[MAX_CHARS];
    char linkImagen[MAX_CHARS_LENGTH];
    char descripcion[MAX_CHARS_LENGTH];
    int id;
    int estado;
    int puntaje;
    int duracion;

}Movie;

int menu(void);
void inicializarArray(Movie *auxMovie, int cantidadElementos, int valor);
int indicadorEstado(Movie *auxMovie, int cantidadElementos, int valor);
int buscarEspacioLibre(Movie *auxMovie, int cantidadElementos, int valor);
int buscarPorId(Movie *auxMovie, int cantidadElementos, int valor);
void agregarPelicula(Movie *auxMovie);
void modificarPelicula(Movie *auxMovie);
void borrarPelicula(Movie *auxMovie);
void guardarDatos(Movie *auxMovie);
void cargarDatos(Movie *auxMovie);
void generarPaginaWeb(Movie *auxMovie);

#endif // FUNCIONES
