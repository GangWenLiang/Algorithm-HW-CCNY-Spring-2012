#include <stdio.h>
#include <stdlib.h>

struct listnode { struct listnode * next;
                  long              value; } ;
struct listnode *quicksort(struct listnode *data);

int main(void)
{  
   long i; 
   struct listnode *node, *tmpnode, *space;
   int size = 1000000;
   space =  (struct listnode *) malloc( size*sizeof(struct listnode));
   for( i=0; i< size; i++ )
   {  //printf("%li\n",2*((17*i)%size));
      (space + i)->value = 2*((17*i)%size);
      (space + i)->next = space + (i+1);
      
   }
   (space+(size-1))->next = NULL;
   node = space;
   printf("\n prepared list, now starting sort\n");
   node = quicksort(node);
   printf("\n checking sorted list\n");
   for( i=0; i < size; i++)
   {  if( node == NULL )
      {  printf("List ended early\n"); exit(0);
      }
      if( node->value != 2*i )
      {  printf("Node contains wrong value\n"); exit(0);
      }
      //printf("%li\n",node->value );
      node = node->next;
   }
   printf("Sort successful\n");
   exit(0);
}