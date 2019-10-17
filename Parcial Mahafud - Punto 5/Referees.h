#include "Functions.h"

#ifndef DATE_H
#define DATE_H
typedef struct
{
    int day;
    int month;
    int year;

} sDate;

#endif // DATE_H

#ifndef REFEREES_H
#define REFEREES_H
#define REFEREES 15
typedef struct
{
    int code;
    char lastName[31];
    char name[31];
    char sex;
    char email[31];
    sDate birthDate;
    int isEmpty;

} sReferee;
#endif // REFEREES_H

#ifndef MATCHES_H
#define MATCHES_H
#define MATCHES 500
typedef struct
{
    int code;
    int visitorCode;
    int localCode;
    int refereeCode;
    sDate date;
    int isEmpty;
} sMatch;
#endif // MATCHES_H

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
void addReferee(sReferee* list, int len, int* id);

/** \brief Goes over all the array checking if isEmpty==1. In case of true in EVERY element, returns 1. If not, returns 0.
 *
 * \param Struct* Array.
 * \param int Number of indexes.
 * \return Returns 1 if it's all empty, 0 if not.
 *
 */
int checkAllRefereesEmpty (sReferee* list, int len);

/** \brief Checks the existence of an element by its ID.
 *
 * \param Structure to search on.
 * \param Lenght of the structure.
 * \param ID of the element to search for.
 * \return Returns 1 if the element does exist or 0 if it does not.
 *
 */
int checkRefereeExistence (sReferee* list,int len,int id);

/** \brief Deletes an element from an array.
 *
 * \param list sTeam* Array to delete an element from.
 * \param len int Length of the array.
 * \return void
 *
 */
void deleteReferee(sReferee* list,int len);

/** \brief Function with testing purpose only.
 *
 * \param Struct *Array.
 * \return Void
 *
 */
void hardcodeReferees (sReferee* list);

/** \brief To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array.
*
* \param list sStruct* Pointer to array of Elements
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initReferees(sReferee* list, int len);

/** \brief Prints all the sReferee elements with more than 4 sMatches elements linked on
 *
 * \param referee sReferee*
 * \param match sMatch*
 * \param lenR int
 * \param lenM int
 * \return void
 *
 */
void printAllExperiencedReferees(sReferee* referee,sMatch* match,int lenR,int lenM);

/** \brief Searches for the most experienced referee and prints his/her last name, name and de amount of matches directed.
 *
 * \param referee sReferee* Array referees
 * \param match sMatch* Array matches
 * \param lenR int Length of array referees
 * \param lenM int Length of array matches
 * \return void
 *
 */
void printMostExperiencedReferee(sReferee* referee,sMatch* match,int lenR,int lenM);

/** \brief Prints an Element's data by index number.
 *
 * \param Struct* Array.
 * \param Number of index of the element to print.
 * \return Returns -1 when the index is not found or it is associated to an isEmpty (erased) element.
 *         in case of success, returns the index.
 *
 */
int printAReferee (sReferee* list, int i);

/** \brief Prints the content of Elements array
*
* \param list sStruct*
* \param length int
* \return int
*
*/
int printReferees(sReferee* list, int len);

/** \brief Prints a categories tab of the Elements using the same order than the function printAnElement.
 *
 * \return Void.
 *
 */
void printRefereeTab();

/** \brief Searches an array for an ID that receives by param, and prints the value name of the element.
 *
 * \param Array to search on.
 * \param Length of the array.
 * \param Code or ID of the element to search for.
 * \return
 *
 */
void printRefereeNameByCode(sReferee* list, int lenT, int code);
