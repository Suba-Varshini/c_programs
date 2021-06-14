#include<stdio.h>
#include<string.h>
int main()
{
char str[100];
int c=0,space=0,line=0;
int i,n;
char *ptr=str;
printf("enter the character array\n");
scanf("%[^\n]s",str);
while(*ptr!='\0')
{
c++;
if(*ptr==' ')
	space++;
if(*ptr=='.')
	line++;
ptr++;
}
printf("count of characters = %d\n",c);
printf("count of words = %d\n",space-1);
printf("count of lines = %d\n",line);
return 0;
}
