#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"

#define MAX 100
/* util.c */
_Bool pile_vide(void);
_Bool file_vide(void);
node consult(void);
void empiler(node v);
node depiler(void);
void enfiler(node v);
void print_pile(void);
node defiler(void);
void print_file(void);

