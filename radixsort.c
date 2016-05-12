#include <stdio.h>
#include <stdlib.h>

struct listnode { struct listnode * next;
                  unsigned long              value; } ;

int power(unsigned long b,unsigned long p);
struct listnode *radixsort(struct listnode *data,int a, int k);

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

//Solution radixsort

//exponent function
int power(unsigned long b,unsigned long p)
{  
   if(p==0)
      return 1;
   else if(p<=1)
      return b;
   else return
      b*(power(b,p-1));
}
 
struct listnode *radixsort(struct listnode *data,int a, int k)
{  struct listnode *temp, *holder,*bucket=(struct listnode *) malloc( a*sizeof(struct listnode));//created buckets
   int i,tempk;
   for(i=0;i<a;i++) //set all buckets to NULL pointer
      (bucket+i)->next=NULL;
   for(tempk=0;tempk<=k;tempk++)
   {  temp=data;
      while(temp!=NULL)
      {  holder=temp;
         temp=temp->next;
         holder->next=(bucket+(holder->value%power(a,tempk+1)/power(a,tempk)))->next;//insert front of bucket
         (bucket+(holder->value%power(a,tempk+1)/power(a,tempk)))->next=holder;
      }
      data=0;
      for(i=a-1;i>=0;i--)
      {  if((bucket+i)->next!=NULL)//insert front of data but start with last bucket
         {  temp=(bucket+i)->next;
            while(temp!=NULL)
            {  holder=temp;
               temp=temp->next;
               holder->next=data;
               data=holder;  
            }  
         }  
      }
      for(i=0;i<a;i++)
         (bucket+i)->next=NULL;//clear the buckets;
   }
   return data;
}
