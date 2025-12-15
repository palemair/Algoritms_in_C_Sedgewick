#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 1. Combien de temps faut-il pour compter jusqu'à 100 000 ? Estimez le temps et faites tourner */
/*  j = 0; for (int i=0;i< 100000;i++) j++; pour vérifier l'estimation. */

int main ()
{
    int j = 0;

    clock_t A = clock ();

    for(int i = 0; i<100000; i++) j++;

    clock_t B = clock ();

    printf("temps estimé : processeur 2.40 Ghz : 0.0001 s\n");
    printf("time mesuré : %f s\n", ((double) B - (double) A) / CLOCKS_PER_SEC);
}

 /* Resultats : 

temps estimé : processeur 2.40 Ghz : 0.0001 s
time mesuré : 0.000415 s
*/
