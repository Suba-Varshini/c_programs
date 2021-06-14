#include<stdio.h>
#include <stdlib.h>
#include <time.h>
void changeValues(int *,int *);
void shuffleRandon(int [],int);
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
	shuffleRandon(arr,n);
	for (i = 0; i < n; i++)
        printf("%d\n", arr[i]);
}
void changeValues (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void shuffleRandon ( int arr1[], int n )
{
    srand ( time(NULL) );
    for (int i = n-1; i > 0; i--)
    {
        int j = rand() % (i+1);
        changeValues(&arr1[i], &arr1[j]);
    }
}

