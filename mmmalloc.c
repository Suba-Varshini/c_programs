#include <stdio.h>
#include <stdlib.h> 
int main() {
   int row= 2, col = 3;
   int rows=2,cols=3;
   int *arr1 = (int *)malloc(row * col * sizeof(int)); 
   int *arr2 = (int *)malloc(rows * cols * sizeof(int));
   int *arr3 = (int *)malloc(row * col * sizeof(int)); 
   int i, j;
   for (i = 0; i < row; i++)
      for (j = 0; j < col; j++)
         scanf("%d",&(*(arr1 + i*col + j)));  
   printf("The matrix 1 elements are:\n");
   for (i = 0; i < row; i++) {
      for (j = 0; j < col; j++) {
         printf("%d ", *(arr1 + i*col + j)); 
      }
      printf("\n");
   }
    for (i = 0; i < rows; i++)
      for (j = 0; j < cols; j++)
         scanf("%d",&(*(arr2 + i*cols + j))); 
	 printf("The matrix 2 elements are:\n");
    for (i = 0; i < rows; i++) {
      for (j = 0; j < cols; j++) {
         printf("%d ", *(arr1 + i*cols + j)); 
      }
      printf("\n");
   }	 
   for (i = 0; i < row; i++)
      for (j = 0; j < col; j++)
		  *(arr3 + i*col + j)=*(arr1 + i*col + j)* *(arr2 + i*col + j);
	  printf("The matrix 3 elements are:\n");
	for (i = 0; i < rows; i++) {
      for (j = 0; j < cols; j++) {
         printf("%d ", *(arr3 + i*cols + j)); 
      }
      printf("\n");
   }	 
   free(arr1); 
   free(arr2);
   return 0;
}