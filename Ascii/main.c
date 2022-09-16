#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;

    printf("Ingrese un caracter para ver su valor ASCII o \"?\" para ver todos los caracteres:\n");
    while(i==i)
    {
        i=getche();
        printf(" %d\n",i);

        if(i=='?')
        {
            for(i=1;i<=255;i++)
            {
                printf("\n%d - %c",i,i);
            }
            printf("\n");
        }
    }
    return 0;
}
