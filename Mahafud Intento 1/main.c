#include "eEquipos.h"
#include "eJugadores.h"
#include "eReferis.h"
#include "ePartido.h"
#define EQUIPOS 50

int main()
{
    int r;
    eEquipos equipos;
    int idEquipo=1;
    int option;
    initEquipos(equipos,EQUIPOS);
    do{
        option=showMenuGetOption("Seleccione una opcion:\n\n1)Alta de equipos.\n2)Listar equipos.\n3)Alta de jugadores.\n4)Listar jugadores.\n5)Alta de referi.\n6)Alta de partido.\n7)Listar partidos ordenados por fecha.\n8)Salir.\n\n",1,7);
        switch (option)
        {
        case 1:
            r=addEquipo(equipos,50,idEquipo);
            if(r==0)
            {
                showMessage("Equipo cargado con éxito.");
                idEquipo++;
            }else
            {
                showMessage("Hubo un error al cargar el equipo, verifique e intente nuevamente.")
            }
            break;
        case 2:
            sortElementsByStringAndInt(eEquipos,EQUIPOS,1);
            printEquipos(eEquipos,EQUIPOS);
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        }

    }while(option!=8);

    return 0;
}
