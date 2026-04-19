#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "util.h"

/* 7. Examinez le programme en langage machine produit par le compilateur C de votre système pour */
/* l'algorthme de parcours préfixé d'arbre du parcours d'arbre du chap 5. */

static node z;

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

  prefixe(root);

  return 0;
}
