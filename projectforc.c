#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct player
{
	char p_name[20];
	int p_id;
	int contact;
	int age;
	int rank;
};
struct t_score{int t_rounds; int t_points;};
struct s_score{int s_rounds; int s_points;};
struct a_score{int a_rounds; int a_points;};
struct p_tennis_node
{
    struct player p1;
	struct t_score tscore;
    char perf;
    struct p_tennis_node *t_next;
}; 
 struct p_swim_node
{
    struct player p2;
	struct s_score sscore;
    char perf;
    struct p_swim_node *s_next;
};
struct p_ath_node
{
    struct player p3;
	struct a_score ascore;
    char perf;
    struct p_ath_node *a_next;
};
typedef struct p_tennis_node *p_tennis;
typedef struct p_swim_node *p_swim;
typedef struct p_ath_node *p_ath;
typedef p_tennis p_t;
typedef p_swim p_s;
typedef p_ath p_a;
int t_Empty(p_t pt)
{
  return (pt->t_next== NULL);
}
int s_Empty(p_s ps)
{
  return (ps->s_next== NULL);
}
int a_Empty(p_a pa)
{
  return (pa->a_next== NULL);
}
p_t create_list_tennis()
{
	p_t pt;
	pt=(p_t)malloc(sizeof(struct p_tennis_node));
	pt->t_next=pt;
	return pt;
}
p_s create_list_swim()
{
	p_s ps;
	ps=(p_s)malloc(sizeof(struct p_swim_node));
	ps->s_next=ps;
	return ps;
}
p_a create_list_ath()
{
	p_a pa;
	pa=(p_a)malloc(sizeof(struct p_ath_node));
	pa->a_next=pa;
	return pa;
}
void disp_events()
{
    printf("\n*******\nEVENTS:\n*******\n 1. TENNIS\n 2. SWIMMING\n 3. ATHLETICS\n");
}
p_t t_find_previous( int x, p_t pt )
{
p_t pos;
 pos = pt;
 while( (pos->t_next != pt) && (pos->t_next->p1.p_id != x) )
	 pos= pos->t_next;
 return pos;
} 
p_s s_find_previous( int x, p_s ps )
{
p_s pos;
 pos = ps;
 while( (pos->s_next != ps) && (pos->s_next->p2.p_id != x) )
	 pos= pos->s_next;
 return pos;
} 
p_a a_find_previous( int x, p_a pa )
{
p_a pos;
 pos = pa;
 while( (pos->a_next != pa) && (pos->a_next->p3.p_id != x) )
	 pos= pos->a_next;
 return pos;
} 
void t_add_player(p_t pt)
{
        p_t t_new;int points;
		t_new=(p_t)malloc(sizeof(struct p_tennis_node));
		printf("Enter the player name:");
		scanf("%s",t_new->p1.p_name);
        printf("Enter Player ID: ");
        scanf("%d", &(t_new->p1.p_id));
        printf("Enter Player Contact No: ");
        scanf("%d", &(t_new->p1.contact ));
        printf("Enter Player Age:");
        scanf("%d", &(t_new->p1.age));
		t_new->tscore.t_rounds=5;
		while(1)
		{
		printf("enter points:");
		scanf("%d",&points);
		if(points<=5)
		{
			(t_new->tscore.t_points)=points;
			break;
		}
		else 
			printf("enter the points again\n");
		}
        t_new->t_next = NULL;
		if(pt->t_next==NULL)
            {
			pt= t_new->t_next ;
			}
        else
		{			
			p_t t_temp=pt;
			while(t_temp->t_next!= pt)
                    t_temp=t_temp->t_next;
			t_temp->t_next=t_new;
			t_new->t_next=pt;
		}
  }
  void s_add_player(p_s ps)
{
        p_s s_new;int points;
		s_new=(p_s)malloc(sizeof(struct p_swim_node));
		printf("Enter the player name:");
		scanf("%s",s_new->p2.p_name);
        printf("Enter Player ID: ");
        scanf("%d", &(s_new->p2.p_id));
        printf("Enter Player Contact No: ");
        scanf("%d", &(s_new->p2.contact ));
        printf("Enter Player Age:");
        scanf("%d", &(s_new->p2.age));
		s_new->sscore.s_rounds=10;
		while(1)
		{
		printf("enter points:");
		scanf("%d",&points);
		if(points<=10)
		{
			(s_new->sscore.s_points)=points;
			break;
		}
		else 
			printf("enter the points again\n");
		}
        s_new->s_next = NULL;
		if(ps->s_next==NULL)
            {
			ps= s_new->s_next ;
			}
        else
		{			
			p_s s_temp=ps;
			while(s_temp->s_next!= ps)
                    s_temp=s_temp->s_next;
			s_temp->s_next=s_new;
			s_new->s_next=ps;
		}
  }
  void a_add_player(p_a pa)
{
        p_a a_new;int points;
		a_new=(p_a)malloc(sizeof(struct p_ath_node));
		printf("Enter the player name:");
		scanf("%s",a_new->p3.p_name);
        printf("Enter Player ID: ");
        scanf("%d", &(a_new->p3.p_id));
        printf("Enter Player Contact No: ");
        scanf("%d", &(a_new->p3.contact ));
        printf("Enter Player Age:");
        scanf("%d", &(a_new->p3.age));
		a_new->ascore.a_rounds=7;
		while(1)
		{
		printf("enter points:");
		scanf("%d",&points);
		if(points<=7)
		{
			(a_new->ascore.a_points)=points;
			break;
		}
		else 
			printf("enter the points again\n");
		}
        a_new->a_next = NULL;
		if(pa->a_next==NULL)
            {
			pa= a_new->a_next ;
			}
        else
		{			
			p_a a_temp=pa;
			while(a_temp->a_next!= pa)
                    a_temp=a_temp->a_next;
			a_temp->a_next=a_new;
			a_new->a_next=pa;
		}
  }
  void t_display(p_t pt)
  {
    if(!t_Empty(pt))
    {
	 p_t t_temp=pt->t_next;
     printf("\n===========================================================\n");
	 printf(" ID          NAME          CONTACT          AGE         POINTS ");
	 printf("\n===========================================================\n");
	 
     while( t_temp!= pt)
     {
      printf("%4d |", t_temp ->p1.p_id);
	  printf("%9s |", t_temp ->p1.p_name);
      printf("%9d |", t_temp ->p1.contact);
      printf("%9d |", t_temp ->p1.age);
	  printf("%9d / %d",t_temp->tscore.t_points,t_temp->tscore.t_rounds);
      printf("\n");
      t_temp = t_temp ->t_next ;
     }
	 printf("======================================================\n");
     }
    else
        printf("No players in Tennis Event.\n");
  }
