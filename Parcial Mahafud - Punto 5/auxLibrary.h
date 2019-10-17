#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define ELEMENTS 1000

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
    eFecha fechaNac;

} typedef sStruct;

typedef struct
{
    int idPropietario;
    char nombre[51];
    int estaVacio;
    eFecha fechaNac;
} ePropietario;

typedef struct
{
    char patente[8];
    eFecha fechaIngreso;
    int horaIngreso;
    int horaSalida;
    int idPropietario;
    int estaEstacionado;
    int isEmpty;
} eVehiculo;


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
int addElement(sStruct*, int len, int id);

/** \brief Goes over all the array checking if isEmpty==1. In case of true in EVERY element, returns 1. If not, returns 0.
 *
 * \param Struct* Array.
 * \param int Number of indexes.
 * \return Returns 1 if it's all empty, 0 if not.
 *
 */
int checkAllEmpty (sStruct*, int);

/** \brief Checks the existence of an element by its ID.
 *
 * \param Structure to search on.
 * \param Lenght of the structure.
 * \param ID of the element to search for.
 * \return Returns 1 if the element does exist or 0 if it does not.
 *
 */
int checkExistence (sStruct* list,int len,int id);

/** \brief Finds an Element by Id and returns the index position in array.
*
* \param list sStruct*
* \param len int
* \param id int
* \return Return Element index position or (-1) if [Invalid length or NULL pointer received or Element not found]
*
*/
int findElementById(sStruct* list, int len,int id);

/** \brief Finds an Element by a string value and returns the index position in array.
 *
 * \param list sStruct* Array struct to search on.
 * \param len int Length of the array.
 * \param string[] char String to search for.
 * \return int Returns Element index position or (-1) if [Invalid length or NULL pointer received or Element not found]
 *
 */
int findElementByString(sStruct* list, int len,char string[]);

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

/** \brief Prints a message that receives by param and expects a string, upper and lower cases, spaces, apostrophes and numbers
 *         admitted. Validates and in case of success it gets associated to the string provided by param and returns 1.
 *
 * \param Message to print, asking the user to enter a string.
 * \param String where the input data is going to get saved.
 * \param Maximum number of characters that the string allows.
 * \return Returns 1 in case of success, and the string gets saved.
 *
 */
int getAlphanumericalString (char message[],char string[],int maxLen);

/** \brief Expects s/n. Validates (Admits upper and lower case) and returns 1 for 's' y 0 for 'n'.
 *
 * \return int Returns 1 for 's' and 0 for 'n'.
 *
 */
int getConfirm();

/** \brief Prints a message that gets by param. and expects for a number that reresents a valid day of the month and year
 *         that getts by param. It recognizes leap-years.
 *
 * \param char[] Message to print.
 * \param int Year to validate.
 * \param int Month to validate.
 * \return
 *
 */
int getDay (char message[],int year, int month);

/** \brief Prints a message and expects for an email-formatted string. Validates and saves the string in the param string.
 *
 * \param Message to print.
 * \param String to save the email on.
 * \return Returns 1 for success.
 *
 */
int getEmail (char message[],char string[],int maxLen);

/** \brief Prints a message and expects for a float value (Positive and negative values admitted).
 *
 * \param char[] Gets the message to print.
 * \return float Returns the float value provided by the user.
 *
 */
float getFloat(char message[]);

/** \brief Prints a message that receives from param, asks for a string of chars that only accepts numbers,
 *         validates, casts the string into an int and returns it (Positive and negative values admitted).
 *
 * \param char[] message to print, asking for the int.
 * \return int Returns the numeric string entered by the user as an int value.
 *
 */
int getInt(char message[]);

/** \brief Prints a message that receives from param, asks for a string of chars that only accepts numbers,
 *         validates, casts the string into an int and returns it (Positive and negative values admitted).
 *
 * \param message[] char message to print, asking for the int.
 * \param int Min number accepted.
 * \param int Max number accepted.
 * \return int
 *
 */
int getIntMinMax(char message[],int,int);

/** \brief Prints a message and expects for a float value (Only positive values admitted).
 *
 * \param char[] Gets the message to print.
 * \return float Returns the float value provided by the user.
 *
 */
float getPositiveFloat(char[]);

/** \brief Prints a message that receives from param, asks for a string of chars that only accepts numbers,
 *         validates, casts the string into an int and returns it (Only positive values admitted).
 *
 * \param char[] message to print, asking for the int.
 * \return int Returns the numeric string entered by the user as an int value.
 *
 */
int getPositiveInt(char[]);

/** \brief Expects f/m. Validates (Admits upper and lower case) and returns F for 'f' y M for 'm'.
 *
 * \return int Returns F for 'f' and M for 'm'.
 *
 */
char getSex();

/** \brief Function with testing purpose only.
 *
 * \param Struct *Array.
 * \return Void
 *
 */
void hardcodeElements (sStruct*);

/** \brief Function with testing purpose only.
 *
 * \param Struct *Array.
 * \return Void
 *
 */
void hardcodePropietarios (sStruct*);

/** \brief Creates and prints a stat report of salaries.
 *
 * \param Struct* Array.
 * \param int Number of indexes.
 * \return Void.
 *
 */
void informSalaryStat(sStruct*, int);

/** \brief To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array.
*
* \param list sStruct* Pointer to array of Elements
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initElements(sStruct* list, int len);

/** \brief Prints an Element's data by index number.
 *
 * \param Struct* Array.
 * \param Number of index of the element to print.
 * \return Returns -1 when the index is not found or it is associated to an isEmpty (erased) element.
 *         in case of success, returns the index.
 *
 */
int printAnElement (sStruct*, int);

/** \brief print the content of Elements array
*
* \param list sStruct*
* \param length int
* \return int
*
*/
int printElements(sStruct* list, int length);

/** \brief Prints a separation mark.
 *
 * \return void
 *
 */
void printSeparation();

/** \brief Prints a categories tab of the Elements using the same order than the function printAnElement.
 *
 * \return Void.
 *
 */
void printTab ();

/** \brief Remove a Element by Id (put isEmpty Flag in 1)
*
* \param list sStruct*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a Element] - (0) if Ok
*
*/
int removeElement(sStruct* list, int len, int id);


/** \brief Searches for the element with the longest of a determinated string value.
 *
 * \param Array to search on.
 * \param Length of the array.
 * \return
 *
 */
int searchForLongestString (sStruct* list,int len);

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

/** \brief Cleans the screen and prints a message followed by a pause. Then cleans the screen again.
 *
 * \param char[] Message to print.
 * \return Void.
 *
 */
void showMessage(char[]);

/** \brief Sorts by an specific order and prints every element.
 *
 * \param list sStruct* Array to work with.
 * \param len int Length of the array.
 * \param order int 1 for Ascendant, 0 for descendant.
 * \return void
 *
 */
void sortAndPrint(sStruct* list, int len, int order);

/** \brief Sort the elements by an int value, matching int values by a string value and matching strings by another string value.
 *
 * \param list sStruct* Struct to sort.
 * \param len int Number of indexes.
 * \param order int 1 for ascendant order, 0 for descendant.
 * \return int -1 if wrong parameters received.
 *
 */
int sortElementsByIntStringAndString(sStruct* list, int len, int order);

/** \brief Sort the elements by a string value and matching strings by a secondary int value.
 *
 * \param list sStruct* Struct to sort.
 * \param len int Number of indexes.
 * \param order int 1 for ascendant order, 0 for descendant.
 * \return int -1 if wrong parameters received.
 *
 */
int sortElementsByStringAndInt(sStruct* list, int len, int order);
