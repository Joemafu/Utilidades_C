#include "Matches.h"

void addMatch(sMatch* matchList,sTeam* teamList,sReferee* refereeList, int lenM,int lenT,int lenR, int* id)
{
    int i;
    int r;
    int end=0;
    int givenConditions=0;

    if(checkAllRefereesEmpty(refereeList,lenR)==0)
    {
        givenConditions++;
    }
    if(checkAtLeastTwoTeams(teamList,lenT)==1)
    {
        givenConditions++;
    }
    if(givenConditions==2)
    {
        if(matchList!=NULL && lenM>0)
        {
            for(i=0; i<lenM; i++)
            {
                if(matchList[i].isEmpty==1)
                {
                    matchList[i].code=*id;
                    do
                    {
                        matchList[i].visitorCode=getIntMinMax("Codigo de equipo visitante: ",1,TEAMS);
                        r=checkTeamExistence(teamList,lenT,matchList[i].visitorCode);
                    }
                    while(r==0);
                    do
                    {
                        matchList[i].localCode=getIntMinMax("Codigo de equipo local: ",1,TEAMS);
                        r=checkTeamExistence(teamList,lenT,matchList[i].localCode);
                        if(matchList[i].localCode==matchList[i].visitorCode)
                        {
                            showMessage("El equipo local no puede ser el mismo que el visitante.\n");
                            r=0;
                        }
                    }
                    while(r==0);
                    do
                    {
                        matchList[i].refereeCode=getIntMinMax("Codigo de referi: ",1,TEAMS);
                        r=checkRefereeExistence(refereeList,lenR,matchList[i].refereeCode);
                    }
                    while(r==0);

                    matchList[i].date.year=getIntMinMax("Anio: ",1900,2050);
                    matchList[i].date.month=getIntMinMax("Mes: ",1,12);
                    matchList[i].date.day=getDay("Dia: ",matchList[i].date.year,matchList[i].date.month);
                    if(getConfirm()==1)
                    {
                        matchList[i].isEmpty = 0;
                        showMessage("Partido cargado con exito.\n\n");
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
                showMessage("No es posible cargar el partido. Espacio insuficiente.\n\n");
                end=1;
            }
        }
    }
    else
    {
        showMessage("No se puede cargar el partido, arbitro o equipos insuficientes.\n");
        end=1;
    }
    if (end==0)
    {
        showMessage("Hubo un error al cargar el partido, verifique e intente nuevamente.");
        end=1;
    }
}

int checkAllMatchesEmpty (sMatch* list, int len)
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

int checkMatchExistence(sMatch* list,int len,int id)
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
        showMessage("El codigo de partido ingresado no existe.\n");
    }
    return ret;
}

