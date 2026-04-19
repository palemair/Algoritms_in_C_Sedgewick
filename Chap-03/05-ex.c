#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 5. Ecrivez les primitives d'insertion et de suppression dans une liste doublement chaînée. */

struct Node
{
    int data;
    struct Node *nxt;
    struct Node *prv;
};

static struct Node *ptr, *begin, *end;

void initialise(void)
{
    begin = malloc (sizeof *begin);
    end = malloc (sizeof *end);
    begin->nxt = end;
    begin->prv = begin;
    end->nxt = end;
    end->prv = begin;
}

void print_list (void)
{
    ptr = begin;
    while((ptr = ptr->nxt)!= end) printf("%2c > ",ptr->data);
    puts("EOL");
}

bool list_vide(void)
{
    return begin->nxt == end;
}

void append (int v)
{
    struct Node *new = malloc (sizeof *new);
    new->data = v;

    end->prv->nxt = new;
    new->prv = end->prv;
    new->nxt = end;
    end->prv = new;
}

void insertafter (int v, struct Node *ptr)
{
    struct Node *new = malloc (sizeof *new);
    new->data = v;

    new->prv = ptr;
    new->nxt = ptr->nxt;
    ptr->nxt->prv = new;
    ptr->nxt = new;
}

void delafter (struct Node *ptr)
{
    struct Node *p = ptr->nxt;
    ptr->nxt = ptr->nxt->nxt;
    ptr->nxt->prv = ptr;
    free(p);
}

int main(void)
{
    initialise();
    for(int u=65;u<78;u++) append(u);
    print_list();

    struct Node *p = begin->nxt;
    while(p->data != 'D') p = p->nxt;
    
    insertafter('B',p);
    print_list();
    
    while(p->data != 'G') p = p->nxt;
    delafter(p);
    print_list();

    return 0;
}

 /* Resultats : 

 A >  B >  C >  D >  E >  F >  G >  H >  I >  J >  K >  L >  M > EOL
 A >  B >  C >  D >  B >  E >  F >  G >  H >  I >  J >  K >  L >  M > EOL
 A >  B >  C >  D >  B >  E >  F >  G >  I >  J >  K >  L >  M > EOL
*/
