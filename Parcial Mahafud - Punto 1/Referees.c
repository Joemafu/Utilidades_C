#include "Referees.h"
#ifndef DATE_H
#define DATE_H
typedef struct
{
    int day;
    int month;
    int year;

}sDate;

#endif // DATE_H


int initReferees(sReferee* list, int len)
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

void hardcodeReferees (sReferee* list)
{
    int code[6]= {1,2,3,4,5,6};
    char name[6][31]={"Nicolás","Nazareno","Darío","Fernando","Gisella","Yael"};
    char lastName[6][31]= {"Lamolina","Arasa","Herrera","Espinoza","Trucco","Falcón Pérez"};
    char sex[6]= {'M','M','M','M','F','F'};
    int year[6]={1980,1981,1975,1970,1986,1989};
    int month[6]={8,10,5,6,6,2};
    int day[6]={15,5,20,22,12,1};
    int i;

    for(i=0; i<6; i++)
    {
        list[i].code=code[i];
        strcpy(list[i].name,name[i]);
        strcpy(list[i].lastName,lastName[i]);
        list[i].sex=sex[i];
        list[i].birthDate.year=year[i];
        list[i].birthDate.month=month[i];
        list[i].birthDate.day=day[i];
        list[i].isEmpty=0;
    }
    return;
}

int addReferee(sReferee* list, int len, int id)
{
    int i;
    int ret=-1;
    char name[51];
    char lastName[51];
    char email[31];

    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty==1)
            {
                getAlphabeticalString("Apellido: ",lastName,30);
                getAlphabeticalString("Nombre: ",name,30);
                printf("Sexo (f/m): ");
                list[i].sex=getSex();
                list[i].code = id;
                list[i].birthDate.year=getIntMinMax("\nAnio de nacimiento: ",1960,2005);
                list[i].birthDate.month=getIntMinMax("Mes: ",1,12);
                list[i].birthDate.day=getDay("Dia: ",list[i].birthDate.year,list[i].birthDate.month);
                getEmail("Ingrese correo electronico: ",email,30);
                strcpy(list[i].email,email);
                strcpy(list[i].lastName, lastName);
                strcpy(list[i].name, name);
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
            showMessage("No es posible cargar al referi. Espacio insuficiente.\n\n");
            ret=1;
        }
    }
    return ret;
}
