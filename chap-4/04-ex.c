#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "util.h"

/* 4. En considérant l'arbre de la figure 4.2 comme un arbre généralisé à représenter comme un arbre binaire, */
/*     dessinez cette représentation. */ 

int main ()
{
  struct Node* m = nd('M',NULL,nd('N',nd('I',NULL,NULL),NULL));

  struct Node* t = nd('T',nd('E',nd('O',m,NULL),NULL),NULL);

  struct Node* r = nd('R',nd('A',NULL,nd('B',NULL,NULL)),NULL);

  struct Node* l = nd('R',r,t);
  
  struct Node* e = nd('E',l,NULL);
  
  printf("%20s","Arbre de la figure 4.2 :\n");

  printtree(e);
  printf("\n\n");

  return (EXIT_SUCCESS);
}


 /* Resultats : 

Arbre de la figure 4.2 :
                                                                                                                                                                                                        
                                                                                                   (E)                                                                                                  
                                                   +------------------------------------------------+                                                                                                   
                                                  (R)                                                                                                                                                   
                          +------------------------+-----------------------+                                                                                                                            
                         (R)                                              (T)                                                                                                                           
              +-----------+                                    +-----------+                                                                                                                            
             (A)                                              (E)                                                                                                                                       
              +-----+                                    +-----+                                                                                                                                        
                   (B)                                  (O)                                                                                                                                             
                                                      +--+                                                                                                                                              
                                                     (M)                                                                                                                                                
                                                      ++                                                                                                                                                
                                                      (N)                                                                                                                                               
                                                      ++                                                                                                                                                
                                                     (I)                                                                                                                                                


*/
