#include "Functions.h"
#include "Teams.h"
#include "Referees.h"

#ifndef DATE_H
#define DATE_H
typedef struct
{
    int day;
    int month;
    int year;

} sDate;

#endif // DATE_H

#ifndef TEAMS_H
#define TEAMS_H
#define TEAMS 30
typedef struct
{
    int code;
    char name[51];
    char locality[33];
    float averageAge;
    int isEmpty;
} sTeam;
#endif // TEAMS_H

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
void addMatch(sMatch* matchList,sTeam* teamList,sReferee* refereeList, int lenM,int lenT,int lenR, int* id);

/** \brief Goes over all the array checking if isEmpty==1. In case of true in EVERY element, returns 1. If not, returns 0.
 *
 * \param Struct* Array.
 * \param int Number of indexes.
 * \return Returns 1 if it's all empty, 0 if not.
 *
 */
int checkAllMatchesEmpty (sMatch* list, int len);

/** \brief Checks the existence of an element by its ID.
 *
 * \param Structure to search on.
 * \param Lenght of the structure.
 * \param ID of the element to search for.
 * \return Returns 1 if the element does exist or 0 if it does not.
 *
 */
int checkMatchExistence(sMatch* list,int len,int id);

/** \brief Deletes an element from an array.
 *
 * \param list sTeam* Array to delete an element from.
 * \param len int Length of the array.
 * \return void
 *
 */
void deleteMatch(sMatch* list,sTeam* teamList, sReferee* refereeList,int len,int lenT,int lenR);

/** \brief Function with testing purpose only.
 *
 * \param Struct *Array.
 * \return Void
 *
 */
void hardcodeMatches (sMatch* list);

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

/** \brief Prints the content of Elements array
*
* \param list sStruct*
* \param length int
* \return int
*
*/
int printAllMatches(sMatch* match,sTeam* team,sReferee* referee, int lenM,int lenT,int lenR);

/** \brief Prints the content of Elements array sorted by date.
*
* \param list sStruct*
* \param length int
* \return int
*
*/
int printAllMatchesByDate(sMatch* match,sTeam* team,sReferee* referee, int lenM,int lenT,int lenR);


/** \brief Prints all the elements of an sMatch array sorted by its referee value.
 *
 * \param referee sReferee* sReferee array.
 * \param match sMatch* sMatch array.
 * \param team sTeam* sTeam array.
 * \param lenR int Length of sReferee array.
 * \param lenM int Length of sMatch array.
 * \param lenT int Length of sTeam array.
 * \return void
 *
 */
void printAllMatchesByReferee(sReferee* referee,sMatch* match,sTeam* team,int lenR,int lenM,int lenT);

/** \brief Prints an Element's data by index number.
 *
 * \param Struct* Array.
 * \param Number of index of the element to print.
 * \return Returns -1 when the index is not found or it is associated to an isEmpty (erased) element.
 *         in case of success, returns the index.
 *
 */
void printAMatch (sMatch* match,sTeam* team,sReferee* referee, int i,int lenT,int lenR);

/** \brief Asks the user for a date and searches for all the matches played that day, printing the local and visitor team involved
 *         and who was the referee.
 *
 *
 * \param match sMatch* Array of matches
 * \param team sTeam* Array of teams
 * \param referee sReferee* Array of referees
 * \param lenM int Length of array matches
 * \param lenT int Length of array teams
 * \param lenR int Length of array referees
 * \return void
 *
 */
void printMatchesByDate(sMatch* match,sTeam* team,sReferee* referee,int lenM,int lenT,int lenR);

/** \brief Prints a categories tab of the Elements using the same order than the function printAnElement.
 *
 * \return Void.
 *
 */
void printMatchTab();

/** \brief Sort the elements by an int value (year), another int value (month) and another int value (day).
 *
 * \param list sStruct* Struct to sort.
 * \param len int Number of indexes.
 * \return int -1 if wrong parameters received.
 *
 */
int sortMatchesByDate(sMatch* list, int len);


/** \brief Sort the elements by an int value (refereeCode).
 *
 * \param list sStruct* Struct to sort.
 * \param len int Number of indexes.
 * \return int -1 if wrong parameters received.
 *
 */
int sortMatchesByReferee(sMatch* list,int len);