void s_display(p_s ps)
  {
    if(!s_Empty(ps))
    {
	 p_s s_temp=ps->s_next;
    printf("\n===========================================================\n");
	 printf(" ID          NAME          CONTACT          AGE         POINTS ");
	 printf("\n===========================================================\n");
	 
     while( s_temp!= ps)
     {
      printf("|%4d |",s_temp ->p2.p_id);
	  printf("|%9s |", s_temp ->p2.p_name);
      printf("|%9d |", s_temp ->p2.contact);
      printf("|%9d ", s_temp ->p2.age);
	  printf("%9d / %d",s_temp->sscore.s_points,s_temp->sscore.s_rounds);
      printf("\n");
      s_temp = s_temp ->s_next ;
     }
	 	 printf("\n===========================================================\n");
     }
    else
        printf("No players in swimming Event.\n");
  }
void a_display(p_a pa)
  {
    if(!a_Empty(pa))
    {
	 p_a a_temp=pa->a_next;
    printf("\n===========================================================\n");
	 printf(" ID          NAME          CONTACT          AGE         POINTS ");
	 printf("\n===========================================================\n");
	 
     while( a_temp!= pa)
     {
      printf("|%4d |", a_temp ->p3.p_id);
	  printf("|%9s |", a_temp ->p3.p_name);
      printf("|%9d |", a_temp ->p3.contact);
      printf("|%9d ", a_temp ->p3.age);
	  printf("%9d / %d",a_temp->ascore.a_points,a_temp->ascore.a_rounds);
      printf("\n");
      a_temp = a_temp ->a_next ;
     }
	 printf("\n===========================================================\n");
     }
    else
        printf("No players in athletics Event.\n");
  }
