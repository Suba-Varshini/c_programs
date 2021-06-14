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
	L->next=L;
	return L;
}
int is_empty( LIST L )
{
return( L->next == NULL );
} 
int is_last(position p, LIST L )
{
return( p->next == L->next);
} 
void print(LIST L)
{
	position temp=L;
	if(L== NULL)
      printf("\nList is Empty!!!");
	while(temp->next!=L)
	{
		printf("%d\n",temp->element);
		temp=temp->next;
	}
	 printf("%d\n", temp-> element);  
} 

void insertbeg( int x, LIST L)
{
 position tmp_cell,p=L;
 tmp_cell = (position) malloc( sizeof (struct node) );
  tmp_cell -> next = NULL;
  tmp_cell -> element = x;
  if(L!=NULL)
  {
      while(p->next!=L)
      {
        p = p->next;
      }
      p->next = tmp_cell;
  }
  else
  {
    tmp_cell->next = tmp_cell;
  }
  L=tmp_cell;
  printf("the list is:\n");
  print(L);
}
void insertmid( int x, LIST L, int pos )
{
position tmp_cell,p=L;int i=1;
 tmp_cell = (position) malloc( sizeof (struct node) );
 if( tmp_cell == NULL )
      printf("Out of space!!!");
 tmp_cell->element = x;
 while(p->next!=L && i<=pos)
 {
	 p=p->next;i++;
 }
 tmp_cell->next = p->next;
 p->next = tmp_cell;
  printf("the list is:\n");
 print(L);
}
void insertend( int x, LIST L )
{
   position tmp_cell,p=L;
   tmp_cell = (position)malloc(sizeof(struct node));
   tmp_cell-> element = x;
      while(p-> next != L)
         p= p-> next;
    p-> next = tmp_cell;
    tmp_cell -> next = L;
	 printf("the list is:\n");
	 print(L);
} 
int main()
{
	LIST L=createlist();
	int element,choice,c,pos;
	while(1) 
	{
		printf("Choose the operation you want to perform\n");
		l:
		printf("1.insert \n2.print \n3.exit \n");
		printf("Enter the choice\n");
		scanf("%d", &choice);
		switch(choice) 
		{
			case 1:
			printf("enter choice \n1.insert beg \n2.insert middle \n3.insert end\n4.exit\n");
			scanf("%d",&c);
			if(c==1)
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
			else if (c==4)
			{
				printf("Enter the element you wish to insert \n");
				scanf("%d", &element);
				insertend(element,L);
			}
			else 
				goto l;
			break;
			case 2:
			print(L);
			break;
			case 3:
			exit(0);
			break;
		}
	}
	return 0;
}