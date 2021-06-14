#include<stdio.h>
struct fraction
{
   int num;
   int den;
};
int compare(struct fraction x,struct fraction y)
{
	if(x.den!=0 && y.den!=0)
	{
		if(x.num/x.den > y.num/y.den)
			return -1;
		else 
			return 1;
	}
	else
		printf("franctions cannot be compared\n");
	return 0;
}
void main()
{
	struct fraction a,b;
	printf("FRACTION 1\n");
	printf("enter num1\n");
	scanf("%d",&a.num);
	printf("enter den1\n");
	scanf("%d",&a.den);
	printf("FRACTION 2\n");
	printf("enter num2\n");
	scanf("%d",&b.num);
	printf("enter den2\n");
	scanf("%d",&b.den);
	int res=compare(a,b);
	if(res==1)
		printf("frac 2 is great\n");
	else 
		printf("frac 1 is great\n");
}
