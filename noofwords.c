#include<stdio.h>
#include<stdlib.h>
void main()
{
	char str[100];
	printf("enter the sentence\n");
	scanf("%[^\n]s",str);
	int i=0,c=0;
	while(str[i]!='\0')
	{
		if(str[i]==' ')
			c++;
		i++;
	}
	printf("the number of words in the given sentence is %d\n",c+1);
}
