#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "util.h"

/* 1. Donnez la succession des noeuds lors des parcours préfixé,
 *    infixé, postfixé et par niveau de l'arbre fig 4.3. */

int main ()
{
  struct Node* B = nd('B',nd('R',nd('A',NULL,NULL),nd(' ',NULL,NULL)),nd('E',nd('R',NULL,NULL),nd('C',NULL,NULL)));
  struct Node* R = nd(' ',nd('M',nd('O',NULL,NULL),nd('P',NULL,NULL)),nd('E',nd('L',NULL,NULL),nd('T',NULL,NULL)));
  struct Node* arbre = nd(' ',B,R);

  printf("%20s","Arbre de la figure 4.3 :\n");
  printtree(arbre);
  printf("\n\n");

  printf("%20s","Preorder :");
  preorder(arbre);
  printf("\n\n");

  printf("%20s","Inorder :");
  inorder(arbre);
  printf("\n\n");

  printf("%20s","Postorder :");
  postorder(arbre);
  printf("\n\n");

  node pt = arbre;

  printf("%20s","Level :");
  enfiler(pt);

  while(!file_vide())
  {
      pt = defiler();
      visiter(pt);
      if(pt->L) enfiler(pt->L);
      if(pt->R) enfiler(pt->R);
  }

  printf("\n\n");

  return (EXIT_SUCCESS);
}

 /* Resultats : 

Arbre de la figure 4.3 :
                                                                                                                        
                                                           ( )                                                          
                               +----------------------------+----------------------------+                              
                              (B)                                                       ( )                             
                +--------------+-------------+                            +--------------+-------------+                
               (R)                          (E)                          (M)                          (E)               
         +------+------+              +------+------+              +------+------+              +------+------+         
        (A)           ( )            (R)           (C)            (O)           (P)            (L)           (T)        
                                                                                                                        


          Preorder :   | B | R | A |   | E | R | C |   | M | O | P | E | L | T |

           Inorder : A | R |   | B | R | E | C |   | O | M | P |   | L | E | T |

         Postorder : A |   | R | R | C | E | B | O | P | M | L | T | E |   |   |

             Level :   | B |   | R | E | M | E | A |   | R | C | O | P | L | T |

*/
