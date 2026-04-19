#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "util.h"

/* 7. Donnez un exemple d'arbre pour lequel la pile utilise plus de place pendant un parcours préfixé que la */
/*     file pendant un parcours par niveau. */

void visit(node nd)
{
     printf(" %c |",nd->data);
}

int main ()
{
  struct Node* r = nd('R',NULL,nd('E',NULL,nd('T',NULL,nd('E',NULL,NULL))));
  struct Node* o = nd('O',r,nd('N',NULL,NULL));
  struct Node* pt ;

  enfiler(o);

  printf("   |");
  while(!file_vide())
  {
    print_file();
    pt =defiler();
    visit(pt);
    if(pt->L) enfiler(pt->L);
    if(pt->R) enfiler(pt->R);
  }

  printf("\n\n");

  empiler(o);

  printf("   |");
  while(!pile_vide())
  {
    print_pile();
    pt =depiler();
    visit(pt);
    if(pt->R) empiler(pt->R);
    if(pt->L) empiler(pt->L);
  }

  printf("\n");

  return (EXIT_SUCCESS);
}

 /* Resultats : 

   | File : O -
 O | File : N -R -
 R | File : E -N -
 N | File : E -
 E | File : T -
 T | File : E -
 E |

   | Pile : O -
 O | Pile : N -R -
 R | Pile : N -E -
 E | Pile : N -T -
 T | Pile : N -E -
 E | Pile : N -
 N |
*/
