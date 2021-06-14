#include<stdio.h>
void main()
{
    int i,n,m,j;
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
	int s=0;
	for(i=0;i<m;i++)
    {
	    for(j=0;j<n;j++)
		{
		if (arr[i]==arr[j])
            s+=arr[i][j];
		}
	}
	printf("sum of diagonal is %d\n",s);
}
