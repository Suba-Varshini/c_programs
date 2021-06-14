#include<stdio.h>
#include<string.h>
void main()
{
	char str1[100],str2[100];
	printf("enter the string\n");
	scanf("%s",str1);
	printf("enter the string to be appended\n");
	scanf("%s",str2);
	int i=0,len;
	len=strlen(str1);
	while(str2[i]!='\0')
	{
		str1[len]=str2[i];
		i++;
		len++;
	}
	printf("%s\n",str1);
}
