#include "Headers.h"

int main()
{
    ArrayList *pArrayList = al_newArrayList();
    Product *pProduct;

    product_loadFile(pArrayList, pProduct);

    char seguir = 's';
    int opcion;

    while(seguir == 's')
    {
        opcion = menu();

        switch(opcion)
        {
        case 1:
            product_addProduct(pArrayList, pProduct);
            break;
        case 2:
            product_modifyProduct(pArrayList, pProduct);
            break;
        case 3:
            product_deleteProduct(pArrayList, pProduct);
            break;
        case 4:
            product_listProduct(pArrayList, pProduct);
            break;
        case 5:
            product_orderProduct(pArrayList, pProduct);
            break;
        case 6:
            product_saveFile(pArrayList, pProduct);
            seguir = 'n';
            break;
        }
    }

    al_deleteArrayList(pArrayList);

    return 0;
}