void detail_player(p_t pt,p_s ps,p_a pa)
{
    int opt;
    do{
       printf("ENTER THE EVENT TO DISPLAY THE PLAYERS:\n");
       disp_events();
       printf(" 4. EXIT\n CHOOSE YOUR OPTION : ");
       scanf("%d", &opt);
       switch(opt)
       {
       case 1:
           t_display(pt);
           break;
		case 2:
           s_display(ps);
           break;
		case 3:
           a_display(pa);
           break;
       }
       }while (opt != 4);
}
void add_player(p_t pt,p_s ps,p_a pa)
{
    int opt;
    do{
       printf("ENTER THE EVENT TO ADD PLAYERS:\n");
       disp_events();
       printf(" 4. EXIT\n CHOOSE YOUR OPTION : ");
       scanf("%d", &opt);
       switch(opt)
       {
        case 1:
           t_add_player(pt);
           break;
	    case 2:
           s_add_player(ps);
           break;
		case 3:
           a_add_player(pa);
           break;
       case 4:
        printf("\n<<<EXITING ADDING MENU>>>\n");
        break;
       default:
        printf("INVALID OPTION!");
		break;
       }
       }while (opt != 4);
}
void delete_player(p_t pt,p_s ps,p_a pa)
{
	int id;
	printf("The TENNIS players are:\n");
	t_display(pt);
	printf("The SWIMMING players are:\n");
	s_display(ps);
	printf("The ATHLETICS players are:\n");
	a_display(pa);
	printf("Enter ID of which player you want to delete?:");
	scanf("%d",&id);
	p_t p_t_t, t_tmp_cell;
    p_t_t = t_find_previous( id, pt );
    if( p_t_t->t_next != pt) 
    {
    t_tmp_cell = p_t_t->t_next;
    p_t_t->t_next = t_tmp_cell->t_next; 
    free( t_tmp_cell );
    }
	
	
	p_s p_s_s, s_tmp_cell;
    p_s_s = s_find_previous( id, ps );
    if( p_s_s->s_next != ps) 
    {
    s_tmp_cell = p_s_s->s_next;
    p_s_s->s_next = s_tmp_cell->s_next; 
    free( s_tmp_cell );
    }
	
	
	p_a p_a_a, a_tmp_cell;
    p_a_a = a_find_previous( id, pa );
    if( p_a_a->a_next != pa) 
    {
    a_tmp_cell = p_a_a->a_next;
    p_a_a->a_next = a_tmp_cell->a_next; 
    free( a_tmp_cell );
    }
	
}
void t_display_winner(p_t pt)
  {
	 p_t t_temp=pt->t_next;
     printf("\n==========================================================================\n");
	 printf(" ID          NAME          CONTACT          AGE         POINTS     RANK ");
	 printf("\n==========================================================================\n");
	 int count = 0;
     while( t_temp!= pt && count < 3)
     {
      printf("%4d |", t_temp ->p1.p_id);
	  printf("%9s |", t_temp ->p1.p_name);
      printf("%9d |", t_temp ->p1.contact);
      printf("%9d |", t_temp ->p1.age);
	  printf("%9d / %d |",t_temp->tscore.t_points,t_temp->tscore.t_rounds);
	  printf("%3d ", t_temp ->p1.rank);
      printf("\n");
      t_temp = t_temp ->t_next ;
      count++;
     }
	 printf("===========================================================================\n");
  }

