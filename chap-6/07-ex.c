#include <stdio.h>
#include <stdlib.h>

/* 7. Ecrivez un programme pour calculer la valeur exacte de Cn dans la formule 2 */
/*  et comparer à log N. */

#define NB 100

void reccurence(int x)
{
  int t[NB] = {0};
  int i = 1;
  int u = 1;

  while(u<x)
  {
      u*=2;
      ++i;
      t[i] = t[i-1] + 1;
      printf(" log2 %-3d C%-2d = %2d\n",u,i,t[i]);
  }
}

int main ()
{
    int d = 128;

    reccurence(d);
    
}

 /* Resultats : 

 log2 2   C2  =  1
 log2 4   C3  =  2
 log2 8   C4  =  3
 log2 16  C5  =  4
 log2 32  C6  =  5
 log2 64  C7  =  6
 log2 128 C8  =  7
*/
