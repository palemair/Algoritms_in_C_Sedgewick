#include <stdio.h>
#include <stdlib.h>

/* 9. Ecrivez un programme récursif pour résoudre le problème de josephus. */

struct Node
{
    int data;
    struct Node *nxt;
};

struct Node begin = {-1,NULL};


void cercle(int N)
{
    struct Node *t = malloc (sizeof *t);
    t->data = 1;
    struct Node *ptr = t;

    for(int u = 2; u<=N;u++)
    {
        ptr->nxt = malloc (sizeof *ptr);
        ptr = ptr->nxt;
        ptr->data = u;
    }

    ptr->nxt = t;
    begin.nxt = t;
}

void josephus(struct Node *ls, int step)
{
    if(ls == ls->nxt) 
    {
        printf("%3d\n",ls->data);
        return;
    }
    else
    {
        for(int u = 1; u<step; u++) ls = ls->nxt;
        printf("%3d",ls->nxt->data);
        struct Node *tmp = ls->nxt;
        ls->nxt = ls->nxt->nxt;
        free(tmp);
        josephus(ls,step);
    }
}

int main()
{
    int N = 9;
    int M = 5;
    
    cercle(N);
    
    struct Node *pt = &begin;
    
    printf("\nN = %d, M = %d\n",N,M);
    printf("Version itérative : ");
    while(pt != pt->nxt) 
    {
        for(int i=1;i<M;i++) pt = pt->nxt;
        printf("%3d",pt->nxt->data);
        struct Node *x = pt->nxt;
        pt->nxt = pt->nxt->nxt;
        free(x);
    }
    printf("%3d\n",pt->data);

    cercle(N);
    struct Node *t = &begin;
    printf("Version récursive : ");
    josephus(t,M);

    N = 12; M = 3;

    cercle(N);
    pt = &begin;
    
    printf("\nN = %d, M = %d\n",N,M);
    printf("Version itérative : ");
    while(pt != pt->nxt) 
    {
        for(int i=1;i<M;i++) pt = pt->nxt;
        printf("%3d",pt->nxt->data);
        struct Node *x = pt->nxt;
        pt->nxt = pt->nxt->nxt;
        free(x);
    }
    printf("%3d\n",pt->data);

    cercle(N);
    t = &begin;
    printf("Version récursive : ");
    josephus(t,M);

    return 0;
}

 /* Resultats : 


N = 9, M = 5
Version itérative :   5  1  7  4  3  6  9  2  8
Version récursive :   5  1  7  4  3  6  9  2  8

N = 12, M = 3
Version itérative :   3  6  9 12  4  8  1  7  2 11  5 10
Version récursive :   3  6  9 12  4  8  1  7  2 11  5 10
*/
