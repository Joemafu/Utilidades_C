#include "Players.h"

void addPlayer(sPlayer* list,sTeam* teamList, int lenP,int lenT, int* id)
{
    int i;
    int r;
    int end=0;
    char name[51];
    char lastName[51];

    if(list!=NULL && lenP>0)
    {
        for(i=0; i<lenP; i++)
        {
            if(list[i].isEmpty==1)
            {
                getAlphabeticalString("Apellido: ",lastName,30);
                getAlphabeticalString("Nombre: ",name,30);

                do
                {
                    printAllTeams(teamList,lenT);
                    list[i].teamCode=getIntMinMax("Codigo de equipo: ",1,TEAMS);
                    r=checkTeamExistence(teamList,lenT,list[i].teamCode);                         ///VALIDA QUE EXISTA EL EQUIPO
                }
                while(r==0);

                printf("Sexo (f/m): ");
                list[i].sex=getSex();
                list[i].code = *id;
                list[i].birthDate.year=getIntMinMax("\nAnio de nacimiento: ",1960,2005);
                list[i].birthDate.month=getIntMinMax("Mes: ",1,12);
                list[i].birthDate.day=getDay("Dia: ",list[i].birthDate.year,list[i].birthDate.month);
                strcpy(list[i].lastName, lastName);
                strcpy(list[i].name, name);
                if(getConfirm()==1)
                {
                    list[i].isEmpty = 0;
                    showMessage("Jugador cargado con exito.\n\n");
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
            showMessage("No es posible cargar al jugador. Espacio insuficiente.\n\n");
            end=1;
        }
    }
    if (end==0)
    {
        showMessage("Hubo un error al cargar el jugador, verifique e intente nuevamente.");
        end=1;
    }
}

int checkAllPlayersEmpty (sPlayer* list, int len)
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

int checkPlayerExistence(sPlayer* list,int len,int id)
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
        showMessage("El codigo de jugador ingresado no existe.\n");
    }
    return ret;
}

