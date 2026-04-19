#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

int main (void)
{
    FILE* output = fopen ("plot/log.dat", "w");

    if (!output)
    {
        perror ("Probleme ouverture fichier !!");
        return EXIT_FAILURE;
    }
    fprintf (output,"#Les deux fonctions à tester\n");

    int N = 24;
    for (int u = 1; u <= N; u++)
    {
        fprintf (output, "%d ", u);

        fprintf (output, "%u ", (unsigned int)(10*u*log2(u) - (2*u*u)));

        fprintf (output, "%u ", 0);

        fputc ('\n', output);
    }
    fclose (output);

    return EXIT_SUCCESS;
}
