#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 2. Remplacez la boucle du programme précédent par une boucle **repeat** puis **While** */
/* et repondre à la même question. */

int main ()
{

    clock_t A = clock ();
    int j = 0;
    int i = 0;

    do
    {
        i++;
    }
    while(i<100000);
    j++;


    clock_t B = clock ();

    printf("temps estimé : processeur 2.40 Ghz : 0.0001 s\n");
    printf("repeat temps mesuré : %f s\n", ((double) B - (double) A) / CLOCKS_PER_SEC);

    clock_t C = clock ();
    int u = 0;
    int v = 0;

    while(u<100000)
    {
        u++;
    }
    v++;


    clock_t D = clock ();
    printf("while temps mesuré : %f s\n", ((double) D - (double) C) / CLOCKS_PER_SEC);
}

 /* Resultats : 

temps estimé : processeur 2.40 Ghz : 0.0001 s
repeat temps mesuré : 0.000417 s
while temps mesuré : 0.000401 s
*/
