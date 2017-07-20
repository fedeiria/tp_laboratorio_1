#include "main_product.h"

/**
 * \brief Menu that allows you to add a product
 * \param ArrayList *pArrayList Pointer to ArrayList
 * \param Product *pProduct Pointer to Product
 * \return void
 */
void product_addProduct(ArrayList *pArrayList, Product *pProduct)
{
    if(pArrayList != NULL && pProduct != NULL)
    {
        system("cls");
        printf("\n******** NUEVO PRODUCTO ********\n");
        pProduct = product_new();
        product_setDescription(pProduct);
        product_setPrice(pProduct);
        product_setCode(pArrayList, pProduct);
        al_add(pArrayList, pProduct);
        printf("\n");
        system("pause");
    }
    else
    {
        system("cls");
        printf("\n******** NUEVO PRODUCTO ********\n");
        printf("\nERROR!, no hay espacio en memoria RAM.\n");
        exit(0);
    }
}

/**
 * \brief Menu that allows you to modify a product
 * \param ArrayList *pArrayList Pointer to ArrayList
 * \param Product *pProduct Pointer to Product
 * \return void
 */
void product_modifyProduct(ArrayList *pArrayList, Product *pProduct)
{
    int i;
    int flag;
    int option;
    int modifyCode;

    if(pArrayList != NULL && pProduct != NULL)
    {
        if(!al_len(pArrayList))
        {
            system("cls");
            printf("\n******** MODIFICAR PRODUCTO ********\n");
            printf("\nLa lista esta vacia. No hay productos para modificar.\n\n");
            system("pause");
        }
        else
        {
            flag = 0;
            system("cls");
            printf("\n******** MODIFICAR PRODUCTO ********\n");
            getValidInt("\nIngrese el codigo a modificar: ", "\nEl codigo debe ser numerico.\n", "\nSolo se permiten valores entre 1 y 5000.\n", &modifyCode, 1, 5000, 5);
            for(i = 0; i < al_len(pArrayList); i++)
            {
                pProduct = al_get(pArrayList, i);
                if(pProduct->code == modifyCode)
                {
                    flag = 1;
                    product_print(pProduct);
                    getValidInt("Desea modificar el producto?\n\n1 - Modificar.\n2 - No modificar.\n\nIngrese opcion: ", "\nError!, la opcion debe ser numerica. Ingrese 1 - SI | 2 - NO.\n\n", "\nError! Ingrese una opcion entre 1 y 2.\n\n", &option, 1, 2, 5);
                    if(option == 1)
                    {
                        al_set(pArrayList, i, pProduct);
                        product_setDescription(pProduct);
                        product_setPrice(pProduct);
                        product_setCode(pArrayList, pProduct);
                        printf("\nProducto modificado.\n\n");
                        system("pause");
                        break;
                    }
                    else
                    {
                        printf("\nProducto sin modificacion.\n\n");
                        system("pause");
                        break;
                    }
                }
            }
            if(flag == 0)
            {
                printf("\nNo se encontro el codigo o no existe en la lista.\n\n");
                system("pause");
            }
        }
    }
    else
    {
        system("cls");
        printf("\n******** MODIFICAR PRODUCTO ********\n");
        printf("\nERROR!, no hay espacio en memoria RAM.\n");
        exit(0);
    }
}

/**
 * \brief Menu that allows you to delete a product
 * \param ArrayList *pArrayList Pointer to ArrayList
 * \param Product *pProduct Pointer to Product
 * \return void
 */
