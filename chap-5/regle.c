#include <stdio.h>
#include <string.h>

#define DIM 32
#define DIMH 6

int tb[DIMH][DIM];

void afft (void)
{
  putchar ('\n');
  for (int u = DIMH; u >= 0; u--)
  {
    for (int y = 0; y < DIM; y++)
    {
      printf (" %c ", tb[u][y]);
    }

    putchar ('\n');
  }
  putchar ('\n');
}

void point (int x, int y, char c)
{
  if ((x >= 0 && x < DIM) && (y >= 0 && y < DIMH))
  {
    tb[y][x] = c;
  }
}

void marquer (int x, int h)
{
  for (int u = 1; u <= h; u++)
  {
    point (x, u, '|');
  }
}

void regle (int g, int d, int h)
{
  if (h > 0)
  {
    int m = (g + d) / 2;

    marquer (m, h);
    regle (g, m, h - 1);
    regle (m + 1, d, h - 1);
  }
}

int hauteur (size_t u)
{
  unsigned int i = 1;
  int count = 0;

  while ((u & i) == 0)
  {
    count++;
    u >>= i;
  }
  return count;
}

int main ()
{

  printf ("\nVersion iterative :\n");
  memset (tb, ' ', sizeof tb);

  for (size_t v = 1; v < DIM; v++)
  {
    for (int x = 0; x < hauteur (v) + 1; x++)
      tb[x][v] = '|';
  }

  afft ();
  printf ("\nVersion recursive :\n");
  memset (tb, ' ', sizeof tb);
  regle (0, DIM, DIMH - 1);
  afft ();
  return 0;
}

 /* Resultats : 


Version iterative :

                                                                                                
                                                 |                                              
                         |                       |                       |                      
             |           |           |           |           |           |           |          
       |     |     |     |     |     |     |     |     |     |     |     |     |     |     |    
    |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  | 


Version recursive :

                                                 |                                              
                         |                       |                       |                      
             |           |           |           |           |           |           |          
       |     |     |     |     |     |     |     |     |     |     |     |     |     |     |    
    |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  | 
                                                                                                

*/
