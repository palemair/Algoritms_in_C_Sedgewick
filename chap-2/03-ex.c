#include <stdio.h>
#include <stdlib.h>

/* 3. Implanter une procédure pour rendre irréductible une fraction utilisant la : */

/*                         struct fraction */
/*                              { int numerateur, denominateur ;}. */

typedef struct Fraction
{
    int denom;
    int num;

} fraction;

/* PGCD % */
int pgcd (int u, int v)
{
    if (u < 0) u = -u;
    if (v < 0) v = -v;

    if (u < v)
    {
        int temp = u;

        u = v;
        v = temp;
    }
    int r = 1;

    while (r > 0)
    {
        r = u % v;
        u = v;
        v = r;
    }
    return u;
}

fraction* reduce (fraction* fr)
{
    int pg = pgcd (fr->denom, fr->num);

    fr->denom /= pg;
    fr->num /= pg;
    printf ("%d/%d \n", fr->denom, fr->num);
    return fr;
}

int main (void)
{
    int x, y;

    x = 3;
    y = 15;

    printf ("\t%d/%d => ", x, y);
    fraction fr = { x, y };

    reduce (&fr);

    return 0;
}


 /* Resultats : 

	3/15 => 1/5 
*/
