#include "Teams.h"

void addTeam(sTeam* list, int len, int* id)
{
    int i;
    int end=0;
    char name[51];
    char locality[33];

    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty==1)
            {
                getAlphanumericalString("Nombre del equipo: ",name,50);
                getAlphabeticalString("Localidad: ",locality,32);
                list[i].code = *id;
                strcpy(list[i].name, name);
                strcpy(list[i].locality, locality);
                if(getConfirm()==1)
                {
                    list[i].isEmpty = 0;
                    showMessage("Equipo cargado con exito.\n\n");
                    *id=*id+1;
                    end=1;
                }
                else
                {
                    showMessage("Se cancelo la carga.\n\n");
                    end=1;
                }
                break;
            }
        }
        if(end==0)
        {
            showMessage("No es posible cargar el equipo. Espacio insuficiente.\n\n");
            end=1;
        }
    }
    if (end==0)
    {
        showMessage("Hubo un error al cargar el equipo, verifique e intente nuevamente.");
        end=1;
    }
}

int checkAllTeamsEmpty (sTeam* list, int len)
{
    int i;
    int ret=1;
    for (i=0; i<len; i++)
    {
        if(list[i].isEmpty==0)
        {
            ret=0;
            break;
        }
    }
    return ret;
}

int checkAtLeastTwoTeams (sTeam* list, int len)
{
    int i;
    int ret=0;
    int counter=0;
    for (i=0; i<len; i++)
    {
        if(list[i].isEmpty==0)
        {
            counter++;
            if(counter>1)
            {
                ret=1;
                break;
            }
        }
    }
    return ret;
}

int checkTeamExistence (sTeam* list,int len,int id)
{
    int i;
    int ret=0;

    for(i=0; i<len; i++)
    {
        if((id==list[i].code)&&(list[i].isEmpty==0))
        {
            ret=1;
        }
    }
    if(ret==0)
    {
        showMessage("El codigo ingresado no corresponde a ningun equipo.\n");
    }
    return ret;
}

void deleteTeam(sTeam* list,int len)
{
    int i;
    int id;
    int e;

    if(checkAllTeamsEmpty(list,len)==0)
    {
        do
        {
            id=getIntMinMax("Ingrese el codigo del equipo a dar de baja: ",1,len);
            e=checkTeamExistence(list,len,id);
        }
        while(e==0);

        for (i=0; i<len; i++)
        {
            if(list[i].code==id)
            {
                printf("Esta a punto de eliminar el siguiente equipo:\n\n");
                printTeamTab();
                printATeam(list,i);
                if(getConfirm()==1)
                {
                    list[i].isEmpty=1;
                    showMessage("El equipo se dio de baja con exito.\n");
                }
                else
                {
                    showMessage("Se cancelo la baja.\n");
                }
                break;
            }
        }
    }
    else
    {
        showMessage("No hay ningun equipo cargado.\n");
    }
}

void getTeamsAverageAge (sTeam* team,sPlayer* player,int lenT,int lenP)
{
    int i;
    int j;
    int counter;
    int ageAccumulator;

    for(i=0; i<lenT; i++)
    {
        if(team[i].isEmpty==0)
        {
            counter=0;
            ageAccumulator=0;
            for(j=0; j<lenP; j++)
            {
                if(player[j].isEmpty==0&&player[j].teamCode==team[i].code)
                {
                    counter++;
                    ageAccumulator+=(2019-player[j].birthDate.year);
                }

            }
            if(counter==0)
            {
                team[i].averageAge=0;
            }
            else
            {
                team[i].averageAge=(ageAccumulator/(float)counter);
            }
        }
    }
}

void hardcodeTeams (sTeam* list)
{
    int code[10]= {1,2,3,4,5,6,7,8,9,10};
    char name[10][51] = {"Cambios FC","Camboya","Dep Muy Caliente","Hacha y Birra","Bidon de Branco","Real Coholicos","Suc. Congreso","Sucursal Flores","Los Isotopos","Ornad + 4"};
    char locality[10][33] = {"Lanus","Banfield","Avellaneda","CABA","Lanus","Banfield","Avellaneda","CABA","Lanus","Banfield"};
    int i;

    for(i=0; i<10; i++)
    {
        list[i].code=code[i];
        strcpy(list[i].name,name[i]);
        strcpy(list[i].locality,locality[i]);
        list[i].isEmpty=0;
    }
    return;
}

