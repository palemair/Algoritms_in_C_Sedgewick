#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

int partitionner(int *tab, int l, int r)
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
     return i;
 }

#define MAX 885

void trirapide2(int *tab,int N)
{
    int i;
    int l = 0;
    int r = N -1;

y : if(l>=r) goto x;
   
    i = partitionner(tab,l,r);
    empiler(r);
    empiler(i+1);
    
    r = i-1;
    goto y;
  
x: if(pile_vide()) goto z;
   l=depiler();
   r=depiler();
   goto y;
    
z: ;
}

int main()
{
    int t[MAX];
    for(int u = 0; u<MAX;u++) t[u]=u;
    melange(t,MAX,sizeof t[0]);
    
    PRINTAB(t,MAX);
    
    trirapide2(t,MAX);

    sorted(t,MAX);

    return EXIT_SUCCESS;
}
