#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
}*head;

void createList(int n);
void displayList();
void insertAtBeginning(int data);
void insertAtN(int data, int position);
void insertAtEnd(int data);
void swap();
int main()
{
    int n, data, choice=1;

    head = NULL;

    while(choice != 0)
    {
        printf("1. Create List\n");
        printf("2. Display list\n");
        printf("3. Insert at beginning\n");
        printf("4. Insert at any position\n");
		printf("5. Insert at end\n");
		printf("6. Swap\n");
        printf("0. Exit\n");
        printf("--------------------------------------------\n");
        printf("Enter your choice : ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the total number of nodes in list: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                displayList();
                break;
            case 3:
                printf("Enter data to be inserted at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 4:
                printf("Enter node position: ");
                scanf("%d", &n);
                printf("Enter data you want to insert at %d position: ", n);
                scanf("%d", &data);
                insertAtN(data, n);
                break;
			case 5:
			printf("Enter data to be inserted at end: ");
             scanf("%d", &data);
			insertAtEnd(data);
			break;
			case 6:
			swap();
			break;
            case 0:
                break;
            default:
                printf("Error! Invalid choice. Please choose between 0-4");
        }
    }

    return 0;
}

void createList(int n)
{
    int i, data;
    struct node *prevNode, *newNode;

    if(n >= 1)
    {

        head = (struct node *)malloc(sizeof(struct node));

        printf("Enter data of 1 node: ");
        scanf("%d", &data);

        head->data = data;
        head->next = NULL;

        prevNode = head;

        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            printf("Enter data of %d node: ", i);
            scanf("%d", &data);

            newNode->data = data;
            newNode->next = NULL;

            prevNode->next = newNode;
     
            prevNode = newNode;
        }

        prevNode->next = head;

        printf("\nCIRCULAR LINKED LIST CREATED SUCCESSFULLY\n");
    }
}


void displayList()
{
    struct node *current;
    int n = 1;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        current = head;
        printf("DATA IN THE LIST:\n");

        do {
            printf("Data %d = %d\n", n, current->data);

            current = current->next;
            n++;
        }while(current != head);
    }
}

void insertAtBeginning(int data)
{
    struct node *newNode, *current;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
 
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = head;


        current = head;
        while(current->next != head)
        {
            current = current->next;
        }
        current->next = newNode;

        head = newNode;

        printf("NODE INSERTED SUCCESSFULLY\n");
    }
    printf("the list is:\n");
	displayList();
}

void insertAtN(int data, int position)
{
    struct node *newNode, *current;
    int i;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else if(position == 1)
    {
        insertAtBeginning(data);
    }
    else
    {

        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;

        current = head;
        for(i=2; i<=position-1; i++)
        {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;

    }
    printf("the list is:\n");
	displayList();
}
void insertAtEnd( int data )
{
   struct node *tmp_cell,*p;
   p=head;
   tmp_cell = (struct node*)malloc(sizeof(struct node));
   tmp_cell-> data = data;
      while(p-> next != head)
         p= p-> next;
    p->next=tmp_cell;
	tmp_cell->next=head;
	 printf("the list is:\n");
	displayList();
} 
void swap()
{
	displayList();
	int a,b;
	printf("enter 2 node values\n");
	scanf("%d%d",&a,&b);
	struct node *p,*t,*p1,*p2,*r,*q,*s;
	p=head;
	t=head;
	r=head;
	while(p-> next != head && p->data==a)
         p= p-> next;
	while(t-> next != head && t->data==b)
         t= t-> next;
	while(r-> next != head)
         r= r-> next;
	q= (struct node*)malloc(sizeof(struct node));
   q-> data = a;
   s= (struct node*)malloc(sizeof(struct node));
   s-> data = b;
   r->next=s;
   s->next=q;
   q->next=head;
	 printf("the list is:\n");
	displayList();
}