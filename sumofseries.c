#include <stdio.h>
long double fact(int);
int xyfunc(int,int);
int main()
{
  int i,sign =  - 1,x;
  float sum = 0;
  printf("Enter the value of x : ");
  scanf("%d", &x);
  for (i = 1; i <= 5; i += 2)
  {
    sign =  - 1 * sign;
    sum += sign * xyfunc(x,i) / fact(i);
  }
  printf("sum of f(%d) = %d-%d^3/3! + %d^5/5! = %f\n", x,x,x,x, sum);
  return 0;
}
long double fact(int n) 
{
    if (n>=1)
        return n*fact(n-1);
    else
        return 1;
}
int xyfunc(int x, int y)
{
    if (y!= 0)
        return (x*xyfunc(x,y-1));
    else
        return 1;
}

