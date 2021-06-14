#include<stdio.h>
int main()
{
	int arr[100],x,n,i,j;
	printf("enter n\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("arr[%d]= ",i);
		scanf("%d",&arr[i]);
		printf("\n");
	}
	printf("enter x\n");
	scanf("%d",&x);
	int *ptr=arr;
	int *ytr,c=0;
	i=0;
	printf("the combinations are\n");
	while(i<n)
	{
		ytr=arr;
		j=0;
		while(j<n)
		{
			if(*ytr==x-*ptr && x-*ptr!=*ptr)
			{
				c++;
			    printf("%d and %d\n",*ptr,*ytr);
			}
		    ytr++;
			j++;
		}
		ptr++;
		i++;
	}
	if(c==0)
		printf("none\n");

	return 0;
}
