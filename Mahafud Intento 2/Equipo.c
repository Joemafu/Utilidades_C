#include "Equipo.h"

int showMenuGetOption(char message[], int min, int max)
{
    int option;
    do
    {
        printf(message);
        scanf("%d", &option);
        fflush(stdin);
        system("cls");
        if(option<min||option>max)
        {
            system("cls");
            printf("Indique una opcion valida entre %d y %d.\n\n",min,max);
        }
    }
    while(option <min||option>max);
    return option;
}


int addElement(eEquipo* list, int len, int id)
{
    int i;
    int ret=-1;
    char name[51];
    char localidad[33];

    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty==1)
            {
                getAlphabeticalString("Nombre:",name,50);
                getAlphabeticalString("Localidad:",localidad,32);
                list[i].idEquipo=id;
                strcpy(list[i].nombreEquipo,name);
                strcpy(list[i].localidadEquipo,localidad);
                list[i].isEmpty=0;
                ret=0;
                break;
            }
        }
    }
    return ret;
}


int getAlphabeticalString (char message[],char string[],int maxLen)
{
    int i;
    int len;
    int ret;

    do
    {
        printf(message);
        gets(string);
        fflush(stdin);
        len=strlen(string);
        ret=1;
        if(len>maxLen)
        {
            system("cls");
            printf("Se supero el maximo de caracteres permitidos para este campo (%d).\n",maxLen);
            system("pause");
            system("cls");
            ret=0;
        }
        else
        {
            for(i=0; i<len; i++)
            {
                if (!((string[i]==32)||(string[i]==39)||(string[i]>64&&string[i]<91)||(string[i]>96&&string[i]<123)))
                {
                    showMessage("Ingreso caracteres no alfabeticos, verifique e intente nuevamente.\n\n");
                    ret=0;
                    break;
                }
            }
        }

    }while(len==0||ret==0);


    return ret;
}

void showMessage(char message[])
{
    system("cls");
    printf(message);
    system("pause");
    system("cls");
}


int initElements(eEquipo* list, int len)
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

