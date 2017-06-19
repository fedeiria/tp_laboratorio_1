#ifndef __PRODUCT
#define __PRODUCT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayList.h"
#define MAX_CHAR 51

typedef struct{

    char description[MAX_CHAR];
    int code;
    float price;

}Product;

/**
 * \brief Allocates dynamic memory for a variable of type Product
 * \param -
 * \return Pointer *value Pointer to Product with dynamic memory
 *                  - (NULL) If error [if can't allocate memory]
 */
Product *product_new(void);

/**
 * \brief Set a field of structure Product
 * \param Product *this Pointer to structure Product
 * \return int value 0 If successfully, -1 Error
 */
void product_setCode(ArrayList *pArrayList, Product *this);

/**
 * \brief Verifies if the product code to add already exists in the list
 * \param ArrayList *pArrayList Pointer to ArrayList
 * \param Product *pProduct Pointer to Product
 * \param int code Value to check
 * \return int value Return - (1) if code already exists
 *                          - (0) if Ok
 */
int product_checkCode(ArrayList *pArrayList, Product *pProduct, int code);

/**
 * \brief Obtains the data of a field of the structure Product
 * \param Product *this Pointer to structure Product
 * \return int value Data of a field of the structure, -1 Error
 */
int product_getCode(Product *this);

/**
 * \brief Set a field of structure Product
 * \param Product *this Pointer to structure Product
 * \return int value 0 If successfully, -1 Error
 */
void product_setDescription(Product *this);

/**
 * \brief Obtains the data of the field structure Product
 * \param Product *this Pointer to structure Product
 * \return char *value Pointer with the data of the field of the structure - [NULL] If error
 */
char *product_getDescription(Product *this);

/**
 * \brief Set a field of structure Product
 * \param Product *this Pointer to the structure Product
 * \return int value 0 If successfully, -1 Error
 */
void product_setPrice(Product *this);

/**
 * \brief Obtains the data of the field structure Product
 * \param Product *this Pointer to the structure Product
 * \return int value Data of a field of the structure, -1 Error
 */
int product_getPrice(Product *this);

/**
 * \brief Compare the field price of the structure Product
 * \param void *productA Pointer to the structure Product
 * \param void *productB Pointer to the structure Product
 * \return int value 1 If productA is greater than productB, 0 If productA is less than productB
 *         -1 If productA or productB are NULL
 */
int product_comparePrice(void *productA, void *productB);

/**
 * \brief Compare the field code of the structure Product
 * \param void *productA Pointer to the structure Product
 * \param void *productB Pointer to the structure Product
 * \return int value 1 If productA is greater than productB, 0 If productA is less than productB
 *         -1 If productA or productB are NULL
 */
int product_compareCode(void *productA, void *productB);

/**
 * \brief Compare the field description of the structure Product
 * \param void *productA Pointer to the structure Product
 * \param void *productB Pointer to the structure Product
 * \return int value 1 If productA is greater than productB, 0 If productA is less than productB
 *         -1 If productA or productB are NULL
 */
int product_compareDescription(Product *productA, Product *productB);

/**
 * \brief Prints a list with the values of the fields of the Product structure
 * \param Product *this Pointer to the structure product
 * \return void
 */
void product_print(Product *this);

/**
 * \brief Shows a menu with options
 * \param void
 * \return int option Returns the value entered by the user
 */
int menu(void);

#endif // __PRODUCT
