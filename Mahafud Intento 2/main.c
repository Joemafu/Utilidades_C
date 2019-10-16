#include <stdio.h>
#include <stdlib.h>
#include "Equipo.h"

int main()
{

    int idEquipo=1;
    int option;
    eEquipo equipo[5];
    initElements(equipo,EQUIPOS);
    do{
        option=showMenuGetOption("1)Alta equipo.\n2)lista equipos.\n",1,8);
        switch (option)
        {
        case 1:
            addElement(equipo,EQUIPOS,idEquipo);

            break;
        case 2:
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
    }while (option!=8);

    return 0;
}
