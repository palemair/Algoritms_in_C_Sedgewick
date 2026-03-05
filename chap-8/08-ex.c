#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 8. Le tri par selection est-il stable ? même question pour celui par insertion et à bulles. */

#define PRINTAB(t,x) for(int u = 0; u<(x);u++) printf("%4c",t[u].c);printf("\n")
#define PRINTPOS(t,x) for(int u = 0; u<(x);u++) printf("%4zu",t[u].position);printf("\n\n")

typedef struct value {
        char c;
        size_t position;
} value;
    
/* tri par selection */
int tri_selection (value* t, size_t nbelem)
{
    value tmp;
    size_t j, min;

    for (size_t i = 0; i < nbelem - 1 ; i++)
    {
        min = i;
        for (j = i + 1; j < nbelem; j++)
        {
            if (t[j].c <= t[min].c) min = j;
        }

        tmp = t[i];
        t[i] = t[min];
        t[min] = tmp;
    }
    return EXIT_SUCCESS;
}

/* tri à bulles */
int tri_bulles (value* t, size_t nbelem)
{
    int i, j;
    value v;

    for(i = nbelem-1;i>=0;i--)
        for(j = 1;j<=i;j++)
            if(t[j-1].c > t[j].c)
            {
                v = t[j-1];
                t[j-1] = t[j];
                t[j] = v;
            }

    return EXIT_SUCCESS;
}

/* tri par insertion */
int tri_insertion (value* t, size_t nbelem)
{
    int j;
    value q;
    for (size_t i = 1; i < nbelem; i++)
    {
        q = t[i];
        j = i; 
        while (j>0 && (t[j-1].c > q.c))
            {
                t[j]=t[j-1];
                j--;
            }
            t[j] = q;
    }
    return EXIT_SUCCESS;
}

int main ()
{
    char str[]="BCEDFETAB";
    int len = strlen(str);

    value t[len];
    
    for(int u = 0; u<len;u++) {
        t[u].c = str[u];
        t[u].position = u+1;
    }

    value t2[len];
    memcpy(t2,t, sizeof t);

    value t3[len];
    memcpy(t3,t, sizeof t);

    printf("chaine à trier\n%s\n\n",str);
    PRINTAB(t,len);
    PRINTPOS(t,len);

    puts("   TRI SELECTION\n");

    tri_selection(t,len);
    PRINTAB(t,len);
    PRINTPOS(t,len);

    puts("   TRI INSERTION\n");
    tri_insertion(t2,len);
    PRINTAB(t2,len);
    PRINTPOS(t2,len);

    puts("   TRI BULLES\n");
    tri_bulles(t3,len);
    PRINTAB(t3,len);
    PRINTPOS(t3,len);
}

 /* Resultats : 

chaine à trier
BCEDFETAB

   B   C   E   D   F   E   T   A   B
   1   2   3   4   5   6   7   8   9

   TRI SELECTION

   A   B   B   C   D   E   E   F   T
   8   9   1   2   4   3   6   5   7

   TRI INSERTION

   A   B   B   C   D   E   E   F   T
   8   1   9   2   4   3   6   5   7

   TRI BULLES

   A   B   B   C   D   E   E   F   T
   8   1   9   2   4   3   6   5   7

  Sur cet exemple on constate que le tri selection n'est pas stable :
  l'echange de valeur envoi la case evaluée à une position aléatoire.
  
  En revanche les tris bulles et insertion conserve l'ordre relatif des éléments
  chaque valeur est 'controlée' pour atteindre sa position 'définitive' :
    relative aux éléments déjà triés -> insertion
    absolue -> bulles
*/
