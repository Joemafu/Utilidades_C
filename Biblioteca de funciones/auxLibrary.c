#include "auxLibrary.h"


int addElement(sStruct* list, int len, int id)
{
    int i;
    int ret=-1;
    int sector;
    float salary;
    char name[51];

    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty==1)
            {
                getAlphabeticalString("Nombre",name,50);
                sector=getPositiveInt("Sector");
                salary=getPositiveFloat("Sueldo");
                ///Values to scan and charge
                list[i].id = id;
                strcpy(list[i].name, name);
                list[i].salary = salary;
                list[i].sector = sector;
                list[i].isEmpty = 0;
                ret=0;
                break;
            }
        }
        if(ret<0)
        {
            showMessage("No se pudo cargar el elemento, espacio insuficiente.");
        }
    }
    return ret;
}


int checkAllEmpty (sStruct* list, int len)
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


int checkExistence (sStruct* list,int len,int id)
{
    int i;
    int ret=0;

    for(i=0; i<len; i++)
    {
        if((id==list[i].id)&&(list[i].isEmpty==0))
        {
            ret=1;
        }
    }
    if(ret==0)
    {
        showMessage("El ID de elemento ingresado no existe.\n");
    }
    return ret;
}


int findElementById(sStruct* list, int len,int id)
{
    int i;
    int ret=-1;
    for(i=0; i<len; i++)
    {
        if(list[i].id==id && list[i].isEmpty==0)
        {
            ret=i;
            break;
        }
    }
    return ret;
}


