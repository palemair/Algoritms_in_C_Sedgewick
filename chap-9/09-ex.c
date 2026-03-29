#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

/* 9. Serait il envisageable d'utiliser une file au lieu d'une pile dans l'implantation itérative du tri rapide ? */
/*     Pourquoi oui ou pourquoi non ? */

#define MAX 1000

int isorted(int *t, int len)
{
    for(int i=1;i<len;i++) 
        if(t[i]!=i) 
        {
            printf("Tri non correct au rang %d!!",i);
            return i;
        }
    puts("liste triée : OK !!");
    return 0;
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

void trirapide_goto(int *tab,int N)
{
    int i;
    int l = 1;
    int r = N;

y : if(r<=l) goto x;
   
    i = partitionner(tab,l,r);
    enfiler(i+1);
    enfiler(r);
    r = i - 1;
    goto y;
  
x: if(file_vide()) goto z;
   l=defiler();
   r=defiler();
   goto y;
    
z: ;
}

int main(void)
{
    int t2[MAX];
    for(int u = 0; u<MAX;u++) t2[u]=u+1;

    melange(t2,MAX,sizeof t2[0]);

    int t[MAX+1];
    memcpy(t+1,t2,sizeof t2);
    t[0]=-1;

    for (int x = 0; x<MAX+1; x++)
        printf("%4d",t[x]);
    putchar('\n');
    
    trirapide_goto(t,MAX);
    
    isorted(t,MAX);

    for (int x = 0; x<MAX; x++)
        printf("%4d",t[x]);
    putchar('\n');
    
    return EXIT_SUCCESS;
}

/* L'utilisation d'une file ne change pas le principe de l'algorithme puisqu'on enfile les sous-fichiers à traiter */
/* chaque sous fichier est partitionné de façon indépendante */
/* mais l'ordre est dans ce cas incertain et si on veut procéder à un tri par insertion "global", ça pourrait être génant. */
