#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* 10. Ecrivez un programme itératif pour l'exercice précédent. et comparer aux lib C mathématiques. */

long int rxlog2(int x)
{
  if (x > 1)
  {
      return (2* rxlog2(x - 1));
  }
  return 2;
}

long int ixlog2(int x)
{
  long int cumul = 1;

  while(x>= 1)
  {
      cumul *=2;
      x --;
  }
  return cumul;
}

int main ()
{
    int d[] = {1,2,3,4,8,12,16,32};

    for(size_t u = 0;u < (sizeof(d) / sizeof d[0]);u++)
    {
        printf("N = %3d : rlog2 = %12ld | ilog2 = %12ld | log2(C) = %12ld \n",d[u],rxlog2(d[u]),ixlog2(d[u]), (long int)pow(2,d[u]));
    }

}

 /* Resultats : 

N =   1 : rlog2 =            2 | ilog2 =            2 | log2(C) =            2 
N =   2 : rlog2 =            4 | ilog2 =            4 | log2(C) =            4 
N =   3 : rlog2 =            8 | ilog2 =            8 | log2(C) =            8 
N =   4 : rlog2 =           16 | ilog2 =           16 | log2(C) =           16 
N =   8 : rlog2 =          256 | ilog2 =          256 | log2(C) =          256 
N =  12 : rlog2 =         4096 | ilog2 =         4096 | log2(C) =         4096 
N =  16 : rlog2 =        65536 | ilog2 =        65536 | log2(C) =        65536 
N =  32 : rlog2 =   4294967296 | ilog2 =   4294967296 | log2(C) =   4294967296 
*/