void product_deleteProduct(ArrayList *pArrayList, Product *pProduct)
{
    int i;
    int flag;
    int option;
    int removeCode;

    if(pArrayList != NULL && pProduct != NULL)
    {
        if(!al_len(pArrayList))
        {
            system("cls");
            printf("\n******** BORRAR PRODUCTO ********\n");
            printf("\nLa lista esta vacia. No hay productos para eliminar.\n\n");
            system("pause");
        }
        else
        {
            flag = 0;
            system("cls");
            printf("\n******** BORRAR PRODUCTO ********\n");
            getValidInt("\nIngrese el codigo del producto a eliminar: ", "\nEl codigo debe ser numerico.\n", "\nSolo se permiten valores entre 1 y 5000.\n", &removeCode, 1, 5000, 5);
            for(i = 0; i < al_len(pArrayList); i++)
            {
                pProduct = al_get(pArrayList, i);
                if(pProduct->code == removeCode)
                {
                    flag = 1;
                    product_print(pProduct);
                    getValidInt("Desea eliminar el producto?\n\n1 - Eliminar.\n2 - No eliminar.\n\nIngrese opcion: ", "\nError!, solo numeros. Ingrese 1 - SI | 2 - NO\n\n", "\nError! Ingrese una opcion entre 1 y 2.\n\n", &option, 1, 2, 5);
                    if(option == 1)
                    {
                        al_remove(pArrayList, i);
                        printf("\nProducto eliminado.\n\n");
                        system("pause");
                        break;
                    }
                    else
                    {
                        printf("\nNo se han realizado cambios.\n\n");
                        system("pause");
                        break;
                    }
                }
            }
            if(flag == 0)
            {
                printf("\nNo se encontro el codigo o no existe en la lista.\n\n");
                system("pause");
            }
        }
    }
    else
    {
        system("cls");
        printf("\n******** BORRAR PRODUCTO ********\n");
        printf("\nERROR!, no hay espacio en memoria RAM.\n");
        exit(0);
    }
}

/**
 * \brief Menu that allows displaying the list of products
 * \param ArrayList *pArrayList Pointer to ArrayList
 * \param Product *pProduct Pointer to Product
 * \return void
 */
void product_listProduct(ArrayList *pArrayList, Product *pProduct)
{
    int i;

    if(pArrayList != NULL && pProduct != NULL)
    {
        if(!al_len(pArrayList))
        {
            system("cls");
            printf("\n******** LISTA PRODUCTOS ********\n");
            printf("\nLa lista esta vacia. No hay productos para mostrar.\n\n");
            system("pause");
        }
        else
        {
            system("cls");
            printf("\n******** LISTA PRODUCTOS ********\n");
            for(i = 0; i < al_len(pArrayList); i++)
            {
                pProduct = al_get(pArrayList, i);
                product_print(pProduct);
            }
            system("pause");
        }
    }
    else
    {
        system("cls");
        printf("\n******** LISTA PRODUCTOS ********\n");
        printf("\nERROR!, no hay espacio en memoria RAM.\n");
        exit(0);
    }
}

/**
 * \brief Menu that allows to order the products according to the selected option
 * \param ArrayList *pArrayList Pointer to ArrayList
 * \param Product *pProduct Pointer to Product
 * \return void
 */
void product_orderProduct(ArrayList *pArrayList, Product *pProduct)
{
    int option;

    if(pArrayList != NULL && pProduct != NULL)
    {
        if(al_len(pArrayList))
        {
            system("cls");
            printf("\n******** ORDENAR PRODUCTOS ********\n");
            printf("\nOrdenar por: ");
            printf("\n\n1 - DESCRIPCION");
            printf("\n2 - PRECIO");
            printf("\n3 - CODIGO\n");
            getValidInt("\nIngrese opcion: ", "\nERROR! La opcion debe ser numerica.\n", "\nERROR! Por favor ingrese una opcion entre 1 y 3.\n", &option, 1, 3, 5);
            if(option == 1)
            {
                al_sort(pArrayList, product_compareDescription, 1);
                printf("\nLista ordenada por descripcion.\n\n");
                system("pause");
            }
            else if(option == 2)
            {
                al_sort(pArrayList, product_comparePrice, 1);
                printf("\nLista ordenada por precio.\n\n");
                system("pause");
            }
            else
            {
                al_sort(pArrayList, product_compareCode, 1);
                printf("\nLista ordenada por codigo.\n\n");
                system("pause");
            }
        }
        else
        {
            system("cls");
            printf("\n******** ORDENAR PRODUCTOS ********\n");
            printf("\nLa lista esta vacia. No hay productos para ordenar.\n\n");
            system("pause");
        }
    }
    else
    {
        system("cls");
        printf("\n******** ORDENAR PRODUCTOS ********\n");
        printf("\nERROR!, no hay espacio en memoria RAM.\n");
        exit(0);
    }
}

