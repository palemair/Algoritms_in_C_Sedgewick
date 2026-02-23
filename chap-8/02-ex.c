#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* 2. Laquelle des 3 méthodes élémentaires (selection, insertion, bulles) est la plus rapide */
/* pour un fichier déjà ordonné */

#define MAX 900
#define PRINTAB for(int u = 0; u<MAX;u++) printf("%4d",t[u]);printf("\n\n")

typedef clock_t* timer;

/* Le tri selection ne dépend pas de l'ordre des données donc il reste en N2. */
/* le tri bulles également. */
/* le tri selection est linéaire dans ce cas */

/* Mélange par permutation d'un tableau C fisher-yates*/
void melange (void* tb, size_t sizetb, size_t size)
{
    srand (time (NULL));
    unsigned char* ptr = tb;
    unsigned char temp[size];
    unsigned int j = 0;

    for (size_t i = sizetb - 1; i > 0; i--)
    {
        j = rand () % i;
        memcpy (temp, (ptr + (size * i)), size);
        memcpy ((ptr + (size * i)), (ptr + (size * j)), size);
        memcpy ((ptr + (size * j)), temp, size);
    }
}

clock_t* init_timer(void)
{
    clock_t *t = malloc(sizeof(*t));
    *t = clock();
    return t;
}

double delta_t(clock_t *t1,clock_t *t2, const char* str)
{
    double res = ((double)*t2 - (double)*t1) / CLOCKS_PER_SEC;
    printf("time for fnct %-15s : %4.6f \n",str,res);
    free(t1); free(t2);

    return res;
}

/* tri par selection */
int tri_selection (int* t, size_t nbelem)
{
    int tmp;
    size_t j, min;

    for (size_t i = 0; i < nbelem - 1 ; i++)
    {
        min = i;
        for (j = i + 1; j < nbelem; j++)
        {
            if (t[j] < t[min]) min = j;
        }

        tmp = t[i];
        t[i] = t[min];
        t[min] = tmp;
    }
    return EXIT_SUCCESS;
}

/* tri à bulles */
int tri_bulles (int* t, size_t nbelem)
{
    int i, j, v;

    for(i = nbelem-1;i>=0;i--)
        for(j = 1;j<=i;j++)
            if(t[j-1] > t[j])
            {
                v = t[j-1];
                t[j-1] = t[j];
                t[j] = v;
            }

    return EXIT_SUCCESS;
}

/* tri par insertion */
int tri_insertion (int* t, size_t nbelem)
{
    int j,q;
    for (size_t i = 1; i < nbelem; i++)
    {
        q = t[i];
        j = i; 
        while (j>0 && (t[j-1] > q))
            {
                t[j]=t[j-1];
                j--;
            }
            t[j] = q;
    }
    return EXIT_SUCCESS;
}


int main ()
{
    int t[MAX];
    for(int u = 0; u<MAX;u++) t[u]=u;
    /* melange(t,MAX,sizeof t[0]); */
    PRINTAB;
    
    timer A = init_timer();
    tri_insertion(t,MAX);
    timer B = init_timer();
    delta_t(A,B,"tri insertion");

    timer E = init_timer();
    tri_bulles(t,MAX);
    timer F = init_timer();
    delta_t(E,F,"tri à bulles");

    timer C = init_timer();
    tri_selection(t,MAX);
    timer D = init_timer();
    delta_t(C,D,"tri selection");

}

 /* Resultats : 

time for fnct tri insertion   : 0.000018 
time for fnct tri à bulles   : 0.003663 
time for fnct tri selection   : 0.003603 
*/
