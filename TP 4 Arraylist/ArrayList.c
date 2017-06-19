#include "ArrayList.h"

// funciones privadas
int resizeUp(ArrayList *this);
int expand(ArrayList *this, int index);
int contract(ArrayList *this, int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/**
 * \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList *value Return (NULL) if Error [if can't allocate memory]
 *                               - (pointer to new arrayList) if Ok
 */
ArrayList *al_newArrayList(void)
{
    ArrayList *this;
    ArrayList *value = NULL;
    void *pElements;
    this = (ArrayList*)malloc(sizeof(ArrayList));

    if(this != NULL)
    {
        pElements = malloc(sizeof(void*) * AL_INITIAL_VALUE);
        if(pElements != NULL)
        {
            this->size = 0;
            this->pElements = pElements;
            this->reservedSize = AL_INITIAL_VALUE;
            this->add = al_add;
            this->len = al_len;
            this->set = al_set;
            this->remove = al_remove;
            this->clear = al_clear;
            this->clone = al_clone;
            this->get = al_get;
            this->contains = al_contains;
            this->push = al_push;
            this->indexOf = al_indexOf;
            this->isEmpty = al_isEmpty;
            this->pop = al_pop;
            this->subList = al_subList;
            this->containsAll = al_containsAll;
            this->deleteArrayList = al_deleteArrayList;
            this->sort = al_sort;
            value = this;
        }
        else
        {
            free(this);
        }
    }

    return value;
}

/**
 * \brief Add an element to arrayList and if is necessary resize the array
 * \param ArrayList *this Pointer to arrayList
 * \param void *pElement Pointer to element
 * \return int value Return (-1) if Error [this or pElement are NULL pointer]
 *                         - (0) if Ok
 */
int al_add(ArrayList *this, void *pElement)
{
    int value = -1;

    if(this != NULL && pElement != NULL)
    {
        if(this->size == this->reservedSize)
        {
            resizeUp(this);
            this->pElements[this->size] = pElement;
            this->size++;
            value = 0;
        }
        else
        {
            this->pElements[this->size] = pElement;
            this->size++;
            value = 0;
        }
    }

    return value;
}

/**
 * \brief Delete arrayList
 * \param ArrayList *this Pointer to arrayList
 * \return int value Return (-1) if Error [this is NULL pointer] - (0) if Ok
 */
int al_deleteArrayList(ArrayList *this)
{
    int value = -1;

    if(this != NULL)
    {
        free(this->pElements);
        free(this);
        value = 0;
    }

    return value;
}

/**
 * \brief Delete arrayList
 * \param ArrayList *this Pointer to arrayList
 * \return int value Return length of array or (-1) if Error [this is NULL pointer]
 */
int al_len(ArrayList *this)
{
    int value = -1;

    if(this != NULL)
        value = this->size;

    return value;
}

/**
 * \brief Get an element by index
 * \param ArrayList *this Pointer to arrayList
 * \param int index Index of the element
 * \return void *value Return (NULL) if Error [this is NULL pointer or invalid index]
 *                          - (Pointer to element) if Ok
 */
void *al_get(ArrayList *this, int index)
{
    void *value = NULL;

    if(this != NULL && index >= 0 && index < this->size)
            value = this->pElements[index];

    return value;
}

/**
 * \brief Find if this contains at least one element pElement
 * \param ArrayList *this Pointer to arrayList
 * \param void *pElement Pointer to element
 * \return int value Return (-1) if Error [this or pElement are NULL pointer]
 *                         - (0) if Ok but not found a element
 *                         - (1) if this list contains at least one element pElement
 */
int al_contains(ArrayList *this, void *pElement)
{
    int i;
    int value = -1;

    if(this != NULL && pElement != NULL)
    {
        for(i = 0; i < this->size; i++)
        {
            if(this->pElements[i] == pElement)
            {
                value = 1;
                break;
            }
            else
            {
                value = 0;
            }
        }
    }

    return value;
}

/**
 * \brief Set a element in this at index position
 * \param ArrayList *this Pointer to arrayList
 * \param int index Index of the element
 * \param void *pElement Pointer to element
 * \return int value Return (-1) if Error [this or pElement are NULL pointer or invalid index]
 *                         - (0) if Ok
 */
int al_set(ArrayList *this, int index, void *pElement)
{
    int value = -1;

    if(this != NULL && pElement != NULL)
    {
        if(index >= 0 && index < this->size)
        {
            this->pElements[index] = pElement;
            value = 0;
        }
    }

    return value;
}

/**
 * \brief Remove an element by index
 * \param ArrayList *this Pointer to arrayList
 * \param int index Index of the element
 * \return int value Return (-1) if Error [this is NULL pointer or invalid index]
 *                         - (0) if Ok
 */
int al_remove(ArrayList *this, int index)
{
    int i;
    int value = -1;

    if(this != NULL && index >= 0 && index < this->size)
    {
        for(i = index; i < this->size - 1; i++)
        {
            this->pElements[i] = this->pElements[i + 1];
        }
        this->size--;
        value = 0;
    }

    return value;
}

/**
 * \brief Removes all of the elements from this list
 * \param ArrayList *this Pointer to arrayList
 * \return int value Return (-1) if Error [this is NULL pointer]
 *                         - (0) if Ok
 */
int al_clear(ArrayList *this)
{
    int i;
    int value = -1;

    if(this != NULL)
    {
        for(i = 0; i < this->reservedSize; i++)
        {
            free(this->pElements[i]);
        }
        this->size = 0;
        value = 0;
    }

    return value;
}

/**
 * \brief Returns an array containing all of the elements in this list in proper sequence
 * \param ArrayList *this Pointer to arrayList
 * \return ArrayList *value Return (NULL) if Error [this is NULL pointer]
 *                               - (New array) if Ok
 */
ArrayList *al_clone(ArrayList *this)
{
    int i;
    ArrayList *value = NULL;

    if(this != NULL)
    {
        value = al_newArrayList();
        if(value != NULL)
        {
            for(i = 0; i < this->size; i++)
            {
                al_add(value, al_get(this, i));
            }
        }
    }

    return value;
}

/**
 * \brief Inserts the element at the specified position
 * \param ArrayList *this Pointer to arrayList
 * \param int index Index of the element
 * \param void *pElement Pointer to element
 * \return int value Return (-1) if Error [this or pElement are NULL pointer or invalid index]
 *                         - (0) if Ok
 */
int al_push(ArrayList *this, int index, void *pElement)
{
    int i;
    int value = -1;
    void *aux = NULL;

    if(this != NULL && pElement != NULL)
    {
        if(index >= 0 && index <= this->size)
        {
            if(this->size == this->reservedSize)
            {
                aux = realloc(this->pElements, sizeof(void*) * (this->size + 1));
                if(aux != NULL)
                {
                    this->pElements = aux;
                    this->reservedSize = (this->size + 1);
                }
                for(i = index; i < this->size - 1; i++)
                {
                    this->pElements[i + 1] = this->pElements[i];
                }
                this->pElements[index] = pElement;
                this->size++;
            }
            else
            {
                for(i = index; i < this->size - 1; i++)
                {
                    this->pElements[i + 1] = this->pElements[i];
                }
                this->pElements[index] = pElement;
                this->size++;
            }
        }
        value = 0;
    }

    return value;
}

/**
 * \brief Returns the index of the first occurrence of the specified element
 * \param ArrayList *this Pointer to arrayList
 * \param void *pElement Pointer to element
 * \return int value Return (-1) if Error [this or pElement are NULL pointer]
 *                        - (index to element) if Ok
 */
int al_indexOf(ArrayList *this, void *pElement)
{
    int i;
    int value = -1;

    if(this != NULL && pElement != NULL)
    {
        for(i = 0; i < this->size; i++)
        {
            if(this->pElements[i] == pElement)
            {
                value = i;
                break;
            }
        }
    }

    return value;
}

/**
 * \brief Returns true if this list contains no elements.
 * \param ArrayList *this Pointer to arrayList
 * \return int value Return (-1) if Error [this is NULL pointer]
 *                         - (0) if Not Empty
 *                         - (1) if is Empty
 */
int al_isEmpty(ArrayList *this)
{
    int value = -1;

    if(this != NULL)
    {
        if(this->size == 0)
            value = 1;
        else
            value = 0;
    }

    return value;
}

/**
 * \brief Remove the item at the given position in the list, and return it.
 * \param ArrayList *this Pointer to arrayList
 * \param int Index index of the element
 * \return void *value Return (NULL) if Error [this is NULL pointer or invalid index]
 *                          - (element pointer) if Ok
 */
void *al_pop(ArrayList *this, int index)
{
    void *value = NULL;

    if(this != NULL && index >= 0 && index < this->size)
    {
        value = al_get(this, index);
        al_remove(this, index);
    }

    return value;
}

/**
 * \brief Returns a new arrayList with a portion of pList between the specified
 *                               from Index, inclusive, and to Index, exclusive.
 * \param ArrayList *this Pointer to arrayList
 * \param int from Initial index of the element (inclusive)
 * \param int to Final index of the element (exclusive)
 * \return ArrayList *value Return (NULL) if Error [this is NULL pointer or invalid 'from' or invalid 'to']
 *                               - (pointer to new array) if Ok
 */
ArrayList *al_subList(ArrayList *this, int from, int to)
{
    int i;
    ArrayList *value = NULL;

    if(this != NULL && from >= 0 && from < to && to <= this->size)
    {
        value = al_newArrayList();
        if(value != NULL)
        {
            for(i = from; i <= to; i++)
            {
                al_add(value, al_get(this, i));
            }
        }
    }

    return value;
}

/**
 * \brief Returns true if this list contains all of the elements of this2
 * \param ArrayList *this Pointer to arrayList
 * \param ArrayList *this2 Pointer to arrayList
 * \return int value Return (-1) if Error [this or this2 are NULL pointer]
 *                         - (0) if Not contains All
 *                         - (1) if is contains All
 */
int al_containsAll(ArrayList *this, ArrayList *this2)
{
    int i;
    int value = -1;

    if(this != NULL && this2 != NULL)
    {
        for(i = 0; i < this->size; i++)
        {
            if(this->pElements[i] == this2->pElements[i])
                value = 1;
            else
                value = 0;
        }
    }

    return value;
}

/**
 * \brief Sorts objects of list, use compare pFunc
 * \param ArrayList *pFunc Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to function to compare elements of arrayList
 * \param int order [1] indicate UP - [0] indicate DOWN
 * \return int value Return (-1) if Error [this or pFunc are NULL pointer]
 *                         - (0) if ok
 */
int al_sort(ArrayList *this, int (*pFunc)(void*, void*), int order)
{
    int i, j;
    int value = -1;
    void *aux = NULL;

    if(this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
        for(i = 0; i < this->size - 1; i++)
        {
            for(j = i + 1; j < this->size; j++)
            {
                if(pFunc(this->pElements[i], this->pElements[j]) > 0 && order == 1)
                {
                    aux = this->pElements[i];
                    this->pElements[i] = this->pElements[j];
                    this->pElements[j] = aux;
                }
                if(pFunc(this->pElements[i], this->pElements[j]) < 0 && order == 0)
                {
                    aux = this->pElements[i];
                    this->pElements[i] = this->pElements[j];
                    this->pElements[j] = aux;
                }
            }
        }
        value = 0;
    }

    return value;
}

/**
 * \brief Increment the number of elements in this in AL_INCREMENT elements.
 * \param ArrayList *this Pointer to arrayList
 * \return int value Return (-1) if Error [this is NULL pointer or if can't allocate memory]
 *                         - (0) if ok
 */
int resizeUp(ArrayList *this)
{
    int value = -1;
    void *aux = NULL;

    if(this != NULL)
    {
        aux = realloc(this->pElements, sizeof(void*) * (this->size + AL_INCREMENT));

        if(aux != NULL)
        {
            this->pElements = aux;
            this->reservedSize = (this->size + AL_INCREMENT);
            this->size++;
        }
        value = 0;
    }

    return value;
}

/**
 * \brief Expand an array list
 * \param ArrayList *this Pointer to arrayList
 * \param int index Index of the element
 * \return int value Return (-1) if Error [this is NULL pointer or invalid index]
 *                         - (0) if Ok
 */
int expand(ArrayList *this, int index)
{
    int value = -1;
    void *aux = NULL;

    if(this != NULL && index > 0 && index < this->size && this->size == this->reservedSize)
    {
        aux = realloc(this->pElements, sizeof(void*) * (this->size + index));
        if(aux != NULL)
        {
            this->pElements = aux;
            this->reservedSize = (this->size + index);
            value = 0;
        }
    }

    return value;
}

/**
 * \brief Contract an array list
 * \param ArrayList *this Pointer to arrayList
 * \param int index Index of the element
 * \return int value Return (-1) if Error [this is NULL pointer or invalid index]
 *                         - (0) if Ok
 */
int contract(ArrayList *this, int index)
{
    int value = -1;
    void *aux = NULL;

    if(this != NULL && index > 0 && index < this->size)
    {
        aux = realloc(this->pElements, sizeof(void*) * (this->size - index));
        if(aux != NULL)
        {
            this->pElements = aux;
            this->size = (this->size - index);
            this->reservedSize = (this->reservedSize - index);
            value = 0;
        }
    }

    return value;
}
