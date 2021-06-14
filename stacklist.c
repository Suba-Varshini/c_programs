#include<stdio.h>
#include<stdlib.h>
typedef struct node *node_ptr;
struct node
{
int element;
node_ptr next;
};
typedef node_ptr STACK; 


int is_empty( STACK S )
{
return( S->next == NULL );
} 


STACK create_stack()
{
STACK S;
S = (STACK) malloc( sizeof( struct node ) );
if( S == NULL )
	printf("Out of space!!!");
return S;
}


void make_null( STACK S )
{
if( S != NULL )
S->next = NULL; 
else
printf("Must use create_stack first");
} 


void push( int x, STACK S )
{
node_ptr tmp_cell;
tmp_cell = (node_ptr) malloc( sizeof ( struct node ) );
if( tmp_cell == NULL )
printf("Out of space!!!");
else
{
tmp_cell->element = x;
tmp_cell->next = S->next;
S->next = tmp_cell;
}
}


int top( STACK S )
{
if( is_empty( S ) )
printf("Empty stack");
else
return S->next->element;
} 


int pop( STACK S )
{
	int e ;
node_ptr first_cell;
if( is_empty( S ) )
printf("Empty stack");
else
{
first_cell = S->next;
 e =first_cell->element;
S->next = S->next->next;
free( first_cell );
}
return e;
} 

void display(STACK S)
{
	node_ptr first_cell=S->next;
	printf("the elements are\n");
	while(first_cell->next!=NULL)
	{
		printf("%d\n",first_cell->element);
		first_cell=first_cell->next;
	}
	printf("%d\n",first_cell->element);
}
	
		
int main()
{
	STACK S=create_stack();
	int element, choice;
	while(1) {
		printf("Choose the operation you want to perform\n");
		printf("1. push \n2. pop \n3. top \n4. display \n5. exit\n");
		printf("Enter the choice\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter the element you wish to push\n");
				scanf("%d", &element);
				push(element,S);
				break;
			case 2:
				printf("poped element is %d\n", pop(S));
				break;
			case 3:
				printf("Top most element is %d\n", top(S));
				break;
			case 4:
				display(S);
				break;
			case 5:
			    make_null(S);
				exit(0);
				break;
			default:
				printf("Invalid input\n");
		}
	}
	return 0;
}