#include <stdio.h>
#include <stdlib.h>
struct cqueue
{
	int *items;		
	int maxsize;	
	int front;		
	int rear;		
	int size;		
};
struct cqueue* newQueue(int size)
{
	struct cqueue *cq = NULL;
	cq = (struct cqueue*)malloc(sizeof(struct cqueue));

	cq->items = (int*)malloc(size * sizeof(int));
	cq->maxsize = size;
	cq->front = 0, cq->rear = -1;
	cq->size = 0;

	return cq;
}
int size(struct cqueue *cq)
{
	return cq->size;
}
int isEmpty(struct cqueue *cq)
{
	return !size(cq);
}
int isFull(struct cqueue *cq)
{
	return cq->size==cq->maxsize;
}
int front(struct cqueue *cq)
{
	if (isEmpty(cq))
	{
		printf("UnderFlow\nProgram Terminated\n");
		exit(EXIT_FAILURE);
	}

	return cq->items[cq->front];
}
void enqueue(struct cqueue *cq, int x)
{
	if (isFull(cq))
	{
		printf("OverFlow\nProgram Terminated\n");
		exit(EXIT_FAILURE);
	}
	else if(isEmpty(cq))
	{
		cq->rear=0;
		cq->items[cq->rear]=x;
		cq->size++;
		printf("inserted %d\n",cq->items[cq->rear]);
	}
	else if ((cq->rear==cq->maxsize-1)&&(cq->front!=0))
	{
	cq->rear=0;
	cq->items[cq->rear] = x;
	cq->size++;
	printf("inserted %d\n",cq->items[cq->rear]);
	}
	else 
	{
	cq->rear = (cq->rear + 1) ;
	cq->items[cq->rear] = x;
	cq->size++;
	printf("inserted %d\n",cq->items[cq->rear]);
	}
}
void dequeue(struct cqueue *cq)
{
	if (isEmpty(cq))
	{
		printf("UnderFlow\nProgram Terminated\n");
		exit(EXIT_FAILURE);
	}
    else if (cq->front == cq->rear) 
	{
		int data = cq->items[cq->front];
		cq->front = -1;
		cq->rear = -1;
		printf("removed %d\n",data);
	}		
	else if ((cq->front ==cq->capacity-1)&&(cq->rear!=0))
	{
		cq->front=0;
		int data=cq->items[cq->front];
		cq->front = (cq->front + 1) ;
		printf("removed %d\n",data);
	}
	else 
	{
	int data = cq->items[cq->front];
	cq->front = (cq->front + 1) ;
	cq->size--;
	printf("removed %d\n",data);
	}
}
void display( struct cqueue *cq)
{
	printf("cq is \n");
	if(isEmpty(cq))
	{
		printf("is empty\n");
	}
	else if(cq->rear>=cq->front)
	{
	int i;
	for (i = cq->front; i <=cq->rear; i++)
		printf("%d\t", cq->items[i]);
	printf("\n");
	}
	else 
	{
		int i;
		for(i=cq->front;i<cq->maxsize;i++)
			printf("%d\t", cq->items[i]);
		for(i=0;i<=cq->rear;i++)
			printf("%d\t", cq->items[i]);
		printf("\n");
	}
			
}
int main()
{
	struct cqueue *cq = newQueue(10);
    int element, choice;
	while(1) {
		printf("Choose the operation you want to perform\n");
		printf("1. insert \n2. delete \n3. front \n4. display \n5. exit\n");
		printf("Enter the choice\n");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("Enter the element you wish to push\n");
				scanf("%d", &element);
				enqueue(cq, element);
				break;
			case 2:
			    dequeue(cq);
				break;
			case 3:
				printf("front element is %d\n", front(cq));
				break;
			case 4:
				display(cq);
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