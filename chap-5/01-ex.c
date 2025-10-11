#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 1. Ecrivez un programme récursif pour dessiner un arbre tel que la racine apparait au milieu de la page */
/*     ,la racine du sous-arbre gauche au centre de la sous-page gauche ... */

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
int main ()
{
  struct Node* B = nd('B',nd('R',nd('A',NULL,NULL),nd('Y',NULL,NULL)),nd('E',nd('R',NULL,NULL),nd('C',NULL,NULL)));
  struct Node* R = nd('Z',nd('M',nd('O',NULL,NULL),nd('P',NULL,NULL)),nd('E',nd('L',NULL,NULL),nd('T',NULL,NULL)));
  struct Node* arbre = nd('S',B,R);

  printf("%20s","Arbre complet :\n");
  printtree(arbre);
  printf("\n\n");
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


*/
