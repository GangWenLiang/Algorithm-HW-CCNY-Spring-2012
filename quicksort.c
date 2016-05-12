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

//Solution quicksort link list!
struct listnode *quicksort(struct listnode *data)
{
   unsigned long datalength=1,random;
   struct listnode *temp=data,*b4pivot, *pivot=data,*min=data,*scanner;
   struct listnode *swap=NULL,*big=NULL,*Top=NULL,*End=NULL;
   //base case 1 length = 0;
   if(data==NULL) 
      return NULL;
   //finding length of linklist
   while(temp->next!=NULL)
   {  
      datalength++;
      temp=temp->next; 
   }
   //base case 2 length = 1;           
   if(datalength==1)
      return data;
   //recursion step for length > 1
   if(datalength>1)
   {  //set cirular linked list
      temp->next=data;
      b4pivot=temp;
      random =(rand()%datalength);
      for(int i=1; i<random;i++)
         b4pivot=b4pivot->next;
      //set pivot in the first place data 2nd and end array
      pivot=b4pivot->next;data=pivot->next;b4pivot->next=0;
      //partition start here                                   
      scanner=data;temp=pivot;            
      while(scanner!=NULL)
      {  //small keep in the data array
         if(scanner!=NULL && scanner->value < pivot->value)
         {  
            scanner=scanner->next; 
            temp=temp->next;
         }
         else if(scanner!=NULL && scanner->value >= pivot->value)
         {  //big value added to big array
            swap=scanner;  
            scanner=scanner->next; 
            temp->next=scanner; 
            swap->next=big; 
            big=swap;
         }
      }
      min=pivot->next;
      //since pivot is 1st and data fill with mean set min back
      pivot->next=NULL;
   }
   //pivot is 1st end it.
   End=Top=min=quicksort(min);
   //recurrsive start here 
   big=quicksort(big);
   if(End!=NULL)
   {  //if there is something in the min
      while(End->next!=NULL)// check is end yet
         End=End->next;
   }
   // move to the end
   if(End==NULL)
   {  //pivot part. if min->0 and pivot is smallest, min=pivot->big
      End = pivot;
      Top = pivot;
   }
   else
   {  //if big list and min list divided. min->pivot->big
      End->next=pivot;
      End=End->next;
   }
   // link the big list
   End->next=big;
   return Top;
}
