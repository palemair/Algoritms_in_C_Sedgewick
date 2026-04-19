#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "util.h"

/* 6. Donnez le contenu de la file chaque fois qu'un noeud est visiter pendant le parcours */
/*     par niveau de la figure 4.12. */ 

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

  enfiler(arbre);

  printf("   |");
  while(!file_vide())
  {
    print_file();
    pt =defiler();
    visit(pt);
    if(pt->L) enfiler(pt->L);
    if(pt->R) enfiler(pt->R);
  }

  printf("\n");

  return (EXIT_SUCCESS);
}

 /* Resultats : 

   | File : E -
 E | File : T -R -
 R | File : R -T -
 T | File : E -R -
 R | File : B -A -E -
 E | File : O -B -A -
 A | File : O -B -
 B | File : O -
 O | File : N -M -
 M | File : N -
 N | File : I -
 I |
*/
