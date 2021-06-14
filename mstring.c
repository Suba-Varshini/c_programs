#include<stdio.h>
#include<string.h>
void operatefn(char(*operate)(char),char a)
{
	*operate(a);
}
char accept()
{
	char *str[100];
	printf("enter string\n");
    scanf("%[^\n]s",*str);
	return *str;
}
void display(char *a)
{
    printf("the string is %s",a);
}
void length(char *a)
{
	printf("the length of string is %ld\n",strlen(a));
}
char merge()
{
char str1[100],str2[100];
int i=strlen(str1);
printf("enter the character array\n");
scanf("%[^\n]s",str1);
printf("enter the character array\n");
scanf("%[^\n]s",str2);
char *ptr=str2;
int j=0;
while(j<strlen(str2))
{
	str1[i]=(*ptr);
	ptr++;
}
printf("%s\n",str1);
	
}
int main()
{
	int n;
	char *res[100];
	printf("*******\n");
	printf("menu\n1.accept\n2.display\n3.length\n4.merge\n");
	printf("*******\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1:res=accept();break;
		case 2:operatefn(display,res);break;
		case 3:length();break;
		case 4:merge();break;
		default:printf("cannot operate\n");break;
	}
	return 0;
}