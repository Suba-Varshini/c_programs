#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
char str1[100],str2[100];
int i,n;
printf("enter the character array\n");
scanf("%[^\n]s",str1);
printf("enter the n characters to be copied\n");
scanf("%d",&n);
char *ptr=str1;
ptr=ptr+strlen(str1)-n;
for(i=0;i<n;i++)
{
	str2[i]=toupper(*ptr);
	ptr++;
}
printf("%s\n",str2);
return 0;
}
