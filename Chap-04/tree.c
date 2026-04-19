#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "util.h"

node nd(int c,node L, node R)
{
    node root = malloc(sizeof(*root));
    root->data = c;
    root->L = L;
    root->R = R;
    
    return root;
}

void insert(struct Node **tree,char val)
{
    if(*tree == NULL)
    {
        node new = malloc(sizeof(node));
        new->data = val;
        new->L = NULL;
        new->R = NULL;

        *tree = new;
    }
    else
    {
        if(val <= (*tree)->data) insert(&(*tree)->L,val);
        else insert(&(*tree)->R,val);
    }
}

struct Node* append(struct Node *tree,char val)
{
    if (!tree) return nd(val,NULL,NULL);

    if(val <= tree->data)
    {
        tree->L = append(tree->L,val);
    }

    else
    {
        tree->R = append(tree->R,val);
    }
    return tree;
}

void visiter(node nd)
{
     printf(" %c |",nd->data);
}

void preorder(node tree)
{
    if(tree != NULL)
    {
        visiter(tree);
        preorder(tree->L);
        preorder(tree->R);
    }
}

void inorder(node tree)
{
    if(tree != NULL)
    {
       inorder(tree->L);
       visiter(tree);
       inorder(tree->R);
    }
}

void postorder(node tree)
{
    if(tree != NULL)
    {
       postorder(tree->L);
       postorder(tree->R);
       visiter(tree);
    }
}

void postorder_iter(node pt)
{
  struct Node * p2 = NULL;
  
    while(1)
    {
        while (pt != NULL)
        {
            if(pt->R) empiler(pt->R);
            empiler(pt);
            pt = pt->L;
        }
        if(pile_vide()) break;
        pt = depiler();
        p2 = consult();

        if((pt->R != NULL) && (p2 == pt->R)) 
        {
            depiler();
            empiler(pt);
            pt = pt->R;
        }
        else
        {
            printf("-> %c | ", pt->data);
            pt = NULL;
        }
    }
    printf("\n");
}

bool is_in(struct Node * pt, int test)
{
    if (pt != NULL)
    {
        if (pt->data == test) return true;
        
        return((test < pt->data) ? is_in(pt->L, test) : is_in(pt->R, test));
    }
    return false;
}

int min(struct Node * pt)
{
    if (pt->L != NULL)
    {
        return(min(pt->L));
    }
    return pt->data;
}

int rmax(int a, int b)
{
    return a>=b ? a : b;
}

int taille(struct Node * pt)
{
    if (pt == NULL)
    {
        return 0;
    }
    return (1 + (taille(pt->L) + taille(pt->R)));
}

int chemin(struct Node * pt,int x)
{
    if (pt == NULL)
    {
        return 0;
    }
    return (x + (chemin(pt->L,x+1) + chemin(pt->R,x+1)));
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
  int h = hauteur(root) * 2  + 2;
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
