#include<stdio.h>
void main()
{
    int i,n1,m1,j,m2,n2;
    printf("enter the number of rows and columns of matrix 1\n");
    scanf("%d%d",&m1,&n1);
	printf("enter the number of rows and columns of matrix 2\n");
    scanf("%d%d",&m2,&n2);
    int arr1[m1][n1],arr2[m2][n2];
	if(n1==m2)
	{
    printf("matrix can be multiplied\n***********************\n");
	printf("MATRIX 1\n");
    for(i=0;i<m1;i++)
    {
	    for(j=0;j<n1;j++)
		{
        printf("enter the array element arr[%d][%d]\n",i,j);
        scanf("%d",&arr1[i][j]);
		}
    }
	printf("MATRIX 2\n");
	for(i=0;i<m2;i++)
    {
	    for(j=0;j<n2;j++)
		{
        printf("enter the array element arr[%d][%d]\n",i,j);
        scanf("%d",&arr2[i][j]);
		}
    }
	printf("the given matrix 1 is\n");
    for(i=0;i<m1;i++)
    {
	    for(j=0;j<n1;j++)
		{
        printf("%d\t",arr1[i][j]);
		}
		printf("\n");
    }
	printf("the given matrix 2 is\n");
    for(i=0;i<m2;i++)
    {
	    for(j=0;j<n2;j++)
		{
        printf("%d\t",arr2[i][j]);
		}
		printf("\n");
    }
	int arr3[m1][n2],s=0,k;
	for (i=0;i<m1;i++)
	{
		for(j=0;j<n2;j++)
		{
			for(k=0;k<m2;k++)
			{
			s=s+arr1[i][k]*arr2[k][j];
			}
		}
		arr3[i][j]=s;
		s=0;
	}
	printf("the matrix 3 is\n");
    for(i=0;i<m1;i++)
    {
	    for(j=0;j<n2;j++)
		{
        printf("%d\t",arr3[i][j]);
		}
		printf("\n");
    }
	}
	else
	{
		printf("matrix cannot be multiplied");
	}
}
