#include <stdio.h>
int main() 
{
   int arr[100];
   int i,n;
printf("enter the number of array elements\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("arr[%d]= ",i);
scanf("%d",&arr[i]);
printf("\n");
}
   int j, pos, temp;
   for (i = 0; i < (n - 1); i++) {
      pos = i;
      for (j = i + 1; j < n; j++) {
         if (arr[pos] > arr[j])
            pos = j;
      }
      if (pos != i) {
         temp = arr[i];
         arr[i] = arr[pos];
         arr[pos] = temp;
      }
   }
   for (i = 0; i < n; i++)
      printf("%d\n", arr[i]);
   return 0;
}

