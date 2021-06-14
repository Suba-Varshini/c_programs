#include <stdio.h>
#include<math.h>
int fact(int,int *);
float sine(int,int,float *);
int main()
{
 int n;
  float x, sum = 0;
  printf("Enter the value of x : ");
  scanf("%f", &x);
  printf("Enter the value of n : ");
  scanf("%d", &n);
  sum=sine(x,n,&sum);
  printf("sin %0.2f = %f\n", x, sum);
  return 0;
}
int fact(int n,int *fact)
    {
       *fact=1;
       while(n>=1)
	   {
		   *fact=*fact * n;
		   n--;
	   }
       return *fact;
    }
float sine(int x,int n,float *sum)
{
 int i,sign =  - 1;
 int f;
*sum=0;
 for (i = 1; i <= n; i += 2)
  {
    sign =  - 1 * sign;
	f=fact(i,&f);
    *sum += sign * pow(x,i) / f;
  }
  return *sum;
}