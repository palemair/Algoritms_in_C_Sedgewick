#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

#define MAX 1000000

/* Mélange par permutation d'un tableau C fisher-yates*/
void melange2 (void* tb, size_t sizetb, size_t size)
{
    FILE* source = fopen("/dev/random","r");
    int buffer;

    if(source == NULL) 
    {
        perror("ouverture dev random");
    }
    else
    {
        unsigned char* ptr = tb;
        unsigned char temp[size];
        unsigned int j = 0;

        for (size_t i = sizetb - 1; i > 0; i--)
        {
            fread(&buffer,sizeof(int),1,source);
            j = buffer % i;
            memcpy (temp, (ptr + (size * i)), size);
            memcpy ((ptr + (size * i)), (ptr + (size * j)), size);
            memcpy ((ptr + (size * j)), temp, size);
        }
    }
    fclose(source);
}

int main()
{
    int t[MAX];
    for(int u = 0; u<MAX;u++) t[u]=u;

    timer A,B;

    A = init_timer();
    melange(t,MAX,sizeof t[0]);
    B = init_timer();

    printf("med %.2f µs\n", delta_t(A,B));

    A = init_timer();
    melange2(t,MAX,sizeof t[0]);
    B = init_timer();

    printf("med %.2f µs\n", delta_t(A,B));

    return EXIT_SUCCESS;
}
