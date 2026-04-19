#include <stdio.h>

/* 1. Ecrivez un programme pour remplir un tableau à 2 dimensions de booléens en mettant 1 dans t[i][j] si */ 
/*    si pgcd(i,j) est 1, 0 sinon. */

int pgcd (int u, int v)
{
    int r;

    if (u < v)
    {
        int temp = u;

        u = v;
        v = temp;
    }

    while ((r = u % v) > 0)
    {
        u = v;
        v = r;
    }
    return v;
}

int main (void)
{
    unsigned int n = 15;

    printf("%5c",' ');
    for(unsigned int i=1;i<=n;i++) printf("%2d ",i);
    putchar('\n');
    for(unsigned int i=1;i<=3*n+4;i++) printf("-");
    putchar('\n');

    
    for(unsigned int i=1;i<=n;i++)
    {
        printf("%3d |", i);
        for(unsigned int j = 1; j <=n; j++)
        {
            printf("%2c",(pgcd(i,j) == 1)? '1':'0');
            putchar(' ');
        }
    putchar('\n');
    }
   
    return 0;
}


 /* Resultats : 

      1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 
-------------------------------------------------
  1 | 1  1  1  1  1  1  1  1  1  1  1  1  1  1  1 
  2 | 1  0  1  0  1  0  1  0  1  0  1  0  1  0  1 
  3 | 1  1  0  1  1  0  1  1  0  1  1  0  1  1  0 
  4 | 1  0  1  0  1  0  1  0  1  0  1  0  1  0  1 
  5 | 1  1  1  1  0  1  1  1  1  0  1  1  1  1  0 
  6 | 1  0  0  0  1  0  1  0  0  0  1  0  1  0  0 
  7 | 1  1  1  1  1  1  0  1  1  1  1  1  1  0  1 
  8 | 1  0  1  0  1  0  1  0  1  0  1  0  1  0  1 
  9 | 1  1  0  1  1  0  1  1  0  1  1  0  1  1  0 
 10 | 1  0  1  0  0  0  1  0  1  0  1  0  1  0  0 
 11 | 1  1  1  1  1  1  1  1  1  1  0  1  1  1  1 
 12 | 1  0  0  0  1  0  1  0  0  0  1  0  1  0  0 
 13 | 1  1  1  1  1  1  1  1  1  1  1  1  0  1  1 
 14 | 1  0  1  0  1  0  0  0  1  0  1  0  1  0  1 
 15 | 1  1  0  1  0  0  1  1  0  0  1  0  1  1  0 
*/
