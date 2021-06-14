#include <stdio.h>
int main() {
   int r, sum = 1, d , i, j;
   printf("Enter the number of rows-r for pascals triangle: ");
   scanf("%d", &r);
   for (i = 0; i < r; i++)
	{
      for (d = 1; d <= r - i; d++)
         printf("  ");
      for (j = 0; j <= i; j++) {
         if (j == 0 || i == 0)
            sum = 1;
         else
            sum = sum * (i - j + 1) / j;
         printf("%5d", sum);
      }
      printf("\n");
   }
   return 0;
}



