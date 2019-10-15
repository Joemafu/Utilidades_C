#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EQUIPOS 50
typedef struct
{
    int idEquipo;
    char nombreEquipo[51];
    char localidadEquipo[33];
    int isEmpty;
}eEquipo;

/** \brief Gets an options menu as a string, minimal and maximal valid option, prints the menu and gets
 *         selected option by scanf. Validate than the option is between the values provided by \param
 *         and returns it as an int.
 *
 * \param char[] Message to print as a menu (it must include an enumerated options list).
 * \param int Minimal option accepted.
 * \param int Maximal option accepted.
 * \return int Returns -1 in error case (non valid option) - Or the option number selected in case of success.
 *
 *
 */
int showMenuGetOption(char[],int,int);


/** \brief Prints a message that receives by para, expects a string, upper and lower cases, spaces and apostrophes
 *         admitted. Validates and in case of success it gets associated to the string provided by param and returns 1.
 *
 * \param Message to print, asking the user to enter a string.
 * \param String where the input data is going to get saved.
 * \param Maximum number of characters that the string allows.
 * \return Returns 1 in case of success, and the string gets saved.
 *
 */
int getAlphabeticalString (char[], char[],int);

/** \brief Cleans the screen and prints a message followed by a pause. Then cleans the screen again.
 *
 * \param char[] Message to print.
 * \return Void.
 *
 */
void showMessage(char[]);

/**\brief add in an existing list of Elements the values received as parameters
*         in the first empty position.
*
* \param list *
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int addElement(eEquipo*, int len, int id);

/** \brief To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array.
*
* \param list sStruct* Pointer to array of Elements
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initElements(eEquipo* list, int len);
