#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utils.h"

/* 3. Transformez le tri-échange basique de manière à ignorer les bits de poids fort identiques */
/*    pour toutes les clés. Dans quelles situations cette technique serait-elle avantageuse ? */

#define BITS(v,p) ((v>>p) & ~(~0U<<1U))

bool isBitEqual(int *tab, int b, int l,int r)
{
    unsigned int q = BITS(tab[l],b);
    int i = l+1;

    while(i<=r) if(q^BITS(tab[i++],b)) return false;
    return true;
} 

void tri_echange(int *tab,int b,int l,int r)
{
    int i, j;
    int q;

    if(isBitEqual(tab,b,l,r)&& b>8)
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

    PRINTAB(tab,100);

    return EXIT_SUCCESS;
}

 /* Resultats : 

67  66  69  46  24  4   94  90  25  1   73  32  37  63  30  38  74  64  36  83  58  72  62  97  86  84  13  19  88  50  33  44  61  49  98  55  76  51  92  27  82  29  28  10  89  2   26  96  68  99  9   35  18  5   56  59  79  6   34  15  8   47  21  93  12  60  95  39  52  43  42  23  65  85  70  3   80  77  31  14  7   40  78  54  41  71  100 48  22  81  17  20  75  16  87  11  53  57  91  45  
1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35  36  37  38  39  40  41  42  43  44  45  46  47  48  49  50  51  52  53  54  55  56  57  58  59  60  61  62  63  64  65  66  67  68  69  70  71  72  73  74  75  76  77  78  79  80  81  82  83  84  85  86  87  88  89  90  91  92  93  94  95  96  97  98  99  100 
  *
  * Dans le cas de caractères ou de petits nombres, les bits de poids forts sont identiques et de valeur  0,
  * donc il est inutile d'essayer de les ordonner.
  *
*/
