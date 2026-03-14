#include <stdio.h>

/* 1. Donnez une suite d'opérations d'échanges comparaisons pour 4 éléments. */

void tri4(char* t) {
    int q ;

    if(t[1] > t[2])
        {q =t[1]; t[1] = t[2]; t[2] = q;}

    if(t[3] > t[4])
        {q =t[3]; t[3] = t[4]; t[4] = q;}

    if(t[1] > t[3])
        {q =t[1]; t[1] = t[3]; t[3] = q;}

    if(t[2] > t[3])
        {q =t[2]; t[2] = t[3]; t[3] = q;}

    if(t[2] > t[4])
        {q =t[2]; t[2] = t[4]; t[4] = q;}

    if(t[3] > t[4])
        {q =t[3]; t[3] = t[4]; t[4] = q;}
}


#define MAX 10

int main()
{
    char t[] ="xDCBA";
    t[0] = 0;
    for(int i = 1; i<=4;i++)
        printf("%c ",t[i]);
    putchar('\n');
    tri4(t);
    
    for(int i = 1; i<=4;i++)
        printf("%c ",t[i]);
    putchar('\n');
}


 /* Resultats : 

D C B A 
A B C D 
*/
