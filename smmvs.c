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
	int sum=0,median;
	float mean,var,std;
	for(i=0;i<n;i++)
    {
       sum+=arr[i];
    }
	mean=sum/n;
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
	if(n%2==0)
		median=(arr[n/2]+arr[(n/2)+1])/2;
	else
		median=arr[(n+1)/2];
	int s = 0;
    for (int i = 0; i < n; i++) 
        s += arr[i]; 
    double m = (double)s / (double)n; 
    double sqd = 0; 
    for (int i = 0; i < n; i++)  
        sqd += (arr[i] - m) *  
                  (arr[i] - m); 
    var=sqd / n; 
	std=sqrt(var);
	printf("\nthe mean is %.2f\n the sum is %d\n the std is %.2f\n the variance is %.2lf\n the median is %d\n",mean,sum,std,var,median);
}	