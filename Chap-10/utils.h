/* utils.c */
#include <stddef.h>
#include <stdbool.h>
#include <time.h>

#define PRINTAB(tab,max) for(int u = 0; u<(max);u++) printf("%-4u",tab[u]);printf("\n")

typedef clock_t* timer;

timer init_timer(void);

double delta_t(clock_t *t1, clock_t *t2);

void melange(void *tb, size_t sizetb, size_t size);

bool sorted(int *t, int len);

bool empiler(int v);

int depiler(void);

bool pile_vide(void);

void print_pile(void);

_Bool file_vide(void);

void enfiler(int v);

int defiler(void);

void print_file(void);

void *xmalloc(size_t size);

int *randtab(int size);
