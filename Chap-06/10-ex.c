#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* 10. Ecrivez un programme itératif pour l'exercice précédent. et comparer aux lib C mathématiques. */

int rxlog2(int x)
{
  if (x > 1)
  {
      return (1 + rxlog2(x/2));
  }
  return 0;
}


int ixlog2(int x)
{
  int cumul = 0;

  while(x> 1)
  {
      cumul ++;
      x /=2;
  }
  return cumul;
}

int main ()
{
    int d[] = {1,2,3,4,8,12,16,32,45,60,64};

    for(size_t u = 0;u < (sizeof(d) / sizeof d[0]);u++)
    {
        printf("N = %3d : rlog2 = %12d | ilog2 = %12d | log2(C) = %12.2f \n",d[u],rxlog2(d[u]),ixlog2(d[u]), log2(d[u]));
    }

}

 /* Resultats : 

N =   1 : rlog2 =            0 | ilog2 =            0 | log2(C) =         0.00 
N =   2 : rlog2 =            1 | ilog2 =            1 | log2(C) =         1.00 
N =   3 : rlog2 =            1 | ilog2 =            1 | log2(C) =         1.58 
N =   4 : rlog2 =            2 | ilog2 =            2 | log2(C) =         2.00 
N =   8 : rlog2 =            3 | ilog2 =            3 | log2(C) =         3.00 
N =  12 : rlog2 =            3 | ilog2 =            3 | log2(C) =         3.58 
N =  16 : rlog2 =            4 | ilog2 =            4 | log2(C) =         4.00 
N =  32 : rlog2 =            5 | ilog2 =            5 | log2(C) =         5.00 
N =  45 : rlog2 =            5 | ilog2 =            5 | log2(C) =         5.49 
N =  60 : rlog2 =            5 | ilog2 =            5 | log2(C) =         5.91 
N =  64 : rlog2 =            6 | ilog2 =            6 | log2(C) =         6.00 
*/
