#include <stdio.h>

/* PGCD SEDGEWICK */
/* 1. Mettez en oeuvre la version classique de l'algorithme d'Euclide 
 * présentée dans le texte.*/

int pgcd (int u, int v)
{
    int t;

    while (u > 0)
    {
        if (u < v)
        {
            t = u;
            u = v;
            v = t;
        }
        u = u - v;
    }
    return v;
}

int main (void)
{
    struct point
    {
        int x, y;
    };

    struct point tab[] = { {5, 3}, {-5, 8}, {39, 65}, {461952, 116298} };

    for (int i = 0; i < 4; i++)
        printf ("%d %d = pgcd %d\n", tab[i].x, tab[i].y, pgcd (tab[i].x, tab[i].y));

    return 0;
}

 /* Resultats : 

5 3 = pgcd 1
-5 8 = pgcd 8
39 65 = pgcd 13
461952 116298 = pgcd 18
*/
