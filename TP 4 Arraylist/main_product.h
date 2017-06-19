#ifndef __MAIN_PRODUCT
#define __MAIN_PRODUCT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Product.h"
#include "ArrayList.h"

#define PRODUCT_DATA "data.bin"

/**
 * \brief Menu that allows you to add a product
 * \param ArrayList *pArrayList Pointer to ArrayList
 * \param Product *pProduct Pointer to Product
 * \return void
 */
void product_addProduct(ArrayList *pArrayList, Product *pProduct);

/**
 * \brief Menu that allows you to modify a product
 * \param ArrayList *pArrayList Pointer to ArrayList
 * \param Product *pProduct Pointer to Product
 * \return void
 */
void product_modifyProduct(ArrayList *pArrayList, Product *pProduct);

/**
 * \brief Menu that allows you to delete a product
 * \param ArrayList *pArrayList Pointer to ArrayList
 * \param Product *pProduct Pointer to Product
 * \return void
 */
void product_deleteProduct(ArrayList *pArrayList, Product *pProduct);

/**
 * \brief Menu that allows displaying the list of products
 * \param ArrayList *pArrayList Pointer to ArrayList
 * \param Product *pProduct Pointer to Product
 * \return void
 */
void product_listProduct(ArrayList *pArrayList, Product *pProduct);

/**
 * \brief Menu that allows to order the products according to the selected option
 * \param ArrayList *pArrayList Pointer to ArrayList
 * \param Product *pProduct Pointer to Product
 * \return void
 */
void product_orderProduct(ArrayList *pArrayList, Product *pProduct);

/**
 * \brief Loads the data stored in the program
 * \param ArrayList *pArrayList Pointer to ArrayList
 * \param Product *pProduct Pointer to Product
 * \return void
 */
void product_loadFile(ArrayList *pArrayList, Product *pProduct);

/**
 * \brief Save changes made to the program
 * \param ArrayList *pArrayList Pointer to ArrayList
 * \param Product *pProduct Pointer to Product
 * \return void
 */
void product_saveFile(ArrayList *pArrayList, Product *pProduct);

#endif // __MAIN_PRODUCT
