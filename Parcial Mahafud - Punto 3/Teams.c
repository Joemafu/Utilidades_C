#include "Teams.h"

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

int addTeam(sTeam* list, int len, int id)
{
    int i;
    int ret=-1;
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
                list[i].code = id;
                strcpy(list[i].name, name);
                strcpy(list[i].locality, locality);
                if(getConfirm()==1)
                {
                    list[i].isEmpty = 0;
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
            showMessage("No es posible cargar el equipo. Espacio insuficiente.\n\n");
            ret=1;
        }
    }
    return ret;
}

int sortTeamsByStringAndInt(sTeam* list, int len, int order)
{
    int i;
    int j;
    int ret=-1;
    sTeam aux[1];

    if(list!=NULL||len<0||order<0||order>1)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=1; j<len; j++)
            {
//                switch(order)
//                {
                ///DESCENDENTE:
//                case 0:
//                    if (stricmp(list[i].name,list[j].name)>0)
//                    {
//                        aux[0]=list[i];
//                        list[i]=list[j];
//                        list[j]=aux[0];
//                    }
//                    if((stricmp(list[i].name,list[j].name)==0) && (list[i].code>list[j].code))
//                    {
//                        aux[0]=list[i];
//                        list[i]=list[j];
//                        list[j]=aux[0];
//                    }
//                    break;
                ///ASCENDENTE:
//                case 1:
                    if (stricmp(list[i].name,list[j].name)<0)
                    {
                        aux[0]=list[i];
                        list[i]=list[j];
                        list[j]=aux[0];
                    }
//                    if((stricmp(list[i].name,list[j].name)==0) && (list[i].code<list[j].code))
//                    {
//                        aux[0]=list[i];
//                        list[i]=list[j];
//                        list[j]=aux[0];
//                    }
//                    break;
//                }
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
        system("cls");
    }else
    {
        showMessage("No hay equipos cargados.\n");
    }
    return 0;
}

void printTeamTab ()
{
    char str[18]={"CODIGO"};
    char stri[18]={"EQUIPO"};
    char strin[18]={"LOCALIDAD"};
    printf("%s\t%18s\t\t%18s\n\n",str,stri,strin);
    return;
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
        }while(e==0);

        for (i=0;i<len;i++)
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
                    }else
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
                    }else
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
    }else
    {
        showMessage("No hay ningun equipo cargado.\n");
    }
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
        }while(e==0);

        for (i=0;i<len;i++)
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
                }else
                {
                    showMessage("Se cancelo la baja.\n");
                }
                break;
            }
        }
    }else
    {
        showMessage("No hay ningun equipo cargado.\n");
    }
}

void printLongestTeam (sTeam* list,int len)
{
    int i;
    int iMax;
    int maxLen;
    int flag=0;
    int counter=0;

    ///BUSCO LA LONGITUD DEL NOMBRE MAS LARGO Y CUENTO LOS EQUIPOS CON ESA LONGITUD.
    for(i=0;i<len;i++)
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
        for(i=0;i<len;i++)
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
        }else
        {
            printf("\nTodos con %d caracteres.\n",maxLen);
        }
    }else
    {
        printf("El equipo con el nombre mas largo es: %s (%d caracteres).\n\n",list[iMax].name,maxLen);
    }
    system("pause");
}



