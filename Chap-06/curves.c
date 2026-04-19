#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

int main (void)
{
    FILE* output = fopen ("plot/ex3.dat", "w");

    if (!output)
    {
        perror ("Probleme ouverture fichier !!");
        return EXIT_FAILURE;
    }
    fprintf (output,"#Les deux fonctions à tester\n");

    int N = 1000;
    for (int u = 50; u <= N; u += 10)
    {
        fprintf (output, "%d ", u);

        long double x = u;

        fprintf (output, "%Lf ", x * log2l (x ));

        fprintf (output, "%Lf ", 100000 * (x * log2l (x)));

        fprintf (output, "%Lf ", x * x * x);

        fputc ('\n', output);
    }
    fclose (output);

    return EXIT_SUCCESS;
}
