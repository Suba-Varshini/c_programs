#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node *node_ptr;
struct node
{
char c;
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
position find_previous( char x, LIST L )
{
position p;
 p = L;
 while( (p->next != NULL) && (p->next->c != x) )
	 p = p->next;
 return p;
} 
void print(LIST L)
{
	position temp=L->next;
	printf("\nthe characters are:\n");
	while(temp!=NULL)
	{
		printf("%c\n",temp->c);
		temp=temp->next;
	}
}
void insertbeg( int x, LIST L)
{
position tmp_cell;
 tmp_cell = (position) malloc( sizeof (struct node) );
 if( tmp_cell == NULL )
      printf("Out of space!!!");
else
{
 tmp_cell->c = x;
 tmp_cell->next = L->next;
 L->next = tmp_cell;
}
print(L);
}
void insertmid( char x, LIST L, int p )
{
position tmp_cell;int i=1;
 tmp_cell = (position) malloc( sizeof (struct node) );
 if( tmp_cell == NULL )
      printf("Out of space!!!");
 tmp_cell->c = x;
 while(L->next!=NULL && i<p)
 {
	 L=L->next;i++;
 }
 tmp_cell->next = L->next;
 L->next = tmp_cell;
 print(L);
}
void insertend( int x, LIST L )
{
position tmp_cell,p=L;
 tmp_cell = (position) malloc( sizeof (struct node) );
 if( tmp_cell == NULL )
      printf("Out of space!!!");
else
{
 tmp_cell->c = x;
 while(p->next!=NULL)
 {
	 p=p->next;
 }
 tmp_cell->next = p->next;
 p->next = tmp_cell;
}
print(L);
} 
void nodepreceedc(LIST L)
{
	char ch1='z',ch2='Z';
	position t,x,temp=L;
	printf("\ncharacters after deleting c preceeding \n"); 
	while(temp->next!=NULL)
	{
		if(L->next->c==ch1 || L->next->c==ch2)
		{
        position p=L, tmp_cell;
        tmp_cell=L->next; 
	    L->next=tmp_cell->next;
        free( tmp_cell );
		}
		    else if(temp->next->next->c=='c' || temp->next->next->c=='C')
			{
			x=temp;
			t=temp->next;
			x->next=temp->next->next;
			free(t);
			}
			else
		    temp=temp->next;
	}
	print(L);
}
void updatelast(LIST L)
{
	char ch='z';
	position temp=L;
	printf("\nthe characters are:\n");
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->c=ch;
	print(L);
}
int main()
{
	LIST L=createlist();
	char element;
	int choice,c,pos;
	while(1)
	{
		printf("Choose the operation you want to perform\n");
		printf("1. insert \n2. display \n3. update \n4. delete \n5. exit\n");
		printf("Enter the choice\n");
		scanf("%d", &choice);
		switch(choice) 
		{
			case 1:
			printf("enter choice \n1.insert beg \n2.insert middle \n3.insert end\n");
			scanf("%d",&c);
			if(c==1 || is_empty(L))
			{
				printf("Enter the character you wish to insert\n");
				scanf("%s", &element);
				insertbeg(element,L);
			}
			else if(c==2)
			{
				printf("Enter the character you wish to insert\n");
				scanf("%s",&element);
				printf("Enter the element position\n");
				scanf("%d",&pos);
				insertmid(element,L,pos);
			}
			else
			{
				printf("Enter the character you wish to insert \n");
				scanf("%s", &element);
				insertend(element,L);
			}
			case 2:
			    if(is_empty(L))
				{
				printf("no elements\n");
			    break;
				}
				else
					print(L);
				break;
			case 3:
				updatelast(L);
				break;
			case 4:
			    nodepreceedc(L);
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