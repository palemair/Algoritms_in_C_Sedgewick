#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 1. Comparez le nombre d'échanges effectués par le tri echange basique et le tri rapide */
/*    pour un fichier constitué des clés : */
/*    001, 011, 101, 110, 000, 001, 010, 111, 110, 010. */

#define BITS(v,p) ((v>>p) & ~(~0U<<1U))

unsigned char conv_binaire(char * str)
{
    unsigned char ret = 0;
    int k = 4;
    
    while(*str)
    {
        ret += (*str++ == '1') ? k : 0;
        k /=2;
    }
    return ret;
}

typedef struct Data {
    char *str;
    int value;
} data;

void tri_echange(data *tab,int b,int l,int r)
{
    int i, j;
    data q;

    if(r>l && b>=0)
    {
     i = l; j = r;

     while(i!=j)
     {
         while((BITS(tab[i].value,b) ==0) && (i<j)) i++;
         while((BITS(tab[j].value,b) !=0) && (j>i)) j--;
         q = tab[i];
         tab[i] = tab[j];
         tab[j] = q;
     }

    for(int v=0; v<10;v++)
        printf("%s | ",tab[v].str);
    putchar('\n');

     if(BITS(tab[r].value,b) == 0) j++;

     tri_echange(tab,b-1,l,j-1);
     tri_echange(tab,b-1,j,r);
    }
}

int partitionner(data *tab, int l, int r)
{
     int pivot = tab[r].value;
     int i, j;
     data temp;
     i = l-1;
     j = r;

     while(1)
     {
         while(tab[++i].value<pivot);
         while(tab[--j].value>pivot);
         if(i>=j) break;
         temp = tab[i];
         tab[i] = tab[j];
         tab[j] = temp;
     }
     temp = tab[i];
     tab[i] = tab[r];
     tab[r] = temp;
     return i;
 }

void tri_rapide(data *tab,int l,int r)
{
    if(r>l)
    {
        int pivot = partitionner(tab,l,r);

    for(int v=0; v<10;v++)
        printf("%s | ",tab[v].str);
    putchar('\n');
     
     tri_rapide(tab,l,pivot-1);
     tri_rapide(tab,pivot,r);
    }
}

int main()
{
    char *test[] = {"001","011",
                    "101","110",
                    "000","001",
                    "010","111",
                    "110","010"};
   
    int len = sizeof test / sizeof test[0];
    
    data tab[len];

    for(int u =0; u<len; u++)
    {
        tab[u].str = test[u];
        tab[u].value = conv_binaire(test[u]);
    }
   
    puts("Tri echange basique :");
    puts("Etat initial :");
    for(int v=0; v<len;v++)
        printf("%3d | ",tab[v].value);
    putchar('\n');
    for(int v=0; v<(6*len)-1;v++)
        printf("=");
    putchar('\n');
    for(int v=0; v<len;v++)
        printf("%s | ",tab[v].str);
    putchar('\n');
    putchar('\n');

    data tab2[len];
    memcpy(tab2,tab,len * sizeof(data));

    tri_echange(tab,2,0,len-1);

    for(int v=0; v<(6*len)-1;v++)
        printf("=");
    putchar('\n');
    for(int v=0; v<len;v++)
        printf("%3d | ",tab[v].value);
    putchar('\n');
    putchar('\n');

    puts("Tri rapide :");
    puts("Etat initial :");
    for(int v=0; v<len;v++)
        printf("%3d | ",tab2[v].value);
    putchar('\n');
    for(int v=0; v<(6*len)-1;v++)
        printf("=");
    putchar('\n');
    for(int v=0; v<len;v++)
        printf("%s | ",tab2[v].str);
    putchar('\n');
    putchar('\n');

    tri_rapide(tab2,0,len-1);

    for(int v=0; v<(6*len)-1;v++)
        printf("=");
    putchar('\n');
    for(int v=0; v<len;v++)
        printf("%3d | ",tab2[v].value);
    putchar('\n');
    return EXIT_SUCCESS;
}

 /* Resultats : 

Tri echange basique :
Etat initial :
  1 |   3 |   5 |   6 |   0 |   1 |   2 |   7 |   6 |   2 | 
===========================================================
001 | 011 | 101 | 110 | 000 | 001 | 010 | 111 | 110 | 010 | 

001 | 011 | 010 | 010 | 000 | 001 | 110 | 111 | 110 | 101 | 
001 | 001 | 000 | 010 | 010 | 011 | 110 | 111 | 110 | 101 | 
000 | 001 | 001 | 010 | 010 | 011 | 110 | 111 | 110 | 101 | 
000 | 001 | 001 | 010 | 010 | 011 | 110 | 111 | 110 | 101 | 
000 | 001 | 001 | 010 | 010 | 011 | 101 | 111 | 110 | 110 | 
000 | 001 | 001 | 010 | 010 | 011 | 101 | 110 | 110 | 111 | 
===========================================================
  0 |   1 |   1 |   2 |   2 |   3 |   5 |   6 |   6 |   7 | 

Tri rapide :
Etat initial :
  1 |   3 |   5 |   6 |   0 |   1 |   2 |   7 |   6 |   2 | 
===========================================================
001 | 011 | 101 | 110 | 000 | 001 | 010 | 111 | 110 | 010 | 

001 | 010 | 001 | 000 | 010 | 101 | 011 | 111 | 110 | 110 | 
000 | 010 | 001 | 001 | 010 | 101 | 011 | 111 | 110 | 110 | 
000 | 001 | 001 | 010 | 010 | 101 | 011 | 111 | 110 | 110 | 
000 | 001 | 001 | 010 | 010 | 101 | 011 | 111 | 110 | 110 | 
000 | 001 | 001 | 010 | 010 | 101 | 011 | 111 | 110 | 110 | 
000 | 001 | 001 | 010 | 010 | 101 | 011 | 110 | 110 | 111 | 
000 | 001 | 001 | 010 | 010 | 101 | 011 | 110 | 110 | 111 | 
000 | 001 | 001 | 010 | 010 | 011 | 101 | 110 | 110 | 111 | 
000 | 001 | 001 | 010 | 010 | 011 | 101 | 110 | 110 | 111 | 
000 | 001 | 001 | 010 | 010 | 011 | 101 | 110 | 110 | 111 | 
===========================================================
  0 |   1 |   1 |   2 |   2 |   3 |   5 |   6 |   6 |   7 | 
*/
