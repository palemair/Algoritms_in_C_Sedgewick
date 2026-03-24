#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

#define MAX 40
#define M 25

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


void trirapide_goto(int *tab,int N)
{
    int i;
    int l = 1;
    int r = N -1;

y : if(r-l<M)
    {
        insertsort(tab+l,r-l+1);
        goto x;
    }
   
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

void trirapide2(int *tab,int N)
{
    int i;
    int l = 1;
    int r = N -1;

    while(1)
    {
        while(r-l>=M)
        {
            i = partitionner(tab,l,r);
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
    int t[MAX];
    for(int u = 0; u<=MAX;u++) t[u]=u+1;
    int tcpy[MAX+1];
    tcpy[0]=0;

    melange(t,MAX,sizeof t[0]);
    memcpy(tcpy+1,t,sizeof t); 
    
    for (int x = 0; x<MAX+1; x++)
        printf("%4d",tcpy[x]);
    putchar('\n');
    
    
    trirapide_goto(tcpy,MAX+1);

    for (int x = 0; x<MAX+1; x++)
        printf("%4d",tcpy[x]);
    putchar('\n');
    
    return EXIT_SUCCESS;
}
