#include "Functions.h"
#include "Teams.h"

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

#ifndef PLAYERS_H
#define PLAYERS_H
#define PLAYERS 330
typedef struct
{
    int code;
    char lastName[31];
    char name[31];
    int teamCode;
    char sex;
    sDate birthDate;
    int isEmpty;
}sPlayer;
#endif // PLAYERS_H

/**\brief add in an existing list of Elements the values received as parameters
*         in the first empty position.
*
* \param list sStruct* Struct to add de element.
* \param list sStruct* Struct to check existance on.
* \param len int Lenght of the first struct.
* \param len int Lenght of the second struct.
* \param id int Id for the element to be added.
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int addPlayer(sPlayer* list,sTeam* teamList, int lenP,int lenT, int id);

/** \brief Sort the elements by a string value and matching strings by a secondary int value.
 *
 * \param list sStruct* Struct to sort.
 * \param len int Number of indexes.
 * \param order int 1 for ascendant order, 0 for descendant.
 * \return int -1 if wrong parameters received.
 *
 */
int sortPlayersByStringAndInt(sPlayer* list, int len, int order);

/** \brief Prints a categories tab of the Elements using the same order than the function printAnElement.
 *
 * \return Void.
 *
 */
void printTab ();

/** \brief print the content of Elements array
*
* \param list sStruct*
* \param length int
* \return int
*
*/
int printPlayers(sPlayer* list, int length);

/** \brief Prints an Element's data by index number.
 *
 * \param Struct* Array.
 * \param Number of index of the element to print.
 * \return Returns -1 when the index is not found or it is associated to an isEmpty (erased) element.
 *         in case of success, returns the index.
 *
 */
int printAPlayer (sPlayer* list, int i);

/** \brief To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array.
*
* \param list sStruct* Pointer to array of Elements
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPlayers(sPlayer* list, int len);

/** \brief Function with testing purpose only.
 *
 * \param Struct *Array.
 * \return Void
 *
 */
void hardcodePlayers (sPlayer* list);

/** \brief Goes over all the array checking if isEmpty==1. In case of true in EVERY element, returns 1. If not, returns 0.
 *
 * \param Struct* Array.
 * \param int Number of indexes.
 * \return Returns 1 if it's all empty, 0 if not.
 *
 */
int checkAllPlayersEmpty (sPlayer* list, int len);

/** \brief Deletes an element from an array.
 *
 * \param list sTeam* Array to delete an element from.
 * \param len int Length of the array.
 * \return void
 *
 */
void deletePlayer(sPlayer* list,int len);


/** \brief Prints all players by their team
 *
 * \param player sPlayer* Array players
 * \param team sTeam* Array teams
 * \param lenP int Length of array players
 * \param lenT int Length of array teams
 * \return void
 *
 */
void printAllPlayersByTeam(sPlayer* player,sTeam* team,int lenP,int lenT);
