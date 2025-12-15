#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 9. Ecrivez un programme récursif permettant de calculer le plus grand entier inférieur ou égal à log2 N. */

long int xlog2(int x)
{
  if (x > 1)
  {
      return (2* xlog2(x - 1));
  }
  return 2;
}

int main ()
{
    int d[] = {1,2,4,6,8,12,16,32};

    for(size_t u = 0;u < (sizeof(d) / sizeof d[0]);u++)
    {
        printf("N = %u : xlog2 = %lu\n",d[u],xlog2(d[u]));
    }

}

 /* Resultats : 

N = 1 : xlog2 = 2
N = 2 : xlog2 = 4
N = 4 : xlog2 = 16
N = 6 : xlog2 = 64
N = 8 : xlog2 = 256
N = 12 : xlog2 = 4096
N = 16 : xlog2 = 65536
N = 32 : xlog2 = 4294967296
*/
