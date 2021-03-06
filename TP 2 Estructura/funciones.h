#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define CANTIDAD_ELEMENTOS 5
#define LONGITUD_CADENA 51

typedef struct{

    char nombre[LONGITUD_CADENA];
    int edad;
    int estado;
    long int dni;

}EPersona;

int menu(void);
void inicializarArrayEstado(EPersona persona[], int cantidadElementos, int valor);
int indicadorEstado(EPersona persona[], int cantidadElementos, int valor);
int buscarEspacioLibre(EPersona persona[], int cantidadElementos, int valor);
int buscarPorDni(EPersona persona[], int cantidadElementos, long int valor);
void ordenarRegistro(EPersona persona[], int cantidadElementos);
void graficoDeBarras(int hasta18, int de19a35, int mayorDe35);
void agregarPersona(EPersona persona[]);
void borrarPersona(EPersona persona[]);
void imprimirLista(EPersona persona[]);
void imprimirGrafico(EPersona persona[]);

#endif // FUNCIONES_H_INCLUDED
