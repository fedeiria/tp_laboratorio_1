#ifndef __ARRAYLIST
#define __ARRAYLIST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ArrayList{
    int size;
    void **pElements;
    int reservedSize;

    int     (*add)();
    int     (*len)();
    int     (*contains)();
    int     (*set)();
    int     (*remove)();
    int     (*clear)();
    int     (*push)();
    int     (*indexOf)();
    int     (*isEmpty)();
    void*   (*get)();
    void*   (*pop)();
    int     (*containsAll)();
    int     (*sort)();
    struct ArrayList* (*clone)();
    struct ArrayList* (*subList)();
    int     (*deleteArrayList)();

}typedef ArrayList;

#endif // __ARRAYLIST

/**
 * \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList *value Return (NULL) if Error [if can't allocate memory]
 *                               - (pointer to new arrayList) if Ok
 */
ArrayList* al_newArrayList(void);

/**
 * \brief Add an element to arrayList and if is necessary resize the array
 * \param ArrayList *this Pointer to arrayList
 * \param void *pElement Pointer to element
 * \return int value Return (-1) if Error [this or pElement are NULL pointer]
 *                         - (0) if Ok
 */
int al_add(ArrayList *this, void *pElement);

/**
 * \brief Delete arrayList
 * \param ArrayList *this Pointer to arrayList
 * \return int value Return (-1) if Error [this is NULL pointer] - (0) if Ok
 */
int al_deleteArrayList(ArrayList *this);

/**
 * \brief Delete arrayList
 * \param ArrayList *this Pointer to arrayList
 * \return int value Return length of array or (-1) if Error [this is NULL pointer]
 */
int al_len(ArrayList *this);

/**
 * \brief Get an element by index
 * \param ArrayList *this Pointer to arrayList
 * \param int index Index of the element
 * \return void *value Return (NULL) if Error [this is NULL pointer or invalid index]
 *                          - (Pointer to element) if Ok
 */
void *al_get(ArrayList *this, int index);

/**
 * \brief Find if this contains at least one element pElement
 * \param ArrayList *this Pointer to arrayList
 * \param void *pElement Pointer to element
 * \return int value Return (-1) if Error [this or pElement are NULL pointer]
 *                         - (0) if Ok but not found a element
 *                         - (1) if this list contains at least one element pElement
 */
int al_contains(ArrayList *this, void *pElement);

/**
 * \brief Set a element in this at index position
 * \param ArrayList *this Pointer to arrayList
 * \param int index Index of the element
 * \param void *pElement Pointer to element
 * \return int value Return (-1) if Error [this or pElement are NULL pointer or invalid index]
 *                         - (0) if Ok
 */
int al_set(ArrayList *this, int index, void *pElement);

/**
 * \brief Remove an element by index
 * \param ArrayList *this Pointer to arrayList
 * \param int index Index of the element
 * \return int value Return (-1) if Error [this is NULL pointer or invalid index]
 *                         - (0) if Ok
 */
int al_remove(ArrayList *this, int index);

/**
 * \brief Removes all of the elements from this list
 * \param ArrayList *this Pointer to arrayList
 * \return int value Return (-1) if Error [this is NULL pointer]
 *                         - (0) if Ok
 */
int al_clear(ArrayList *this);

/**
 * \brief Returns an array containing all of the elements in this list in proper sequence
 * \param ArrayList *this Pointer to arrayList
 * \return ArrayList *value Return (NULL) if Error [this is NULL pointer]
 *                               - (New array) if Ok
 */
ArrayList *al_clone(ArrayList *this);

/**
 * \brief Inserts the element at the specified position
 * \param ArrayList *this Pointer to arrayList
 * \param int index Index of the element
 * \param void *pElement Pointer to element
 * \return int value Return (-1) if Error [this or pElement are NULL pointer or invalid index]
 *                         - (0) if Ok
 */
int al_push(ArrayList *this, int index, void *pElement);

/**
 * \brief Returns the index of the first occurrence of the specified element
 * \param ArrayList *this Pointer to arrayList
 * \param void *pElement Pointer to element
 * \return int value Return (-1) if Error [this or pElement are NULL pointer]
 *                        - (index to element) if Ok
 */
int al_indexOf(ArrayList *this, void *pElement);

/**
 * \brief Returns true if this list contains no elements.
 * \param ArrayList *this Pointer to arrayList
 * \return int value Return (-1) if Error [this is NULL pointer]
 *                         - (0) if Not Empty
 *                         - (1) if is Empty
 */
int al_isEmpty(ArrayList *this);

/**
 * \brief Remove the item at the given position in the list, and return it.
 * \param ArrayList *this Pointer to arrayList
 * \param int Index index of the element
 * \return void *value Return (NULL) if Error [this is NULL pointer or invalid index]
 *                          - (element pointer) if Ok
 */
void *al_pop(ArrayList *this, int index);

/**
 * \brief Returns a new arrayList with a portion of pList between the specified
 *                               from Index, inclusive, and to Index, exclusive.
 * \param ArrayList *this Pointer to arrayList
 * \param int from Initial index of the element (inclusive)
 * \param int to Final index of the element (exclusive)
 * \return ArrayList *value Return (NULL) if Error [this is NULL pointer or invalid 'from' or invalid 'to']
 *                               - (pointer to new array) if Ok
 */
ArrayList *al_subList(ArrayList *this, int from, int to);

/**
 * \brief Returns true if this list contains all of the elements of this2
 * \param ArrayList *this Pointer to arrayList
 * \param ArrayList *this2 Pointer to arrayList
 * \return int value Return (-1) if Error [this or this2 are NULL pointer]
 *                         - (0) if Not contains All
 *                         - (1) if is contains All
 */
int al_containsAll(ArrayList *this, ArrayList *this2);

/**
 * \brief Sorts objects of list, use compare pFunc
 * \param ArrayList *pFunc Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to function to compare elements of arrayList
 * \param int order [1] indicate UP - [0] indicate DOWN
 * \return int value Return (-1) if Error [this or pFunc are NULL pointer]
 *                         - (0) if ok
 */
int al_sort(ArrayList *this, int (*pFunc)(void*, void*), int order);

/**
 * \brief Increment the number of elements in this in AL_INCREMENT elements.
 * \param ArrayList *this Pointer to arrayList
 * \return int value Return (-1) if Error [this is NULL pointer or if can't allocate memory]
 *                         - (0) if ok
 */
int resizeUp(ArrayList *this);

/**
 * \brief Expand an array list
 * \param ArrayList *this Pointer to arrayList
 * \param int index Index of the element
 * \return int value Return (-1) if Error [this is NULL pointer or invalid index]
 *                         - (0) if Ok
 */
int expand(ArrayList *this, int index);

/**
 * \brief Contract an array list
 * \param ArrayList *this Pointer to arrayList
 * \param int index Index of the element
 * \return int value Return (-1) if Error [this is NULL pointer or invalid index]
 *                         - (0) if Ok
 */
int contract(ArrayList *this, int index);

// Private functions
int resizeUp(ArrayList* pList);
int expand(ArrayList* pList, int index);
int contract(ArrayList* pList, int index);
//___________________
