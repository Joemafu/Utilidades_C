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
        option=showMenuGetOption("Seleccione una opcion:\n\n\
     1) Alta de equipos.\n\
     2) Listar equipos.\n\
     3) Alta de jugadores.\n\
     4) Listar jugadores.\n\
     5) Alta de referi.\n\
     6) Alta de partido.\n\
     7) Listar partidos ordenados por fecha.\n\
     8) Salir.\n\n",1,8);
        switch (option)
        {
        case 1:
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
        case 2:
            sortTeamsByStringAndInt(team,TEAMS,1);
            printAllTeams(team,TEAMS);
            break;
        case 3:
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
        case 4:
            sortPlayersByStringAndInt(player,PLAYERS,1);
            printPlayers(player,PLAYERS);
            break;
        case 5:
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
        case 6:
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
        case 7:
            sortMatchesByDate(match,MATCHES,1);
            printAllMatches(match,MATCHES);
            break;
        case 8:
            break;
        }

    }while(option!=8);
    return 0;
}
