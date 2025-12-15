#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 3. En le faisant fonctionner sur de petites valeurs, estimez le temps que dvrait prendre la version du crible d'Eratosthène */
/* décrite au chapitre 3 pour une valeur de N = 1 000 000 (si l'on disposait d'assez de mémoire). */

#define N 1000000

int main ()
{
    clock_t A = clock ();
    int i,j,t[N+1];

    for (t[1] = 0, i = 2; i <= N; i++) t[i]=1;
    for (i = 2; i <= N/2; i++) 
        for (j=2;j<=N/i;j++) t[i*j]=0;
    clock_t B = clock ();
    for (i = 1; i <= N; i++) 
        if (t[i]) printf("%4d",i) ;
    printf("\n");
    printf("temps mesuré sans printf : %f s\n", ((double) B - (double) A) / CLOCKS_PER_SEC);
}

/* on peut estimer le temps à :
 *  10 x 0,0004 pour la première boucle : 0.004
 *  + (10 x 10 x 0.0004) pour la boucle 2 imbriquée.
 *  soit O.044 s pour N = 1 million*/ 

 /* Resultats : 


temps mesuré sans printf : 0.156974 s
*/
