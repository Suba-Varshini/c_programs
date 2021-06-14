#include<stdio.h>
#include<stdlib.h>
typedef struct node *node_ptr;
struct node
{
int element;
node_ptr next;
};
typedef struct node *node_ptr;
typedef node_ptr LIST;
typedef node_ptr position; 
LIST createlist()
{
	LIST L=(struct node*)malloc(sizeof(struct node));
	L->next=NULL;
	return L;
}
int is_empty( LIST L )
{
return( L->next == NULL );
} 
int is_last( position p, LIST L )
{
return( p->next == NULL );
} 
position find( int x, LIST L )
{
position p; 
p = L->next;
 while( (p != NULL) && (p->element != x) )
	 p = p->next;
 return p;
}
position find_previous( int x, LIST L )
{
position p;
 p = L;
 while( (p->next != NULL) && (p->next->element != x) )
	 p = p->next;
 return p;
} 

void insertbeg( int x, LIST L)
{
position tmp_cell;
 tmp_cell = (position) malloc( sizeof (struct node) );
 if( tmp_cell == NULL )
      printf("Out of space!!!");
else
{
 tmp_cell->element = x;
 tmp_cell->next = L->next;
 L->next = tmp_cell;
}
}
void insertmid( int x, LIST L, int p )
{
position tmp_cell;int i=1;
 tmp_cell = (position) malloc( sizeof (struct node) );
 if( tmp_cell == NULL )
      printf("Out of space!!!");
 tmp_cell->element = x;
 while(L->next!=NULL && i<p)
 {
	 L=L->next;i++;
 }
 tmp_cell->next = L->next;
 L->next = tmp_cell;
}
void insertend( int x, LIST L )
{
position tmp_cell,p;
p=L
 tmp_cell = (position) malloc( sizeof (struct node) );
 if( tmp_cell == NULL )
      printf("Out of space!!!");
else
{
 tmp_cell->element = x;
 while(p->next!=NULL)
 {
	 p=p->next;
 }
 tmp_cell->next = p->next;
}
} 
void delete_beg(LIST L)
{
     position tmp_cell;
     tmp_cell=L->next; 
	 L->next=tmp_cell->next;
     free( tmp_cell );
} 
void delete_end( LIST L )
{
   if(L== NULL)
   {
      printf("\nList is Empty!!!\n");
   }
   else
   {
      position p,t;
	  p=L;
      if(L->next == NULL)
		 L = NULL;
      else
      {
	 while(p->next != NULL)
	 {
	    t = p;
	    p = p->next;
	 }
	 t->next = NULL;
      }
      free(p);
   }
} 
void delete_pos( int pos, LIST L )
{
int i=1;
position p=L,tmp_cell;
 while(p->next!=pos)
 {
	 p=p->next;i++;
 }
 tmp_cell= p->next;
 p->next = tmp_cell->next;
 free(tmp_cell);
} 
void delete_ele( int x, LIST L )
{
position p, tmp_cell;
p = find_previous( x, L );
if( p->next != NULL ) 
{
tmp_cell = p->next;
p->next = tmp_cell->next; 
free( tmp_cell );
}
} 
void delete_list( LIST L )
{
position p, tmp;
 p = L->next;
 L->next = NULL;
 while( p != NULL )
{
 tmp = p->next;
 free( p );
 p = tmp;
}
} 
void make_empty(LIST L)
{
	if(L!=NULL)
		delete_list(L);
	L=malloc(sizeof(struct node));
	if(L==NULL)
		printf("out of memory");
	L->next=NULL;
}

void print(LIST L)
{
	position temp=L->next;
	while(temp!=NULL)
	{
		printf("%d\n",temp->element);
		temp=temp->next;
	}
}
int main()
{
	LIST L=createlist();
	int element,choice,c,pos;
	while(1) 
	{
		printf("Choose the operation you want to perform\n");
		printf("1. insert \n2. delete \n3. find \n4. display \n5. exit\n");
		printf("Enter the choice\n");
		scanf("%d", &choice);
		switch(choice) 
		{
			case 1:
			printf("enter choice \n1.insert beg \n2.insert middle \n3.insert end\n");
			scanf("%d",&c);
			if(c==1 || is_empty(L))
			{
				printf("Enter the element you wish to insert\n");
				scanf("%d", &element);
				insertbeg(element,L);
			}
			else if(c==2)
			{
				printf("Enter the element you wish to insert and the position\n");
				scanf("%d%d", &element,&pos);
				insertmid(element,L,pos);
			}
			else
			{
				printf("Enter the element you wish to insert \n");
				scanf("%d", &element);
				insertend(element,L);
			}
				
				break;
			case 2:
			printf("enter choice \n1.delete beg \n2.delete position \n3.delete element \n4.delete end\n");
			scanf("%d",&c);
			if(c==1)
			{
				delete_beg(L);
			}
			else if(c==2)
			{
				printf("Enter the position of element to be deleted\n");
				scanf("%d",&pos);
				delete_pos(pos,L);
			}
			else if(c==3)
			{
				printf("Enter the element you wish to delete\n");
				scanf("%d", &element);
				delete_ele(element,L);
			}
			else
			{
				delete_end(L);
			}
				break;
			case 3:
			    printf("Enter the element you wish to find\n");
				scanf("%d", &element);
				printf("position is %p\n", find(element,L));
				break;
			case 4:
			    if(is_empty(L))
				{
				printf("no elements\n");
			    break;
				}
				else
					print(L);
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("Invalid input\n");
		}
	}
	return 0;
}
