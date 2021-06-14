#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct player
{
	char p_name[20];
	int p_id;
	int contact;
	int age;
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
		printf("Enter the Points(Out of 5): ");
		scanf("%d",&points);
		if(points<=5)
		{
			(t_new->tscore.t_points)=points;
			break;
		}
		else
			printf("Invalid! Enter the points again: ");
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
		printf("Enter the player name: ");
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
		printf("Enter the Points(Out of 10): ");
		scanf("%d",&points);
		if(points<=10)
		{
			(s_new->sscore.s_points)=points;
			break;
		}
		else
			printf("Invalid! Enter the points again: ");
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
		printf("Enter the player name: ");
		scanf("%s",a_new->p3.p_name);
        printf("Enter Player ID: ");
        scanf("%d", &(a_new->p3.p_id));
        printf("Enter Player Contact No: ");
        scanf("%d", &(a_new->p3.contact ));
        printf("Enter Player Age: ");
        scanf("%d", &(a_new->p3.age));
		a_new->ascore.a_rounds=7;
		while(1)
		{
		printf("Enter the points(Out of 7): ");
		scanf("%d",&points);
		if(points<=7)
		{
			(a_new->ascore.a_points)=points;
			break;
		}
		else
			printf("Invalid! Enter the points again: ");
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
     printf("\n====================================================\n");
	 printf("  ID       NAME         CONTACT     AGE    POINTS ");
	 printf("\n====================================================\n");

     while( t_temp!= pt)
     {
      printf("%5d |", t_temp ->p1.p_id);
	  printf("%11s |", t_temp ->p1.p_name);
      printf("%13d |", t_temp ->p1.contact);
      printf("%4d |", t_temp ->p1.age);
	  printf("%4d/%d",t_temp->tscore.t_points,t_temp->tscore.t_rounds);
      printf("\n");
      t_temp = t_temp ->t_next ;
     }
	 printf("====================================================\n");
     }
    else
        printf("\nNo players in Tennis Event.\n");
  }
void s_display(p_s ps)
  {
    if(!s_Empty(ps))
    {
	 p_s s_temp=ps->s_next;
    printf("\n====================================================\n");
	 printf("  ID       NAME         CONTACT     AGE    POINTS ");
	 printf("\n====================================================\n");

     while( s_temp!= ps)
     {
      printf("%5d |",s_temp ->p2.p_id);
	  printf("%11s |", s_temp ->p2.p_name);
      printf("%13d |", s_temp ->p2.contact);
      printf("%4d |", s_temp ->p2.age);
	  printf("%4d/%d",s_temp->sscore.s_points,s_temp->sscore.s_rounds);
      printf("\n");
      s_temp = s_temp ->s_next ;
     }
	 	 printf("====================================================\n");
     }
    else
        printf("\nNo players in swimming Event.\n");
  }
void a_display(p_a pa)
  {
    if(!a_Empty(pa))
    {
	 p_a a_temp=pa->a_next;
    printf("\n====================================================\n");
	 printf("  ID       NAME         CONTACT     AGE    POINTS ");
	 printf("\n====================================================\n");

     while( a_temp!= pa)
     {
      printf("%5d |", a_temp ->p3.p_id);
	  printf("%11s |", a_temp ->p3.p_name);
      printf("%13d |", a_temp ->p3.contact);
      printf("%4d |", a_temp ->p3.age);
	  printf("%4d/%d",a_temp->ascore.a_points,a_temp->ascore.a_rounds);
      printf("\n");
      a_temp = a_temp ->a_next ;
     }
	 printf("====================================================\n");
     }
    else
        printf("\nNo players in athletics Event.\n");
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
int main()
{
	p_t pt=create_list_tennis();
	p_s ps=create_list_swim();
	p_a pa=create_list_ath();
	int c,n;
	char password_correct[26]="admin_sports",password[26];
	printf("******\n");
	printf("ENTER YOUR ROLE : \n");
	printf("******\n");
	printf("\n1.  ADMIN \n2.  PLAYER \n3.  VISITOR \n4.  LOG-OUT\nENTER YOUR CHOICE : ");
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
			case 9:
			    printf("\n<<<LOGGING OUT OF ADMIN>>>\n");
				break;
			default:
			printf("INVALID OPTION!\n");
			break;
			}
			}
		}
		else
		{
			if(count<=3)
			{
			printf("PASSWORD IS INCORRECT\n");
			printf("try again\n");
			}
			else
			{
				printf("You are not an admin!!\n");
				break;
			}
			count+=1;
		}
		break;
		case 2:
		printf("Welcome Player!!\n");
		printf("****************\n");
		printf("Enter your password:");
		scanf("%[^\n]s",password);
		break;
		case 3:
		printf("Welcome Visitor!!\n");
		printf("*****************\n");
		printf("Enter your password:");
		scanf("%[^\n]s",password);
		break;
		case 4:
		exit(0);
		break;
		default:
		printf("\nINVALID OPTION!\n");
		break;
		}
		}
	}
	return 0;
}