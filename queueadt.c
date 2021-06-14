#include <stdio.h>
#include <stdlib.h>

struct queue
{
	int *items;		
	int maxsize;	
	int front;		
	int rear;		
	int size;		
};
struct queue* newQueue(int size)
{
	struct queue *q = NULL;
	q = (struct queue*)malloc(sizeof(struct queue));
	q->items = (int*)malloc(size * sizeof(int));
	q->maxsize = size;
	q->front = 0, q->rear = -1;
	q->size = 0;
	return q;
}
int size(struct queue *pt)
{
	return pt->size;
}
int isEmpty(struct queue *pt)
{
	return !size(pt);
}

int front(struct queue *pt)
{
	if (isEmpty(pt))
	{
		printf("UnderFlow\nProgram Terminated\n");
		exit(EXIT_FAILURE);
	}

	return pt->items[pt->front];
}
void enqueue(struct queue *pt, int x)
{
	if (size(pt) == pt->maxsize)
	{
		printf("OverFlow\nProgram Terminated\n");
		exit(EXIT_FAILURE);
	}
	pt->rear = (pt->rear + 1) ;
	pt->items[pt->rear] = x;
	pt->size++;
}
void dequeue(struct queue *pt)
{
	if (isEmpty(pt))
	{
		printf("UnderFlow\nProgram Terminated\n");
		exit(EXIT_FAILURE);
	}

	printf("Removing %d\n", front(pt));

	pt->front = (pt->front + 1) ;
	pt->size--;
}
void display(struct queue *pt) {
	int i = pt->rear;
	for (; i >= pt->front; --i)
		printf("%d\t", pt->items[i]);
	printf("\n");
}
int main()
{
	struct queue *pt = newQueue(5);
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
				enqueue(pt, element);
				break;
			case 2:
			    dequeue(pt);
				break;
			case 3:
				printf("front element is %d\n", front(pt));
				break;
			case 4:
				display(pt);
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
