#include<stdio.h>
void main()
{
	char str[100];
	printf("enter the string\n");
	scanf("%s",str);
	int i=0;
	while(str[i]!='\0')
	{
		if(str[i]>='a' && str[i]<='z')
			str[i]=str[i];
		else 
			str[i]=str[i]+32;
		i+=2;
	}
	printf("%s\n",str);
}
