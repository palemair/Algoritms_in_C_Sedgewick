#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 7. Ecrivez un programme pour calculer la valeur exacte de Cn dans la formule 2 */
/*  et comparer à log N. */

#define NB 100

void cn(double x)
{
  int i = 0;
  while(x>1)
  {
      ++i;
      x/=2;
  }
  printf("%2d |\n",i);
}

int rcn(int x)
{
  if (x == 1) return 0;
  
  else
    return 1 + rcn(x/2);
}

int main ()
{
    int d = 500;

    cn(d);
    printf("%d\n",rcn(d));
    printf("log2(x) : %.2f\n",log2(d));

    d = 128;

    cn(d);
    printf("%d\n",rcn(d));
    printf("log2(x) : %.2f\n",log2(d));
    
    d = 2;

    cn(d);
    printf("%d\n",rcn(d));
    printf("log2(x) : %.2f\n",log2(d));
    
}