int findElementByString(sStruct* list, int len,char string[])
{
    int i;
    int ret=-1;
    for(i=0; i<len; i++)
    {
        if(stricmp(list[i].name,string)==0 && list[i].isEmpty==0)
        {
            ret=i;
            break;
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

    }
    while(len==0||ret==0);


    return ret;
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
                if (!((string[i]==32)||(string[i]==39)||(string[i]>64&&string[i]<91)||(string[i]>96&&string[i]<123)||(string[i]>47&&string[i]<58)))
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


float getFloat(char message[])
{
    int i;
    int flagFloatingPoint;
    char string[10];
    int ret;
    do
    {
        printf(message);
        scanf("%s",string);
        fflush(stdin);
        ret=0;
        flagFloatingPoint=0;
        if (!((string[0]>47&&string[0]<58)||(string[0]==45)))
        {
            ret--;
        }
        for(i=1; string[i]!='\0'; i++)
        {
            if(string[i]==46)
            {
                flagFloatingPoint++;
            }
            if((flagFloatingPoint>1)||(ret<0)||((string[i]!=46)&&(string[i]<48||string[i]>57)))
            {
                showMessage("Ingrese un valor numerico valido. (Solo numeros positivos o negativos, con o sin punto).\n\n");
                ret--;
                break;
            }
        }
    }
    while(ret<0);
    ret=atoi(string);
    return ret;
}


int getInt(char message[])
{
    int i;
    char string[10]; ///Almacena hasta el 2147483647.
    int ret;
    do
    {
        printf(message);
        scanf("%s",string);
        fflush(stdin);
        ret=0;
        if (!((string[0]>47&&string[0]<58)||(string[0]==45)))
        {
            ret--;
        }
        for(i=1; string[i]!='\0'; i++)
        {
            if(string[i]<48||string[i]>57||ret<0)
            {
                showMessage("Ingrese un valor numerico valido. (Solo numeros enteros positivos).\n\n");
                ret--;
                break;
            }
        }
    }
    while(ret<0);
    ret=atoi(string);
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


float getPositiveFloat(char message[])
{
    int i;
    int flagFloatingPoint=0;
    char string[10];
    float ret;
    do
    {
        printf(message);
        scanf("%s",string);
        fflush(stdin);
        ret=0;
        for(i=0; string[i]!='\0'; i++)
        {
            if(string[i]==46)
            {
                flagFloatingPoint++;
            }
            if((flagFloatingPoint>1)||((string[i]<48||string[i]>57)&&(string[i]!=46)))
            {
                showMessage("Ingrese un valor numerico valido. (Positivos con o sin punto.)");
                ret--;
                flagFloatingPoint=0;
                break;
            }
        }
    }
    while(ret<0);
    ret=atof(string);
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


void hardcodeElements (sStruct* list)
{
    int id[13]= {1,2,3,4,5,6,7,8,9,10,11,12,13};
    char name[13][51]= {"Homero","Bob","Moe","Apu","Rafa","Juan","Hank","Milhouse","Barney","Lenny","Carl","Extrapalapaquetel","Bart"};
    char lastName[13][51]= {"Simpson","Patinio","Szyslak","Nahasapeemapetilon","Gorgory","Topo","Scorpio","Van Houten","Gomez","Leonard","Carlson","Cabezota Olmeca","Simpson"};
    float salary[13]= {10000,80000,30000,40000,20000,100000,60000,70000,90000,50000,110000,75000,35000};
    int sector[13]= {7,4,4,3,1,3,1,1,7,7,4,3,2};
    int i;

    for(i=0; i<13; i++)
    {
        list[i].id=id[i];
        strcpy(list[i].name,name[i]);
        strcpy(list[i].lastName,lastName[i]);
        list[i].salary=salary[i];
        list[i].sector=sector[i];
        list[i].isEmpty=0;
    }
    return;
}


void hardcodePropietarios (sStruct* list)
{
    int id[10]= {1,2,3,4,5,6,7,8,9,10};
    char name[10][51]= {"Homero","Bob","Moe","Apu","Rafa","Juan","Hank","Barney","Lenny","Carl"};
    int dia[10]= {7,21,4,30,1,17,1,19,7,11};
    int mes[10]= {7,4,4,3,1,3,1,1,7,7};
    int anio[10]= {1991,1992,2001,2000,1964,1955,1958,1976,1984,1990};
    int i;

    for(i=0; i<10; i++)
    {
        list[i].id=id[i];
        strcpy(list[i].name,name[i]);
        list[i].fechaNac.dia=dia[i];
        list[i].fechaNac.mes=mes[i];
        list[i].fechaNac.anio=anio[i];
        list[i].isEmpty=0;
    }
    return;
}


void informSalaryStat(sStruct* list, int len)
{
    int i;
    int count=0;
    double accumulator;
    float average;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==0)
        {
            accumulator+=list[i].salary;
            count++;
        }
    }
    average=accumulator/count;

    system("cls");
    printf("El total de los salarios es de %.2f.\n",accumulator);
    printf("El promedio de los salarios es de %.2f.\n",average);
    count=0;
    for(i=0; i<len; i++)
    {
        if((list[i].isEmpty==0)&&(list[i].salary>average))
        {
            count++;
        }
    }
    if(count==0)
    {
        printf("No hay empleados que superen el promedio de salario.\n\n");
    }
    else
    {
        printf("La cantidad de empleados que superan el promedio de salario es de %d y se enlista/n a continuacion:\n\n",count);
        printTab();
        for(i=0; i<len; i++)
        {
            if((list[i].isEmpty==0)&&(list[i].salary>average))
            {
                printAnElement(list,i);
            }
        }
    }
    system("pause");
    return;
}


int initElements(sStruct* list, int len)
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


int printAnElement (sStruct* list, int i)
{
    int ret=-1;
    if (list[i].isEmpty==0)
    {
        printf("%04d\t%03d\t\t%18s\t%18s\t%.2f\n",list[i].id,list[i].sector,list[i].lastName,list[i].name,list[i].salary);
        ret=i;
    }
    return ret;
}


int printElements(sStruct* list, int length)
{
    int i;
    system("cls");
    printTab();
    for(i=0; i<length; i++)
    {
        printAnElement(list, i);
    }
    system("pause");
    system("cls");
    return 0;
}


void printSeparation()
{
    printf("\n------------------------------------------------------\n\n");
}


void printTab ()
{
    printf("ID\tSECTOR\t\t\tAPELLIDO\t\tNOMBRE\t\tSALARIO\n\n");
    return;
}


int removeElement(sStruct* list, int len, int id)
{
    int i;
    int ret=-1;
    i=findElementById(list, len, id);
    if (i!=-1)
    {
        printf("Esta a punto de dar de baja al siguiente empleado:\n\n");
        printTab();
        printAnElement(list, i);
        printf("\ns/n\n");

        if(getConfirm()==1)
        {
            list[i].isEmpty = 1;
            showMessage("El empleado se dio de baja con exito.\n");
            ret=0;
        }
        else
        {
            showMessage("Se cancelo la baja del usuario.\n");
            ret=0;
        }
    }
    return ret;
}

int searchForLongestString (sStruct* list,int len)
{
    int i;
    int iMax;
    int flag=0;

    for(i=0; i<len; i++)
    {
        if(flag==0||strlen(list[i].name)>strlen(list[iMax].name))
        {
            flag=1;
            iMax=i;
        }
    }
    return iMax;
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


void sortAndPrint(sStruct* list, int len, int order)
{
    sortElementsByStringAndInt(list,len,order);
    printElements(list,len);
    return;
}


int sortElementsByIntStringAndString(sStruct* list, int len, int order)
{
    int i;
    int j;
    int ret=-1;
    sStruct aux[1];

    if(list!=NULL&&len>0&&order>-1&&order<2)
    {
        for(i=1; i<len; i++)
        {
            for(j=0; j<len-1; j++)
            {
                switch (order)
                {
                ///DESCENDENTE:
                case 0:
                    if (list[i].sector>list[j].sector)
                    {
                        aux[0]=list[i];
                        list[i]=list[j];
                        list[j]=aux[0];
                    }
                    if((list[i].sector==list[j].sector)&&(stricmp(list[i].lastName,list[j].lastName)>0))
                    {
                        aux[0]=list[i];
                        list[i]=list[j];
                        list[j]=aux[0];
                    }
                    if ((list[i].sector==list[j].sector) && (stricmp(list[i].lastName,list[j].lastName)==0) && (stricmp(list[i].name,list[j].name)>0))
                    {
                        aux[0]=list[i];
                        list[i]=list[j];
                        list[j]=aux[0];
                    }
                ///ASCENDENTE:
                case 1:
                    if (list[i].sector<list[j].sector)
                    {
                        aux[0]=list[i];
                        list[i]=list[j];
                        list[j]=aux[0];
                    }
                    if((list[i].sector==list[j].sector)&&(stricmp(list[i].lastName,list[j].lastName)<0))
                    {
                        aux[0]=list[i];
                        list[i]=list[j];
                        list[j]=aux[0];
                    }
                    if(list[i].sector==list[j].sector && stricmp(list[i].lastName,list[j].lastName)==0 && stricmp(list[i].name,list[j].name)<0)
                    {
                        aux[0]=list[i];
                        list[i]=list[j];
                        list[j]=aux[0];
                    }
                }
            }
        }
        ret=0;
    }
    return ret;
}


int sortElementsByStringAndInt(sStruct* list, int len, int order)
{
    int i;
    int j;
    int ret=-1;
    sStruct aux[1];

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
                    if (stricmp(list[i].name,list[j].name)>0)
                    {
                        aux[0]=list[i];
                        list[i]=list[j];
                        list[j]=aux[0];
                    }
                    if((stricmp(list[i].name,list[j].name)==0) && (list[i].fechaNac.anio>list[j].fechaNac.anio))
                    {
                        aux[0]=list[i];
                        list[i]=list[j];
                        list[j]=aux[0];
                    }
                    break;
                ///ASCENDENTE:
                case 1:
                    if (stricmp(list[i].name,list[j].name)<0)
                    {
                        aux[0]=list[i];
                        list[i]=list[j];
                        list[j]=aux[0];
                    }
                    if((stricmp(list[i].name,list[j].name)==0) && (list[i].fechaNac.anio<list[j].fechaNac.anio))
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



///getCappedAlphabeticalString
//
///getPhone
//
///getDNI
//
///getCUIT
//
///getCellPhone

