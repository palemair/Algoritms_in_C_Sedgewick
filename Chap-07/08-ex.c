#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/* 8. Imanginez un moyen de tester si l'implantation d'un pile par liste chainée est plus performante */ 
/* qu'une implantation par tableau dans votre environnement de programmation. */

struct Node
{
    int data;
    struct Node *nxt;
};

static struct Node *ptr, *lpile, *z;

struct Node *initialise(void)
{
    lpile = malloc (sizeof *lpile);
    z = malloc (sizeof *z);
    lpile->data = -1;
    lpile->nxt = z;
    return lpile;
}

struct Node *lempiler(int v)
{
    struct Node *x = malloc (sizeof *x);
    x->data = v;
    x->nxt = lpile;
    lpile = x;
    return lpile;
}

int ldepiler(void)
{
    if(lpile->nxt == z) return -1;
    
    else
    {
        int k = lpile->data;
        ptr= lpile;
        struct Node *tmp = ptr->nxt;
        lpile = tmp;
        free(ptr);
        return k;
    }
}

#define MAX 20000
static int tp[MAX + 1];
static int sp = 0;

void empiler(int v)
{
    if (sp < MAX) tp[sp++] = v;
    else puts("Pile pleine !!");
}

int depiler(void)
{
    if(sp > 0)
    {
        int tmp = tp[--sp];
        return tmp;
    }
    else 
    {
        return -1;
    }
}

int main(void)
{
    clock_t A,B,C,D;

    initialise();
    
    for(int data = 500; data <= 20000; data += 500)
    {

        A = clock ();

        for(int u = 0;u<data;u++)
        {
           lempiler(u);
        }
        
        int res;
        while((res = ldepiler()) != -1);

        B = clock ();
        double tps = ((double) B - (double) A) / CLOCKS_PER_SEC;

        C = clock ();

        for(int u = 0;u<data;u++)
        {
           empiler(u);
        }
        int res2;
        while((res2 = depiler()) != -1);
            
        D = clock ();
        double tps2 = ((double) D - (double) C) / CLOCKS_PER_SEC;
        printf("tps liste - tableau : %12f s\n", tps - tps2);
    }

}


 /* Resultats : 

tps liste - tableau :     0.000020 s
tps liste - tableau :     0.000040 s
tps liste - tableau :     0.000043 s
tps liste - tableau :     0.000057 s
tps liste - tableau :     0.000064 s
tps liste - tableau :     0.000088 s
tps liste - tableau :     0.000086 s
tps liste - tableau :     0.000098 s
tps liste - tableau :     0.000112 s
tps liste - tableau :     0.000120 s
tps liste - tableau :     0.000126 s
tps liste - tableau :     0.000146 s
tps liste - tableau :     0.000154 s
tps liste - tableau :     0.000155 s
tps liste - tableau :     0.000162 s
tps liste - tableau :     0.000183 s
tps liste - tableau :     0.000188 s
tps liste - tableau :     0.000195 s
tps liste - tableau :     0.000218 s
tps liste - tableau :     0.000226 s
tps liste - tableau :     0.000213 s
tps liste - tableau :     0.000283 s
tps liste - tableau :     0.000234 s
tps liste - tableau :     0.000245 s
tps liste - tableau :     0.000321 s
tps liste - tableau :     0.000281 s
tps liste - tableau :     0.000326 s
tps liste - tableau :     0.000284 s
tps liste - tableau :     0.000332 s
tps liste - tableau :     0.000304 s
tps liste - tableau :     0.000320 s
tps liste - tableau :     0.000305 s
tps liste - tableau :     0.000356 s
tps liste - tableau :     0.000350 s
tps liste - tableau :     0.000396 s
tps liste - tableau :     0.000319 s
tps liste - tableau :     0.000366 s
tps liste - tableau :     0.000416 s
tps liste - tableau :     0.000391 s
tps liste - tableau :     0.000439 s
*/
