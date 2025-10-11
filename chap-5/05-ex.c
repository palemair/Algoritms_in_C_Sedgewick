#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

static int pile[MAX + 1];

static int sp = -1;

bool pile_vide(void)
{
    return sp == -1;
}

void empiler(int v)
{
   if(sp < MAX)
   {
       pile[++sp] = v;
   }
}

int depiler(void)
{
   if(!pile_vide())
   {
       return pile[sp--];
   }
   return -1;
}


int fibo_rec(int N)
{
    if(N <= 1) 
        return 1;
    else
        return(fibo_rec(N-2) + fibo_rec(N-1));
}

int fibo_derec(int N)
{

g : if(N<=1) goto x;
    N = N -1;

      
x: 
   empiler(depiler() + depiler());
}

int main ()
{
  for(int u = 0; u<12; u++)  printf("Nombre de fibonacci : %d\n",fibo_rec(u));
  
}
