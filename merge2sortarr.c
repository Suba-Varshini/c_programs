#include <stdio.h>
void sort(int arr[],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
void sortedmerge(int a[], int b[], int c[], int n, int m) 
{
    int i = 0, j = 0, k = 0; 
    while (i < n && j < m) { 
        if (a[i] <= b[j]) { 
            c[k] = a[i]; 
            i += 1; 
            k += 1; 
        } else { 
            c[k] = b[j]; 
            j += 1; 
            k += 1; 
        } 
    }     
    while (i < n) {  
        c[k] = a[i]; 
        i += 1; 
        k += 1; 
    }     
    while (j < m) { 
        c[k] = b[j]; 
        j += 1; 
        k += 1; 
    } 	
} 
void main()
    {
        int arr1[50], arr2[50], arr3[100], m, n, i, j, k = 0;
        printf("\n Enter size of array Array 1: ");
        scanf("%d", &m);
        printf("\n Enter elements of array 1: \n");
        for (i = 0; i < m; i++) 
        {
			printf("\narr[i] = ");
            scanf("%d", &arr1[i]);
			printf("\n");
        }
        printf("\n Enter size of array 2: ");
        scanf("%d", &n);
        printf("\n Enter elements of array 2: \n");
        for (i = 0; i < n; i++) 
        {
            printf("\narr[i] = ");
            scanf("%d", &arr2[i]);
			printf("\n");
        }
		sort(arr1,m);
		sort(arr2,n);
        sortedmerge(arr1,arr2,arr3,m,n);
        printf("\n After merging 2 sorted arrays is: \n");
        for (i = 0; i < m + n; i++) 
        {
            printf("%d\t", arr3[i]);
        }
		printf("\n");
    }
	