/**
 * \brief Loads the data stored in the program
 * \param ArrayList *pArrayList Pointer to ArrayList
 * \param Product *pProduct Pointer to Product
 * \return void
 */
void product_loadFile(ArrayList *pArrayList, Product *pProduct)
{
    int i;
    int size;
    int length;
	FILE *file;

	file = fopen(PRODUCT_DATA, "rb");
	if(file == NULL)
	{
	    file = fopen(PRODUCT_DATA, "wb");
        if(file == NULL)
        {
            printf("ERROR!, no se pudo abrir el archivo: %s.\n", PRODUCT_DATA);
            exit(0);
        }
	}
	else
    {
        fseek(file, 0, SEEK_END);
        size = ftell(file);
        length = size / sizeof(Product);
        rewind(file);

        for(i = 0; i < length; i++)
        {
            pProduct = product_new();
            fread(pProduct, sizeof(Product), 1, file);
            al_add(pArrayList, pProduct);
        }
    }

    fclose(file);
}

/**
 * \brief Save changes made to the program
 * \param ArrayList *pArrayList Pointer to ArrayList
 * \param Product *pProduct Pointer to Product
 * \return void
 */
void product_saveFile(ArrayList *pArrayList, Product *pProduct)
{
    int i;
    int option;
    FILE *file;

    getValidInt("\nDesea guardar los cambios antes de salir?\n\n1 - Guardar.\n2 - Salir sin guardar.\n\nIngrese opcion: ", "\nERROR!, la opcion debe ser numerica.\n", "\nERROR!, opciones validas 1 o 2.\n", &option, 1, 2, 5);

    if(option == 1)
    {
        file = fopen(PRODUCT_DATA, "wb");

        if(file == NULL)
        {
            printf("\nERROR!, no se pudo abrir el archivo: %s.\n\n", PRODUCT_DATA);
            exit(0);
        }
        else
        {
            for(i = 0; i < al_len(pArrayList); i++)
            {
                pProduct = al_get(pArrayList, i);
                fwrite(pProduct, sizeof(Product), 1, file);
            }

            printf("\nCambios guardados con exito.\n\n");
            system("pause");
        }
    }
    else
    {
        printf("\nCambios sin guardar.\n\n");
        system("pause");
    }

    fclose(file);
}

/**
 * \brief Creates a text file with the information contained
 * \param ArrayList *pArrayList Pointer to the ArrayList
 * \param Product *pProduct Pointer to the struct Product
 * \return void
 */
void product_createFile(ArrayList *pArrayList, Product *pProduct)
{
    int i;
    FILE *file;

    file = fopen(PRODUCT_DATA_FILE, "w");

    if(pArrayList != NULL && pProduct != NULL)
    {
        if(file != NULL)
        {
            fprintf(file, "************ LISTA DE PRODUCTOS ************\n\n");
            fprintf(file, "DESCRIPCION\t\t\t\tPRECIO\t\tCODIGO\n\n");

            for(i = 0; i < al_len(pArrayList); i++)
            {
                pProduct = al_get(pArrayList, i);
                fprintf(file, "%s\t\t\t%-10.2f\t%d\n", pProduct->description, pProduct->price, pProduct->code);
            }
        }

        printf("\nArchivo generado con exito.\n\n");
        system("pause");
    }
    else
    {
        printf("ERROR! al crear el archivo %s.\n", PRODUCT_DATA_FILE);
        exit(0);
    }

    fclose(file);
}
