#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* 9. Donnez une version spécialisée de comptage d'occurences permettant de trier un fichier dont */
/*     les éléments sont égaux à une valeur parmi 2 possibles (x ou y). */

#define PRINTAB(t,x) for(int u = 0; u<(x);u++) printf("%2c",t[u]);printf("\n\n")

void melange (void* tb, size_t sizetb, size_t size)
{
    srand (time (NULL));
    unsigned char* ptr = tb;
    unsigned char temp[size];
    unsigned int j = 0;

    for (size_t i = sizetb - 1; i > 0; i--)
    {
        j = rand () % i;
        memcpy (temp, (ptr + (size * i)), size);
        memcpy ((ptr + (size * i)), (ptr + (size * j)), size);
        memcpy ((ptr + (size * j)), temp, size);
    }
}

int tri_compteur (char* t, char first, int nbelem)
{
    int temp[2] = {-1,nbelem-1};
    char s[nbelem];

    for(int x=0;x<nbelem;x++)
       if(t[x]==first) temp[0]++;

    for(int u=nbelem-1;u>=0;u--)
        (t[u]==first)?(s[temp[0]--] = t[u]):(s[temp[1]--]=t[u]);

    for(int i=0;i<nbelem;i++)
        t[i]=s[i];
    return EXIT_SUCCESS;
}

int main ()
{
    const int MAX = 30;
    char t[MAX];
    for(int u=0;u<MAX;u++)
        t[u] = 'a';

    for(int u=0;u<MAX/2;u++)
        t[u] = 'z';

    melange(t,sizeof t,sizeof t[0]);
    PRINTAB(t,MAX);

    tri_compteur(t,'a',MAX);
    PRINTAB(t,MAX);

    tri_compteur(t,'z',MAX);
    PRINTAB(t,MAX);
}

 /* Resultats : 

 a z z z a z a a a z a a z z z a a a z z z a z a a a a z z z

 a a a a a a a a a a a a a a a z z z z z z z z z z z z z z z

 z z z z z z z z z z z z z z z a a a a a a a a a a a a a a a

*/
