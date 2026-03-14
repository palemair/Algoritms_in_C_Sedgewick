#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int trirapide(int *tab,int l,int r)
{
    if(l<r)
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
     trirapide(tab,l,i-1);
     trirapide(tab,i+1,r);
    }
    return 0;
}

void trirapide2(int *tab,int l,int r)
{
y : if(l>=r) goto x;
   
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

     trirapide(tab,l,i-1);
     
     l = i+1;
     goto y;
  
x: ;
}
#define M 30
int qsortinsert(int *tab,int l,int r)
{
    if(r-l>M)
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
     trirapide(tab,l,i-1);
     trirapide(tab,i+1,r);
    }
    else
    {
    }

    return 0;
}


#define MAX 721

int main()
{
    int t[MAX];
    for(int u = 0; u<MAX;u++) t[u]=u;
    melange(t,MAX,sizeof t[0]);
    
    PRINTAB(t,MAX);
    
    insertsort(t,MAX);
    
    PRINTAB(t,MAX);

    return EXIT_SUCCESS;
}