int initTeams(sTeam* list, int len)
{
    int i;
    int ret;
    if(list!=NULL && len>0)
    {
        for (i=0; i<len; i++)
        {
            list[i].isEmpty=1;
        }
        ret=0;
    }
    else
    {
        showMessage("Fallo la inicialización.\n");
        ret=-1;
    }
    return ret;
}

void modifyTeam(sTeam* list,int len)
{
    int i;
    int id;
    int e;
    int option;
    char auxName[51];
    char auxLocality[33];

    if(checkAllTeamsEmpty(list,len)==0)
    {
        do
        {
            id=getIntMinMax("Ingrese el codigo del equipo a modificar: ",1,len);
            e=checkTeamExistence(list,len,id);
        }
        while(e==0);

        for (i=0; i<len; i++)
        {
            if(list[i].code==id)
            {

                printTeamTab();
                printATeam(list,i);
                option=showMenuGetOption("\nSeleccione el campo a modificar:\n\n1) Nombre.\n2) Localidad.\n3) Cancelar.\n\n",1,3);
                switch(option)
                {
                case 1:
                    system("cls");
                    getAlphanumericalString("Ingrese el nuevo nombre: ",auxName,50);
                    option=3;
                    if(getConfirm()==1)
                    {
                        strcpy(list[i].name,auxName);
                        system("cls");
                        printf("\nEl nombre ha sido modificado. Se muestran los datos actuales.\n");
                        printTeamTab();
                        printATeam(list,i);
                        system("pause");
                    }
                    else
                    {
                        showMessage("Se cancelo la modificacion.\n");
                    }
                    break;
                case 2:
                    system("cls");
                    getAlphabeticalString("Ingrese la nueva localidad: ",auxLocality,32);
                    option=3;
                    if(getConfirm()==1)
                    {
                        strcpy(list[i].locality,auxLocality);
                        system("cls");
                        printf("\nLa localidad ha sido modificada. Se muestran los datos actuales.\n");
                        printTeamTab();
                        printATeam(list,i);
                        system("pause");
                    }
                    else
                    {
                        showMessage("Se cancelo la modificacion.\n");
                    }
                    break;
                case 3:
                    break;
                }
                break;
            }
        }
    }
    else
    {
        showMessage("No hay ningun equipo cargado.\n");
    }
}

int printAllTeams(sTeam* list, int len)
{
    int i;
    system("cls");
    if(checkAllTeamsEmpty(list,len)==0)
    {
        printTeamTab();
        for(i=0; i<len; i++)
        {
            printATeam(list, i);
        }
        system("pause");
    }
    else
    {
        showMessage("No hay equipos cargados.\n");
    }
    return 0;
}

void printAllTeamsByName(sTeam* list,int len)
{
    sortTeamsByName(list,len);
    printAllTeams(list,len);
}

int printATeam (sTeam* list, int i)
{
    int ret=-1;
    if (list[i].isEmpty==0)
    {
        printf("%04d\t%18s\t\t%18s\n",list[i].code,list[i].name,list[i].locality);
        ret=i;
    }
    return ret;
}

