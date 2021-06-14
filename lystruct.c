#include<stdio.h>
struct date
{
   int year;
};
void calculate(struct date y)
{
	if(y.year%400==0)
		printf("leap year\n");
	else if(y.year%4==0 && y.year%100!=0)
		printf("leap year\n");
	else
		printf("not a leap year\n");
}
void main()
{
	struct date d;
	printf("enter the year\n");
	scanf("%d",&d.year);
	calculate(d);
}

