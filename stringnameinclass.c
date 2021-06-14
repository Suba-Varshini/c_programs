#include<stdio.h>
#include<string.h>
void main()
{
	int n,i,j;
	char temp[50];
	printf("enter the number of students\n");
	scanf("%d",&n);
	char str[n][50];
	for(i=0;i<n;i++)
	{
		printf("enter the %d student\n",i+1);
		scanf("%s[^\n]",str[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("student %d is %s\n",i+1,str[i]);
	}
	for (i = 0; i < n-1; i++) 
	{
		for (j = i+1; j < n; j++) 
		{
			if (strcmp(str[i],str[j])>0) 
			{
					strcpy(temp,str[i]);
					strcpy(str[i],str[j]);
					strcpy(str[j],temp);
			}
		}
	}
	printf("After sorting names\n");
	for(i=0;i<n;i++)
	{
		printf("student %d is %s\n",i+1,str[i]);
	}
}