#include <stdio.h>
#include<stdlib.h>
#include <string.h>
struct visitornode 
{
int seat_number;
char *status;
char *name;
struct visitornode *link;
};

struct visitornode *head_ticket_t, *current_ticket_t,*head_ticket_a,*current_ticket_a,*head_ticket_s,*current_ticket_s;
struct visitornode *temp,*ptr,*t,*s,*a;
void create_list_swim()
{
  	int i;
	head_ticket_s=(struct visitornode *)malloc (sizeof(struct visitornode));
    head_ticket_s->seat_number = 1;
    head_ticket_s->status="free";
    head_ticket_s->link=NULL;
	ptr=head_ticket_s;
	for(i=2;i<=5;i++)
	{
		current_ticket_s =(struct visitornode *)malloc (sizeof(struct visitornode));
		current_ticket_s->seat_number=i;
		current_ticket_s->link=NULL;
        current_ticket_s->status="free";
		ptr->link=current_ticket_s;
		ptr=ptr->link;
	}
}
void create_list_ath()
{
	int i;
	head_ticket_a=(struct visitornode *)malloc (sizeof(struct visitornode));
    head_ticket_a->seat_number = 1;
    head_ticket_a->status="free";
    head_ticket_a->link=NULL;
	ptr=head_ticket_a;
	for(i=2;i<=5;i++)
	{
		current_ticket_a =(struct visitornode *)malloc (sizeof(struct visitornode));
		current_ticket_a->seat_number=i;
		current_ticket_a->link=NULL;
        current_ticket_a->status="free";
		ptr->link=current_ticket_a;
		ptr=ptr->link;
	}
}
void create_list_tennis()
{
	int i;
	head_ticket_t=(struct visitornode *)malloc (sizeof(struct visitornode));
    head_ticket_t->seat_number = 1;
    head_ticket_t->status="free";
    head_ticket_t->link=NULL;
	ptr=head_ticket_t;
	for(i=2;i<=5;i++)
	{
		current_ticket_t =(struct visitornode *)malloc (sizeof(struct visitornode));
		current_ticket_t->seat_number=i;
		current_ticket_t->link=NULL;
        current_ticket_t->status="free";
		ptr->link=current_ticket_t;
		ptr=ptr->link;
	}
}

void print (struct visitornode *first){
    struct visitornode *ptr;
    ptr=first;
    while(ptr!=NULL){
        printf("seat number:%d\tstatus:%s\tname:%s\n",ptr->seat_number,ptr->status,ptr->name);
        ptr=ptr->link;
    }
}

void tickets_available (struct visitornode *first)
{
    ptr=first;
	printf("the available seats are:\n");
    while(ptr!=NULL){
      if (ptr->status=="free")
	  {
		  printf("%d\t",ptr->seat_number);
        ptr=ptr->link;
      }
    else {ptr=ptr->link;}
}
printf("\n");
}
void print_ticket(int x,char names[20]){

    printf("---------BOOKING-INVOICE-------------\n\n");
    printf("---YOUR BOOKING HAS BEEN CONFIRMED!---\n\n");
    printf("your seat_number: %d\n",x);
    printf("your name: %s\n",names);

    printf("-------------------------------------\n\n");
}
void update_data_book(int old,struct visitornode *first) 
{
   char namer[20];
   if(first==NULL) {
      printf("Linked List not initialized");
      return;
   }

   temp = first;
   while(temp!=NULL) 
   {
      if(temp->seat_number == old && temp->status=="free") 
	  {
        scanf("%s",namer);
         temp->status = "taken";

         temp->name = malloc(12 * sizeof(char));
         strcpy(temp->name, namer);
         print_ticket(old,namer);
      }
      temp = temp->link;
   }
}

void update_booking_cancel(struct visitornode *first)
{
   char namer[20]="(null)";
   int s;
   printf("enter the seat for cancellation:\n");
   scanf("%d",&s);
   if(first==NULL) 
   {
      printf("Linked List not initialized");
      return;
   }
   temp = first;
   while(temp!=NULL) 
   {
      if(temp->seat_number == s && temp->status=="taken") 
	  {
         temp->status = "free";
         temp->name = malloc(12 * sizeof(char));
         strcpy(temp->name, namer);
         print(first);
      }
      temp = temp->link;
   }
}

int main()
{
	create_list_tennis();
	create_list_swim();
	create_list_ath();
int r,p,l,m,q;
int a,b,c,d,e;
while(1)
{
  printf("please choose your option\n1.Book ticket\n2.Cancel your booking\n3.exit\n");
  scanf("%d",&r);
switch (r)
{
  case 1:
  {
    printf("select the event1\n1.SWIMMING\n2.ATHLETICS\n3.TENNIS\n4.EXIT\n");
    scanf("%d",&p);
    switch (p) {
    case 1:
	{
print(head_ticket_s);
	  tickets_available(head_ticket_s);
	    printf("enter the seat you want to book and your name\n");
      scanf("%d\n",&l );
update_data_book(l,head_ticket_s); break;
}
    case 2:
	{
print(head_ticket_a);
	  tickets_available(head_ticket_a);
	  printf("enter the seat you want to book and your name\n");
      scanf("%d\n",&a );
     update_data_book(a,head_ticket_a);  break;
}
    case 3:
	{
print(head_ticket_t);
    tickets_available(head_ticket_t);
	  printf("enter the seat you want to book and your name\n");
  scanf("%d\n",&b );
update_data_book(b,head_ticket_t);break;
}
}break;

}
    case 2:
      printf("select the event2\n1.SWIMMING\n2.ATHLETICS\n3.TENNIS\n4.EXIT\n");
      scanf("%d",&q);
      switch (q)
	  {
      case 1:
	  {
       print(head_ticket_s);
       update_booking_cancel(head_ticket_s);
       break;
	   }
      case 2:
	  {
           print(head_ticket_a);
            update_booking_cancel(head_ticket_a);
           break;
	}
      case 3:
	  {
          print(head_ticket_t);
	      update_booking_cancel(head_ticket_t); 
	      break;
	  }
    }
  break;
  case 3:
  exit(0);
  break;
  default:
  printf("invalid\n");
  break;
  }
}
return 0;
}