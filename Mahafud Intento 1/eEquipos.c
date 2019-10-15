#include "eEquipos.h"



int addEquipo(eEquipos* list, int len, int id)
{
    int i;
    int ret=-1;
    char auxName[51];
    char auxLoc[33];

    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty==1)
            {
                list[i].codigo=id;
                getAlphabeticalString("Ingrese el nombre del equipo",auxName,51);
                getAlphabeticalString("Ingrese la localidad del equipo",auxLoc,33);
                ret=0;
                break;
            }
        }
    }
    return ret;
}

int initEquipos(eEquipos list, int len)

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
int sortElementsByString(eEquipos* list, int len, int order)
{
    int i;
    int j;
    int ret=-1;
    eEquipos aux[1];

    if(list!=NULL||len<0||order<0||order>1)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=1; j<len; j++)
            {
                switch(order)
                {
                ///DESCENDENTE:
                case 0:
                    if (stricmp(list[i].nombre,list[j].nombre)>0)
                    {
                        aux[0]=list[i];
                        list[i]=list[j];
                        list[j]=aux[0];
                    }
                    break;
                ///ASCENDENTE:
                case 1:
                    if (stricmp(list[i].nombre,list[j].nombre)<0)
                    {
                        aux[0]=list[i];
                        list[i]=list[j];
                        list[j]=aux[0];
                    }
                    break;
                }
            }
        }
        ret=0;
    }
    return ret;
}

int printEquipos(eEquipos* list, int length)
{
    int i;
    system("cls");
    printTabEquipos();
    for(i=0; i<length; i++)
    {
        printAnEquipo(list, i);
    }
    system("pause");
    system("cls");
    return 0;
}

void printTabEquipos ()
{
    printf("CODIGO\tEQUIPO\t\t\tLOCALIDAD");
    return;
}


int printAnEquipo (eEquipos* list, int i)
{
    int ret=-1;
    if (list[i].isEmpty==0)
    {
        printf("%04d\t%18s\t%18s\n",list[i].codigo,list[i].nombre,list[i].localidad);
        ret=i;
    }
    return ret;
}
