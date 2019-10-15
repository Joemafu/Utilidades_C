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

}sReferee;
#endif // REFEREES_H

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

/** \brief Function with testing purpose only.
 *
 * \param Struct *Array.
 * \return Void
 *
 */
void hardcodeReferees (sReferee* list);

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
int addReferee(sReferee* list, int len, int id);

