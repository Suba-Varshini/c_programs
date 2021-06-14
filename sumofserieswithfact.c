#include<stdio.h>
long double fact(int);
int main()
{
int n,i;
long double sum=0;
printf("enter the number upto which series has to be calculated\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
	sum=sum+(1/fact(i));
}
printf("the sum of series is %Lf\n",sum);
return 0;
}
long double fact(int n)
{
int j;
int fact=1;
for(j=1;j<=n;j++)
{
	fact=fact*j;
}
return fact;
}
