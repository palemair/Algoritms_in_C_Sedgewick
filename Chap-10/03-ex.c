#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

/* 3. Transformez le tri-échange basique de manière à ignorer les bits de poids fort identiques */
/*    pour toutes les clés. Dans quelles situations cette technique serait-elle avantageuse ? */

#define BITS(v,p) ((v>>p) & ~(~0U<<1U))

unsigned int isBitEqual(int *tab, int b, int l,int r)
{
    unsigned int q = BITS(tab[l],b);
    int i = l+1;

    while(i<=r) if(q^BITS(tab[i++],b)) return 0;
    return 1;
} 

void tri_echange(int *tab,int b,int l,int r)
{
    int i, j;
    int q;

    if(isBitEqual(tab,b,l,r)&& b>0)
    {
        tri_echange(tab,b-1,l,r);
    }
    else
    {
         
        if(r>l && b>=0)
        {
         i = l; j = r;

         while(i!=j)
         {
             while((BITS(tab[i],b) ==0) && (i<j)) i++;
             while((BITS(tab[j],b) !=0) && (j>i)) j--;
             q = tab[i];
             tab[i] = tab[j];
             tab[j] = q;
         }

         if(BITS(tab[r],b) == 0) j++;

         tri_echange(tab,b-1,l,j-1);
         tri_echange(tab,b-1,j,r);
        }
    }
}

int main()
{
    int *tab = randtab(100);

    PRINTAB(tab,100);

    tri_echange(tab,30,0,99);

    putchar('\n');
    PRINTAB(tab,100);

    return EXIT_SUCCESS;
}

 /* Resultats : 

7   84  2   42  26  86  87  61  23  62  60  51  11  34  53  77  25  17  29  89  19  40  31  21  56  90  58  30  72  73  63  27  59  5   12  93  10  37  35  74  65  81  70  24  99  75  54  79  55  43  57  47  100 68  14  95  71  83  67  97  18  15  38  28  39  80  82  94  33  16  20  3   88  50  4   22  92  13  8   98  66  49  69  48  52  96  9   32  1   85  64  41  76  36  6   46  45  91  44  78  

1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35  36  37  38  39  40  41  42  43  44  45  46  47  48  49  50  51  52  53  54  55  56  57  58  59  60  61  62  63  64  65  66  67  68  69  70  71  72  73  74  75  76  77  78  79  80  81  82  83  84  85  86  87  88  89  90  91  92  93  94  95  96  97  98  99  100 

  Dans le cas de tri de caractères par exemple, les bits de poids fort sont tous nuls et il est inutile de les comparer.

*/
