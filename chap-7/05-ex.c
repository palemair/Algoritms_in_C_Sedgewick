#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/* 5. Verifiez l'assertion selon laquelle la suppression de la récursion dans l'algorithme de parcours préfixé d'arbre */
/* du chap 5 (avec un accès direct à la pile) rend le programme plus efficace. */

typedef struct Node
{
    int data;
    struct Node* L;
    struct Node* R;
} * node;

node nd(int c,node L, node R)
{
    node root = malloc(sizeof(*root));
    root->data = c;
    root->L = L;
    root->R = R;
    
    return root;
}

#define MAX 100

static node pile[MAX + 1];
static int sp = -1;

bool pile_vide(void)
{
    return sp == -1;
}

void empiler(node v)
{
   if(sp < MAX)
   {
       pile[++sp] = v;
   }
}

node depiler(void)
{
   if(!pile_vide())
   {
       return pile[sp--];
   }
   return NULL;
}

node consult(void)
{
    return pile[sp];
}

int rmax(int a, int b)
{
    return a>=b ? a : b;
}

int hauteur(struct Node * pt)
{
    if (pt == NULL)
    {
        return -1;
    }
    return (1 + rmax(hauteur(pt->L) , hauteur(pt->R)));
}

static int y = -1;
#define NB 100

void parcours(node tree,int t[][NB],size_t l,size_t r)
{
    y+=2;
    
    if(tree != NULL)
    {
       size_t m = (l + r) /2;
       t[y][m-1] = '(';
       t[y][m] = tree->data;
       t[y][m+1] = ')';
       if(tree->L != NULL) 
       {
           t[y+1][(l+m)/2] = '+';
           for(size_t z=(l+m)/2+1; z<m; z++) t[y+1][z] = '-';
           t[y+1][m] = '+';
        }

       if(tree->R != NULL)
       {
           for(size_t z=m; z<(m+r)/2 ; z++) t[y+1][z] = '-';
           t[y+1][(r+m)/2] = '+';
           t[y+1][m] = '+';
       }
       parcours(tree->L,t,l,m);
       parcours(tree->R,t,m,r);
    }
    
    y-=2;
}

void printtree(node root)
{
  int h = (hauteur(root) + 1)* 2 ;
  int tab[h][NB];
  
  for(int u = 0; u <h ;u++)
  {
      for (int i=0;i<NB;i++) tab[u][i] = ' ';
  }

  parcours(root,tab,2,NB-2);
  
  for(int u = 0; u <h;u++)
  {
      for (int i=0;i<NB;i++) printf("%c",tab[u][i]);
      printf("\n");
  }
}

/* version recursive du pacours prefixe */
void prefixe(node pt)
{
    if(pt != NULL)
    {
        printf("-> %c | ", pt->data);
        prefixe(pt->L);
        prefixe(pt->R);
    }
}

/* version itérative du pacours prefixe */
void iprefixe(node pt)
{
  empiler(pt);
  
  while (! pile_vide())
        {
            pt = depiler();
            printf("-> %c | ", pt->data);
            if(pt->R != NULL) empiler(pt->R);
            if(pt->L != NULL) empiler(pt->L);
        }
}

int main ()
{
  struct Node* B = nd('B',nd('R',nd('A',NULL,NULL),nd('Y',NULL,NULL)),nd('E',nd('R',NULL,NULL),nd('C',NULL,NULL)));
  struct Node* R = nd('Z',nd('M',nd('O',NULL,NULL),nd('P',NULL,NULL)),nd('E',nd('L',NULL,NULL),nd('T',NULL,NULL)));
  struct Node* arbre = nd('S',B,R);

  printf("%20s","Arbre complet :\n");
  printtree(arbre);
  printf("\n\n");
  
  clock_t A = clock ();
  
  prefixe(arbre);

  printf("\n\n");
  
  clock_t F = clock ();
  printf("temps mesuré recursif : %f s\n\n", ((double) F - (double) A) / CLOCKS_PER_SEC);

  clock_t C = clock ();
  iprefixe(arbre);
  printf("\n\n");
  clock_t D = clock ();
  printf("temps mesuré itératif : %f s\n\n", ((double) D - (double) C) / CLOCKS_PER_SEC);

  return 0;
}

 /* Resultats : 

    Arbre complet :
                                                                                                    
                                                 (S)                                                
                          +-----------------------+-----------------------+                         
                         (B)                                             (Z)                        
              +-----------+-----------+                       +-----------+-----------+             
             (R)                     (E)                     (M)                     (E)            
        +-----+-----+           +-----+-----+           +-----+-----+           +-----+-----+       
       (A)         (Y)         (R)         (C)         (O)         (P)         (L)         (T)      


-> S | -> B | -> R | -> A | -> Y | -> E | -> R | -> C | -> Z | -> M | -> O | -> P | -> E | -> L | -> T | 

temps mesuré recursif : 0.000006 s

-> S | -> B | -> R | -> A | -> Y | -> E | -> R | -> C | -> Z | -> M | -> O | -> P | -> E | -> L | -> T | 

temps mesuré itératif : 0.000005 s

*/
