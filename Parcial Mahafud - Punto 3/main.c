#include "Teams.h"
#include "Players.h"
#include "Referees.h"
#include "Matches.h"

int main()
{
    int r;
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


    do{
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
     17) Salir.\n\n",1,17);



        switch (option)
        {
        case 1: ///Punto A.
            r=addTeam(team,TEAMS,teamCode);
            if(r==0)
            {
                showMessage("Equipo cargado con exito.\n\n");
                teamCode++;
            }else if (r==-1)
            {
                showMessage("Hubo un error al cargar el equipo, verifique e intente nuevamente.");
            }
            break;
        case 2: ///Punto B.
            sortTeamsByStringAndInt(team,TEAMS,1);
            printAllTeams(team,TEAMS);
            break;
        case 3: ///Punto C.
            r=addPlayer(player,team,PLAYERS,TEAMS,playerCode);
            if(r==0)
            {
                showMessage("Jugador cargado con exito.\n\n");
                playerCode++;
            }else if (r==-1)
            {
                showMessage("Hubo un error al cargar el jugador, verifique e intente nuevamente.");
            }
            break;
        case 4: ///Punto D.
            sortPlayersByStringAndInt(player,PLAYERS,1);
            printPlayers(player,PLAYERS);
            break;
        case 5: ///Punto E.
            r=addReferee(referee,REFEREES,refereeCode);
            if(r==0)
            {
                showMessage("Referi cargado con exito.\n\n");
                refereeCode++;
            }else if (r==-1)
            {
                showMessage("Hubo un error al cargar el referi, verifique e intente nuevamente.");
            }
            break;
        case 6: ///Punto F.
            r=addMatch(match,team,referee,MATCHES,TEAMS,REFEREES,matchCode);
            if(r==0)
            {
                showMessage("Partido cargado con exito.\n\n");
                refereeCode++;
            }else if (r==-1)
            {
                showMessage("Hubo un error al cargar el partido, verifique e intente nuevamente.");
            }
            break;
        case 7: ///Punto G.
            sortMatchesByDate(match,MATCHES,1);
            printAllMatches(match,MATCHES);
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

            break;
        case 16: ///Punto P.
            break;
        case 17: ///SALIR.
            break;
        }

    }while(option!=11);
    return 0;
}
