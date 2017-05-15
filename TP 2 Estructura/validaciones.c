#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 1024

/**
 * \brief Verifies if the received value is composed only by letters
 * \param char str String to be analyzed
 * \return 1 If value is composed only by letters - 0 If does not contain it
 */
int onlyWords(char str[])
{
    int i = 0;
    int returnAux = 1;

    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            returnAux = 0;
        i++;
    }
    return returnAux;
}

/**
 * \brief Verifies whether the received value is composed only by letters and numbers (No special characters)
 * \param char str String to be analyzed
 * \return 1 if it contains only spaces, a period, letters and numbers - 0 If it does not contain it
 */
int onlyAlphanumeric(char str[])
{
    int i = 0;
    int count = 0;
    int returnAux = 1;

    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] != '.') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            returnAux = 0;
        i++;

        if(str[i] == '.')
            count++;

        if(count > 1)
            returnAux = 0;
    }
    return returnAux;
}

/**
 * \brief Verifies whether the received value is numeric
 * \param char str String to be analyzed
 * \return 1 If the value is numerical - 0 If does not contain it
 */
int onlyNumbers(char str[])
{
    int i = 0;
    int returnAux = 1;

    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            returnAux = 0;
        i++;
    }
    return returnAux;
}

/**
 * \brief verifies whether the received value is floating numeric
 * \param char str String to be analyzed
 * \return 1 If the value is numerical - 0 If does not contain it
 */
int onlyFloatingNumbers(char str[])
{
    int i = 0;
    int count = 0;
    int returnAux = 1;

    while(str[i] != '\0')
    {
        if((str[i] < '0' || str[i] > '9') && (str[i] != '.'))
            returnAux = 0;
        i++;

        if(str[i] == '.')
            count++;

        if(count > 1)
            returnAux = 0;
    }
    return returnAux;
}

/**
 * \brief Requests a text from the user and returns it
 * \param char message The message to be shown
 * \param char input String where the message is loaded
 * \return void
 */
void getString(char message[], char input[])
{
    printf("%s", message);
    fflush(stdin);
    gets(input);
}

/**
 * \brief Requests a text from the user and returns it, check if it is composed by letters
 * \param char message The message to be shown
 * \param char input String where the message is loaded
 * \return 1 If text is composed only by letters - 0 If it is not
 */
int getStringWords(char message[], char input[])
{
    char aux[MAX_LENGTH];
    int returnAux = 0;

    getString(message, aux);

    if(onlyWords(aux))
    {
        strcpy(input, aux);
        returnAux = 1;
    }
    return returnAux;
}

/**
 * \brief Requests a text from the user and returns it, check if it is alphanumeric
 * \param char message The message to be shown
 * \param char input String where the message is loaded
 * \return 1 if text is alphanumeric - 0 if it is not
 */
int getStringAlphanumeric(char message[], char input[])
{
    char aux[MAX_LENGTH];
    int returnAux = 0;

    getString(message, aux);

    if(onlyAlphanumeric(aux))
    {
        strcpy(input, aux);
        returnAux = 1;
    }
    return returnAux;
}

/**
 * \brief Requests a text from the user and returns it, check if it is composed only by numbers
 * \param char message The message to be shown
 * \param char input String where the text is loaded
 * \return 1 If the text is composed only by numbers - 0 If it is not
 */
int getStringNumbers(char message[], char input[])
{
    char aux[MAX_LENGTH];
    int returnAux = 0;

    getString(message, aux);

    if(onlyNumbers(aux))
    {
        strcpy(input, aux);
        returnAux = 1;
    }
    return returnAux;
}

/**
 * \brief Requests a text from the user and returns it, check if it is composed only by floating numbers
 * \param char message The message to be shown
 * \param char input String where the text is loaded
 * \return 1 If the text is composed only by floating numbers - 0 If it is not
 */
int getStringFloatingNumbers(char message[], char input[])
{
    char aux[MAX_LENGTH];
    int returnAux = 0;

    getString(message, aux);

    if(onlyFloatingNumbers(aux))
    {
        strcpy(input, aux);
        returnAux = 1;
    }
    return returnAux;
}

/**
 * \brief Requests a text from the user and validates it
 * \param char requestMessage The message to be shown to the user
 * \param char errorMessage Message to be shown to the user in case of data type error
 * \param char errorMessageLength Message to be shown to the user in case of length error
 * \param char input String where the entered text will be loaded
 * \param int minLenght Minimun length limit to be checked
 * \param int maxLength Maximum length limit to be checked
 * \param int attempts Indicates the number of retries to an error
 * \return 0 If the text is composed only by letters -1 If it is not
 */
int getValidString(char requestMessage[], char errorMessage[], char errorMessageLength[], char input[], int minLength, int maxLength, int attempts)
{
    char buffer[MAX_LENGTH];
    int i;
    int returnAux = -1;

    for(i = 0; i < attempts; i++)
    {
        if (!getStringWords(requestMessage, buffer))
        {
            printf ("%s", errorMessage);
            continue;
        }
        if(strlen(buffer) <= minLength || strlen(buffer) >= maxLength)
        {
            printf ("%s", errorMessageLength);
            continue;
        }
        strcpy(input, buffer);
        returnAux = 0;
        break;
    }
    return returnAux;
}

