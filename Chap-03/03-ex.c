#include <stdio.h>
#include <stdlib.h>

/* 3. Implantez une procédure **Echanger ( struct noeud  \*t,** struct noeud \*u)*** sur une liste chainée */
/*    qui échange les positions des noeuds suivant ceux sur lesquels pointent t et u. */

struct Node
{
    int data;
    struct Node *nxt;
};

static struct Node *ptr, *begin, *end;

void initialise(void)
{
    begin = malloc (sizeof *begin);
    end = malloc (sizeof *end);
    begin->nxt = end;
    end->nxt = end;
}

void print_list (void)
{
    ptr = begin->nxt;
    while(ptr!= end)
    {
        printf("%3c -> ",ptr->data);
        ptr = ptr->nxt;
    }
    puts("EOL");
}

void echanger (struct Node *t,struct Node *x)
{
    struct Node *tmpx, *tmpt;

    tmpx = x->nxt;
    tmpt = t->nxt;

    t->nxt = t->nxt->nxt;
    x->nxt = x->nxt->nxt;

    tmpx->nxt = t->nxt;
    tmpt->nxt = x->nxt;
    
    t->nxt = tmpx;
    x->nxt = tmpt;

}

int main(void)
{

    initialise();
    struct Node *p,*q;
    p = begin;

    for(int u = 65;u<80;u++)
    {
       struct Node *x = malloc (sizeof *x);
       x->data = u;
       p->nxt = x;
       p =x;
    }
    p->nxt = end;

    print_list();
    
    p =begin;
    q =begin;

    while(p != end)
    {
        if(p->nxt->data == 'H') break;
        p=p->nxt;
    }
    while(q != end)
    {
        if(q->nxt->data == 'D') break;
        q=q->nxt;
    }
    printf("echange %c et %c\n", p->nxt->data,q->nxt->data);
    echanger(p,q);

    print_list();
}

 /* Resultats : 

  A ->   B ->   C ->   D ->   E ->   F ->   G ->   H ->   I ->   J ->   K ->   L ->   M ->   N ->   O -> EOL
echange H et D
  A ->   B ->   C ->   H ->   E ->   F ->   G ->   D ->   I ->   J ->   K ->   L ->   M ->   N ->   O -> EOL
*/
