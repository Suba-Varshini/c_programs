#include<stdio.h>
void main()
{
int m,n,i,j;
printf("enter the number of rows and columns\n");
scanf("%d%d",&m,&n);
int arr[m][n];
    for(i=0;i<m;i++)
    {
	    for(j=0;j<n;j++)
		{
        printf("enter the array element arr[%d][%d]\n",i,j);
        scanf("%d",&arr[i][j]);
		}
    }
	printf("the given matrix is\n");
    for(i=0;i<m;i++)
    {
	    for(j=0;j<n;j++)
		{
        printf("%d\t",arr[i][j]);
		}
		printf("\n");
    }
	printf("the upper triangular matrix is\n");
    for(i=0;i<m;i++)
    {
	    for(j=0;j<=i;j++)
		{
        printf("%d\t",arr[i][j]);
		}
		printf("\n");
    }
	printf("the lower triangular matrix is\n");
	for(i=0;i<m;i++)
    {
	    for(j=i;j<n;j++)
		{
        printf("%d\t",arr[i][j]);
		}
		printf("\n");
    }
}
