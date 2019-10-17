#include "Teams.h"
#include "Players.h"
#include "Referees.h"
#include "Matches.h"

int main()
{
    sTeam team[30];
    sPlayer player[330];
    sReferee referee[15];
    sMatch match[500];
    int teamCode=1;
    int playerCode=1;
    int refereeCode=1;
    int matchCode=1;
    int option;

    initTeams(team,TEAMS);
    initPlayers(player,PLAYERS);
    initReferees(referee,REFEREES);
    initMatches(match,MATCHES);
    hardcodeTeams(team);
    hardcodePlayers(player);
    hardcodeReferees(referee);
    hardcodeMatches(match);
    teamCode+=10;
    playerCode+=100;
    refereeCode+=6;
    matchCode+=25;

    do
    {
        system("cls");
        option=showMenuGetOption("Seleccione una opcion:\n\n\
     1) Alta de equipos.\n\
     2) Listar equipos.\n\
     3) Alta de jugadores.\n\
     4) Listar jugadores.\n\
     5) Alta de referi.\n\
     6) Alta de partido.\n\
     7) Listar partidos ordenados por fecha.\n\
     8) Modificar equipo.\n\
     9) Baja de equipo.\n\
     10) Baja de jugador.\n\
     11) Listar jugadores por equipo.\n\
     12) Informar el referi que mas partidos dirigio.\n\
     13) Buscar jugadores por nombre.\n\
     14) Informar equipo/s con nombre mas largo.\n\
     15) Equipos y referi participantes por fecha.\n\
     16) Equipos mas jovenes (en promedio).\n\
     17) Modificar equipo.\n\
     18) Listar equipos alfabeticamente.\n\
     19) Modificar jugadores.\n\
     20) Listar jugadores por sexo.\n\
     21) Listar referis con mas de 4 partidos dirigidos.\n\
     22) Listar todos los partidos ordenados por arbitro.\n\
     23) Salir.\n\
     \n\n",1,23);

        switch (option)
        {
        case 1: ///Punto A.
            addTeam(team,TEAMS,&teamCode);
            break;
        case 2: ///Punto B.
            printAllTeamsByName(team,TEAMS);
            break;
        case 3: ///Punto C.
            addPlayer(player,team,PLAYERS,TEAMS,&playerCode);
            break;
        case 4: ///Punto D.
            printPlayersByLastNameAndName(player,PLAYERS);
            break;
        case 5: ///Punto E.
            addReferee(referee,REFEREES,&refereeCode);
            break;
        case 6: ///Punto F.
            addMatch(match,team,referee,MATCHES,TEAMS,REFEREES,&matchCode);
            break;
        case 7: ///Punto G.
            printAllMatchesByDate(match,team,referee,MATCHES,TEAMS,REFEREES);
            break;
        case 8: ///Punto H.
            modifyTeam(team,TEAMS);
            break;
        case 9: ///Punto I.
            deleteTeam(team,TEAMS);
            break;
        case 10: ///Punto J.
            deletePlayer(player,PLAYERS);
            break;
        case 11: ///Punto K.
            printAllPlayersByTeam(player,team,PLAYERS,TEAMS);
            break;
        case 12: ///Punto L.
            printMostExperiencedReferee(referee,match,REFEREES,MATCHES);
            break;
        case 13: ///Punto M.
            searchPlayerByName(player,team,PLAYERS,TEAMS);
            break;
        case 14: ///Punto N.
            printLongestTeam(team,TEAMS);
            break;
        case 15: ///Punto O.
            printMatchesByDate(match,team,referee,MATCHES,TEAMS,REFEREES);
            break;
        case 16: ///Punto P.
            printTeamsByAverageAge(team,player,TEAMS,PLAYERS);
            break;
        case 17: ///Punto A2.
            modifyTeam(team,TEAMS);
            break;
        case 18: ///Punto B2.
            printAllTeamsByName(team,TEAMS);
            break;
        case 19: ///Punto C2.
            modifyPlayer(player,team,PLAYERS,TEAMS);
            break;
        case 20: ///Punto D2.
            printPlayersBySex(player,PLAYERS);
            break;
        case 21: ///Punto E2.
            printAllExperiencedReferees(referee,match,REFEREES,MATCHES);
            break;
        case 22: ///Punto F2.
            printAllMatchesByReferee(referee,match,team,REFEREES,MATCHES,TEAMS);
            break;
        case 23: ///SALIR.
            break;
        }
    }
    while(option!=17);
    return 0;
}
