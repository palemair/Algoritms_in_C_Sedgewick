#include <stdio.h>

/* 2. Vérifiez quelles valeurs sont calculées par votre systeme C 
 * pour u % v lorsque u et v n sont pas toujours positifs. */

int main (void)
{
    int x, y;

    x = -60;
    y = 11;

    printf ("%3d %% %3d => %3d\n", x, y, x % y);

    return 0;
}

 /* Resultats : 

-60 %  11 =>  -5
*/
