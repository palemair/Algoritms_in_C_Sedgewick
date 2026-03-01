#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* 6. Combien de comparaisons sont nécessaires pour 7-ordonner puis 3-ordonner */ 
/* les clés de la chaine QUESTIONFACILE ? */

int h_ord (int h, char* tb, int len)
{
    int j, q;
    
    for(int i = h ; i<len; ++i)
    {
        q = tb[i];
        j = i;
        while(j>=h && tb[j-h]>q) 
        {
            tb[j] = tb[j-h];
            j-=h;
            
        }
        tb[j] = q;
        for(int u = 0; u<len;u++) 
            printf("%2c",tb[u]);
        printf("\n\n");
    }
    return EXIT_SUCCESS;
}

int main ()
{
    char p[]="QUESTIONFACILE";
    printf("INITIAL :\n");
    for(int u = 0; u<(int)strlen(p);u++) 
        printf("%2c",p[u]);
    printf("\n7 ORDONNE :\n\n");
    h_ord(7,p,(sizeof(p) / sizeof(p[0])) -1);

    printf("INITIAL :\n");
    for(int u = 0; u<(int)strlen(p);u++) 
        printf("%2c",p[u]);
    printf("\n3 ORDONNE :\n\n");
    h_ord(3,p,(sizeof(p) / sizeof(p[0])) -1);

}

 /* Resultats : 

INITIAL :
 Q U E S T I O N F A C I L E
7 ORDONNE :

 N U E S T I O Q F A C I L E

 N F E S T I O Q U A C I L E

 N F A S T I O Q U E C I L E

 N F A C T I O Q U E S I L E

 N F A C I I O Q U E S T L E

 N F A C I I O Q U E S T L E

 N F A C I I E Q U E S T L O

 7 comparaisons sont nécessaires.

INITIAL :
 N F A C I I E Q U E S T L O
3 ORDONNE :

 C F A N I I E Q U E S T L O

 C F A N I I E Q U E S T L O

 C F A N I I E Q U E S T L O

 C F A E I I N Q U E S T L O

 C F A E I I N Q U E S T L O

 C F A E I I N Q U E S T L O

 C F A E I I E Q U N S T L O

 C F A E I I E Q U N S T L O

 C F A E I I E Q T N S U L O

 C F A E I I E Q T L S U N O

 C F A E I I E O T L Q U N S

 15 comparaisons sont nécessaires.

*/
