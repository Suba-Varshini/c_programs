#include<stdio.h>
void main()
{
    int i,n;
    printf("enter the number of array elements\n");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        printf("enter the array element arr[%d]\n",i);
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("arr[%d]=%d\n",i,arr[i]);
    }
}