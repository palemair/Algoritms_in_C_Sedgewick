#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "util.h"

/* 9. Donnez une implantation à base de pile du parcours postfixé d'un arbre binaire. */

void visit(node nd)
{
     printf(" %c |",nd->data);
}

void postorder_it(node pt)
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
            visit(pt);
            pt = NULL;
        }
    }
    printf("\n");
}


int main ()
{
  struct Node* T = nd('T',NULL,nd('E',NULL,nd('O',nd('M',NULL,NULL),nd('N',nd('I',NULL,NULL),NULL))));
  struct Node* R = nd('R',nd('R',nd('A',NULL,NULL),nd('B',NULL,NULL)),NULL);
  struct Node* arbre = nd('E',R,T);

  postorder_it(arbre);


  printf("\n");

  return (EXIT_SUCCESS);
}


 /* Resultats : 

 A | B | R | R | M | I | N | O | E | T | E |

*/
