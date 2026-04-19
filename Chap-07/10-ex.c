#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "util.h"

/* 10. Déterminez le nombre exact d'empilements supplémentaires nécessaires à l'implantation */
/* itérative du chapitre 5 pour le parcours préfixé d'un arbre complet contenant 2n-1 noeuds ? */

static node z;
static int y = -1;
#define NB 120

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

/* version itérative du pacours prefixe */
void prefixe(node pt)
{
  empiler(pt);
  
  while (! pile_vide())
        {
            print_pile();
            pt = depiler();
            if(pt->R != NULL) empiler(pt->R);
            if(pt->L != NULL) empiler(pt->L);
        }
}

node insert(node *root,char elem)
{
    node tmp = malloc(sizeof(*tmp));
    tmp->data = elem;
    tmp->L = z;
    tmp->R = z;

    if (*root == NULL) 
    {
        return tmp;
    }
    else
    {
        node tp = z;
        enfiler(*root);
        while(!file_vide())
        {
            tp = defiler();
            if(tp->L == z) 
            {
                tp->L = tmp;
                break;
            }
            else enfiler(tp->L);

            if(tp->R == z) 
            {
                tp->R = tmp;
                break;
            }
            else enfiler(tp->R);
        }
    return *root;
    }
}

int main ()
{
  char *str = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmn";

  node root = NULL;

  for(char *c = str; *c != '\0'; c++)
  {
      root = insert(&root,*c);
  }

  printf("Sur cet exemple, on constate que le nombre d'empilements est directement celui de la hauteur de l'arbre\n\n");
  printf("%20s","Arbre complet :\n");
  printtree(root);
  printf("\n\n");
  
  prefixe(root);

  return 0;
}


 /* Resultats : 

Sur cet exemple, on constate que le nombre d'empilements est directement celui de la hauteur de l'arbre

    Arbre complet :
                                                                                                                        
                                                           (A)                                                          
                               +----------------------------+----------------------------+                              
                              (B)                                                       (C)                             
                +--------------+-------------+                            +--------------+-------------+                
               (D)                          (E)                          (F)                          (G)               
         +------+------+              +------+------+              +------+------+              +------+------+         
        (H)           (I)            (J)           (M)            (K)           (N)            (O)           (P)        
     +---+--+      +---+---+      +---+--+      +---+---+      +---+--+      +---+---+      +---+--+      +---+---+     
    (L)    (Q)    (R)     (U)    (S)    (V)    (W)     (a)    (T)    (X)    (Y)     (b)    (Z)    (c)    (d)     (e)    
   +-+-+  +-+-+  +-+-+   +-+    +-+                          +-+                                                        
  (f) (g)(h) (l)(i) (m) (n)    (j)                          (k)                                                         


 -> A | 
 -> C | B | 
 -> C | E | D | 
 -> C | E | I | H | 
 -> C | E | I | Q | L | 
 -> C | E | I | Q | g | f | 
 -> C | E | I | Q | g | 
 -> C | E | I | Q | 
 -> C | E | I | l | h | 
 -> C | E | I | l | 
 -> C | E | I | 
 -> C | E | U | R | 
 -> C | E | U | m | i | 
 -> C | E | U | m | 
 -> C | E | U | 
 -> C | E | n | 
 -> C | E | 
 -> C | M | J | 
 -> C | M | V | S | 
 -> C | M | V | j | 
 -> C | M | V | 
 -> C | M | 
 -> C | a | W | 
 -> C | a | 
 -> C | 
 -> G | F | 
 -> G | N | K | 
 -> G | N | X | T | 
 -> G | N | X | k | 
 -> G | N | X | 
 -> G | N | 
 -> G | b | Y | 
 -> G | b | 
 -> G | 
 -> P | O | 
 -> P | c | Z | 
 -> P | c | 
 -> P | 
 -> e | d | 
 -> e | 
*/
