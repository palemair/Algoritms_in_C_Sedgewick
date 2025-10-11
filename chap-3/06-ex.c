#include <stdio.h>
#include <stdlib.h>

#define max 10

/* 6. Ecrivez les primitives relatives à une représentation de pile par liste chaînées mais utilisant des */
/*    tableaux parallèles. */

static int cle[max + 1], suivant[max + 1];

static int debut,sp;

void initialise(void)
{
    debut = 0;
    sp = 1;
    suivant[debut] = 1;
    suivant[sp] = sp;
}

void print_list (void)
{
    int u = suivant[debut];
    while(suivant[u] != u)
    {
        u = suivant[u];
        printf("%2d > ",cle[u]);
    }
    puts("EOL");
}

void empiler (int t)
{
    suivant[sp] = sp + 1;
    sp++;
    cle[sp] = t;
    suivant[sp] = sp;
}

int depiler(void)
{
    int t = cle[sp];
    sp--;
    suivant[sp] = sp;
    return t;
}

int main(void)
{
    initialise();
    print_list();
    empiler(7);
    empiler(8);
    empiler(9);
    
    print_list();
    
    depiler();
    depiler();
    print_list();

    return 0;
}

 /* Resultats : 

EOL
 7 >  8 >  9 > EOL
 7 > EOL
*/
