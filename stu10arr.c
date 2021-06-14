#include<stdio.h>
void main()
{
	int arr[10][3],i,j,tot_mark[10],sum; float avg[10];
	for(i=0;i<10;i++)
	{
		printf("STUDENT %d:\n",i+1);
		for(j=0;j<3;j++)
		{
			printf("mark %d : ",j+1);
			scanf("%d",&arr[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<10;i++)
	{
		sum=0;
		for(j=0;j<3;j++)
		{
			sum+=arr[i][j];
		}
		tot_mark[i]=sum;
		avg[i]=tot_mark[i]/3;
	}
	for(i=0;i<10;i++)
	{
		printf("STUDENT %d:\n",i+1);
		for(j=0;j<3;j++)
		{
			printf("mark %d : %d\n",j+1,arr[i][j]);
		}
		printf("total mark : %d\n",tot_mark[i]);
		printf("avg : %.2f\n",avg[i]);
		printf("\n");
	}
}
