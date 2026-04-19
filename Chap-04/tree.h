#include <stdlib.h>
#include <stdbool.h>

#define NB 100

typedef struct Node
{
    int data;
    struct Node* L;
    struct Node* R;
} * node;

/* tree.c */
node nd(int c, node L, node R);
void insert(struct Node **tree, char val);
struct Node *append(struct Node *tree, char val);
void visiter(node nd);
void preorder(node tree);
void inorder(node tree);
void postorder(node tree);
void postorder_iter(node pt);
_Bool is_in(struct Node *pt, int test);
int min(struct Node *pt);
int rmax(int a, int b);
int taille(struct Node *pt);
int chemin(struct Node *pt, int x);
int hauteur(struct Node *pt);
void infixe_it(node pt);
void infixe_2(node pt);
void parcours(node tree, int t[][NB], size_t l, size_t r);
void printtree(node root);
