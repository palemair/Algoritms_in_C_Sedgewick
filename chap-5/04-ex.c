#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* 4. Donnez les coordonnées engendrées par le programme récursif de dessin d'arbre appliqué à l'arbre binaire de la figure 4.2 */

#define NB 100

typedef struct Node
{
    int data;
    int x,y;
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


static int ye = -1;

void parcours(node tree,int t[][NB],size_t l,size_t r)
{
    ye+=2;
    
    if(tree != NULL)
    {
       size_t m = (l + r) /2;
       t[ye][m-1] = '(';
       t[ye][m] = tree->data;
       t[ye][m+1] = ')';
       if(tree->L != NULL) 
       {
           t[ye+1][(l+m)/2] = '+';
           for(size_t z=(l+m)/2+1; z<m; z++) t[ye+1][z] = '-';
           t[ye+1][m] = '+';
        }

       if(tree->R != NULL)
       {
           for(size_t z=m; z<(m+r)/2 ; z++) t[ye+1][z] = '-';
           t[ye+1][(r+m)/2] = '+';
           t[ye+1][m] = '+';
       }
       parcours(tree->L,t,l,m);
       parcours(tree->R,t,m,r);
    }
    
    ye -=2;
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

/* REPONSE EXERCICE */

static int x = 0;
static int y = 0;
char tb[12][8];

void visiter(node n)
{
    n->x = ++x;
    n->y = y;
    tb[n->x][n->y] = n->data;
    printf("noeud : %c | x : %3d | y : %3d\n",n->data,n->x,n->y); 
}

void infixe(node n)
{
    y++;
    if(n != NULL)
    {
        infixe(n->L);
        visiter(n);
        infixe(n->R);
    }
    y--;
}

int main ()
{

  struct Node* T = nd('T',NULL,nd('E',NULL,nd('O',nd('M',NULL,NULL),nd('N',nd('I',NULL,NULL),NULL))));
  struct Node* R = nd('R',nd('R',nd('A',NULL,NULL),nd('B',NULL,NULL)),NULL);
  struct Node* arbre = nd('E',R,T);

  printf("%20s","Arbre 4.2 :\n");
  printtree(arbre);

  memset(tb,' ',sizeof(tb));

  infixe(arbre);
    
  for(int u = 0;u<8;u++)
  {
      for(int v = 0; v<12;v++)
      {
          printf("%c",tb[v][u]);
      }
      printf("\n");
  }
}

 /* Resultats : 

        Arbre 4.2 :
                                                                                                    
                                                 (E)                                                
                          +-----------------------+-----------------------+                         
                         (R)                                             (T)                        
              +-----------+                                               +-----------+             
             (R)                                                                     (E)            
        +-----+-----+                                                                 +-----+       
       (A)         (B)                                                                     (O)      
                                                                                         +--+--+    
                                                                                        (M)   (N)   
                                                                                             +-+    
                                                                                            (I)     
noeud : A | x :   1 | y :   4
noeud : R | x :   2 | y :   3
noeud : B | x :   3 | y :   4
noeud : R | x :   4 | y :   2
noeud : E | x :   5 | y :   1
noeud : T | x :   6 | y :   2
noeud : E | x :   7 | y :   3
noeud : M | x :   8 | y :   5
noeud : O | x :   9 | y :   4
noeud : I | x :  10 | y :   6
noeud : N | x :  11 | y :   5
            
     E      
    R T     
  R    E    
 A B     O  
        M  N
          I 
            
*/
