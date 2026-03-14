#include <stdlib.h>
#include <string.h>
#include "utils.h"

timer init_timer(void)
{
    timer t = malloc(sizeof(*t));
    *t = clock();
    return t;
}

/* Renvoit une différence de clock() en micro secondes*/
double delta_t(clock_t *t1,clock_t *t2)
{
    double res = (((double)*t2 - (double)*t1) * 1000000)  / CLOCKS_PER_SEC;
    free(t1); free(t2);
    t1 = t2 = NULL;
    return res;
}

/* Mélange par permutation d'un tableau C fisher-yates*/
void melange (void* tb, size_t sizetb, size_t size)
{
    srand (time(NULL));
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

/* Fonction de vérification q'un tableau d'entier est correctement trié*/
bool sorted(int *t, int len)
{
    for(int i=0;i<len;i++) if(t[i]!=i) return false;
    return true;
}

