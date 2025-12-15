#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
  }
  for (int u = 1; u<=i;u++) printf(" C%-2d = %2d |",u,t[u]);
  printf("log2(x) : %.2f\n",log2(x));
}

void recc(int x)
{
  double cumul = 0;

  while(x>= 1)
  {
      cumul++;
      x/=2;
  }
  printf("Cn : %.2f\n",cumul);
}

int main ()
{
    int d = 500;

    reccurence(d);
    recc(d);

    d = 128;

    reccurence(d);
    recc(d);
    
}

 /* Resultats : 

 C1  =  0 | C2  =  1 | C3  =  2 | C4  =  3 | C5  =  4 | C6  =  5 | C7  =  6 | C8  =  7 | C9  =  8 | C10 =  9 |log2(x) : 8.97
Cn : 9.00
 C1  =  0 | C2  =  1 | C3  =  2 | C4  =  3 | C5  =  4 | C6  =  5 | C7  =  6 | C8  =  7 |log2(x) : 7.00
Cn : 8.00
*/