void deletePlayer(sPlayer* list,int len)
{
    int i;
    int id;
    int e=0;

    if(checkAllPlayersEmpty(list,len)==0)
    {
        do
        {
            id=getIntMinMax("Ingrese el codigo del jugador a dar de baja: ",1,len);
            e=checkPlayerExistence(list,len,id);
        }
        while(e==0);

        for (i=0; i<len; i++)
        {
            if(list[i].code==id)
            {
                printf("Esta a punto de eliminar el siguiente jugador:\n\n");
                printPlayerTab();
                printAPlayer(list,i);
                if(getConfirm()==1)
                {
                    list[i].isEmpty=1;
                    showMessage("El jugador se dio de baja con exito.\n");
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
        showMessage("No hay ningun jugador cargado.\n");
    }
}

void hardcodePlayers (sPlayer* list)
{
    int code[100]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100};
    char name[100][50]= {"JUAN","JOSE LUIS","JOSE","MARIA GUADALUPE","FRANCISCO","GUADALUPE","MARIA","JUANA","ANTONIO","JESUS","MIGUEL ANGEL","PEDRO","ALEJANDRO","MANUEL","MARGARITA","MARIA DEL CARMEN","JUAN CARLOS","ROBERTO","FERNANDO","DANIEL","CARLOS","JORGE","RICARDO","MIGUEL","EDUARDO","JAVIER","RAFAEL","MARTIN","RAUL","DAVID","JOSEFINA","JOSE ANTONIO","ARTURO","MARCO ANTONIO","JOSE MANUEL","JUAN","JOSE LUIS","JOSE","MARIA GUADALUPE","FRANCISCO","GUADALUPE","MARIA","JUANA","ANTONIO","JESUS","MIGUEL ANGEL","PEDRO","ALEJANDRO","MANUEL","MARGARITA","MARIA DEL CARMEN","JUAN CARLOS","ROBERTO","FERNANDO","DANIEL","CARLOS","JORGE","RICARDO","MIGUEL","EDUARDO","JAVIER","RAFAEL","MARTIN","RAUL","DAVID","JOSEFINA","JOSE ANTONIO","ARTURO","MARCO ANTONIO","JOSE MANUEL","JUAN","JOSE LUIS","JOSE","MARIA GUADALUPE","FRANCISCO","GUADALUPE","MARIA","JUANA","ANTONIO","JESUS","MIGUEL ANGEL","PEDRO","ALEJANDRO","MANUEL","MARGARITA","MARIA DEL CARMEN","JUAN CARLOS","ROBERTO","FERNANDO","DANIEL","CARLOS","JORGE","RICARDO","MIGUEL","EDUARDO","JAVIER","RAFAEL","MARTIN","RAUL","DAVID"};
    char lastName[100][50]= {"Gonzalez","Rodriguez","Gomez","Fernandez","Lopez","Diaz","Martinez","Perez","Romero","Sanchez","Garcia","Sosa","Torres","Ramirez","Alvarez","Benitez","Acosta","Flores","Medina","Ruiz","Gonzalez","Rodriguez","Gomez","Fernandez","Lopez","Diaz","Martinez","Perez","Romero","Sanchez","Garcia","Sosa","Torres","Ramirez","Alvarez","Benitez","Acosta","Flores","Medina","Ruiz","Gonzalez","Rodriguez","Gomez","Fernandez","Lopez","Diaz","Martinez","Perez","Romero","Sanchez","Garcia","Sosa","Torres","Ramirez","Alvarez","Benitez","Acosta","Flores","Medina","Ruiz","Gonzalez","Rodriguez","Gomez","Fernandez","Lopez","Diaz","Martinez","Perez","Romero","Sanchez","Garcia","Sosa","Torres","Ramirez","Alvarez","Benitez","Acosta","Flores","Medina","Ruiz","Gonzalez","Rodriguez","Gomez","Fernandez","Lopez","Diaz","Martinez","Perez","Romero","Sanchez","Garcia","Sosa","Torres","Ramirez","Alvarez","Benitez","Acosta","Flores","Medina","Ruiz"};
    char sex[100]= {'M','M','M','F','M','F','F','F','M','M','M','M','M','M','F','F','M','M','M','M','M','M','M','M','M','M','M','M','M','M','F','M','M','M','M','M','M','M','F','M','F','F','F','M','M','M','M','M','M','F','F','M','M','M','M','M','M','M','M','M','M','M','M','M','M','F','M','M','M','M','M','M','M','F','M','F','F','F','M','M','M','M','M','M','F','F','M','M','M','M','M','M','M','M','M','M','M','M','M','M'};
    int teamCode[100] = {1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10,10,10,10,10};
    int day[100]= {25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30};
    int month[100]= {1,3,5,7,8,10,12,5,4,6,3,1,1,3,5,7,8,10,12,5,4,6,3,1,1,3,5,7,8,10,12,5,4,6,3,1,1,3,5,7,8,10,12,5,4,6,3,1,1,3,5,7,8,10,12,5,4,6,3,1,1,3,5,7,8,10,12,5,4,6,3,1,1,3,5,7,8,10,12,5,4,6,3,1,1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5};
    int year[100]= {2000,2001,2000,1998,1995,2000,2001,2000,1998,1995,2000,2001,2000,1998,1995,2000,2001,2000,1998,1995,2000,2001,2000,1998,1995,2000,2001,2000,1998,1995,2000,2001,2000,1998,1995,2000,2001,2000,1998,1995,2000,2001,2000,1998,1995,2000,2001,2000,1998,1995,2000,2001,2000,1998,1995,2000,2001,2000,1998,1995,2000,2001,2000,1998,1995,2000,2001,2000,1998,1995,2000,2001,2000,1998,1995,2000,2001,2000,1998,1995,2000,2001,2000,1998,1995,2000,2001,2000,1998,1995,2000,2001,2000,1998,1995,2000,2001,2000,1998,1995};
    int i;

    for(i=0; i<100; i++)
    {
        list[i].code=code[i];
        strcpy(list[i].name,name[i]);
        strcpy(list[i].lastName,lastName[i]);

        list[i].sex=sex[i];

        list[i].teamCode=teamCode[i];
        list[i].birthDate.day=day[i];
        list[i].birthDate.month=month[i];
        list[i].birthDate.year=year[i];
        list[i].isEmpty=0;
    }
    return;
}

int initPlayers(sPlayer* list, int len)
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
        showMessage("Fallo la inicializacion.\n");
        ret=-1;
    }
    return ret;
}

