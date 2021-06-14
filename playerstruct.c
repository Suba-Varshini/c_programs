#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct score
{
	int boundary,sixer;
};
struct player
{
   char name[50];
   int id;
   struct score s;
   int scores;
   char rating[20];
};
void accept(struct player* play,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
	printf("enter the name of player:");
	scanf("%s", (play+i)->name);
	printf("enter the id of player:");
	scanf("%d",&(play+i)->id);
	printf("enter the boundaries and sixers:\n");
	scanf("%d%d",&(play+i)->s.boundary,&(play+i)->s.sixer);
	(play+i)->scores=(4*(play+i)->s.boundary)+(6*(play+i)->s.sixer);
	}
}
void display(struct player* play,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
	printf("PLAYER  %d\n",i+1);
	printf("player name      : %s\n",(play+i)->name);
	printf("player id        : %d\n",(play+i)->id);
	printf("player boundary  : %d\n",(play+i)->s.boundary);
	printf("player sixers    : %d\n",(play+i)->s.sixer);
	printf("player scores    : %d\n",(play+i)->scores);
	printf("player remark    : %s\n",(play+i)->rating);
	printf("\n");
	}
}
void scoreboard(struct player* play,int n)
{
	int i,j;
	int arr[n];
	for(i=0;i<n;i++)
	{
		arr[i]=(play+i)->scores;
	}
    int pos, temp;
    for (i = 0; i < (n - 1); i++) {
      pos = i;
      for (j = i + 1; j < n; j++) {
         if (arr[pos] > arr[j])
            pos = j;
      }
      if (pos != i)
	  {
         temp = arr[i];
         arr[i] = arr[pos];
         arr[pos] = temp;
       }
    }
	printf("the scores of players in sorted order is\n");
	for (i=0;i<n;i++)
	{
		printf("%d\n",arr[i]);
	}
}
struct player rating_remarks(struct player* play,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
	if((play+i)->scores>100)
		strcpy((play+i)->rating,"EXCELLENT");
	else if((play+i)->scores>50 && (play+i)->scores<100 )
		strcpy((play+i)->rating,"GOOD");		
	else
		strcpy((play+i)->rating,"FAIR");	
	}
	return *play;
}
int main()
{
	struct player *p;
	int n;
	printf("enter no of players: \n");
	scanf("%d",&n);
	p = (struct player*)malloc(n*sizeof(struct player));
	accept(p,n);
	printf("\n");
	printf("\n");
	*p=rating_remarks(p,n);
	display(p,n);
	scoreboard(p,n);
	return 0;
}   