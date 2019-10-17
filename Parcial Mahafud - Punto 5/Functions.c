#include "Functions.h"

void getAlphabeticalString (char message[],char string[],int maxLen)
{
    int i;
    int len;

    do
    {
        printf(message);
        gets(string);
        fflush(stdin);
        len=strlen(string);
        if(len>maxLen)
        {
            system("cls");
            printf("Se supero el maximo de caracteres permitidos para este campo (%d).\n",maxLen);
            system("pause");
            system("cls");
            len=0;
        }
        else
        {
            for(i=0; i<len; i++)
            {
                if (!((string[i]==32)||(string[i]==39)||(string[i]>64&&string[i]<91)||(string[i]>96&&string[i]<123)))
                {
                    showMessage("Ingreso caracteres no alfabeticos, verifique e intente nuevamente.\n\n");
                    len=0;
                    break;
                }
            }
        }

    }
    while(len==0);
    return;
}

int getAlphanumericalString (char message[],char string[],int maxLen)
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
            printf("Se supero el maximo de caracteres permitidos para este campo (hasta %d).\n",maxLen);
            system("pause");
            system("cls");
            ret=0;
        }
        else
        {
            for(i=0; i<len; i++)
            {
                if (!((string[i]==46)||(string[i]==43)||(string[i]==32)||(string[i]==39)||(string[i]>64&&string[i]<91)||(string[i]>96&&string[i]<123)||(string[i]>47&&string[i]<58)))
                {
                    showMessage("Se ingresaron caracteres no alfanumericos, verifique e intente nuevamente.\n\n");
                    ret=0;
                    break;
                }
            }
        }

    }
    while(len==0||ret==0);


    return ret;
}

int getConfirm()
{
    int ret=-1;
    printf("Desea confirmar? s/n.\n");
    do
    {
        ret=getche();
        fflush(stdin);
        if((ret==83)||(ret==115))
        {
            ret=1;
        }
        else if((ret==78)||(ret==110))
        {
            ret=0;
        }
        else
        {
            printf("\n\nPresione s para confirmar, n para cancelar: \n");
        }
    }
    while(ret!=0&&ret!=1);

    return ret;
}

int getDay (char message[],int year, int month)
{
    int day;

    if (month==1||month==3||month==5||month==7||month==8||month==10||month==12)
    {
        day=getIntMinMax(message,1,31);
    }
    else if (month==4||month==6||month==9||month==11)
    {
        day=getIntMinMax(message,1,30);
    }
    else if (((month==2)&&(year%400==0))||((month==2)&&(year%100!=0)&&(year%4==0)))
    {
        day=getIntMinMax(message,1,29);
    }
    else
    {
        day=getIntMinMax(message,1,28);
    }
    return day;
}

int getEmail (char message[],char string[],int maxLen)
{
    int i;
    int len;
    int ret;
    int flagAt;
    int flagDot;
    do
    {
        printf(message);
        gets(string);
        fflush(stdin);
        len=strlen(string);
        ret=1;
        flagAt=0;
        flagDot=0;
        if(len>maxLen)
        {
            system("cls");
            printf("Se supero el maximo de caracteres permitidos para este campo (hasta %d).\n",maxLen);
            system("pause");
            system("cls");
            ret=-1;
        }
        else
        {
            for(i=0; i<len; i++)
            {
                if (!((string[i]==45)||(string[i]==95)||(string[i]==46)||(string[i]>63&&string[i]<91)||(string[i]>96&&string[i]<123)||(string[i]>47&&string[i]<58)))
                {
                    ret=0;
                    break;
                }
                if(string[i]==64)
                {
                    flagAt++;
                    if (!((string[(i+1)]>64&&string[(i+1)]<91)||(string[(i+1)]>96&&string[(i+1)]<123)))
                    {
                        ret=0;
                        break;
                    }
                }
                if (flagAt==1&&string[i]==46)
                {
                    flagDot++;
                    if (!((string[(i+1)]>64&&string[(i+1)]<91)||(string[(i+1)]>96&&string[(i+1)]<123)))
                    {
                        ret=0;
                        break;
                    }
                }
            }
        }
        if(flagAt!=1||flagDot<1||flagDot>2)
        {
            ret=0;
        }
        if(ret==0)
        {
            printf("\nFormato de eMail invalido, verifique e intente nuevamente.\n\n");
        }
    }
    while(len==0||ret<1);
    return ret;
}

int getIntMinMax(char message[],int min,int max)
{
    int i;
    char string[10]; ///Almacena hasta el 2147483647.
    int ret;
    int success;
    do
    {
        printf(message);
        scanf("%s",string);
        fflush(stdin);
        success=0;
        if (!((string[0]>47&&string[0]<58)||(string[0]==45)))
        {
            success--;
        }
        for(i=1; string[i]!='\0'; i++)
        {
            if((string[i]<48||string[i]>57)||(success<0))
            {
                success--;
                break;
            }
        }
        ret=atoi(string);
        if ((ret<min||ret>max)||(success<0))
        {
            printf("Ingrese un valor numerico valido. (Solo numeros enteros entre %d y %d).\n\n",min,max);
            success--;
        }
    }
    while(success<0);

    return ret;
}

int getPositiveInt(char message[])
{
    int i=0;
    char string[10]; ///Almacena hasta el 2147483647.
    int ret;
    do
    {
        printf(message);
        scanf("%s",string);
        fflush(stdin);
        ret=0;
        for(i=0; string[i]!='\0'; i++)
        {
            if(string[i]<48||string[i]>57)
            {
                showMessage("Ingrese un valor numerico valido. (Solo numeros enteros positivos).\n\n");
                ret=-1;
                break;
            }
        }
    }
    while(ret==-1);
    ret=atoi(string);
    return ret;
}

char getSex()
{
    int value=-1;
    char ret;

    do
    {
        value=getche();
        fflush(stdin);
        if((value==70)||(value==102))
        {
            value=0;///Fem.
        }
        else if((value==77)||(value==109))
        {
            value=1; ///Masc.
        }
        else
        {
            printf("\n\nIngrese f para femenino, m para masculino.\n");
        }
    }
    while(value!=0&&value!=1);
    switch (value)
    {
    case 0:
        ret='F';
        break;
    case 1:
        ret='M';
        break;
    }
    return ret;
}

void printSeparation()
{
    printf("\n------------------------------------------------------\n\n");
}

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

void showMessage(char message[])
{
    system("cls");
    printf(message);
    system("pause");
    system("cls");
}
