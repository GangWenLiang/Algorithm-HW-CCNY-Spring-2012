#include <stdio.h>
#include <stdlib.h>

struct listnode { struct listnode * next;
                  unsigned long              value; } ;
int main(void)
{  
   unsigned long i; 
   struct listnode *node, *tmpnode, *space;
   space =  (struct listnode *) malloc( 10000000*sizeof(struct listnode));
   for( i=0; i< 5000000; i++ )
   {  (space + i)->value = 2*((17*37*i)%5000000);
      (space + i)->next = space + (i+1);
   }
   for( i=5000000; i< 10000000; i++ )
   {  (space + i)->value = 99000000-3*i;
      (space + i)->next = space + (i+1);
   }
   (space+9999999)->next = NULL;
   node = space;
   printf("\n prepared list, now starting sort\n");
   node = radixsort(node, 100000, 2);
   printf("\n checking sorted list\n");
   for( i=0; i < 5000000; i++)
   {  if( node == NULL )
      {  printf("List ended early\n"); exit(0);
      }
      if( node->value != 2*i )
      {  printf("Node contains wrong value\n"); exit(0);
      }
      node = node->next;
   }
   for( i=9999999; i >= 5000000; i--)
   {  if( node == NULL )
      {  printf("List ended early\n"); exit(0);
      }
      if( node->value != 99000000 - 3*i )
      {  printf("Node contains wrong value\n"); exit(0);
      }
      node = node->next;
   }
   printf("Sort successful\n");
   exit(0);
}
