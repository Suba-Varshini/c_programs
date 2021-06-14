#include<stdio.h>
void main()
{
int n;
printf("menu\n");
printf("********\n");
printf("1.circle\n2.triangle3.rectangle\n");
scanf("%d",&n);
switch(n)
{
case 1:
ar_circle();
break;
case 2:
ar_triang();
break;
case 3:
ar_rect;
break;
default:
printf("enter valid number\n");
goto l;
break;
}
}