/**
 * \brief Requests a text from the user and validate if it is alphanumeric (No special characters)
 * \param char requestMessage The message to be shown to the user
 * \param char errorMessage The message to be shown to the user in case of data type error
 * \param char errorMessageLength Message to be shown to the user in case of length error
 * \param char input String where the entered text will be loaded
 * \param int maxLength Maximum length limit to be checked
 * \param int attempts Indicates the number of retries to an error
 * \return 0 If the text is composed only by numbers and letters -1 If it is not
 */
int getValidAlphanumeric(char requestMessage[], char errorMessage[], char errorMessageLength[], char input[], int maxLength, int attempts)
{
    char buffer[MAX_LENGTH];
    int i;
    int returnAux = -1;

    for(i = 0; i < attempts; i++)
    {
        if (!getStringAlphanumeric(requestMessage, buffer))
        {
            printf ("%s", errorMessage);
            continue;
        }
        if(strlen(buffer) >= maxLength)
        {
            printf ("%s", errorMessageLength);
            continue;
        }
        strlwr(buffer);
        strcpy(input, buffer);
        returnAux = 0;
        break;
    }
    return returnAux;
}

/**
 * \brief Requests a text from the user and validates if it is integer
 * \param char requestMessage The message to be shown to the user
 * \param char errorMessage The message to be shown to the user in case of data type error
 * \param char errorMessageLength The message to be shown to the user in case of error of length
 * \param int *input Pointer to the place where the entered value will be loaded
 * \param int lowLimit The limit of the lowest number that can be accepted
 * \param int hiLimit The limit of the highest number that can be accepted
 * \param int attempts Indicates the number of retries to an error
 * \return 0 If the number is composed only by integer -1 if it is not
 */
int getValidInt(char requestMessage[], char errorMessage[], char errorMessageLength[], int *input, int lowLimit, int hiLimit, int attempts)
{
    char auxStr[MAX_LENGTH];
    int i, auxInt;
    int returnAux = -1;

    for(i = 0; i < attempts; i++)
    {
        if(!getStringNumbers(requestMessage, auxStr))
        {
            printf("%s", errorMessage);
            continue;
        }
        auxInt = atoi(auxStr);

        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf("%s", errorMessageLength);
            continue;
        }
        *input = auxInt;
        returnAux = 0;
        break;
    }
    return returnAux;
}

/**
 * \brief Requests a text from the user and validates if it is long integer
 * \param char requestMessage The message to be shown to the user
 * \param char errorMessage The message to be shown to the user in case of data type error
 * \param char errorMessageLength The message to be shown to the user in case of error of length
 * \param long int *input Pointer to the place where the entered value will be loaded
 * \param long int lowLimit The limit of the lowest number that can be accepted
 * \param long int hiLimit The limit of the highest number that can be accepted
 * \param int attempts Indicates the number of retries to an error
 * \return 0 If the number is composed only by long integer -1 if it is not
 */
int getValidLongInt(char requestMessage[], char errorMessage[], char errorMessageLength[], long int *input, long int lowLimit, long int hiLimit, int attempts)
{
    char auxStr[MAX_LENGTH];
    long int auxLongInt;
    int i, returnAux = -1;

    for(i = 0; i < attempts; i++)
    {
        if(!getStringNumbers(requestMessage, auxStr))
        {
            printf("%s", errorMessage);
            continue;
        }
        auxLongInt = atol(auxStr);

        if(auxLongInt < lowLimit || auxLongInt > hiLimit)
        {
            printf("%s", errorMessageLength);
            continue;
        }
        *input = auxLongInt;
        returnAux = 0;
        break;
    }
    return returnAux;
}

/**
 * \brief Requests a text from the user and validates if it is a floating numeric
 * \param char requestMessage The message to be shown to the user
 * \param char errorMessage The message to be shown to the user in case of data type error
 * \param char errorMessageLength The message to be shown to the user in case of error of length
 * \param float *input Pointer to the place where the entered value will be loaded
 * \param float lowLimit The limit of the lowest number that can be accepted
 * \param float hiLimit The limit of the highest number that can be accepted
 * \param int attempts Indicates the number of retries to an error
 * \return 0 If the number is composed only by floating numbers -1 if it is not
 */
int getValidFloat(char requestMessage[], char errorMessage[], char errorMessageLength[], float *input, float lowLimit, float hiLimit, int attempts)
{
    char auxStr[MAX_LENGTH];
    int i;
    int returnAux = -1;
    float auxFloat;

    for(i = 0; i < attempts; i++)
    {
        if(!getStringFloatingNumbers(requestMessage, auxStr))
        {
            printf("%s", errorMessage);
            continue;
        }
        sscanf(auxStr, "%f", &auxFloat);

        if(auxFloat < lowLimit || auxFloat > hiLimit)
        {
            printf("%s", errorMessageLength);
            continue;
        }
        *input = auxFloat;
        returnAux = 0;
        break;
    }
    return returnAux;
}

/**
 * \brief Clean the 'stdin', similar to 'fflush'
 * \param -
 * \return void
 */
void clearStdin(void)
{
    setbuf(stdin, NULL);
}
