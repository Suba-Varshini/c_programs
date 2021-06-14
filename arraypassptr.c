#include <stdio.h>
void funcn( int *ptr, int n)
{

    for(int x=0; x<n; x++)
    {
        printf("Value of arr[%d] is: %d \n", x, *ptr);
        ptr++;
    }
}
void disp( int *num)
{
    printf("%d ", *num);
}
int main()
{
int arr[100],i,n;
printf("enter the number of array elements\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("arr[%d]= ",i);
scanf("%d",&arr[i]);
printf("\n");
}
funcn(arr, n);
for(i=0;i<n;i++)
{
	disp(&arr[i]);
}
return 0;
}