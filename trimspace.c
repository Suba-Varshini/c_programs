#include<stdio.h>
#include<ctype.h>
#include<string.h>
void main()
{
	char str[100];
	printf("enter the string\n");
	scanf("%s",str);
    int i;
    int begin = 0;
    int end = strlen(str) - 1;

    while (isspace((unsigned char) str[begin]))
        begin++;

    while ((end >= begin) && isspace((unsigned char) str[end]))
        end--;
    for (i = begin; i <= end; i++)
        str[i - begin] = str[i];

    str[i - begin] = '\0'; 
	printf("%s\n",str);
}