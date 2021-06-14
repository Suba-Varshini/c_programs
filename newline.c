#include<stdio.h>
#include<stdlib.h>
void main()
{
	char str[100];
	printf("enter the sentence\n");
	scanf("%[^\n]s",str);
	printf("%s\n",str);
}
