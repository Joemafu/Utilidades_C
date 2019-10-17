#include "Functions.h"

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

/**\brief Adds in an existing list of Elements the values received as parameters
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
void addTeam(sTeam*, int len, int* id);

/** \brief Goes over all the array checking if isEmpty==1. In case of true in EVERY element, returns 1. If not, returns 0.
 *
 * \param Struct* Array.
 * \param int Number of indexes.
 * \return Returns 1 if it's all empty, 0 if not.
 *
 */
int checkAllTeamsEmpty (sTeam* list, int len);

/** \brief Goes over all the array checking if there is at least two elements with isEmpty==0. In case of true, returns 1. If not, returns 0.
 *
 * \param Struct* Array.
 * \param int Number of indexes.
 * \return Returns 1 if there is at least 2 not-empty elements, 0 if not.
 *
 */
int checkAtLeastTwoTeams (sTeam* list, int len);

/** \brief Checks the existence of an element by its ID.
 *
 * \param Structure to search on.
 * \param Lenght of the structure.
 * \param ID of the element to search for.
 * \return Returns 1 if the element does exist or 0 if it does not.
 *
 */
int checkTeamExistence (sTeam* list,int len,int id);

/** \brief Deletes an element from an array.
 *
 * \param list sTeam* Array to delete an element from.
 * \param len int Length of the array.
 * \return void
 *
 */
void deleteTeam(sTeam* list,int len);

/** \brief Calculates the average age of a team based on their players.
 *
 * \param team sTeam* Array team
 * \param player sPlayer* Array player
 * \param lenT int Length of array team
 * \param lenP int Length of array player
 * \return void
 *
 */
void getTeamsAverageAge (sTeam* team,sPlayer* player,int lenT,int lenP);

/** \brief Function with testing purpose only.
 *
 * \param Struct *Array.
 * \return Void
 *
 */
void hardcodeTeams (sTeam* list);

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

/** \brief Allows to modify any value but code of an element of an sTeam array.
 *
 * \param list sTeam* Array that contains the element to modify.
 * \param len int Length of the array.
 * \return void
 *
 */
void modifyTeam(sTeam* list,int len);

/** \brief print the content of Elements array
*
* \param list sStruct*
* \param length int
* \return int
*
*/
int printAllTeams(sTeam* list, int length);

/** \brief Sorts all teams alphabetically and prints them in that order.
 *
 * \param list sTeam* Array of teams.
 * \param len int Length of the array
 * \return void
 *
 */
void printAllTeamsByName(sTeam* list,int len);

/** \brief Prints an Element's data by index number.
 *
 * \param Struct* Array.
 * \param Number of index of the element to print.
 * \return Returns -1 when the index is not found or it is associated to an isEmpty (erased) element.
 *         in case of success, returns the index.
 *
 */
int printATeam (sTeam* list, int i);

/** \brief Searches for the longest name/s in an array and prints each result.
 *
 * \param Array to search on.
 * \param length of the array.
 * \return void
 *
 */
void printLongestTeam (sTeam* list,int len);

/** \brief Searches an array for an ID that receives by param, and prints the value name of the element.
 *
 * \param Array to search on.
 * \param Length of the array.
 * \param Code or ID of the element to search for.
 * \return
 *
 */
void printTeamNameByCode (sTeam* list, int lenT, int code);

/** \brief Calculates the average age of a team based on their players and sort the array ascendantly by that value,
 *         then prints the results.
 *
 * \param team sTeam* Array team
 * \param player sPlayer* Array player
 * \param lenT int Length of array team
 * \param lenP int Length of array player
 * \return void
 *
 */
void printTeamsByAverageAge (sTeam* team,sPlayer* player,int lenT,int lenP);

/** \brief Prints a categories tab of the Elements using the same order than the function printAnElement.
 *
 * \return Void.
 *
 */
void printTeamTab();

/** \brief Calculates the average age of a team based on their players and sort the array ascendantly by that value.
 *
 * \param team sTeam* Array team
 * \param player sPlayer* Array player
 * \param lenT int Length of array team
 * \param lenP int Length of array player
 * \return void
 *
 */
void sortTeamsByAverageAge(sTeam* team,sPlayer* player,int lenT,int lenP);


/** \brief Sort the elements by an int value.
 *
 * \param list sStruct* Struct to sort.
 * \param len int Number of indexes.
 * \return int -1 if wrong parameters received.
 *
 */
int sortTeamsByCode(sTeam* list, int len);

/** \brief Sort the elements by a string.
 *
 * \param list sStruct* Struct to sort.
 * \param len int Number of indexes.
 * \return int -1 if wrong parameters received.
 *
 */
int sortTeamsByName(sTeam* list, int len);
