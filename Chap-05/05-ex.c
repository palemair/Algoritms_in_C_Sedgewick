#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/* 5. Supprimez de manière mécanique la récursion du programme `Fibonacci` présenté dans le texte pour obtenir une version itérative. */

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
   return 1;
}

int fibo_rec(int N)
{
    if(N == 0) return 0;
    if(N == 1) return 1;
    else
        return(fibo_rec(N-1) + fibo_rec(N-2));
}

int fibo_derec(int N)
{
    empiler(N);
    int u,res = 0;

g : u = depiler();
    if(u<2) goto x;
    empiler(u-1);
    empiler(u-2);
    goto g;

x : res += u;
    if(pile_vide()) goto e;
    goto g;

e: return res;

}

int fib_derec(int N)
{
    int u,res = 0;
    empiler(N);
    while(!pile_vide())
    {
        u = depiler();
        if(u<2) 
        {
            res += u;
        }
        else
        {
            empiler(u-1);
            empiler(u-2);
        }
    }
    return res;
}

int test(int (*fct)(int),int a)
{
  for(int u = 0; u<a; u++)  printf("%8d",fct(u));
  printf("\n\n");
  return 0;
}

int main ()
{
      int n = 20;
      printf("Suite de fibonacci fonction recursive\n");
      test(fibo_rec, n);

      printf("Suite de fibonacci fonction goto\n");
      test(fibo_derec, n);

      printf("Suite de fibonacci fonction derecursivée\n");
      test(fib_derec, n);
}

 /* Resultats : 

Suite de fibonacci fonction recursive
       0       1       1       2       3       5       8      13      21      34      55      89     144     233     377     610     987    1597    2584    4181

Suite de fibonacci fonction goto
       0       1       1       2       3       5       8      13      21      34      55      89     144     233     377     610     987    1597    2584    4181

Suite de fibonacci fonction derecursivée
       0       1       1       2       3       5       8      13      21      34      55      89     144     233     377     610     987    1597    2584    4181

*/
