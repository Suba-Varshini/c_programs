#include<stdio.h>
#include<math.h>
void main()
{
    int i,n,j;
    printf("enter the number of array elements\n");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        printf("enter the array element arr[%d]\n",i);
        scanf("%d",&arr[i]);
    }
	printf("the given array is\n");
    for(i=0;i<n;i++)
    {
        printf("arr[%d]=%d\n",i,arr[i]);
    }
	int sum=0;
	for(i=0;i<n;i++)
    {
        sum+=arr[i]*arr[i];
    }
	printf("sum of squares of elements is %d\n",sum);
}