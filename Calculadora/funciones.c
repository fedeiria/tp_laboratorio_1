#include <stdio.h>
#include <stdlib.h>

/**
 * \brief muestra un menu de opciones para calcular operaciones matematicas
 * \param valor1 recibe un numero ingresado y lo muestra en el menu
 * \param valor2 Recibe un numero ingresado y lo muestra en el menu
 * \return valor ingresado por el usuario
 */
int menu(float valor1, float valor2)
{
    int opcion;

    do{
        system("cls");
        printf("---------------- CALCULADORA ----------------\n\n");
        printf("1 - Ingresar primer operando (A = %.2f)\n", valor1);
        printf("2 - Ingresar segundo operando (B = %.2f)\n", valor2);
        printf("3 - Calcular la suma (A + B)\n");
        printf("4 - Calcular la resta (A - B)\n");
        printf("5 - Calcular la division (A / B)\n");
        printf("6 - Calcular la multiplicacion (A * B)\n");
        printf("7 - Calcular el factorial (A!)\n");
        printf("8 - Calcular todas las operaciones\n");
        printf("9 - Salir");

        printf("\n\nIngrese opcion: ");
        scanf("%d", &opcion);

        }while(opcion < 1 || opcion > 9);

    return opcion;
}

/**
 * \brief solicita un numero y lo retorna
 * \return numero ingresado por el usuario
 */
float ingresoNumero(void)
{
    float operando;
    printf("\nIngrese un numero: ");
    scanf("%f", &operando);
    return operando;
}

/**
 * \brief realiza la operacion de sumar dos numeros
 * \param nro1 Parametro actual que recibe un numero
 * \param nro2 Parametro actual que recibe un numero
 * \return valor de la operacion suma
 */
float suma(float nro1, float nro2)
{
    float suma;
    suma = nro1 + nro2;
    return suma;
}

/**
 * \brief realiza la operacion de restar dos numeros
 * \param nro1 Parametro actual que recibe un numero
 * \param nro2 Parametro actual que recibe un numero
 * \return valor de la operacion resta
 */
float resta(float nro1, float nro2)
{
    float resta;
    resta = nro1 - nro2;
    return resta;
}

/**
 * \brief realiza la operacion de dividir dos numeros
 * \param nro1 Parametro actual que recibe un numero
 * \param nro2 Parametro actual que recibe un numero
 * \return valor de la operacion division
 */
float division(float nro1, float nro2)
{
    while(nro2 == 0)
    {
        printf("\nEl numero del segundo operando debe ser mayor a cero.\n");
        printf("\nReingrese numero: ");
        scanf("%f", &nro2);
    }

    float division;
    division = nro1 / nro2;
    return division;
}

/**
 * \brief realiza la operacion de multiplicar dos numeros
 * \param nro1 Parametro actual que recibe un numero
 * \param nro2 Parametro actual que recibe un numero
 * \return valor de la operacion multiplicacion
 */
float multiplicacion(float nro1, float nro2)
{
    float multiplicacion;
    multiplicacion = nro1 * nro2;
    return multiplicacion;
}

/**
 * \brief realiza la operacion de multiplicar un numero por su antecedente hasta el numero 1
 * \param nro1 Parametro actual que recibe un numero
 * \return valor de la operacion factorial
 */
float factorial(float nro1)
{
    float i, acumulador = 1;

    while(nro1 == 0)
    {
        printf("\nEl numero del operando debe ser mayor a cero.\n");
        printf("\nReingrese numero: ");
        scanf("%f", &nro1);
    }

    for(i = nro1; i > 0; i --)
    {
        acumulador *= i;
    }

    return acumulador;
}

/**
 * \brief muestra los resultados de todas las operaciones de la calculadora
 * \param nro1 Parametro actual que recibe un numero
 * \param nro2 Parametro actual que recibe un numero
 * \return 0 si la funcion es exitosa
 */
float todosCalculos(float nro1, float nro2)
{
    float i, acumulador = 1;
    float suma, resta, division, multiplicacion;

    // suma
    suma = nro1 + nro2;
    printf("\nSuma: %.2f\n\n", suma);

    // resta
    resta = nro1 - nro2;
    printf("Resta: %.2f\n\n", resta);

    // division
    division = nro1 / nro2;
    if(nro2 == 0)
    {
        printf("Division: sin calcular, el segundo operando debe ser mayor a cero\n\n");
    }

    if(nro2 > 0)
    {
        printf("Division: %.2f\n\n", division);
    }

    // multiplicacion
    multiplicacion = nro1 * nro2;
    printf("Mutiplicacion: %.2f\n\n", multiplicacion);

    // factorial
    for(i = nro1; i > 0; i --)
    {
        acumulador *= i;
    }
    printf("Factorial (A!): %.0f\n\n", acumulador);

    return 0;
}
