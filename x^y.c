#include <stdio.h>
int xyfunc(int,int);
void main()
{
    int x,y;
  	printf("Enter a number x\n");
  	scanf("%d",&x);
    printf("Enter a number y\n");
  	scanf("%d",&y);
    printf("Value of %d^%d = %d\n",x,y,xyfunc(x,y));
}
int xyfunc(int x, int y)
{
    if (y!= 0)
        return (x*xyfunc(x,y-1));
    else
        return 1;
}
