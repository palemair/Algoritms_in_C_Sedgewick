#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* 10. Testez différentes suites d'incréments pour le tri shell : */ 
/*     donnez une suite s'accompagnant de meilleures performances que celles relatives à la suite */
/*     donnée pour un fichier de 1000 éléments aléatoires. */

#define MAX 1000
#define PRINTAB(t,x) for(int u = 0; u<(x);u++) printf("%-4u",t[u]);printf("\n")

typedef clock_t* timer;

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
    printf("time for increment: %-50.50s : %4.6f \n\n",str,res);
    free(t1); free(t2);
    t1 = t2 = NULL;
    return res;
}

int h_ord (int h, int* tb, int len)
{
    int j, q;
    
    for(int i = h ; i<len; ++i)
    {
        q = tb[i];
        j = i;
        while(j>=h && tb[j-h]>q) 
        {
            tb[j] = tb[j-h];
            j-=h;
        }
        tb[j] = q;
    }
    return EXIT_SUCCESS;
}

void tri_shell(int* incr, int start,int* tab, int len)
{
    int j, q, h;
    /* start = (start<=4)?start:4; */
    for(int u=start; u>=0;u--)
    {
        h = incr[u];
        for(int i = h ; i<len; ++i)
        {
            q = tab[i];
            j = i;
            while(j>=h && tab[j-h]>q) 
            {
                tab[j] = tab[j-h];
                j-=h;
            }
            tab[j] = q;
        }
    }
}

int list_incr(int(*pf)(int),int *tincr,char *buffer)
{
    memset(buffer,0,100);
    memset(tincr,0,25*sizeof(int));
    int x = 0;
    int h = 1;
    for(int u=0; h<MAX/2;u++) 
    { 
        tincr[u]=h;
        h=(*pf)(h);
    }
    char nb[8];
    sprintf(buffer,"%5d",tincr[0]);
    int *p = tincr + 1;
    while(*p!=0)
    {
        sprintf(nb,"%5d",*p++);
        strcat(buffer,nb);
        x++;
    }
    return x;
}

int H0(int x)
{
    return 3*x + 1;
}

int H1(int x)
{
    return 3*x + 2;
}

int H2(int x)
{
    return 2*x + 1;
}
int H3(int x)
{
    return 2*x;
}

int H4(int x)
{
    return 3*x - 1;
}

int H5(int x)
{
    return 4*x - 1;
}

int main ()
{
    /* tableau initial */
    timer A,B;
    int t[MAX];
    for(int u = 0; u<MAX;u++) t[u]=u;
    melange(t,MAX,sizeof t[0]);

    /* tab == copie de t */
    int tab[MAX];
    int incr[25];
    char buffer[100]={'\0'};
    int x;

    /* h = 3 *h +1 */
    x = list_incr(&H0,incr,buffer);
    memcpy(tab,t,MAX * sizeof(int)); 

    A = init_timer();
    tri_shell(incr,x,tab,MAX);
    B = init_timer();
    delta_t(A,B,buffer);

    /* h = 3 *h + 2 */
    x = list_incr(&H1,incr,buffer);
    memcpy(tab,t,MAX * sizeof(int)); 

    A = init_timer();
    tri_shell(incr,x,tab,MAX);
    B = init_timer();
    delta_t(A,B,buffer);

    /* h = 2 *h + 1 */
    x = list_incr(&H2,incr,buffer);
    memcpy(tab,t,MAX * sizeof(int)); 

    A = init_timer();
    tri_shell(incr,x,tab,MAX);
    B = init_timer();
    delta_t(A,B,buffer);

    /* h = 2 *h */
    x = list_incr(&H3,incr,buffer);
    memcpy(tab,t,MAX * sizeof(int)); 

    A = init_timer();
    tri_shell(incr,x,tab,MAX);
    B = init_timer();
    delta_t(A,B,buffer);

    /* h = 3 *h-1 */
    x = list_incr(&H4,incr,buffer);
    memcpy(tab,t,MAX * sizeof(int)); 

    A = init_timer();
    tri_shell(incr,x,tab,MAX);
    B = init_timer();
    delta_t(A,B,buffer);

    /* h = 4 *h-1 */
    x = list_incr(&H5,incr,buffer);
    memcpy(tab,t,MAX * sizeof(int)); 

    A = init_timer();
    tri_shell(incr,x,tab,MAX);
    B = init_timer();
    delta_t(A,B,buffer);

}

 /* Resultats : 

time for increment:     1    4   13   40  121  364                     : 0.000273 

time for increment:     1    5   17   53  161  485                     : 0.000253 

time for increment:     1    3    7   15   31   63  127  255           : 0.000282 

time for increment:     1    2    4    8   16   32   64  128  256      : 0.000393 

time for increment:     1    2    5   14   41  122  365                : 0.000264 

time for increment:     1    3   11   43  171                          : 0.000258 

*/
