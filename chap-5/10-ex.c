#include <stdio.h>

/* 10. Ecrivez un programme récursif pour résoudre l'algorithme d'Euclide. */

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

int pgcd_rec (int a, int b)
{
    if(a==0 || b == 0) return -1;
    if(a == b) return a;
    if(b>a) {int t=a; a=b; b=t;}
    
    int r = a%b;

    if(r==0) return b;

    else
        return(pgcd_rec(b,r));
}

int main (void)
{
    struct point
    {
        int x, y;
    };

    struct point tab[] = { {5, 3}, {5, 8}, {25,35},{39, 65}, {461952, 116298} };

    for (size_t i = 0; i < 5; i++)
        printf ("%d %d = pgcd %d\n", tab[i].x, tab[i].y, pgcd (tab[i].x, tab[i].y));
    puts(" ");

    for (size_t i = 0; i < 5; i++)
        printf ("%d %d = pgcd récursif %d\n", tab[i].x, tab[i].y, pgcd_rec (tab[i].x, tab[i].y));
    return 0;
}

 /* Resultats : 

5 3 = pgcd 1
5 8 = pgcd 1
25 35 = pgcd 5
39 65 = pgcd 13
461952 116298 = pgcd 18
 
5 3 = pgcd récursif 1
5 8 = pgcd récursif 1
25 35 = pgcd récursif 5
39 65 = pgcd récursif 13
461952 116298 = pgcd récursif 18
*/
