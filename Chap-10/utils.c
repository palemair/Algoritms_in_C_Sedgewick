#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

#define MAXPILE 1000
#define MAXFILE 1000

static int tpile[MAXPILE + 1];
static int tfile[MAXFILE + 1];

static int sp = -1;
static int debut = 0;
static int fin = 0;

bool pile_vide(void)
{
    return sp == -1;
}

bool empiler(int v)
{
   if(sp < MAXPILE)
   {
       tpile[++sp] = v;
       return true;
   }
   return false;
}

int depiler(void)
{
   if(!pile_vide())
   {
       return tpile[sp--];
   }
   return -1;
}

void print_pile(void)
{
    printf(" Pile : ");
    for(int u=0;u<=sp;u++) printf("%d -",tpile[u]);
    printf("\n");
}

bool file_vide(void)
{
    return debut == fin;
}

void enfiler(int v)
{
   if(v)
   {
       tfile[fin++] = v;
   }

   if(fin > MAXFILE) fin = 0;
}

int defiler(void)
{
    int t = tfile[debut++];

    if(debut > MAXFILE) debut = 0;
    return t;
}

void print_file(void)
{
    printf(" File : ");
    for(int u=fin-1;u>=debut;u--) printf("%d -",tfile[u]);
    printf("\n");
}

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

/* malloc custom to avoid error test */
void* xmalloc (size_t size)
{
    void* value = NULL;

    value = malloc (size);
    if (value == NULL)
    {
        perror ("Virtual memory exhausted");
        exit (EXIT_FAILURE);
    }

    return value;
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
/* Fonction de données aléatoires de 1 à N */
int* randtab(int size)
{
    int* tb = xmalloc(size * sizeof(int));
    for(int u=0; u<size; u++)
        tb[u]=u+1;
    melange(tb,size,sizeof(int));

    return tb;
}


/* Fonction de vérification q'un tableau d'entier est correctement trié */ 

bool sorted(int *t, int len)
{
    for(int i=0;i<len;i++) 
        if(t[i]!=i) 
        {
            puts("Tri non correct !!");
            return false;
        }
    puts("liste triée : OK !!");
    return true;
}

int bits(unsigned int value, int position, int nb)
{
    return (value >> position) & ~(~0U << nb);
}
