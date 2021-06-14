#include<stdio.h>
#include<string.h>
int sumofdigits(char *p,int n)
{
	int z,i=0,sum=0;
	while(i<n)
    {
	switch(*p)
	{
		case '1':*p=1;break;
		case '2':*p=2;break;
		case '3':*p=3;break;
		case '4':*p=4;break;
		case '5':*p=5;break;
		case '6':*p=6;break;
		case '7':*p=7;break;
		default : break;
	}
	sum+=*p;
	p++;i++;
    }
	return sum;
}
void addition(char *pt)
{
	int i=0,c[10]={3,4,5,7,7,8,7};
	printf("the resultant characters is ");
	while(*pt!='\0')
	{
	printf("%c",(int)(*pt+c[i]));
	pt++;i++;
	}
	printf("\n");
}
int main()
{
char str[20];
int i,n;
printf("enter the character array\n");
scanf("%[^\n]s",str);
char *ptr=str;
printf("the character array is ");
while(*ptr!='\0')
{
	printf("%c",*ptr);
	ptr++;
}
printf("\n");
printf("now calling function sumofdigits()\n");
printf("the sum is %d\n",sumofdigits(str,strlen(str)));
printf("now addition of 1234567 + 3457787\n");
addition(str);
return 0;
}

