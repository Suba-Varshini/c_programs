#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
struct queue
{
    int count;
    node *front;
    node *rear;
};
typedef struct queue queue;
queue createqueue()
{
	queue *q;
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
	return *q;
}
int isempty(queue *q)
{
    return (q->rear == NULL);
}
void enqueue(queue *q, int value)
{
    node *tmp;
    tmp = malloc(sizeof(node));
    tmp->data = value;
    tmp->next = NULL;
    if(!isempty(q))
    {
        q->rear->next = tmp;
        q->rear = tmp;
    }
    else
    {
        q->front = q->rear = tmp;
    }
    q->count++;
}
int dequeue(queue *q)
{
    node *tmp;
    int n = q->front->data;
    tmp = q->front;
    q->front = q->front->next;
    q->count--;
    free(tmp);
    return(n);
}
void display(node *q)
{
    if(q == NULL)
    {
        printf("NULL\n");
    }
    else
    {
        printf("%d\n", q->data);
        display(q->next);
    }
}
int front(queue *q)
{
	return q->front->data;
}
int main()
{
	queue *q;
    q = malloc(sizeof(queue));
	*q=createqueue();
	int choice,element;
	while(1) {
		printf("Choose the operation you want to perform\n");
		printf("1. insert \n2. delete \n3. front \n4. display \n5. exit\n");
		printf("Enter the choice\n");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("Enter the element you wish to push\n");
				scanf("%d", &element);
				enqueue(q,element);
				break;
			case 2:
			    dequeue(q);
				break;
			case 3:
				printf("front element is %d\n", front(q));
				break;
			case 4:
				display(q->front);
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

