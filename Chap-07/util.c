#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "util.h"

static node file[MAX + 1];
static node pile[MAX + 1];

static int sp = -1;
static int debut = 0;
static int fin = 0;

bool pile_vide(void)
{
    return sp == -1;
}

bool file_vide(void)
{
    return debut == fin;
}

void empiler(node v)
{
   if(sp < MAX)
   {
       pile[++sp] = v;
   }
}

void print_pile(void)
{
    printf(" -> ");
    for(int u=0;u<=sp;u++) printf("%c | ",pile[u]->data);
    printf("\n");

}

node depiler(void)
{
   if(!pile_vide())
   {
       return pile[sp--];
   }
   return NULL;
}

void enfiler(node v)
{
   if(v)
   {
       file[fin++] = v;
   }

   if(fin > MAX) fin = 0;
}

node defiler(void)
{
    node t = file[debut++];

    if(debut > MAX) debut = 0;
    return t;
}

void print_file(void)
{
    printf(" File : ");
    for(int u=fin-1;u>=debut;u--) printf("%c -",file[u]->data);
    printf("\n");

}

node nd(int c,node L, node R)
{
    node root = malloc(sizeof(*root));
    root->data = c;
    root->L = L;
    root->R = R;
    
    return root;
}

int rmax(int a, int b)
{
    return a>=b ? a : b;
}

int hauteur(struct Node * pt)
{
    if (pt == NULL)
    {
        return -1;
    }
    return (1 + rmax(hauteur(pt->L) , hauteur(pt->R)));
}
