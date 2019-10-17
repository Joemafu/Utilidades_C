#include "Referees.h"

void addReferee(sReferee* list, int len, int* id)
{
    int i;
    int end=0;
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
                list[i].code = *id;
                list[i].birthDate.year=getIntMinMax("\nAnio de nacimiento: ",1960,2005);
                list[i].birthDate.month=getIntMinMax("Mes: ",1,12);
                list[i].birthDate.day=getDay("Dia: ",list[i].birthDate.year,list[i].birthDate.month);
                getEmail("Ingrese correo electronico: ",email,30);
                strcpy(list[i].email,email);
                strcpy(list[i].lastName, lastName);
                strcpy(list[i].name, name);
                if(getConfirm()==1)
                {
                    list[i].isEmpty=0;
                    showMessage("Referi cargado con exito.\n\n");
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
            showMessage("No es posible cargar al referi. Espacio insuficiente.\n\n");
            end=1;
        }
    }
    if (end==0)
    {
        showMessage("Hubo un error al cargar el referi, verifique e intente nuevamente.");
        end=1;
    }
}

int checkAllRefereesEmpty (sReferee* list, int len)
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

int checkRefereeExistence(sReferee* list,int len,int id)
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
        showMessage("El codigo de referi ingresado no existe.\n");
    }
    return ret;
}

void deleteReferee(sReferee* list,int len)
{
    int i;
    int id;
    int e;

    if(checkAllRefereesEmpty(list,len)==0)
    {
        do
        {
            id=getIntMinMax("Ingrese el codigo del referi a dar de baja: ",1,len);
            e=checkRefereeExistence(list,len,id);
        }
        while(e==0);

        for (i=0; i<len; i++)
        {
            if(list[i].code==id)
            {
                printf("Esta a punto de eliminar el siguiente referi:\n\n");
                printRefereeTab();
                printAReferee(list,i);
                if(getConfirm()==1)
                {
                    list[i].isEmpty=1;
                    showMessage("El referi se dio de baja con exito.\n");
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
        showMessage("No hay ningun referi cargado.\n");
    }
}

void hardcodeReferees (sReferee* list)
{
    int code[6]= {1,2,3,4,5,6};
    char name[6][31]= {"Nicolas","Nazareno","Dario","Fernando","Gisella","Yael"};
    char lastName[6][31]= {"Lamolina","Arasa","Herrera","Espinoza","Trucco","Falcon Perez"};
    char eMail[6][31]= {"nicolas.lamolina@futbol5.com","nazareno.referi@gmail.com","herrera_dario@arbitraje.com","fer.espinoza@yahoo.com.ar","trucco_gise@gmail.com","fperezyael@hotmail.com"};
    char sex[6]= {'M','M','M','M','F','F'};
    int year[6]= {1980,1981,1975,1970,1986,1989};
    int month[6]= {8,10,5,6,6,2};
    int day[6]= {15,5,20,22,12,1};
    int i;

    for(i=0; i<6; i++)
    {
        list[i].code=code[i];
        strcpy(list[i].name,name[i]);
        strcpy(list[i].lastName,lastName[i]);
        strcpy(list[i].email,eMail[i]);
        list[i].sex=sex[i];
        list[i].birthDate.year=year[i];
        list[i].birthDate.month=month[i];
        list[i].birthDate.day=day[i];
        list[i].isEmpty=0;
    }
    return;
}

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
        showMessage("Fallo la inicializacion.\n");
        ret=-1;
    }
    return ret;
}

int printAReferee (sReferee* list, int i)
{
    int ret=-1;
    if (list[i].isEmpty==0)
    {
        printf("%03d\t%-15s\t%-15s\t\t%c\t%-25s\t%02d/%02d/%d\n",list[i].code,list[i].lastName,list[i].name,list[i].sex,list[i].email,list[i].birthDate.day,list[i].birthDate.month,list[i].birthDate.year);
        ret=i;
    }
    return ret;
}

int printReferees(sReferee* list, int len)
{
    int i;
    system("cls");
    if(checkAllRefereesEmpty(list,len)==0)
    {
        printRefereeTab();
        for(i=0; i<len; i++)
        {
            printAReferee(list, i);
        }
        system("pause");
        system("cls");
    }
    else
    {
        showMessage("No hay referis cargados.\n");
    }

    return 0;
}

void printRefereeTab ()
{
    printf("CODIGO\tAPELLIDO\tNOMBRE\t\t\tSEXO\teMAIL\t\t\t\tFECHA DE NAC.\n\n");
    return;
}

void printMostExperiencedReferee(sReferee* referee,sMatch* match,int lenR,int lenM)
{
    int i;
    int j;
    int counter;
    int flag=0;
    int maxMatches;

    if(checkAllRefereesEmpty(referee,lenR)==1)
    {
        showMessage("No hay referis cargados.\n");
    }
    else
    {
        ///BUSCO EL MAXIMO EN PARTIDOS DIRIGIDOS.
        for(i=0; i<lenR; i++)
        {
            counter=0;
            if(referee[i].isEmpty==0)
            {
                for(j=0; j<lenM; j++)
                {
                    if((match[j].isEmpty==0)&&(match[j].refereeCode==referee[i].code))
                    {
                        counter++;
                    }
                }
                if(flag==0||counter>maxMatches)
                {
                    maxMatches=counter;
                    flag=1;
                }
            }
        }

        ///COMPARO EL MAXIMO ENCONTRADO E IMPRIMO CADA RESULTADO.
        flag=0;
        for(i=0; i<lenR; i++)
        {
            counter=0;
            if(referee[i].isEmpty==0)
            {
                for(j=0; j<lenM; j++)
                {
                    if((match[j].isEmpty==0)&&(match[j].refereeCode==referee[i].code))
                    {
                        counter++;
                    }
                }
                if(flag==0)
                {
                    flag=1;
                    printf("Referi/s con mas partidos dirigidos (%d partidos): \n\n",maxMatches);
                    printRefereeTab();
                }
                if(counter==maxMatches)
                {
                    printAReferee(referee,i);
                }
            }
        }
        system("pause");
    }
}

void printRefereeNameByCode (sReferee* list, int lenT, int code)
{
    int i;

    for(i=0; i<lenT; i++)
    {
        if(list[i].isEmpty==0&&code==list[i].code)
        {
            printf("%s %s",list[i].lastName,list[i].name);
        }
    }
}
