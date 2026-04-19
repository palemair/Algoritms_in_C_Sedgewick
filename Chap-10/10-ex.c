#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

/* 10. Ecrivez un programme permettant de réorganiser un fichier de manière que tous les éléments de clé égale */ 
/*     à la médiane soient en position définitive, les éléments inférieurs à celle-ci étant toujours à sa gauche */
/*     ceux supérieurs à sa droite. */

#define MAX 50

int partitionner(char *tab, int l, int r)
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

int selectionK(char *tab,int l,int r,int k)
{
    int i;
    i = partitionner(tab,l,r);

    if (i == k) return tab[i];

    else
    {
        if(i>k) return selectionK(tab,l,i-1,k);

        else return selectionK(tab,i+1,r,k);
    }
}

int selectK(char *tab,int l,int r,int k)
{
    int i;

    while(1)
    {
        i = partitionner(tab,l,r);

        if (i == k) return tab[i];

        else
        {
            if(i>k) r = i-1;
            else l = i + 1;
        }
    }
}

int main(void)
{
    char t[MAX];
    srand (time(NULL));
    
    for(int u = 0; u<MAX;u++) 
    {
        t[u]='A' + rand() %26;
    }

    melange(t,MAX,sizeof t[0]);

    for (int x = 0; x<MAX; x++)
        printf("%2c",t[x]);
    putchar('\n');

    int med = (MAX/2);
    int ret = selectK(t,0,MAX-1,MAX/2);
    printf("Position %d Median : %c\n",med,ret);
    
    int i = 1;
    while(selectK(t,med + i,MAX-1,med+i) == ret) i++;

    i = 1;
    while(selectK(t,0,med -i,med-i) == ret) i++;

    for (int x = 0; x<MAX; x++)
        printf("%3d",x);
    putchar('\n');
    for (int x = 0; x<MAX; x++)
        printf("%3c",t[x]);
    putchar('\n');
    return EXIT_SUCCESS;
}

 /* Resultats : 

 S B A J C O Z W F F C Y V A X E S G S K W S T S E T T Z P S Y E E E N X E X D Y E S U X D L O Q W O
Position 25 Median : Q
  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49
  O  B  A  J  C  L  D  E  F  F  C  D  E  A  N  E  E  G  E  K  E  E  O  O  P  Q  S  S  S  S  S  S  S  T  T  T  V  U  W  W  W  Y  Y  X  Z  Z  X  X  X  Y
*/