void s_display_winner(p_s ps)
  {
	 p_s s_temp=ps->s_next;
     printf("\n=======================================================================\n");
	 printf(" ID          NAME          CONTACT          AGE         POINTS     RANK");
	 printf("\n=======================================================================\n");
	 int count = 0;
     while( s_temp!= ps && count < 3)
     {
      printf("%4d |", s_temp ->p2.p_id);
	  printf("%9s |", s_temp ->p2.p_name);
      printf("%9d |", s_temp ->p2.contact);
      printf("%9d |", s_temp ->p2.age);
	  printf("%9d / %d |",s_temp->sscore.s_points,s_temp->sscore.s_rounds);
	  printf("%3d ", s_temp ->p2.rank);
      printf("\n");
      s_temp = s_temp ->s_next ;
      count++;
     }
	 printf("=====================================================================\n");
  }
  void a_display_winner(p_a pa)
  {
	 p_a a_temp=pa->a_next;
     printf("\n======================================================================\n");
	 printf(" ID          NAME          CONTACT          AGE         POINTS     RANK");
	 printf("\n======================================================================\n");
	 int count=0;
     while( a_temp!= pa && count < 3)
     {
      printf("%4d |", a_temp ->p3.p_id);
	  printf("%9s |", a_temp ->p3.p_name);
      printf("%9d |", a_temp ->p3.contact);
      printf("%9d |", a_temp ->p3.age);
	  printf("%9d / %d  |",a_temp->ascore.a_points,a_temp->ascore.a_rounds);
	  printf("%3d ", a_temp ->p3.rank);
      printf("\n");
      a_temp = a_temp ->a_next ;
      count++;
     }
	 printf("======================================================================\n");
  }
void swap_t(struct p_tennis_node *a, struct p_tennis_node *b) 
{
    struct player temp = a->p1; 
    a->p1 = b->p1; 
    b->p1 = temp;
    struct t_score temp1 = a->tscore;
    a->tscore = b->tscore;
    b->tscore = temp1;
    char temp2 = a->perf;
    a->perf = b->perf;
    b->perf = temp2; 
}



void t_winner(p_t pt) 
{ 
    p_t temp=pt->t_next;
	int i=1;
        while(temp->t_next!=pt)
        {
            struct p_tennis_node * temp1=(p_t)malloc(sizeof(struct p_tennis_node));
         
            temp1=temp->t_next;
            while(temp1!=pt)
            {     
                if(temp1->tscore.t_points >temp->tscore.t_points)
                {
                    swap_t(temp,temp1);
                }
                temp1=temp1->t_next;
            }
            temp=temp->t_next;
        }
		temp=pt->t_next;
		while(temp!=pt)
		{
			temp->p1.rank=i;
			i++;
			temp=temp->t_next;
		}
     t_display_winner(pt);
    
} 
  
  
void swap_s(struct p_swim_node *a, struct p_swim_node *b) 
{ 
    struct player temp = a->p2; 
    a->p2 = b->p2; 
    b->p2 = temp;
    struct s_score temp1 = a->sscore;
    a->sscore = b->sscore;
    b->sscore = temp1;
    char temp2 = a->perf;
    a->perf = b->perf;
    b->perf = temp2; 
}
void s_winner(p_s ps) 
{ 
      p_s temp=ps->s_next;
	  int i=1;
        while(temp->s_next!=ps)
        {
            struct p_swim_node * temp1=(p_s)malloc(sizeof(struct p_swim_node));
         
            temp1=temp->s_next;
            while(temp1!=ps)
            {     
                if(temp1->sscore.s_points >temp->sscore.s_points)
                {
                    swap_s(temp,temp1);
                }
                temp1=temp1->s_next;
            }
            temp=temp->s_next;
        }
		temp=ps->s_next;
		while(temp!=ps)
		{
			temp->p2.rank=i;
			i++;
			temp=temp->s_next;
		}
     s_display_winner(ps);
} 
  
  

