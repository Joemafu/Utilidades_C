#include "Matches.h"

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

void hardcodeMatches (sMatch* list)
{
    int matchCode[25]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    int visitorCode[25]={1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5};
    int localCode[25]={10,9,8,7,6,4,3,2,1,5,8,7,6,10,9,2,1,5,4,3,6,10,9,8,7};
    int day[25]={21,21,21,21,21,28,28,28,28,28,5,5,5,5,5,12,12,12,12,12,19,19,19,19,19 };
    int month[25]={9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    int year[25]={2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019};
    int refereeCode[25]={1,2,6,4,5,1,2,3,4,6,6,2,3,4,5,1,6,3,4,5,1,2,3,6,5};
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

int addMatch(sMatch* matchList,sTeam* teamList,sReferee* refereeList, int lenM,int lenT,int lenR, int id)
{
    int i;
    int r;
    int ret=-1;

    if(matchList!=NULL && lenM>0)
    {
        for(i=0; i<lenM; i++)
        {
            if(matchList[i].isEmpty==1)
            {
                matchList[i].code=id;
                do
                {
                    matchList[i].visitorCode=getIntMinMax("Codigo de equipo visitante: ",1,TEAMS);
                    r=checkTeamExistence(teamList,lenT,matchList[i].visitorCode);
                }while(r==0);
                do
                {
                    matchList[i].localCode=getIntMinMax("Codigo de equipo local: ",1,TEAMS);
                    r=checkTeamExistence(teamList,lenT,matchList[i].localCode);
                    if(matchList[i].localCode==matchList[i].visitorCode)
                    {
                        showMessage("El equipo local no puede ser el mismo que el visitante.\n");
                        r=0;
                    }
                }while(r==0);
                do
                {
                    matchList[i].refereeCode=getIntMinMax("Codigo de referi: ",1,TEAMS);
                    r=checkRefereeExistence(refereeList,lenR,matchList[i].refereeCode);
                }while(r==0);

                matchList[i].date.year=getIntMinMax("Anio: ",1900,2050);
                matchList[i].date.month=getIntMinMax("Mes: ",1,12);
                matchList[i].date.day=getDay("Dia: ",matchList[i].date.year,matchList[i].date.month);
                printf("Confirmar? (s/n): \n");
                if(getConfirm()==1)
                {
                    matchList[i].isEmpty = 0;
                    ret=0;
                }
                else
                {
                    showMessage("Se cancelo la carga.\n\n");
                    ret=1;
                }
                break;
            }
        }
        if(ret==-1)
        {
            showMessage("No es posible cargar al referi. Espacio insuficiente.\n\n");
            ret=1;
        }
    }
    return ret;
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
//                switch (order)
//                {
                ///DESCENDENTE:
//                case 0:
//                    if (list[i].sector>list[j].sector)
//                    {
//                        aux[0]=list[i];
//                        list[i]=list[j];
//                        list[j]=aux[0];
//                    }
//                    if((list[i].sector==list[j].sector)&&(stricmp(list[i].lastName,list[j].lastName)>0))
//                    {
//                        aux[0]=list[i];
//                        list[i]=list[j];
//                        list[j]=aux[0];
//                    }
//                    if ((list[i].sector==list[j].sector) && (stricmp(list[i].lastName,list[j].lastName)==0) && (stricmp(list[i].name,list[j].name)>0))
//                    {
//                        aux[0]=list[i];
//                        list[i]=list[j];
//                        list[j]=aux[0];
//                    }break;
                ///ASCENDENTE:
//                case 1:
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
//                }
            }
        }
        ret=0;
    }
    return ret;
}

int printAllMatches(sMatch* list, int length)
{
    int i;
    system("cls");
    printMatchTab();
    for(i=0; i<length; i++)
    {
        printAMatch(list, i);
    }
    system("pause");
    system("cls");
    return 0;
}

void printMatchTab ()
{
    char st[18]={"COD. PARTIDO"};
    char str[18]={"COD. VISITANTE"};
    char stri[18]={"COD. LOCAL"};
    char strin[18]={"COD. REFERI"};
    char string[18]={"FECHA"};
    printf("%s\t%s\t%s\t%s\t%s\n\n",st,str,stri,strin,string);
    return;
}

int printAMatch (sMatch* list, int i)
{
    int ret=-1;
    if (list[i].isEmpty==0)
    {
        printf("%04d\t\t%04d\t%04d\t%04d\t%02d/%02d/%d\n",list[i].code,list[i].visitorCode,list[i].localCode,list[i].refereeCode,list[i].date.day,list[i].date.month,list[i].date.year);
        ret=i;
    }
    return ret;
}

int checkTeamExistence (sTeam* list,int len,int id)
{
    int i;
    int ret=0;

    for(i=0;i<len;i++)
    {
        if((id==list[i].code)&&(list[i].isEmpty==0))
        {
            ret=1;
        }
    }
    if(ret==0)
    {
        showMessage("El codigo de equipo ingresado no existe.\n");
    }
    return ret;
}

int checkRefereeExistence(sReferee* list,int len,int id)
{
    int i;
    int ret=0;

    for(i=0;i<len;i++)
    {
        if((id==list[i].code)&&(list[i].isEmpty==0))
        {
            ret=1;
        }
    }
    if(ret==0)
    {
        showMessage("El codigo de referi ingresado no existe.\n");
    }
    return ret;
}

