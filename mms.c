#include<stdio.h>
#include<math.h>
void swap(int *p,int *q) {
   int t;
   
   t=*p; 
   *p=*q; 
   *q=t;
}

void sort(int a[],int n) 
{ 
   int i,j,temp;

   for(i = 0;i < n-1;i++) {
      for(j = 0;j < n-i-1;j++) {
         if(a[j] > a[j+1])
            swap(&a[j],&a[j+1]);
      }
   }
}
float fn_mean(int *ptr,int n)
{
	int i;
float mean=0;
for(i=0;i<n;i++)
{
	mean+=*ptr;
	ptr++;
}
    mean=mean/n;
	return mean;
}
int fn_median(int arr[], int x)
{
	int n=x-1;
	int median;
sort(arr,x);
if(n%2==0)
	median=(arr[n/2]+arr[(n/2)+1])/2;
else
	median=arr[(n+1)/2];
return median;
}
float fn_std(int *ptr,int arr[],int n)
{
      int j; 
      double max[100],sum,variance,mean;
      mean=fn_mean(arr,n);
      sum=0;
      for(j=0;j<n;j++) 
      {
         max[j]=pow((*ptr-mean),2);
         sum+=max[j];
		 ptr++;
      }
      variance=sum/(j-1); 
      return sqrt(variance);
}
int main()
{
int arr[100],i,n;
float mean,std;
int median;
printf("enter the number of array elements\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("arr[%d]= ",i);
scanf("%d",&arr[i]);
printf("\n");
}
mean=fn_mean(arr,n);
median=fn_median(arr,n);
std=fn_std(arr,arr,n);
printf("median= %d\n",median);
printf("mean= %.2f\n",mean);
printf("std= %.2f\n",std);
return 0;
}