void deleteMatch(sMatch* list,sTeam* teamList, sReferee* refereeList,int len,int lenT,int lenR)
{
    int i;
    int id;
    int e;

    if(checkAllMatchesEmpty(list,len)==0)
    {
        do
        {
            id=getIntMinMax("Ingrese el codigo del partido a dar de baja: ",1,len);
            e=checkMatchExistence(list,len,id);
        }
        while(e==0);

        for (i=0; i<len; i++)
        {
            if(list[i].code==id)
            {
                printf("Esta a punto de eliminar el siguiente partido:\n\n");
                printMatchTab();
                printAMatch(list,teamList,refereeList,i,lenT,lenR);
                if(getConfirm()==1)
                {
                    list[i].isEmpty=1;
                    showMessage("El partido se dio de baja con exito.\n");
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
        showMessage("No hay ningun partido cargado.\n");
    }
}

void hardcodeMatches (sMatch* list)
{
    int matchCode[25]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    int visitorCode[25]= {1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5};
    int localCode[25]= {10,9,8,7,6,4,3,2,1,5,8,7,6,10,9,2,1,5,4,3,6,10,9,8,7};
    int day[25]= {21,21,21,21,21,28,28,28,28,28,5,5,5,5,5,12,12,12,12,12,19,19,19,19,19 };
    int month[25]= {9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    int year[25]= {2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019};
    int refereeCode[25]= {1,2,6,4,5,1,2,3,4,6,6,2,3,4,5,1,6,3,4,5,1,2,3,6,5};
    int i;

    for(i=0; i<25; i++)
    {
        list[i].code=matchCode[i];
        list[i].date.year=year[i];
        list[i].date.month=month[i];
        list[i].date.day=day[i];
        list[i].refereeCode=refereeCode[i];
        list[i].localCode=localCode[i];
        list[i].visitorCode=visitorCode[i];
        list[i].isEmpty=0;
    }
    return;
}

int initMatches(sMatch* list, int len)
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

int printAllMatches(sMatch* match,sTeam* team,sReferee* referee, int lenM,int lenT,int lenR)
{
    int i;
    system("cls");
    if(checkAllMatchesEmpty(match,lenM)==0)
    {
        printMatchTab();
        for(i=0; i<lenM; i++)
        {
            printAMatch(match,team,referee,i,lenT,lenR);
        }
        system("pause");
        system("cls");
    }
    else
    {
        showMessage("No hay partidos cargados.\n");
    }

    return 0;
}

int printAllMatchesByDate(sMatch* match,sTeam* team,sReferee* referee, int lenM,int lenT,int lenR)
{
    int i;
    system("cls");
    if(checkAllMatchesEmpty(match,lenM)==0)
    {
        sortMatchesByDate(match,lenM,1);
        printMatchTab();
        for(i=0; i<lenM; i++)
        {
            printAMatch(match,team,referee,i,lenT,lenR);
        }
        system("pause");
        system("cls");
    }
    else
    {
        showMessage("No hay partidos cargados.\n");
    }

    return 0;
}

void printAMatch (sMatch* match,sTeam* team,sReferee* referee, int i,int lenT,int lenR)
{
    int j;
    if (match[i].isEmpty==0)
    {
        printf("    %04d",match[i].code);
        for(j=0; j<lenT; j++)
        {
            if(team[j].isEmpty==0&&match[i].localCode==team[j].code)
            {
                printf("  %18s\t",team[j].name);
                break;
            }
        }
        for(j=0; j<lenT; j++)
        {
            if(team[j].isEmpty==0&&match[i].visitorCode==team[j].code)
            {
                printf("  %18s\t",team[j].name);
                break;
            }
        }
        for(j=0; j<lenR; j++)
        {
            if(referee[j].isEmpty==0&&match[i].refereeCode==referee[j].code)
            {
                printf("  %18s %4s\t",referee[j].lastName,referee[j].name);
                printf("  %02d/%02d/%d\n",match[i].date.day,match[i].date.month,match[i].date.year);
                break;
            }
        }
    }
}

void printMatchesByDate(sMatch* match,sTeam* team,sReferee* referee,int lenM,int lenT,int lenR)
{
    int i;
    int flag=0;
    sDate aux;
    if(checkAllMatchesEmpty(match,lenM)==1)
    {
        showMessage("No hay partidos cargados.\n");
    }
    else
    {
        printf("Ingrese la fecha del partido a buscar: \n");
        aux.year=getIntMinMax("Anio: ",1900,2050);
        aux.month=getIntMinMax("Mes: ",1,12);
        aux.day=getDay("Dia: ",aux.year,aux.month);

        for(i=0; i<lenM; i++)
        {
            if(match[i].isEmpty==0&&match[i].date.year==aux.year&&match[i].date.month==aux.month&&match[i].date.day==aux.day)
            {
                if(flag==0)
                {
                    printf("\nSe listan los resultados:\n\n");
                    flag=1;
                }
                printTeamNameByCode(team,lenT,match[i].localCode);
                printf(" VS. ");
                printTeamNameByCode(team,lenT,match[i].visitorCode);
                printf(". Dirigido por ");
                printRefereeNameByCode(referee,lenR,match[i].refereeCode);
                printf(".\n\n");
            }
        }
        if(flag==0)
        {
            printf("\nNo se jugaron partidos en la fecha indicada.\n");
        }
        system("pause");
    }

}

void printMatchTab ()
{
    printf("COD. PARTIDO \t VISITANTE \t \t  LOCAL\t \t \t \tREFERI \t  \t FECHA\n\n");
    return;
}

int sortMatchesByDate(sMatch* list, int len, int order)
{
    int i;
    int j;
    int ret=-1;
    sMatch aux[1];

    if(list!=NULL&&len>0&&order>-1&&order<2)
    {
        for(i=1; i<len; i++)
        {
            for(j=0; j<len-1; j++)
            {
                if(list[i].date.year<list[j].date.year)
                {
                    aux[0]=list[i];
                    list[i]=list[j];
                    list[j]=aux[0];
                }
                if((list[i].date.year==list[j].date.year)&&(list[i].date.month<list[j].date.month))
                {
                    aux[0]=list[i];
                    list[i]=list[j];
                    list[j]=aux[0];
                }
                if((list[i].date.year==list[j].date.year)&&(list[i].date.month==list[j].date.month)&&(list[i].date.day<list[j].date.day))
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
