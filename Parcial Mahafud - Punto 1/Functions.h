#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

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

/** \brief Prints a message that receives by para, expects a string, upper and lower cases, spaces and apostrophes
 *         admitted. Validates and in case of success it gets associated to the string provided by param and returns 1.
 *
 * \param Message to print, asking the user to enter a string.
 * \param String where the input data is going to get saved.
 * \param Maximum number of characters that the string allows.
 * \return Returns 1 in case of success, and the string gets saved.
 *
 */
void getAlphabeticalString (char[], char[],int);

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

/** \brief Prints a message and expects for an email-formatted string. Validates and saves the string in the param string.
 *
 * \param Message to print.
 * \param String to save the email on.
 * \return Returns 1 for success.
 *
 */
int getEmail (char message[],char string[],int maxLen);

/** \brief Expects f/m. Validates (Admits upper and lower case) and returns F for 'f' y M for 'm'.
 *
 * \return int Returns F for 'f' and M for 'm'.
 *
 */
char getSex();

/** \brief Prints a message that receives from param, asks for a string of chars that only accepts numbers,
 *         validates, casts the string into an int and returns it (Only positive values admitted).
 *
 * \param char[] message to print, asking for the int.
 * \return int Returns the numeric string entered by the user as an int value.
 *
 */
int getPositiveInt(char[]);

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

/** \brief Checks the existence of an element by its ID.
 *
 * \param Structure to search on.
 * \param Lenght of the structure.
 * \param ID of the element to search for.
 * \return Returns 1 if the element does exist or 0 if it does not.
 *
 */
int checkTeamExistence (sTeam* list,int len,int id);


/** \brief Checks the existence of an element by its ID.
 *
 * \param Structure to search on.
 * \param Lenght of the structure.
 * \param ID of the element to search for.
 * \return Returns 1 if the element does exist or 0 if it does not.
 *
 */
int checkRefereeExistence (sReferee* list,int len,int id);