void modifyPlayer(sPlayer* list,sTeam* team,int len,int lenT)
{
    int i;
    int id;
    int e;
    int option;
    char auxName[31];
    int auxNewTeam;
    char auxSex;
    int auxDay;
    int auxMonth;
    int auxYear;

    if(checkAllPlayersEmpty(list,len)==0)
    {
        do
        {
            id=getIntMinMax("Ingrese el codigo del jugador a modificar: ",1,len);
            e=checkPlayerExistence(list,len,id);
        }
        while(e==0);

        for (i=0; i<len; i++)
        {
            if(list[i].code==id)
            {
                printPlayerTab();
                printAPlayer(list,i);
                option=showMenuGetOption("\nSeleccione el campo a modificar:\n\n1) Nombre.\n2) Apellido.\n3) Equipo.\n4) Sexo.\n5) Fecha de nacimiento.\n6) Cancelar.\n\n",1,6);
                switch(option)
                {
                case 1:
                    system("cls");
                    getAlphanumericalString("Ingrese el nuevo nombre: ",auxName,30);
                    option=6;
                    if(getConfirm()==1)
                    {
                        strcpy(list[i].name,auxName);
                        system("cls");
                        printf("\nEl nombre ha sido modificado. Se muestran los datos actuales.\n");
                        printPlayerTab();
                        printAPlayer(list,i);
                        system("pause");
                    }
                    else
                    {
                        showMessage("Se cancelo la modificacion.\n");
                    }
                    break;
                case 2:
                    system("cls");
                    getAlphabeticalString("Ingrese el nuevo apellido: ",auxName,30);
                    option=6;
                    if(getConfirm()==1)
                    {
                        strcpy(list[i].lastName,auxName);
                        system("cls");
                        printf("\nEl apellido ha sido modificado. Se muestran los datos actuales.\n");
                        printPlayerTab();
                        printAPlayer(list,i);
                        system("pause");
                    }
                    else
                    {
                        showMessage("Se cancelo la modificacion.\n");
                    }
                    break;
                case 3:
                    system("cls");
                    auxNewTeam=getIntMinMax("Ingrese el codigo del nuevo equipo: ",1,lenT);
                    if(checkTeamExistence(team,lenT,auxNewTeam)==1)
                    {
                        option=6;
                        if(getConfirm()==1)
                        {
                            list[i].teamCode=auxNewTeam;
                            system("cls");
                            printf("\nEl equipo ha sido modificado. Se muestran los datos actuales.\n");
                            printPlayerTab();
                            printAPlayer(list,i);
                            system("pause");
                        }else
                        {
                            showMessage("Se cancelo la modificacion.\n");
                        }
                    }
                    break;
                case 4:
                    system("cls");
                    printf("Ingrese el nuevo sexo (f/m): ");
                    printf("\n");
                    auxSex=getSex();
                    option=6;
                    if(getConfirm()==1)
                    {
                        list[i].sex=auxSex;
                        system("cls");
                        printf("\nEl sexo ha sido modificado. Se muestran los datos actuales.\n");
                        printPlayerTab();
                        printAPlayer(list,i);
                        system("pause");
                    }
                    break;
                case 5:
                    system("cls");
                    auxYear=getIntMinMax("Ingrese nuevo anio de nacimiento: ",1960,2005);
                    auxMonth=getIntMinMax("Ingrese nuevo mes de nacimiento: ",1,12);
                    auxDay=getDay("Ingrese nuevo dia de nacimiento: ",auxYear,auxMonth);
                    option=6;
                    if(getConfirm()==1)
                    {
                        list[i].birthDate.day=auxDay;
                        list[i].birthDate.month=auxMonth;
                        list[i].birthDate.year=auxYear;
                        system("cls");
                        printf("\nEl dia de nacimiento ha sido modificado. Se muestran los datos actuales.\n");
                        printPlayerTab();
                        printAPlayer(list,i);
                        system("pause");
                    }
                    break;
                case 6:
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

void printAllPlayersByTeam(sPlayer* player,sTeam* team,int lenP,int lenT)
{
    int i;
    int j;

    if(checkAllPlayersEmpty(player,lenP)==1)
    {
        showMessage("No hay jugadores cargados.\n");
    }
    else
    {
        sortTeamsByCode(team,lenT);
        for(i=0; i<lenT; i++)
        {
            if(team[i].isEmpty==0)
            {
                printSeparation();
                printTeamTab();
                printATeam(team,i);
                printf("\n\n");
                printPlayerTab();
                for(j=0; j<lenP; j++)
                {
                    if(player[j].isEmpty==0&&player[j].teamCode==team[i].code)
                    {
                        printAPlayer(player,j);
                    }
                }
            }
        }
        system("pause");
    }
}

int printAPlayer (sPlayer* list, int i)
{
    int ret=-1;
    if (list[i].isEmpty==0)
    {
        printf("%03d\t%18s\t%18s\t\t%03d\t\t%c\t%02d/%02d/%d\n",list[i].code,list[i].lastName,list[i].name,list[i].teamCode,list[i].sex,list[i].birthDate.day,list[i].birthDate.month,list[i].birthDate.year);
        ret=i;
    }
    return ret;
}

int printPlayers(sPlayer* list, int len)
{
    int i;
    system("cls");
    if(checkAllPlayersEmpty(list,len)==0)
    {
        printPlayerTab();
        for(i=0; i<len; i++)
        {
            printAPlayer(list, i);
        }
        system("pause");
        system("cls");
    }
    else
    {
        showMessage("No hay jugadores cargados.\n");
    }

    return 0;
}

int printPlayersByLastNameAndName(sPlayer* list, int len)
{
    int i;
    system("cls");
    if(checkAllPlayersEmpty(list,len)==0)
    {
        sortPlayersByLastNameAndName(list,len,1);
        printPlayerTab();
        for(i=0; i<len; i++)
        {
            printAPlayer(list, i);
        }
        system("pause");
        system("cls");
    }
    else
    {
        showMessage("No hay jugadores cargados.\n");
    }

    return 0;
}

void printPlayersBySex(sPlayer* list,int len)
{
    int i;
    int j;
    sPlayer aux[1];

    if(list!=NULL||len<0)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=1; j<len; j++)
            {
                if (list[i].sex<list[j].sex)
                {
                    aux[0]=list[i];
                    list[i]=list[j];
                    list[j]=aux[0];
                }
            }
        }
        printPlayers(list,len);
    }
}

void printPlayerTab ()
{
    char a[10]= {"CODIGO"};
    char b[10]= {"APELLIDO"};
    char c[10]= {"NOMBRE"};
    char d[15]= {"COD. DE EQUIPO"};
    char e[10]= {"SEXO"};
    char f[15]= {"FECHA DE NAC."};

    printf("%s\t%18s\t%18s\t  %15s\t%s\t%10s\n\n",a,b,c,d,e,f);
    return;
}

void searchPlayerByName(sPlayer* player,sTeam* team,int lenP,int lenT)
{
    int i;
    int j;
    char auxName[31];

    if(checkAllPlayersEmpty(player,lenP)==1)
    {
        showMessage("No hay jugadores cargados.\n");
    }
    else
    {
        getAlphabeticalString("Ingrese nombre del jugador: \n",auxName,30);
        int flagResults=0;

        for(i=0; i<lenP; i++)
        {
            if (player[i].isEmpty==0&&stricmp(player[i].name,auxName)==0)
            {
                if(flagResults==0)
                {
                    printf("\nJUGADOR\t\t\tEQUIPO\n\n");
                    flagResults=1;
                }
                printf("%s %s\t\t",player[i].name,player[i].lastName);
                for(j=0; j<lenT; j++)
                {
                    if(team[j].isEmpty==0&&player[i].teamCode==team[j].code)
                    {
                        printf("%s\n",team[j].name);
                    }
                }
            }
        }
        if(flagResults==0)
        {
            printf("No hay jugadores con ese nombre.\n");
        }
        system("pause");
    }
}

int sortPlayersByLastNameAndName(sPlayer* list, int len, int order)
{
    int i;
    int j;
    int ret=-1;
    sPlayer aux[1];

    if(list!=NULL||len<0||order<0||order>1)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=1; j<len; j++)
            {
                if (stricmp(list[i].lastName,list[j].lastName)<0)
                {
                    aux[0]=list[i];
                    list[i]=list[j];
                    list[j]=aux[0];
                }
                if((stricmp(list[i].lastName,list[j].lastName)==0) && (stricmp(list[i].name,list[j].name)==0))
                {
                    aux[0]=list[i];
                    list[i]=list[j];
                    list[j]=aux[0];
                }
            }
        }
        ret=0;
    }
    return ret;
}
