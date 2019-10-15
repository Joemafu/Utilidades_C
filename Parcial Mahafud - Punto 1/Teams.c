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
                printf("Confirmar? (s/n): \n");
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

int printAllTeams(sTeam* list, int length)
{
    int i;
    system("cls");
    printTeamTab();
    for(i=0; i<length; i++)
    {
        printATeam(list, i);
    }
    system("pause");
    system("cls");
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

int checkExistence (sTeam* list,int len,int id)
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


