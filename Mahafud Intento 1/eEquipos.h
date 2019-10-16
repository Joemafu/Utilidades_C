#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"


typedef struct
{
    int codigo;
    char nombre[51];
    char localidad[33];
    int isEmpty;
}eEquipos;

/**\brief add in an existing list of Elements the values received as parameters
*         in the first empty position.
*
* \param list sStruct*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int addEquipo(eEquipos*, int len, int id);

/** \brief To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array.
*
* \param list sStruct* Pointer to array of Elements
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEquipos(eEquipos* list, int len);

/** \brief Sort the elements by a string value and matching strings by a secondary int value.
 *
 * \param list sStruct* Struct to sort.
 * \param len int Number of indexes.
 * \param order int 1 for ascendant order, 0 for descendant.
 * \return int -1 if wrong parameters received.
 *
 */
int sortElementsByString(eEquipos*, int len, int order);


/** \brief print the content of Elements array
*
* \param list sStruct*
* \param length int
* \return int
*
*/
int printEquipos(eEquipos*, int length);

/** \brief Prints an Element's data by index number.
 *
 * \param Struct* Array.
 * \param Number of index of the element to print.
 * \return Returns -1 when the index is not found or it is associated to an isEmpty (erased) element.
 *         in case of success, returns the index.
 *
 */
int printAnEquipo (eEquipos*, int);

/** \brief Prints a categories tab of the Elements using the same order than the function printAnElement.
 *
 * \return Void.
 *
 */
void printTabEquipos();
