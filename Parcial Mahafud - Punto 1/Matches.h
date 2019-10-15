#include "Functions.h"

#ifndef DATE_H
#define DATE_H
typedef struct
{
    int day;
    int month;
    int year;

}sDate;

#endif // DATE_H

#ifndef TEAMS_H
#define TEAMS_H
#define TEAMS 30
typedef struct
{
    int code;
    char name[51];
    char locality[33];
    int isEmpty;
}sTeam;
#endif // TEAMS_H

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
}sMatch;
#endif // MATCHES_H

/** \brief To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array.
*
* \param list sStruct* Pointer to array of Elements
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initMatches(sMatch* list, int len);

/** \brief Function with testing purpose only.
 *
 * \param Struct *Array.
 * \return Void
 *
 */
void hardcodeMatches (sMatch* list);

/**\brief add in an existing list of Elements the values received as parameters
*         in the first empty position.
*
* \param list sMatch* Struct to add an element on.
* \param list sTeam* Struct sTeam to validate existance of a team with.
* \param list sReferee* Struct sReferee to validate existance of a referee with.
* \param lenM int length on sMatch struct.
* \param lenM int length on sTeam struct.
* \param lenM int length on sReferee struct.
* \param id int Id of the match to be added
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int addMatch(sMatch* matchList,sTeam* teamList,sReferee* refereeList, int lenM,int lenT,int lenR, int id);

/** \brief Sort the elements by an int value, another int value and another int value.
 *
 * \param list sStruct* Struct to sort.
 * \param len int Number of indexes.
 * \param order int 1 for ascendant order, 0 for descendant.
 * \return int -1 if wrong parameters received.
 *
 */
int sortMatchesByDate(sMatch* list, int len, int order);

/** \brief print the content of Elements array
*
* \param list sStruct*
* \param length int
* \return int
*
*/
int printAllMatches(sMatch* list, int length);

/** \brief Prints a categories tab of the Elements using the same order than the function printAnElement.
 *
 * \return Void.
 *
 */
void printMatchTab();

/** \brief Prints an Element's data by index number.
 *
 * \param Struct* Array.
 * \param Number of index of the element to print.
 * \return Returns -1 when the index is not found or it is associated to an isEmpty (erased) element.
 *         in case of success, returns the index.
 *
 */
int printAMatch (sMatch* list, int i);

