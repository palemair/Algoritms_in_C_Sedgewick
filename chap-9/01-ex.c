#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

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

int x = 0;
int qsortinsert(int *tab,int l,int r)
{
    if(r-l>x)
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
     qsortinsert(tab,l,i-1);
     qsortinsert(tab,i+1,r);
    }
    else
    {
        insertsort(tab + l, r-l+1);
    }

    return 0;
}

#define MAX 1000
#define ITER 150

int main()
{
    timer A,B;
    int t[MAX];
    int tcopy[MAX];
    double temps[ITER];

    int z = 0;
    int res[ITER];
    while(z<ITER)
    {
        for(int u = 0; u<MAX;u++) t[u]=u;
        melange(t,MAX,sizeof t[0]);

        while(x<ITER)
        {
            memset(tcopy,0,sizeof tcopy);
            memcpy(tcopy,t,sizeof tcopy);
            
            A = init_timer();
            qsortinsert(tcopy,0,MAX-1);
            B = init_timer();
            temps[x] = delta_t(A,B);
            x++;
        }
        int index = 0;
        
        for(int u=1;u<ITER;u++)
        {
            if(temps[u]<temps[index])
                index = u;
        }
        res[z] = index;
        z++;
    }
    int moy = 0;
    for(int x=0;x<ITER;x++)
        moy += res[x];
    printf("index min : %d\n",moy/z);
    return EXIT_SUCCESS;
}

 /* Resultats : 

index min : 24
une tendance semble se constituer autour de 30 (de 20 à 45)
en fixant à 30 le seuil pour passer en tri par insertion, on note une amélioration 
de performances.
*/
