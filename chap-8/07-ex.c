#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 7. Donnez un exemple simple montrant pourquoi 8, 4, 2, 1 n'est pas un */ 
/* bon candidat pour terminer une suite d'incréments du tri shell ? */

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
    }
    return EXIT_SUCCESS;
}

int main ()
{
    char p[]="ABABABABABABABABABABABABAB";

    printf("Contenu initial 1 : ");
    puts(p);
    printf("\nh-ordonne avec une suite 8,4,2 : \n\n");
    for(int x = 8; x>=2;x/=2)
    {
        h_ord(x,p,(sizeof(p) / sizeof(p[0])) -1);
        printf("Passe %3d : ",x);
        for(int u = 0; u<(int)strlen(p);u++) 
            printf("%2c",p[u]);
        printf("\n");
    }

    printf("\nAvec une suite 13,4 : \n\n");
    for(int x = 13; x>=4;x/=3)
    {
        h_ord(x,p,(sizeof(p) / sizeof(p[0])) -1);
        printf("Passe %3d : ",x);
        for(int u = 0; u<(int)strlen(p);u++) 
            printf("%2c",p[u]);
        printf("\n");
    }

    printf("\n\nOn constate que le fichier est intact dans le premier cas\nmais trié au premier tour 13 dans le 2eme.\n\n");

    char origine[]="AABBAABBAABBAABBAABBAABBAA";

    char t[]="AABBAABBAABBAABBAABBAABBAA";

    printf("Contenu initial 2 : ");
    puts(t);
    printf("\nh-ordonne avec une suite 8,4,2 : \n\n");
    for(int x = 16; x>=4;x/=2)
    {
        h_ord(x,t,(sizeof(t) / sizeof(t[0])) -1);
        printf("Passe %3d : ",x);
        for(int u = 0; u<(int)strlen(t);u++) 
            printf("%2c",t[u]);
        printf("\n");
    }

    memcpy(t,origine,strlen(t)+1);
    printf("\nAvec une suite 13,4 : \n\n");
    for(int x = 13; x>=4;x/=3)
    {
        h_ord(x,t,(sizeof(t) / sizeof(t[0])) -1);
        printf("Passe %3d : ",x);
        for(int u = 0; u<(int)strlen(t);u++) 
            printf("%2c",t[u]);
        printf("\n");
    }
    printf("\n\nLes résultats ne sont pas meilleurs avec une suite 'inverse'\n");
}

 /* Resultats : 

Contenu initial 1 : ABABABABABABABABABABABABAB

h-ordonne avec une suite 8,4,2 : 

Passe   8 :  A B A B A B A B A B A B A B A B A B A B A B A B A B
Passe   4 :  A B A B A B A B A B A B A B A B A B A B A B A B A B
Passe   2 :  A B A B A B A B A B A B A B A B A B A B A B A B A B

Avec une suite 13,4 : 

Passe  13 :  A A A A A A A A A A A A A B B B B B B B B B B B B B
Passe   4 :  A A A A A A A A A A A A A B B B B B B B B B B B B B


On constate que le fichier est intact dans le premier cas
mais trié au premier tour 13 dans le 2eme.

Contenu initial 2 : AABBAABBAABBAABBAABBAABBAA

h-ordonne avec une suite 8,4,2 : 

Passe  16 :  A A B B A A B B A A B B A A B B A A B B A A B B A A
Passe   8 :  A A B B A A B B A A B B A A B B A A B B A A B B A A
Passe   4 :  A A B B A A B B A A B B A A B B A A B B A A B B A A

Avec une suite 13,4 : 

Passe  13 :  A A B A A A B A A A B A A A B B B A B B B A B B B A
Passe   4 :  A A B A A A B A A A B A A A B B B A B B B A B B B A


Les résultats ne sont pas meilleurs avec une suite 'inverse'
*/
