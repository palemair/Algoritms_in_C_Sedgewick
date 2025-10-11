#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 3. Ecrivez un programme récursif pour calculer la longueur totale de chemin extérieur d'un arbre général représenté */
/*     comme un arbre binaire. */

#define NB 100

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

/* FONCTION DE CALCUL DE LONGUEUR TOTALE DE CHEMINS */
int chemin(struct Node * pt,int x)
{
    if (pt == NULL)
    {
        return 0;
    }
    return (x + (chemin(pt->L,x+1) + chemin(pt->R,x)));
}

int main ()
{
  struct Node* r = nd('R',NULL,nd('E',NULL,nd('T',NULL,nd('E',NULL,NULL))));
  struct Node* o = nd('O',nd('M',r,NULL),nd('N',NULL,NULL));
  struct Node* b = nd('B',nd('A',NULL,nd('R',NULL,NULL)),o);
  struct Node* i = nd('I',b,NULL);
  
  printf("%20s","Arbre de la figure 4.1 représenté comme un arbre binaire :\n");

  printtree(i);
  printf("\n\n");

  printf("Longueur totale de chemin : %d \n\n",chemin(i,0));
}

 /* Resultats : 

Arbre de la figure 4.1 représenté comme un arbre binaire :
                                                                                                    
                                                 (I)                                                
                          +-----------------------+                                                 
                         (B)                                                                        
              +-----------+-----------+                                                             
             (A)                     (O)                                                            
              +-----+           +-----+-----+                                                       
                   (R)         (M)         (N)                                                      
                             +--+                                                                   
                            (R)                                                                     
                             ++                                                                     
                             (E)                                                                    
                              ++                                                                    
                              (T)                                                                   
                               +                                                                    
                              (E)                                                                   


Longueur totale de chemin : 21 

*/
