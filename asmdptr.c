#include<stdio.h>
int operatefn(int(*operate)(int,int),int a,int b)
{
	int result=(*operate)(a,b);
	return result;
}
int add(int a,int b)
{
    return a+b;
}
int sub(int a,int b)
{
    return a-b;
}
int main()
{
	int n,a,b,res;
	printf("enter 2 numbers a and b\n");
	scanf("%d%d",&a,&b);
	printf("*******\n");
	printf("menu\n1.add\n2.subtract\n");
	printf("*******\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1:res=operatefn(add,a,b);break;
		case 2:res=operatefn(sub,a,b);break;
		default:printf("cannot operate\n");break;
	}
	printf("result is %d\n",res);
	return 0;
}