void swap_a(struct p_ath_node *a, struct p_ath_node *b) 
{ 
    struct player temp = a->p3; 
    a->p3 = b->p3; 
    b->p3 = temp;
    struct a_score temp1 = a->ascore;
    a->ascore = b->ascore;
    b->ascore = temp1;
    char temp2 = a->perf;
    a->perf = b->perf;
    b->perf = temp2; 
}
void a_winner(p_a pa) 
{ 
        p_a temp=pa->a_next;
		int i=1;
        while(temp->a_next!=pa)
        {
            struct p_ath_node * temp1=(p_a)malloc(sizeof(struct p_ath_node));
         
            temp1=temp->a_next;
            while(temp1!=pa)
            {     
                if(temp1->ascore.a_points >temp->ascore.a_points)
                {
                    swap_a(temp,temp1);
                }
                temp1=temp1->a_next;
            }
            temp=temp->a_next;
        }
		temp=pa->a_next;
		while(temp!=pa)
		{
			temp->p3.rank=i;
			i++;
			temp=temp->a_next;
		}
     a_display_winner(pa); 
} 
 

void winner_player(p_t pt,p_s ps,p_a pa)
{
    int opt;
       printf("ENTER THE EVENT TO DISPLAY THE WINNERS:\n");
       disp_events();
       printf(" 4. EXIT\n CHOOSE YOUR OPTION : ");
       scanf("%d", &opt);
       switch(opt)
       {
       case 1:
           t_winner(pt);
           break;
		case 2:
           s_winner(ps);
           break;
		case 3:
           a_winner(pa);
           break;
        default:
           break;
       }
}
void result_player(p_t pt,p_s ps,p_a pa)
{
    int id;
	printf("enter id:\n");
	scanf("%d",&id);
    p_t pos1;
	p_s pos2;
	p_a pos3;
	pos1=pt->t_next;
	pos2=ps->s_next;
	pos3=pa->a_next;
	while(pos1!=pt)
	{
		if(pos1->p1.p_id==id)
		{
			printf("ID   :%d\n",pos1->p1.p_id);
			printf("NAME :%s\n",pos1->p1.p_name);
			printf("SCORE:%d/%d\n",pos1->tscore.t_points,pos1->tscore.t_rounds);
			printf("RANK :%d\n",pos1->p1.rank);
			printf("EVENT:TENNIS\n");
		}
		pos1=pos1->t_next;
	}
	while(pos2!=ps)
	{
		if(pos2->p2.p_id==id)
		{
			printf("ID   :%d\n",pos2->p2.p_id);
			printf("NAME :%s\n",pos2->p2.p_name);
			printf("SCORE:%d/%d\n",pos2->sscore.s_points,pos2->sscore.s_rounds);
			printf("RANK :%d\n",pos2->p2.rank);
			printf("EVENT:SWIMMING\n");
		}
		pos2=pos2->s_next;
	}
	while(pos3!=pa)
	{
		if(pos3->p3.p_id==id)
		{
			printf("ID   :%d\n",pos3->p3.p_id);
			printf("NAME :%s\n",pos3->p3.p_name);
			printf("SCORE:%d/%d\n",pos3->ascore.a_points,pos3->ascore.a_rounds);
			printf("RANK :%d\n",pos3->p3.rank);
			printf("EVENT:ATHLETICS\n");
		}
		pos3=pos3->a_next;
	}
}

struct visitornode 
{
	int id;
int seat_number;
char *status;
char *name;
struct visitornode *link;
};

