#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

/* 7. Combien de comparaisons sont nécessaires au tri rapide pour trier les clés de la chaine : QUESTIONFACILE ? */

int count = 0;

void trirapide_iter(char *tab,int l, int r)
{
    int i ,j, q;

    while(1)
    {
        while(r>l)
        {
            i = l-1;
            j = r;

            int pivot = tab[r];
            while(1)
            {
                while(tab[++i]<pivot);
                while(tab[--j]>pivot);
                if(i>=j) break;
                q = tab[i];
                tab[i] = tab[j];
                tab[j] = q;
            }
            count += (i-l) + (r-j);
            q = tab[i];
            tab[i] = tab[r];
            tab[r] = q;
            printf("l : %2d | r : %2d | count : %2d | PIVOT %c\n",l,r,count,pivot);
            if(r-l != 1)
            {empiler(i-1);
            empiler(l);
            }
            l = i + 1;
        }

        if(pile_vide()) break;
        l=depiler();
        r=depiler();
    } 
}

int main(void)
{

    char t[]="*QUESTIONFACILE";
    
    puts(t);
    putchar('\n');
    puts("tri rapide iteratif:");
    trirapide_iter(t,1,14);
    putchar('\n');
    puts(t);

    return EXIT_SUCCESS;
}

 /* Resultats : 

*QUESTIONFACILE

tri rapide iteratif:
l :  1 | r : 14 | count : 13 | PIVOT E
l :  4 | r : 14 | count : 24 | PIVOT E
l :  5 | r : 14 | count : 34 | PIVOT S
l : 13 | r : 14 | count : 36 | PIVOT U
l :  5 | r : 11 | count : 43 | PIVOT Q
l :  5 | r : 10 | count : 48 | PIVOT I
l :  7 | r : 10 | count : 52 | PIVOT I
l :  8 | r : 10 | count : 55 | PIVOT O
l :  8 | r :  9 | count : 57 | PIVOT L
l :  1 | r :  2 | count : 59 | PIVOT A

*ACEEFIILNOQSTU
*/
