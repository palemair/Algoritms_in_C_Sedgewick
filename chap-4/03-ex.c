#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "util.h"

/* 3. Dessinez l'arbre syntaxique de l'expression (A+B)*C+(D+E) */

int main ()
{
  char tab[] = "(A+B)*C+(D+E)";
  node x, y;
  char *pt = tab;
  bool mul = false;
  
  while(*pt != '\0')
  {
      if((*pt >= 'A') && (*pt <= 'Z'))
      {
          x = nd(*pt,NULL,NULL);
          
          if(mul)
          {
              y = depiler();
              y->R = x;
              empiler(y);
              mul = false;
          }
          else
          {
              empiler(x);
          }
      }
      
      if(*pt == '+') 
      {
          x = nd(*pt,NULL,NULL);
          x->L = depiler();
          empiler(x);
      }

      if(*pt == '*') 
      {
          x = nd(*pt,NULL,NULL);
          x->L = depiler();
          empiler(x);
          mul = true;
      }
      if(*pt == ')') 
      {
          x = depiler();
          y = depiler();
          y->R = x;
          empiler(y);
      }
      pt++; 
  }
  
  x = depiler();
  y = depiler();
  y->R = x;

  printtree(y);
  printf("\n");

  return (EXIT_SUCCESS);
}

 /* Resultats : 

                                                                                                                        
                                                           (+)                                                          
                               +----------------------------+----------------------------+                              
                              (*)                                                       (+)                             
                +--------------+-------------+                            +--------------+-------------+                
               (+)                          (C)                          (D)                          (E)               
         +------+------+                                                                                                
        (A)           (B)                                                                                               
                                                                                                                        

*/
