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
	int s=0;
	for(i=0;i<n;i++)
    {
        s+=arr[1];
    }
	float avg;
	avg=s/n;
	for(i=0;i<n;i++)
    {
		for(j=i+1;j<n;j++)
		{
			if(arr[i]<arr[j])
			{
				int temp;
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	printf("the given array is after sort\n");
	for(i=0;i<n;i++)
    {
        printf("arr[%d]=%d\n",i,arr[i]);
    }
	printf("the sum of array elements is %d\n", s);
	printf("the average of array elements is %.2f\n", avg);
	printf("the largest array element is %d\n", arr[0]);
}