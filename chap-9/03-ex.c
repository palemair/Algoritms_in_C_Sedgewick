#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

#define MAX 1000
#define M 20

int insertsort (int* t, int nbelem)
{
    int i,j,q;

    for (i = 1; i < nbelem; i++)
    {
        q=t[i];
        j=i;
        while (j>0 && q < t[j-1]) j--;
        memmove (t + j + 1 , t + j, (i-j) * sizeof (int));
        t[j] = q;
    }
    return EXIT_SUCCESS;
}

int qsort_rec(int *tab,int l,int r)
{
    if(r-l > M)
    {
     int pivot = tab[r];

     int i, j, temp;
     i = l-1;
     j = r;

     while(1)
     {
         while(tab[++i]<pivot);
         while(tab[--j]>pivot);
         if(i>=j) break;
         temp = tab[i];
         tab[i] = tab[j];
         tab[j] = temp;
     }
     temp = tab[i];
     tab[i] = tab[r];
     tab[r] = temp;
     qsort_rec(tab,l,i-1);
     qsort_rec(tab,i+1,r);
    }
    else
    {
        insertsort(tab + l, r-l+1);
    }

    return 0;
}

void trirapide_med3(int *tab,int l, int r)
{
    int i ,j, q;
    int m;

    while(1)
    {
        while(r-l > M)
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

            empiler(r);
            empiler(i+1);
            r = i-1;
        }

        insertsort(tab + l, r-l+1);

        if(pile_vide()) break;
        l=depiler();
        r=depiler();
    } 
}

int main(void)
{
    timer A,B;

    int t_init[MAX];
    for(int u = 0; u<MAX;u++) t_init[u]=u;
    melange(t_init,MAX,sizeof t_init[0]);

    int t[MAX];

    memset(t,0,sizeof t);
    memcpy(t,t_init,sizeof t);

    A = init_timer();
    trirapide_med3(t,0,MAX-1);
    B = init_timer();

    printf("med %.2f µs :", delta_t(A,B));
    sorted(t,MAX);

    memset(t,0,sizeof t);
    memcpy(t,t_init,sizeof t);

    A = init_timer();
    qsort_rec(t,0,MAX-1);
    B = init_timer();
    
    printf("rec %.2f µs :", delta_t(A,B));
    sorted(t,MAX);

    return EXIT_SUCCESS;
}

 /* Resultats : 

med 155.00 µs :liste triée : OK !!
rec 150.00 µs :liste triée : OK !!
*/
