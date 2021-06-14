#include<stdio.h>
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
	for(i=0;i<n;i++)
    {
		int c=0;
		for(j=i+1;j<n;j++)
		{
			if(arr[i]==arr[j])
			{
				printf("duplicate is %d\n",arr[i]);
				break;
			}
		}
	}
}
