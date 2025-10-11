#include <stdio.h>
#include <limits.h>

/* 9. Trouvez le couple d'entiers premiers entre eux (pgcd == 1)
 * les plus grands de votre système C. */

/* PGCD % */
unsigned long long pgcd (unsigned long long u, unsigned long long v)
{
    if (u < v)
    {
        unsigned long long temp = u;

        u = v;
        v = temp;
    }
    int r;

    while ((r = u % v) > 0)
    {
        u = v;
        v = r;
    }
    return v;
}

int main (void)
{

    unsigned long long x = LLONG_MAX;
    unsigned long long y = x;

    while (pgcd (x, y--) != 1);

    printf ("pgcd : %llu \n ", pgcd (x, y));
    printf ("x: %llu y: %llu \n", x, y);

    return 0;
}

 /* Resultats : 

pgcd : 1 
 x: 9223372036854775807 y: 9223372036854775805 
*/
