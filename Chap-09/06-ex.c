#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

/* 6. Montrez comment le fichier A B A B A B A est partitionné, suivant les 2 méthodes suggérées dans le texte. */

#define PRINT(tab,max) for(int u = 0; u<(max);u++) printf("%3c",tab[u]);printf("\n")

void trirapide_med3(int *tab,int l, int r)
{
    int i ,j, q;
    int m;

    while(1)
    {
        while(r>l)
        {
            /* recherche de la mediane de 3 */
            m = (r+l)/2;

            if(tab[l] > tab[m])
            {q =tab[l]; tab[l] = tab[m]; tab[m] = q;}

            if(tab[l] > tab[r])
            {q =tab[l]; tab[l] = tab[r]; tab[r] = q;}

            if(tab[m] > tab[r])
            {q =tab[m]; tab[m] = tab[r]; tab[r] = q;}

            q =tab[m]; tab[m] = tab[r]; tab[r] = q;

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
            q = tab[i];
            tab[i] = tab[r];
            tab[r] = q;
            PRINT(tab,7);
            
            if(i==j) break;

            if(i-l > r-i)
            {
                empiler(i-1);
                empiler(l);
                l = i + 1;
            }
            else
            {
                empiler(r);
                empiler(i+1);
                r = i-1;
            }
        }

        if(pile_vide()) break;
        l=depiler();
        r=depiler();
    } 
}

void trirapide_iter(int *tab,int l, int r)
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
            q = tab[i];
            tab[i] = tab[r];
            tab[r] = q;
            PRINT(tab,7);

            if(i==j) break;

            if(i-l > r-i)
            {
                empiler(i-1);
                empiler(l);
                l = i + 1;
            }
            else
            {
                empiler(r);
                empiler(i+1);
                r = i-1;
            }
        }

        if(pile_vide()) break;
        l=depiler();
        r=depiler();
    } 
}

int main(void)
{

    int t_init[]={'A','B','A','B','A','B','A'};

    int t[7];
    memcpy(t,t_init,sizeof t);
    PRINT(t,7);

    puts("tri rapide iteratif:");
    trirapide_iter(t,0,6);

    memcpy(t,t_init,sizeof t);
    puts("\n\ntri rapide mediane de 3:");
    trirapide_med3(t,0,6);

    return EXIT_SUCCESS;
}

 /* Resultats : 

  A  B  A  B  A  B  A
tri rapide iteratif:
  A  A  A  B  A  B  B
  A  A  A  B  A  B  B
  A  A  A  B  A  B  B
  A  A  A  A  B  B  B


tri rapide mediane de 3:
  A  A  A  B  A  B  B
  A  A  A  B  A  B  B
  A  A  A  A  B  B  B
  A  A  A  A  B  B  B
*/
