#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

/* 9. Est-ce la méthode récursive ou itérative la plus rapide pour la graduation d'une règle chap 5 ? */

#define DIM 128
#define DIMH 8

int tb[DIMH][DIM];

void afft (void)
{
  putchar ('\n');
  for (int u = DIMH; u >= 0; u--)
  {
    for (int y = 0; y < DIM; y++)
    {
      (tb[u][y] == '|') ? putchar('|') : putchar(' ');
    }

    putchar ('\n');
  }
  putchar ('\n');
}

void regle (int g, int d, int h)
{
  if (h > 0)
  {
    int m = (g + d) / 2;

    for (int u = 1; u <= h; u++)
      {
          if ((m >= 0 && m < DIM) && (u >= 0 && u < DIMH))
          {
            tb[u][m] = '|';
          }
      }
    regle (g, m, h - 1);
    regle (m + 1, d, h - 1);
  }
}

int hauteur (uint16_t u)
{
  unsigned char i = 1;
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

  printf ("\nVersion iterative 1 :\n");
  memset (tb,0, sizeof tb);

  clock_t A = clock ();
  for (uint16_t v = 1; v < DIM; v++)
  {
    for (int x = 0; x < hauteur (v) + 1; x++)
      tb[x][v] = '|';
  }
  clock_t B = clock ();

  afft ();
  printf("temps mesuré : %f s\n", ((double) B - (double) A) / CLOCKS_PER_SEC);


  printf ("\nVersion recursive :\n");
  memset (tb,0, sizeof tb);
  clock_t E = clock ();

  regle (0, DIM, DIMH - 1);
  clock_t F = clock ();

  afft ();
  printf("temps mesuré : %f s\n", ((double) F - (double) E) / CLOCKS_PER_SEC);
  return 0;
}


 /* Resultats : 

on note un petit avantage pour le récursif

Version iterative :

                                                                                                                                
                                                                                                                                
                                                                |                                                               
                                |                               |                               |                               
                |               |               |               |               |               |               |               
        |       |       |       |       |       |       |       |       |       |       |       |       |       |       |       
    |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   
  | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | 
 |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

temps mesuré : 0.000007 s

Version recursive :

                                                                                                                                
                                                                |                                                               
                                |                               |                               |                               
                |               |               |               |               |               |               |               
        |       |       |       |       |       |       |       |       |       |       |       |       |       |       |       
    |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   
  | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | 
 |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
                                                                                                                                

temps mesuré : 0.000004 s
*/
