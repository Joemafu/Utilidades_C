#include "Functions.h"

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

/** \brief To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array.
*
* \param list sStruct* Pointer to array of Elements
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initTeams(sTeam* list, int len);

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
int addTeam(sTeam*, int len, int id);

/** \brief Sort the elements by a string value and matching strings by a secondary int value.
 *
 * \param list sStruct* Struct to sort.
 * \param len int Number of indexes.
 * \param order int 1 for ascendant order, 0 for descendant.
 * \return int -1 if wrong parameters received.
 *
 */
int sortTeamsByStringAndInt(sTeam* list, int len, int order);

/** \brief print the content of Elements array
*
* \param list sStruct*
* \param length int
* \return int
*
*/
int printAllTeams(sTeam* list, int length);

/** \brief Prints a categories tab of the Elements using the same order than the function printAnElement.
 *
 * \return Void.
 *
 */
void printTeamTab();

/** \brief Prints an Element's data by index number.
 *
 * \param Struct* Array.
 * \param Number of index of the element to print.
 * \return Returns -1 when the index is not found or it is associated to an isEmpty (erased) element.
 *         in case of success, returns the index.
 *
 */
int printATeam (sTeam* list, int i);

/** \brief Function with testing purpose only.
 *
 * \param Struct *Array.
 * \return Void
 *
 */
void hardcodeTeams (sTeam* list);

/** \brief Allows to modify any value but code of an element of an sTeam array.
 *
 * \param list sTeam* Array that contains the element to modify.
 * \param len int Length of the array.
 * \return void
 *
 */
void modifyTeam(sTeam* list,int len);

/** \brief Deletes an element from an array.
 *
 * \param list sTeam* Array to delete an element from.
 * \param len int Length of the array.
 * \return void
 *
 */
void deleteTeam(sTeam* list,int len);

/** \brief Goes over all the array checking if isEmpty==1. In case of true in EVERY element, returns 1. If not, returns 0.
 *
 * \param Struct* Array.
 * \param int Number of indexes.
 * \return Returns 1 if it's all empty, 0 if not.
 *
 */
int checkAllTeamsEmpty (sTeam* list, int len);


