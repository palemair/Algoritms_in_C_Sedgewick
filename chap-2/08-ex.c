#include <stdio.h>

/* 8. Ecrivez un programme calculant le PGCD de 3 entiers u,v et w. */

/* PGCD % */
int pgcd1 (int u, int v)
{
    int r;
    int count = 1;

    if (u < v)
    {
        count += 4;
        int temp = u;

        u = v;
        v = temp;
    }

    while ((r = u % v) > 0)
    {
        count += 3;
        u = v;
        v = r;
    }
    return v;
}
/* PGCD % */
int pgcd3 (int u, int v, int w)
{
    int first = pgcd1(u,v);
    return pgcd1(first,w);
}

int main (void)
{

    printf ("pgcd des nombres : %d %d %d\n", 12345, 6789,180);
    printf ("pgcd3 : %d\n", pgcd3 (12345, 6789,180));

    return 0;
}

 /* Resultats : 

pgcd des nombres : 12345 6789 180
pgcd3 : 3
*/