void printLongestTeam (sTeam* list,int len)
{
    int i;
    int iMax;
    int maxLen;
    int flag=0;
    int counter=0;

    if(checkAllTeamsEmpty(list,len)==1)
    {
        showMessage("No hay equipos cargados.\n");
    }
    else
    {
        ///BUSCO LA LONGITUD DEL NOMBRE MAS LARGO Y CUENTO LOS EQUIPOS CON ESA LONGITUD.
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty==0)
            {
                if(flag==0)
                {
                    flag=1;
                    iMax=i;
                    maxLen=strlen(list[i].name);
                }
                else if(strlen(list[i].name)==strlen(list[iMax].name))
                {
                    counter++;
                }
                else if(strlen(list[i].name)>strlen(list[iMax].name))
                {
                    iMax=i;
                    maxLen=strlen(list[i].name);
                    counter=1;
                }
            }
        }

        ///RECORRO UNA VEZ MAS EL ARRAY IMPRIMIENDO LOS COINCIDENTES CON LA MAXIMA LONGITUD.
        if(counter>1)
        {
            printf("Los equipos con el nombre mas largo son: \n\n");
            for(i=0; i<len; i++)
            {
                if(list[i].isEmpty==0)
                {
                    if(strlen(list[i].name)==strlen(list[iMax].name))
                    {
                        printf("%s\n",list[i].name);
                    }
                }
            }
            if(counter==2)
            {
                printf("\nAmbos con %d caracteres.\n",maxLen);
            }
            else
            {
                printf("\nTodos con %d caracteres.\n",maxLen);
            }
        }
        else
        {
            printf("El equipo con el nombre mas largo es: %s (%d caracteres).\n\n",list[iMax].name,maxLen);
        }
        system("pause");
    }
}

void printTeamNameByCode (sTeam* list, int lenT, int code)
{
    int i;

    for(i=0; i<lenT; i++)
    {
        if(list[i].isEmpty==0&&code==list[i].code)
        {
            printf("%s",list[i].name);
        }
    }
}

void printTeamsByAverageAge (sTeam* team,sPlayer* player,int lenT,int lenP) ///VER QUE DEVUELVE RARO CUANDO UN EQUIPO NO TIENE JUGADORES.
{
    int i;
    int flag=0;
    if(checkAllTeamsEmpty(team,TEAMS)==1)
    {
        showMessage("No hay equipos cargados.\n");
    }
    else
    {
        sortTeamsByAverageAge(team,player,lenT,lenP);

        for(i=0; i<lenT; i++)
        {
            if(team[i].isEmpty==0)
            {
                if(flag==0)
                {
                    flag=1;
                    printf("Se listan los equipos por promedio de edad ascendente: \n\nEQUIPO\t\tPROMEDIO EDAD DEL PLANTEL\n\n");
                }
                if(team[i].averageAge>0)
                {
                    printf("%s\t\t\t(%.02f)\n",team[i].name,team[i].averageAge);
                }
            }
        }
        printf("\n");
        system("pause");
    }
}

void printTeamTab ()
{
    char str[18]= {"CODIGO"};
    char stri[18]= {"EQUIPO"};
    char strin[18]= {"LOCALIDAD"};
    printf("%s\t%18s\t\t%18s\n\n",str,stri,strin);
    return;
}

void sortTeamsByAverageAge(sTeam* team,sPlayer* player,int lenT,int lenP)
{
    int i;
    int j;
    sTeam aux[1];

    getTeamsAverageAge(team,player,lenT,lenP);

    for(i=1; i<lenT; i++)
    {
        for(j=0; j<lenT-1; j++)
        {
            if(team[i].isEmpty==0&&team[i].averageAge<team[j].averageAge)
            {
                aux[0]=team[i];
                team[i]=team[j];
                team[j]=aux[0];
            }
        }
    }
}

int sortTeamsByCode(sTeam* list, int len)
{
    int i;
    int j;
    int ret=-1;
    sTeam aux[1];

    if(list!=NULL||len<0)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=1; j<len; j++)
            {
                if (list[i].code<list[j].code)
                {
                    aux[0]=list[i];
                    list[i]=list[j];
                    list[j]=aux[0];
                }
            }
        }
        ret=0;
    }
    if(ret!=0)
    {
        showMessage("No se pudo realizar el ordenamiento.\n");
    }
    return ret;
}

int sortTeamsByName(sTeam* list, int len)
{
    int i;
    int j;
    int ret=-1;
    sTeam aux[1];

    if(list!=NULL||len<0)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=1; j<len; j++)
            {
                if (stricmp(list[i].name,list[j].name)<0)
                {
                    aux[0]=list[i];
                    list[i]=list[j];
                    list[j]=aux[0];
                }
            }
        }
        ret=0;
    }
    if(ret!=0)
    {
        showMessage("No se pudo realizar el ordenamiento.\n");
    }
    return ret;
}