struct visitornode *head_ticket_t, *current_ticket_t,*head_ticket_a,*current_ticket_a,*head_ticket_s,*current_ticket_s;
struct visitornode *temp,*ptr,*t,*s,*a;
void create_list_ticket_swim()
{
  	int i;
	head_ticket_s=(struct visitornode *)malloc (sizeof(struct visitornode));
    head_ticket_s->seat_number = 1;
	head_ticket_s->id = 0;
    head_ticket_s->status="free";
    head_ticket_s->link=NULL;
	ptr=head_ticket_s;
	for(i=2;i<=5;i++)
	{
		current_ticket_s =(struct visitornode *)malloc (sizeof(struct visitornode));
		current_ticket_s->seat_number=i;
		current_ticket_s->id=0;
		current_ticket_s->link=NULL;
        current_ticket_s->status="free";
		ptr->link=current_ticket_s;
		ptr=ptr->link;
	}
}
void create_list_ticket_ath()
{
	int i;
	head_ticket_a=(struct visitornode *)malloc (sizeof(struct visitornode));
    head_ticket_a->seat_number = 1;
	head_ticket_a->id = 0;
    head_ticket_a->status="free";
    head_ticket_a->link=NULL;
	ptr=head_ticket_a;
	for(i=2;i<=5;i++)
	{
		current_ticket_a =(struct visitornode *)malloc (sizeof(struct visitornode));
		current_ticket_a->seat_number=i;
		current_ticket_a->id=0;
		current_ticket_a->link=NULL;
        current_ticket_a->status="free";
		ptr->link=current_ticket_a;
		ptr=ptr->link;
	}
}
void create_list_ticket_tennis()
{
	int i;
	head_ticket_t=(struct visitornode *)malloc (sizeof(struct visitornode));
    head_ticket_t->seat_number = 1;
	 head_ticket_t->id = 0;
    head_ticket_t->status="free";
    head_ticket_t->link=NULL;
	ptr=head_ticket_t;
	for(i=2;i<=5;i++)
	{
		current_ticket_t =(struct visitornode *)malloc (sizeof(struct visitornode));
		current_ticket_t->seat_number=i;
		current_ticket_t->id=0;
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
        printf("id:%d\tseat number:%d\tstatus:%s\tname:%s\n",ptr->id,ptr->seat_number,ptr->status,ptr->name);
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
void print_ticket(int idn,int x,char names[20]){

    printf("---------BOOKING-INVOICE-------------\n\n");
    printf("---YOUR BOOKING HAS BEEN CONFIRMED!---\n\n");
	printf("your id: %d\n",idn);
    printf("your seat_number: %d\n",x);
    printf("your name: %s\n",names);

    printf("-------------------------------------\n\n");
}
void update_data_book(int idn,int old,struct visitornode *first) 
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
		 temp->id=idn;
         temp->name = malloc(12 * sizeof(char));
         strcpy(temp->name, namer);
         print_ticket(idn,old,namer);
      }
      temp = temp->link;
   }
}

