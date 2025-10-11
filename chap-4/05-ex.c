#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "util.h"

/* 5. Donnez le contenu de la pile chaque fois qu'un noeud est visiter pendant le parcours */
/*     prefixé de la figure 4.9. */ 

void visit(node nd)
{
     printf(" %c |",nd->data);
}

int main ()
{
  struct Node* T = nd('T',NULL,nd('E',NULL,nd('O',nd('M',NULL,NULL),nd('N',nd('I',NULL,NULL),NULL))));
  struct Node* R = nd('R',nd('R',nd('A',NULL,NULL),nd('B',NULL,NULL)),NULL);
  struct Node* arbre = nd('E',R,T);

  struct Node* pt ;

  empiler(arbre);

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

   | Pile : E -
 E | Pile : T -R -
 R | Pile : T -R -
 R | Pile : T -B -A -
 A | Pile : T -B -
 B | Pile : T -
 T | Pile : E -
 E | Pile : O -
 O | Pile : N -M -
 M | Pile : N -
 N | Pile : I -
 I |
*/
