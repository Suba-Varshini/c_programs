#include<stdio.h>
int main()
{
char*ptr[7]={"xyz","abc","def","ghi","jkl","mno","pqr"};
int i;
printf("\n");
for(i=0;i<7;i++)
{
	printf("\nname %d is %s ",i+1,ptr[i]);
}
return 0;
}
	
