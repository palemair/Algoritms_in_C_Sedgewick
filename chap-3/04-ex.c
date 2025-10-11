#include <stdio.h>

/* 4. Ecrivez un programme pour résoudre le problème de Josephus à l'aide d'un tableau. */

int main (void)
{
    int N, M;
    
    N = 23;
    M = 5;

    int tab[N];
    for(int u = 0; u < N;u++) tab[u] = u + 1;
    int index = M - 1;

    while(N > 1)
    {
        printf("%d ",tab[index]);
        for(int u = index; u<N;u++)
        {
            tab[u] = tab[u + 1];
        }
        N--;
        index = (index + (M-1))%N ;
    }
        printf("%d \n",tab[0]);
    return 0;
}



 /* Resultats : 

5 10 15 20 2 8 14 21 4 12 19 6 16 1 13 3 18 11 9 17 23 7 22 
*/
