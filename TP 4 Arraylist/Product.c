#include "Product.h"

/**
 * \brief Allocates dynamic memory for a variable of type Product
 * \param -
 * \return Pointer *value Pointer to Product with dynamic memory
 *                  - (NULL) If error [if can't allocate memory]
 */
Product *product_new(void)
{
    Product *value = NULL;

    value = malloc(sizeof(Product));

    if(value == NULL)
    {
        printf("No hay espacio en memoria RAM.\n");
        exit(0);
    }

    return value;
}

/**
 * \brief Set a field of structure Product
 * \param Product *this Pointer to structure Product
 * \return int value 0 If successfully, -1 Error
 */
void product_setCode(ArrayList *pArrayList, Product *this)
{
    int flag;
    int auxCode;

    if(this != NULL)
    {
        do{
            flag = 0;
            getValidInt("\nIngrese el codigo para el producto: ", "\nERROR! El codigo debe ser numerico.\n", "\nERROR!, Solo se permiten valores entre 1 y 5000.\n", &auxCode, 1, 5000, 5);

            if(product_checkCode(pArrayList, this, auxCode))
                flag = 1;

        }while(flag == 1);

        this->code = auxCode;
    }
    else
    {
        printf("\nError!, no hay espacio en memoria RAM.\n\n");
        system("pause");
        exit(0);
    }
}

/**
 * \brief Verifies if the product code to add already exists in the list
 * \param ArrayList *pArrayList Pointer to ArrayList
 * \param Product *pProduct Pointer to Product
 * \param int code Value to check
 * \return int value Return - (1) if code already exists
 *                          - (0) if Ok
 */
int product_checkCode(ArrayList *pArrayList, Product *pProduct, int code)
{
    int i;
    int value = 0;

    for(i = 0; i < al_len(pArrayList); i++)
    {
        pProduct = al_get(pArrayList, i);

        if(pProduct->code == code)
        {
            printf("\nEl codigo ya existe.\n");
            value = 1;
            break;
        }
    }

    return value;
}

/**
 * \brief Obtains the data of a field of the structure Product
 * \param Product *this Pointer to structure Product
 * \return int value Data of a field of the structure, -1 Error
 */
int product_getCode(Product *this)
{
    int value = -1;

    if(this != NULL)
        value = this->code;

    return value;
}

/**
 * \brief Set a field of structure Product
 * \param Product *this Pointer to structure Product
 * \return int value 0 If successfully, -1 Error
 */
void product_setDescription(Product *this)
{
    char auxDescription[MAX_CHAR];

    if(this != NULL)
    {
        getValidAlphanumeric("\nIngrese descripcion del producto: ", "\nERROR! Caracter/es invalido/s.\n", "\nValor excedido! Solo se permite un maximo de 30 caracteres.\n", auxDescription, 31, 5);
        strcpy(this->description, auxDescription);
    }
    else
    {
        printf("\nError!, no hay espacio en memoria RAM.\n\n");
        system("pause");
        exit(0);
    }
}

/**
 * \brief Obtains the data of the field structure Product
 * \param Product *this Pointer to structure Product
 * \return char *value Pointer with the data of the field of the structure - [NULL] If error
 */
char *product_getDescription(Product *this)
{
    char *value = NULL;

    if(this != NULL)
        value = this->description;

    return value;
}

/**
 * \brief Set a field of structure Product
 * \param Product *this Pointer to the structure Product
 * \return int value 0 If successfully, -1 Error
 */
void product_setPrice(Product *this)
{
    float auxPrice;

    if(this != NULL)
    {
        getValidFloat("\nIngrese el precio del producto: ", "\nERROR! El precio debe ser numerico.\n", "\nERROR! El precio debe ser mayor a 0 (cero) y menor a 50000.\n", &auxPrice, 0.01, 50000.00, 5);
        this->price = auxPrice;
    }
    else
    {
        printf("\nError!, no hay espacio en memoria RAM.\n\n");
        system("pause");
        exit(0);
    }
}

/**
 * \brief Obtains the data of the field structure Product
 * \param Product *this Pointer to the structure Product
 * \return int value Data of a field of the structure, -1 Error
 */
int product_getPrice(Product *this)
{
    int value = -1;

    if(this != NULL)
        value = this->price;

    return value;
}

/**
 * \brief Compare the field price of the structure Product
 * \param void *productA Pointer to the structure Product
 * \param void *productB Pointer to the structure Product
 * \return int value 1 If productA is greater than productB, 0 If productA is less than productB
 *         -1 If productA or productB are NULL
 */
int product_comparePrice(void *productA, void *productB)
{
    int value = -1;

    if(productA != NULL && productB != NULL)
    {
        if(((Product*)productA)->price > ((Product*)productB)->price)
            value = 1;

        if(((Product*)productA)->price < ((Product*)productB)->price)
            value = 0;
    }

    return value;
}

/**
 * \brief Compare the field code of the structure Product
 * \param void *productA Pointer to the structure Product
 * \param void *productB Pointer to the structure Product
 * \return int value 1 If productA is greater than productB, 0 If productA is less than productB
 *         -1 If productA or productB are NULL
 */
int product_compareCode(void *productA, void *productB)
{
    int value = -1;

    if(productA != NULL && productB != NULL)
    {
        if(((Product*)productA)->code > ((Product*)productB)->code)
            value = 1;

        if(((Product*)productA)->code < ((Product*)productB)->code)
            value = 0;
    }

    return value;
}

/**
 * \brief Compare the field description of the structure Product
 * \param void *productA Pointer to the structure Product
 * \param void *productB Pointer to the structure Product
 * \return int value 1 If productA is greater than productB, 0 If productA is less than productB
 *         -1 If productA or productB are NULL
 */
int product_compareDescription(Product *productA, Product *productB)
{
    int value = -1;

    if(productA != NULL && productB != NULL)
    {
        if(strcmp(((void*)productA->description), ((void*)productB->description)) > 0)
            value = 1;

        if(strcmp(((void*)productA->description), ((void*)productB->description)) < 0)
            value = 0;
    }

    return value;
}

/**
 * \brief Prints a list with the values of the fields of the Product structure
 * \param Product *this Pointer to the structure product
 * \return void
 */
void product_print(Product *this)
{
    if(this != NULL)
    {
        printf("\n*************||| LISTA |||**************\n");
        printf("\nDescripcion: %s\n\nPrecio: %.2f\n\nCodigo: %d\n", this->description, this->price, this->code);
        printf("\n----------------------------------------\n\n");
    }
    else
    {
        printf("\nError!, no hay espacio en memoria RAM.\n\n");
        system("pause");
        exit(0);
    }
}

/**
 * \brief Shows a menu with options
 * \param void
 * \return int option Returns the value entered by the user
 */
int menu(void)
{
    int option;

    do{
        system("cls");
        printf("********* MENU PRINCIPAL **********\n\n");
        printf("1 - AGREGAR PRODUCTO\n");
        printf("2 - MODIFICAR DATOS DEL PRODUCTO\n");
        printf("3 - ELIMINAR PRODUCTO\n");
        printf("4 - LISTAR PRODUCTOS\n");
        printf("5 - ORDENAR PRODUCTOS\n");
        printf("6 - SALIR\n");

        getValidInt("\nIngrese opcion: ", "\nERROR! La opcion debe ser numerica.\n", "\nERROR! Seleccione una opcion entre 1 y 6.\n", &option, 1, 6, 5);

    }while(!option);

    return option;
}
