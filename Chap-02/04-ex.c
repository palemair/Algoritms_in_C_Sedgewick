#include <stdio.h>
#include <string.h>
#define MAX 50

/* 4. Ecrivez une fonction **int convertir ()** qui lit un nombre décimal 
 *    chiffre après chiffre, s'arrête à la rencontre d'un espace */

int convertir (char *str)
{
    char c;
    int i = 0;
    int n = 0;

    while ((i < MAX))
    {
        c = *(str + i);
        if ((c == ' ') || (c < '0') || (c > '9')) break;
        n = 10 * n + (c - '0');
        i++;
    }
    return n;
}

int main (int argc, char **argv)
{
    char str[MAX + 1];

    if(argc == 2)
    {
        if(strlen(argv[1]) < MAX)
        {
            strcpy(str,argv[1]);
        }
    }
    else
    {
        printf ("%s", "Entrez un nombre : ");
        fgets (str, MAX, stdin);
    }
    int ret = convertir (str);

    printf ("le nombre converti est : %d ou %#0X\n", ret, ret);
    return 0;
}

 /* Resultats : 

le nombre converti est : 3154 ou 0XC52
*/

