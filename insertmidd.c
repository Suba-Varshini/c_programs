#include<stdio.h>
#include<string.h>
void main()
{
	char str[100],ch[5];
	printf("enter the 3 letter string\n");
	scanf("%s",ch);
	printf("enter the string\n");
	scanf("%s",str);
	int i,len;
	len=strlen(str);
    int mid=len/2;
	for(i=len;i>mid;i--)
	{
		str[i+2]=str[i-1];
	}
	int j,k=0;
	for(j=mid;j<mid+3;j++)
	{
		str[j]=ch[k];
		k++;
	}
	printf("%s\n",str);
}
	