void update_booking_cancel(struct visitornode *first)
{
   char namer[20]="(null)";
   int idn;
   printf("enter the id for cancellation:\n");
   scanf("%d",&idn);
   if(first==NULL) 
   {
      printf("Linked List not initialized");
      return;
   }
   temp = first;
   while(temp!=NULL) 
   {
      if(temp->id == idn && temp->status=="taken") 
	  {
         temp->status = "free";
		 temp->id=0;
         temp->name = malloc(12 * sizeof(char));
         strcpy(temp->name, namer);
         print(first);
      }
      temp = temp->link;
   }
}
void detail_vis(struct visitornode *first1,struct visitornode *first2,struct visitornode *first3)
{
	int idn,c=0;
	printf("enter your id:\n");
	scanf("%d",&idn);
	t=first1;
	s=first2;
	a=first3;
	while(t!=NULL)
	{
		if(t->id==idn)
		{
			printf("Your Ticket has been confirmed\n");
			printf("NAME:   %s\n",t->name);
			printf("SEAT:   %d\n",t->seat_number);
			printf("EVENT:  tennis\n");
			c=1;
		}
		t=t->link;
	}
	while(s!=NULL)
	{
		if(s->id==idn)
		{
			printf("Your Ticket has been confirmed\n");
			printf("NAME:   %s\n",s->name);
			printf("SEAT:   %d\n",s->seat_number);
			printf("EVENT:  swimming\n");
			c=1;
		}
		s=s->link;
	}
	while(a!=NULL)
	{
		if(a->id==idn)
		{
			printf("Your Ticket has been confirmed\n");
			printf("NAME:   %s\n",a->name);
			printf("SEAT:   %d\n",a->seat_number);
			printf("EVENT:  athletics\n");
			c=1;
		}
		a=a->link;
	}
	if(c==0)
	{
		printf("YOUR TICKET WAS NOT BOOKED");
	}
}
int main()
{
	p_t pt=create_list_tennis();
	p_s ps=create_list_swim();
	p_a pa=create_list_ath();
	create_list_ticket_tennis();
	create_list_ticket_swim();
	create_list_ticket_ath();
    int r,p,l,m,q;
	int a,b,c,n,idn;
	char password_correct[26]="admin_sports",password[26];
	char vis_name;
    l:
	printf("******************\n");
	printf("ENTER YOUR ROLE : \n");
	printf("******************\n");
	printf("\n1.  ADMIN \n2.  PLAYER \n3.  VISITOR \n4.  EXIT\nENTER YOUR CHOICE : ");
	scanf("%d",&c);
	while(1)
	{
		switch(c)
		{
		case 1:
		while(1)
		{
		int count=0;
		printf("Enter your password for Admin log-in: ");
	    scanf("%s", password);
		if(strcmp(password_correct,password)==0)
		{
			printf("\n");
			printf("\n");
		    printf("***WELCOME ADMIN***\n");
			while(1)
			{
			printf("----------------------------------\n");
			printf("              MENU                \n");
			printf("----------------------------------\n");
			printf("1.View the events\n");
			printf("2.Player details for each event\n");
			printf("3.Add new player to an event\n");
			printf("4.Remove a player from an event\n");
			printf("5.Show the winners list for each event\n");
			printf("6.Ticket Status for each event\n");
			printf("7.Ticket Reservation for an event\n");
			printf("8.Ticket Cancellation for an event\n");
			printf("9.Log Out\n");
			printf("----------------------------------\n");
			printf("              ****                \n");
			printf("----------------------------------\n");
			printf("ENTER YOUR CHOICE : ");
			scanf("%d",&n);
			switch(n)
			{
			case 1:
			printf("The events are:\n");
			disp_events();
			break;
			case 2:
			detail_player(pt,ps,pa);
			break;
			case 3:
			add_player(pt,ps,pa);
			break;
			case 4:
			delete_player(pt,ps,pa);
			break;
			case 5:
			winner_player(pt,ps,pa);
			break;
			case 6:
			printf("TENNNIS\n");
			tickets_available(head_ticket_t);
			print(head_ticket_t);
			printf("SWIMMING\n");
			tickets_available(head_ticket_s);
			print(head_ticket_s);
			printf("ATHLETICS\n");
			tickets_available(head_ticket_a);
			print(head_ticket_a);
			break;
			case 7:
			printf("select the event1\n1.SWIMMING\n2.ATHLETICS\n3.TENNIS\n4.EXIT\n");
    scanf("%d",&p);
    switch (p) {
    case 1:
	{
print(head_ticket_s);
	  tickets_available(head_ticket_s);
	  printf("enter your id:");
	  scanf("%d",&idn);
	    printf("enter the seat you want to book and your name\n");
      scanf("%d\n",&l );
update_data_book(idn,l,head_ticket_s); break;
}
    case 2:
	{
print(head_ticket_a);
	  tickets_available(head_ticket_a);
	  printf("enter your id:");
	  scanf("%d",&idn);
	  printf("enter the seat you want to book and your name\n");
      scanf("%d\n",&a );
     update_data_book(idn,a,head_ticket_a);  break;
}
    case 3:
	{
print(head_ticket_t);
    tickets_available(head_ticket_t);
	printf("enter your id:");
	  scanf("%d",&idn);
	  printf("enter the seat you want to book and your name\n");
  scanf("%d\n",&b );
update_data_book(idn,b,head_ticket_t);break;
}
	}
			break;
			case 8:
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
			case 9:
			goto l;
			break;
			default:
			printf("INVALID OPTION!\n");
			break;
			}
		}
		}
		
		break;
		}
		case 2:
		{
		printf("Welcome Player!!\n");
		printf("**\n");
        result_player(pt,ps,pa);
        goto l;
		break;
        }
		case 3:
		{
		printf("Welcome Visitor!!\n");
		printf("****************************\n");
		detail_vis(head_ticket_t,head_ticket_s,head_ticket_a);
		goto l;
		break;
		}
		case 4:
		exit(0);
		break;
		default:
		printf("choose correct option\n");
		break;
		}
	}
	return 0;
}

			
			
			
			
		
	