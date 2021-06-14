#include<stdio.h>
#include<string.h>
void main()
{
	char str[100];
	char ch;
	printf("enter the letter\n");
	scanf("%c",&ch);
	printf("enter the string\n");
	scanf("%s",str);
	int i,len,pos,j=0;
	len=strlen(str);
	while(str[j]!='\0')
	{
		if(str[j]==ch)
			pos=j;
		j++;
	}
	for(i=pos;i<len;i++)
	{
		str[i]=str[i+1];
	}
	printf("%s\n",str);
}
	