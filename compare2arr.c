#include <stdio.h>
#include <stdlib.h> 
int main() 
{
   int n,m,i;
   printf("enter n\n");
   scanf("%d",&n);
   int *arr1 = (int *)malloc(n * sizeof(int)); 
   int *arr2 = (int *)malloc(n * sizeof(int));
   for(i=0;i<n;i++)
	    scanf("%d",&(*(arr1 + i)));
   for(i=0;i<n;i++)
	    scanf("%d",&(*(arr2 + i)));
	if(arr1==arr2)
		printf("1 and equal\n");
	else
		printf("not equal\n");
	return 0;
}
		
	