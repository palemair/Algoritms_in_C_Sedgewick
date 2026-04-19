#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "util.h"

/* 10. Ecrivez un programme pour implanter le parcours par niveau d'un arbre général représenté */
/*     comme un arbre binaire. */   

int main ()
{
  struct Node* r = nd('R',NULL,nd('E',NULL,nd('T',NULL,nd('E',NULL,NULL))));
  struct Node* o = nd('O',nd('M',r,NULL),nd('N',NULL,NULL));
  struct Node* b = nd('B',nd('A',NULL,nd('R',NULL,NULL)),o);
  struct Node* i = nd('I',b,NULL);
  
  printf("%20s","Arbre de la figure 4.1 représenté comme un arbre binaire :\n");

  printtree(i);
  printf("\n\n");

  node pt;
  
  printf("parcours par niveau");

  enfiler(i);

  while(!file_vide())
  {
      pt = defiler();
      while(pt)
      {
          printf(" %c |",pt->data);
          if(pt->L) enfiler(pt->L);
          pt = pt->R;
      }

  }

  printf("\n");


  return (EXIT_SUCCESS);
}


 /* Resultats : 

Arbre de la figure 4.1 représenté comme un arbre binaire :
                                                                                                    
                                                 (I)                                                
                          +-----------------------+                                                 
                         (B)                                                                        
              +-----------+-----------+                                                             
             (A)                     (O)                                                            
              +-----+           +-----+-----+                                                       
                   (R)         (M)         (N)                                                      
                             +--+                                                                   
                            (R)                                                                     
                             ++                                                                     
                             (E)                                                                    
                              ++                                                                    
                              (T)                                                                   
                               +                                                                    
                              (E)                                                                   


parcours par niveau I | B | O | N | A | R | M | R | E | T | E |
*/
