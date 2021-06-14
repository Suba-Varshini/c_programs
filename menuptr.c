#include <stdio.h> 
void add(int a, int b) 
{ 
    printf("Addition is %d\n", a+b); 
} 
void subtract(int a, int b) 
{ 
    printf("Subtraction is %d\n", a-b); 
} 
void multiply(int a, int b) 
{ 
    printf("Multiplication is %d\n", a*b); 
} 
void divide( int a, int b)
{
	if(b==0)
		printf("cannot be divided");
	printf("Division is %2d\n",a/b);
}
int main() 
{ 
    void (*fun_ptr_arr[])(int, int) = {add, subtract, multiply, divide}; 
    int c,a,b;
	printf("enter a and b\n");
	scanf("%d%d",&a,&b);
    printf("Enter Choice: 0 for add, 1 for subtract and 2 for multiply 3 for divide\n"); 
    scanf("%d", &c); 
    if (c > 3) 
		return 0; 
    (*fun_ptr_arr[c])(a, b); 
    return 0; 
} 

