#include "stdio.h"

/* 7. Donnez le contenu de la pile pour chaque opération de la suite */ 
/*    *Q\*UES\*\*\*TI\*ON\*FAC\*\*\*IL\*E\*\**. chaque lettre est un empilement, et chaque astérisque */
/*    provoque un dépilement. */

#define MAX 100
static char tp[MAX + 1];
static int sp = 0;

void empiler(char v)
{
    if (sp < MAX)
    {
       tp[sp++] = v;
    }

    else 
    {
        puts("Pile pleine !!");
    }
}

int depiler(void)
{
    if(sp >= 0)
    {
        int tmp = tp[sp];
        sp--;
        return tmp;
    }
    else 
    {
        puts("Pile vide !!");
        return -1;
    }
}

int main(void)
{
    char str[]= "Q*UES***TI*ON*FAC***IL***E**";
    puts(str); 
    char *p = str;
    while(*p != '\0')
    {
        if(*p != '*') 
        {
            empiler(*p);
        }
        else  
        {
            depiler();
        }
        for(int u = sp-1; u>=0;u--) printf("%2c\n",tp[u]);
        printf("  --  \n");
        p++;
    }

    return 0;
}

 /* Resultats : 

Q*UES***TI*ON*FAC***IL***E**
 Q
  --  
  --  
 U
  --  
 E
 U
  --  
 S
 E
 U
  --  
 E
 U
  --  
 U
  --  
  --  
 T
  --  
 I
 T
  --  
 T
  --  
 O
 T
  --  
 N
 O
 T
  --  
 O
 T
  --  
 F
 O
 T
  --  
 A
 F
 O
 T
  --  
 C
 A
 F
 O
 T
  --  
 A
 F
 O
 T
  --  
 F
 O
 T
  --  
 O
 T
  --  
 I
 O
 T
  --  
 L
 I
 O
 T
  --  
 I
 O
 T
  --  
 O
 T
  --  
 T
  --  
 E
 T
  --  
 T
  --  
  --  
*/
