#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

typedef struct Node
{
    int data;
    struct Node* L;
    struct Node* R;
} * node;

/* util.c */
_Bool pile_vide(void);
_Bool file_vide(void);
void empiler(node v);
node depiler(void);
void enfiler(node v);
void print_pile(void);
node defiler(void);
void print_file(void);

node nd(int c, node L, node R);
int rmax(int a, int b);
int hauteur(struct Node *pt);
